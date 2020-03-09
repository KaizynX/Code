#include <bits/stdc++.h>

using namespace std;

const int N = 1e4+7;
const int M = 5e4+7;
const int INF = 0x3f3f3f3f;
typedef pair<int, int> pii;

struct Edge
{
    int u, v, w;
    friend bool operator < (const Edge &e1, const Edge &e2) {
        return e1.w > e2.w;
    }
    friend istream& operator >> (istream &is, Edge &e) {
        return is >> e.u >> e.v >> e.w;
    }
} edge[M];

struct DSU
{
    int fa[N];
    void init(int sz) { for (int i = 0; i <= sz; ++i) fa[i] = i; }
    int get(int s) { return s == fa[s] ? s : fa[s] = get(fa[s]); }
    int& operator [] (int i) { return fa[get(i)]; }
    bool merge(int x, int y) {
        int fx = get(x), fy = get(y);
        if (fx == fy) return false;
        fa[fx] = fy; return true;
    }
} dsu;

template <typename T>
struct LCA
{
    static const int NN = (int)log2(N)+3;
    int f[N][NN], d[N], lg2[N];
    T w[N][NN], init_val = INF;
    LCA() {
        for (int i = 2; i < N; ++i) lg2[i] = lg2[i>>1]+1;
        fill(w[0], w[0]+N*NN, init_val);
    }
    // set sum or min or max, and don't forget to ser init_val
    T update(const T &x, const T &y) { return min(x, y); }
    template <typename TT>
    void build(const TT e[], const int &u = 1, const int &fa = 0) {
        d[u] = d[fa]+1;
        f[u][0] = fa;
        for (int i = 1; (1<<i) <= d[u]; ++i) {
            f[u][i] = f[f[u][i-1]][i-1];
            w[u][i] = update(w[u][i-1], w[f[u][i-1]][i-1]);
        }
        for (auto v : e[u]) if (v.first != fa) {
            w[v.first][0] = v.second;
            build(e, v.first, u);
        }
    }
    T get(int x, int y) {
        T res = init_val;
        if (d[x] < d[y]) swap(x, y);
        while (d[x] > d[y]) {
            res = update(res, w[x][lg2[d[x]-d[y]]]);
            x = f[x][lg2[d[x]-d[y]]];
        }
        if (x == y) return res;
        for (int i = lg2[d[x]]; i >= 0; --i)
            if(f[x][i] != f[y][i]) {
                res = update(res, w[x][i]);
                res = update(res, w[y][i]);
                x = f[x][i], y = f[y][i];
            }
        return update(res, update(w[x][0], w[y][0]));
    }
};

int n, m, q;
list<pii> e[N];
LCA<int> lca;

int main()
{
    cin >> n >> m;
    for (int i = 1; i <= m; ++i)
        cin >> edge[i];
    sort(edge+1, edge+m+1);
    dsu.init(n);
    for (int i = 1, cnt = 0; i <= m; ++i) {
        if (dsu.merge(edge[i].u, edge[i].v)) {
            e[edge[i].u].push_back({edge[i].v, edge[i].w});
            e[edge[i].v].push_back({edge[i].u, edge[i].w});
            if (++cnt >= n-1) break;
        }
    }
    for (int i = 1; i <= n; ++i)
        if (dsu[i] == i) lca.build(e, i, 0);

    cin >> q;
    for (int i = 1, u, v; i <= q; ++i) {
        cin >> u >> v;
        if (dsu[u] != dsu[v]) cout << -1 << endl;
        else cout << lca.get(u, v) << endl;
    }
    return 0;
}
