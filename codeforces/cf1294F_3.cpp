#include <bits/stdc++.h>

using namespace std;

const int N = 2e5+7;

int n;
int vis[N], dis[N];
int fir[N], nex[N<<1], to[N<<1], tot;
vector<int> choose;
int q[N<<1], head, tail;

void dfs(int u, int fa, int d)
{
    dis[u] = d;
    for (int i = fir[u], v; i; i = nex[i]) {
        v = to[i];
        if (v == fa) continue;
        dfs(v, u, d+1);
    }
}

bool dfs2(int u, int fa)
{
    vis[u] = 1;
    if (u == choose.front()) return true;
    for (int i = fir[u], v; i; i = nex[i]) {
        v = to[i];
        if (v == fa) continue;
        if (dfs2(v, u)) return true;
    }
    vis[u] = 0;
    return false;
}

inline void add_edge(int u, int v)
{
    ++tot;
    to[tot] = v;
    nex[tot] = fir[u];
    fir[u] = tot;
}

int main()
{
    scanf("%d", &n);
    for (int i = 1, u, v; i < n; ++i) {
        scanf("%d%d", &u, &v);
        add_edge(u, v);
        add_edge(v, u);
    }
    dfs(1, 0, 0);
    int maxi = 1;
    for (int i = 1; i <= n; ++i)
        if (dis[i] > dis[maxi])
            maxi = i;
    choose.emplace_back(maxi);
    dfs(maxi, 0, 0);
    for (int i = 1; i <= n; ++i)
        if (dis[i] > dis[maxi])
            maxi = i;
    int res = dis[maxi];
    choose.emplace_back(maxi);

    dfs2(maxi, 0);
    for (int i = 1; i <= n; ++i) {
        dis[i] = 0;
        if (vis[i]) q[++tail] = i;
        if (i != choose[0] && i != choose[1]) maxi = i;
    }
    while (head < tail) {
        int u = q[++head];
        if (dis[u] > dis[maxi]) maxi = u;
        for (int i = fir[u], v; i; i = nex[i]) {
            v = to[i];
            if (vis[v]) continue;
            vis[v] = 1;
            dis[v] = dis[u]+1;
            q[++tail] = v;
        }
    }
    res += dis[maxi];
    choose.emplace_back(maxi);
    printf("%d\n", res);
    for (int i : choose) printf("%d ", i);
    return 0;
}
