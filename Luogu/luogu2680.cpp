#include <bits/stdc++.h>

using namespace std;

const int N = 3e5+7;
const int INF = 0x3f3f3f3f;
typedef pair<int, int> pii;

int n, m;
long long maxv, tot;
list<pii> e[N];

template <typename T>
struct LCA
{
    static const int NN = (int)log2(N)+3;
    int f[N][NN], d[N], lg2[N];
    T w[N][NN], init_val = 0;
    LCA() {
        for (int i = 2; i < N; ++i) lg2[i] = lg2[i>>1]+1;
        fill(w[0], w[0]+N*NN, init_val);
    }
    // set sum or min or max, and don't forget to ser init_val
    T update(const T &x, const T &y) { return x+y; }
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
    int get_fa(int x, int y) {
        if (d[x] < d[y]) swap(x, y);
        while (d[x] > d[y])
            x = f[x][lg2[d[x]-d[y]]];
        if (x == y) return x;
        for (int i = lg2[d[x]]; i >= 0; --i)
            if(f[x][i] != f[y][i])
                x = f[x][i], y = f[y][i];
        return f[x][0];
    }
    T get_val(int x, int y) {
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
LCA<int> lca;

template <typename T>
struct Tree
{
    T val[N];
    void update_point(const int &x, const int &y, const T &k) {
        int _lca = lca.get_fa(x, y);
        val[x] += k; val[y] += k;
        val[_lca] -= k; val[lca.f[_lca][0]] -= k;
    }
    void update_edge(const int &x, const int &y, const T &k) {
        int _lca = lca.get_fa(x, y);
        val[x] += k; val[y] += k; val[_lca] -= 2*k;
    }
    void dfs(const int &u = 1, const int &fa = 0) {
        for (pii v : e[u]) if (v.first != fa) {
            dfs(v.first, u);
            long long tmp = 1ll*val[v.first]*v.second;
            maxv = max(maxv, tmp);
            tot += tmp;
            val[u] += val[v.first];
        }
    }
};
Tree<int> tr;

int main()
{
    ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    cin >> n >> m;
    for (int i = 1, u, v, w; i < n; ++i) {
        cin >> u >> v >> w;
        e[u].push_back({v, w});
        e[v].push_back({u, w});
    }
    lca.build(e);
    for (int i = 1, u, v; i <= m; ++i) {
        cin >> u >> v;
        tr.update_edge(u, v, 1);
    }
    tr.dfs();
    cout << tot-maxv << endl;
    return 0;
}
