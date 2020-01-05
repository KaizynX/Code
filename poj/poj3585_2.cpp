#include <cmath>
#include <vector>
#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>

using namespace std;

const int N = 2e5+7;
const long long INF = 1e18;

int T, n, p, tot;
int vis[N], fir[N], nex[N<<1], v[N<<1], w[N<<1], du[N];
long long res;
long long sum[N], dp[N<<1];

long long dfs(int u) {
    vis[u] = 1;
    sum[u] = 0;
    int flag = 1;
    for (int i = fir[u]; i; i = nex[i]) {
        if (vis[v[i]]) continue;
        flag = 0;
        dp[i] = min(1ll*w[i], dfs(v[i]));
        sum[u] += dp[i];
    }
    vis[u] = 0;
    return flag ? INF : sum[u];
}

void dfs2(int u, long long val) {
    vis[u] = 1;
    sum[u] += val;
    if (u != p) res = max(res, sum[u]);
    for (int i = fir[u]; i; i = nex[i]) {
        if (vis[v[i]]) continue;
        dfs2(v[i], min(1ll*w[i], sum[u]-dp[i]));
    }
    vis[u] = 0;
}

inline void add_edge(int x, int y, int z) {
    ++tot;
    v[tot] = y;
    w[tot] = z;
    nex[tot] = fir[x];
    fir[x] = tot;
    dp[tot] = 0;
}

int main()
{
    scanf("%d", &T);
    while (T--) {
        scanf("%d", &n);
        tot = 0;
        for (int i = 1; i <= n; ++i) {
            du[i] = fir[i] = 0;
        }
        for (int i = 1, x, y, z; i < n; ++i) {
            scanf("%d %d %d", &x, &y, &z);
            add_edge(x, y, z);
            add_edge(y, x, z);
            ++du[x]; ++du[y];
        }
        for (int i = 1; i <= n; ++i) {
            if (du[i] == 1) {
                p = i;
                break;
            }
        }
        res = dfs(p);
        dfs2(p, INF);
        printf("%lld\n", res);
    }
    return 0;
}
