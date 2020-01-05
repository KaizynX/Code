#include <cmath>
#include <vector>
#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>

using namespace std;

const int N = 2e5+7;
const long long INF = 1e18;

int T, n, p;
int vis[N];
long long res;
long long sum[N];
vector<int> e[N], w[N];
vector<long long> dp[N];

long long dfs(int u) {
    vis[u] = 1;
    sum[u] = 0;
    int flag = 1;
    for (int i = 0; i < (int)e[u].size(); ++i) {
        int v = e[u][i];
        if (vis[v]) continue;
        flag = 0;
        dp[u][i] = min(1ll*w[u][i], dfs(v));
        sum[u] += dp[u][i];
    }
    vis[u] = 0;
    return flag ? INF : sum[u];
}

void dfs2(int u, long long val) {
    vis[u] = 1;
    sum[u] += val;
    if (u != p) res = max(res, sum[u]);
    for (int i = 0; i < (int)e[u].size(); ++i) {
        int v = e[u][i];
        if (vis[v]) continue;
        dfs2(v, min(1ll*w[u][i], sum[u]-dp[u][i]));
    }
    vis[u] = 0;
}

int main()
{
    scanf("%d", &T);
    while (T--) {
        scanf("%d", &n);
        for (int i = 1; i <= n; ++i) {
            vector<int>().swap(e[i]);
            vector<int>().swap(w[i]);
            vector<long long>().swap(dp[i]);
        }
        for (int i = 1, x, y, z; i < n; ++i) {
            scanf("%d %d %d", &x, &y, &z);
            e[x].push_back(y);
            e[y].push_back(x);
            w[x].push_back(z);
            w[y].push_back(z);
            dp[x].push_back(0);
            dp[y].push_back(0);
        }
        for (int i = 1; i <= n; ++i) {
            if ((int)e[i].size() == 1) {
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
