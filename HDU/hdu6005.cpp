/*
 * @Author: Kaizyn
 * @Date: 2020-03-17 22:28:00
 * @LastEditors: Kaizyn
 * @LastEditTime: 2020-03-17 23:09:37
 * @FilePath: \Code\HDU\hdu6005.cpp
 */
#include <bits/stdc++.h>

// #define DEBUG

using namespace std;

const int N = 8e4+7;
const int M = 4e4+7;
const int MOD = 1e9+7;
const double eps = 1e-7;
const long long INF = 1e18;
typedef pair<int, int> pii;

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
};

template <typename T>
struct LCA
{
    static const int NN = (int)log2(N)+3;
    int f[N][NN], d[N], lg2[N];
    T w[N][NN], init_val = 0;
    LCA() {
        for (int i = 2; i < N; ++i) lg2[i] = lg2[i>>1]+1;
        init();
    }
    // set sum or min or max, and don't forget to set init_val
    T update(const T &x, const T &y) { return x+y; }
    void init(const int &n = N-1) {
        fill(w[0], w[0]+(n+1)*NN, init_val);
    }
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

struct Edge
{
    int u, v, w;
    friend bool operator < (const Edge &e1, const Edge &e2) {
        return e1.w < e2.w;
    }
};

int n, m;
vector<pii> e[N];
map<pii, int> mp;
int used[M];
Edge edge[M];
DSU dsu;
LCA<long long> lca;


inline int get_id(const int &x, const int &y)
{
    pii pt = {x, y};
    if (mp.count(pt)) return mp[pt];
    else return mp[pt] = ++n;
}

inline long long solve()
{
    n = 0;
    mp.clear();
    cin >> m;
    for (int i = 1; i <= n*2; ++i) vector<pii>().swap(e[i]);
    for (int i = 1, r1, c1, r2, c2, u, v, w; i <= m; ++i) {
        cin >> r1 >> c1 >> r2 >> c2 >> w;
        u = get_id(r1, c1);
        v = get_id(r2, c2);
        edge[i] = {u, v, w};
    }
    sort(edge+1, edge+m+1);
    memset(used, 0, sizeof(int)*(m+1));
    dsu.init(n);
    lca.init(n);
    for (int i = 1; i <= n; ++i) vector<pii>().swap(e[i]);
    for (int i = 1, u, v, w; i <= m; ++i) {
        u = edge[i].u; v = edge[i].v; w = edge[i].w;
        if (dsu[u] == dsu[v]) continue;
        dsu.merge(u, v);
        used[i] = 1;
        e[u].emplace_back(v, w);
        e[v].emplace_back(u, w);
    }
    for (int i = 1; i <= n; ++i) {
        if (dsu[i] != i) continue;
        lca.build(e, i);
    }
    long long res = 0;
    function<void(long long&, const long long&)> update = [&](long long &x, const long long &y) -> void {
        if (!x || y < x) x = y;
    };
    for (int i = 1; i <= m; ++i) if (!used[i]) {
        update(res, edge[i].w+lca.get(edge[i].u, edge[i].v));
    }
    return res;
}

signed main()
{
    ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    int testcase = 1;
    cin >> testcase;
    for (int i = 1; i <= testcase; ++i) {
        cout << "Case #" << i << ": " << solve() << endl;
    }
    return 0;
}