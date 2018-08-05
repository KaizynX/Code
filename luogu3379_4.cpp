#include <iostream>
#include <cstdio>

using namespace std;

const int Maxn = 5e5+7;

int n, m, root;
int lg2[Maxn], d[Maxn], f[Maxn][21];
int e[Maxn<<1], fir[Maxn<<1], nex[Maxn<<1], tot;

inline void init()
{
    // lg2[i] = lg2(i) +1
    for(int i = 1; i <= n; ++i)
        lg2[i] = lg2[i>>1]+1;
}

void build_tree(int cur, int fa)
{
    d[cur] = d[fa]+1;
    f[cur][0] = fa;
    for(int i = 1; (1<<i) <= d[cur]; ++i)
        f[cur][i] = f[f[cur][i-1]][i-1];
    for(int k = fir[cur]; k; k = nex[k])
    {
        if(e[k] == fa) continue;
        build_tree(e[k], cur);
    }
}

int lca(int x, int y)
{
    if(d[x] < d[y]) swap(x, y);
    while(d[x] > d[y])
        x = f[x][ lg2[ d[x]-d[y] ]-1 ];
    if(x == y) return x;
    for(int i = lg2[d[x]]; i >= 0; --i)
        if(f[x][i] != f[y][i])
        {
            x = f[x][i];
            y = f[y][i];
        }
    return f[x][0];
}

inline void add(int u, int v)
{
    e[++tot] = v;
    nex[tot] = fir[u];
    fir[u] = tot;
}

int main()
{
    scanf("%d%d%d", &n, &m, &root);
    for(int i = 1, u, v; i < n; ++i)
    {
        scanf("%d%d", &u, &v);
        add(u, v);
        add(v, u);
    }
    init();
    build_tree(root, 0);
    for(int i = 0, u, v; i < m; ++i)
    {
        scanf("%d%d", &u, &v);
        if(u == root || v == root)
            printf("%d\n", root);
        else
            printf("%d\n", lca(u, v));
    }
    return 0;
}
