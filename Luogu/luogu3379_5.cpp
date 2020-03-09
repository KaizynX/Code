#include <bits/stdc++.h>

using namespace std;

const int N = 5e5+7;

int n, m, root;
int lg2[N], d[N], f[N][21];
vector<int> e[N];

inline void init()
{
    // lg2[i] = lg2(i)
    for(int i = 2; i <= n; ++i)
        lg2[i] = lg2[i>>1]+1;
}

void build_tree(int u, int fa)
{
    d[u] = d[fa]+1;
    f[u][0] = fa;
    for (int i = 1; (1<<i) <= d[u]; ++i)
        f[u][i] = f[f[u][i-1]][i-1];
    for (int v : e[u]) if (v != fa)
        build_tree(v, u);
}

inline int lca(int x, int y)
{
    if (d[x] < d[y]) swap(x, y);
    while (d[x] > d[y])
        x = f[x][lg2[d[x]-d[y]]];
    if (x == y) return x;
    for (int i = lg2[d[x]]; i >= 0; --i)
        if(f[x][i] != f[y][i])
            x = f[x][i], y = f[y][i];
    return f[x][0];
}

int main()
{
    scanf("%d%d%d", &n, &m, &root);
    for(int i = 1, u, v; i < n; ++i)
    {
        scanf("%d%d", &u, &v);
        e[u].emplace_back(v);
        e[v].emplace_back(u);
    }
    init();
    build_tree(root, 0);
    for(int i = 0, u, v; i < m; ++i)
    {
        scanf("%d%d", &u, &v);
        printf("%d\n", lca(u, v));
    }
    return 0;
}
