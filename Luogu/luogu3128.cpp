#include <bits/stdc++.h>

using namespace std;

const int N = 5e5+7;

int n, m;
int f[N][21], lg2[N], d[N];
list<int> e[N];

void build_lca_tree(const int &u, const int &fa)
{
    d[u] = d[fa]+1;
    f[u][0] = fa;
    for (int i = 1; (1<<i) <= d[u]; ++i)
        f[u][i] = f[f[u][i-1]][i-1];
    for (int v : e[u]) if (v != fa)
        build_lca_tree(v, u);
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

template <typename T>
struct Tree
{
    T val[N];
    void update_point(const int &x, const int &y, const T &k) {
        int _lca = lca(x, y);
        val[x] += k; val[y] += k;
        val[_lca] -= k; val[f[_lca][0]] -= k;
    }
    void update_edge(const int &x, const int &y, const T &k) {
        int _lca = lca(x, y);
        val[x] += k; val[y] += k; val[_lca] -= 2*k;
    }
    void dfs(const int &u = 1, const int &fa = 0) {
        for (int v : e[u]) if (v != fa) {
            dfs(v, u);
            val[u] += val[v];
        }
    }
};

Tree<int> tr;

int main()
{
    ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    cin >> n >> m;
    for (int i = 1, u, v; i < n; ++i) {
        cin >> u >> v;
        e[u].push_back(v);
        e[v].push_back(u);
    }
    for (int i = 2; i <= n; ++i) lg2[i] = lg2[i>>1]+1;
    build_lca_tree(1, 0);
    for (int i = 1, u, v; i <= m; ++i) {
        cin >> u >> v;
        tr.update_point(u, v, 1);
    }
    tr.dfs();
    int res = 0;
    for (int i = 1; i <= n; ++i)
        res = max(res, tr.val[i]);
    cout << res << endl;
    return 0;
}
