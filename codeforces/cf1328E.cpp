/*
 * @Author: Kaizyn
 * @Date: 2020-03-27 00:11:00
 * @LastEditTime: 2020-03-27 00:24:36
 */
#include <bits/stdc++.h>

// #define DEBUG

using namespace std;

const int N = 2e5+7;
const int MOD = 1e9+7;
const double eps = 1e-7;
const int INF = 0x3f3f3f3f;
typedef pair<int, int> pii;

struct LCA
{
    static const int NN = (int)log2(N)+3;
    int f[N][NN], d[N], lg2[N];
    LCA() { for (int i = 2; i < N; ++i) lg2[i] = lg2[i>>1]+1; }
    template <typename TT>
    void build(const TT e[], const int &u = 1, const int &fa = 0) {
        d[u] = d[fa]+1;
        f[u][0] = fa;
        for (int i = 1; (1<<i) <= d[u]; ++i)
            f[u][i] = f[f[u][i-1]][i-1];
        for (auto v : e[u]) if (v != fa)
            build(e, v, u);
    }
    int get(int x, int y) {
        if (d[x] < d[y]) swap(x, y);
        while (d[x] > d[y])
            x = f[x][lg2[d[x]-d[y]]];
        if (x == y) return x;
        for (int i = lg2[d[x]]; i >= 0; --i)
            if(f[x][i] != f[y][i])
                x = f[x][i], y = f[y][i];
        return f[x][0];
    }
    int getd(int x, int dep) {
        for (int i = lg2[d[x]]; i >= 0; --i)
            if (d[f[x][i]] >= dep) x = f[x][i];
        return x;
    }
};

int n, m;
int v[N];
vector<int> e[N];
LCA lca;

inline void solve()
{
    cin >> n >> m;
    for (int i = 1, u, v; i < n; ++i) {
        cin >> u >> v;
        e[u].emplace_back(v);
        e[v].emplace_back(u);
    }
    lca.build(e);
    for (int i = 1, k; i <= m; ++i) {
        cin >> k;
        for (int j = 1; j <= k; ++j) cin >> v[j];
        sort(v+1, v+k+1, [&](const int &i, const int &j){ return lca.d[i] < lca.d[j]; });
        int rt = 1, dep = 1, flag = 1;
        for (int j = 1; j <= k; ++j) {
            if (v[j] == 1) continue;
            else if (lca.d[v[j]] == dep+1) {
                if (lca.f[v[j]][0] != rt) { flag = 0; break; }
            } else {
                dep = lca.d[v[j]]-1;
                int fa = lca.f[v[j]][0];
                if (lca.get(fa, rt) != rt) { flag = 0; break; }
                rt = fa;
            }
        }
        cout << (flag ? "YES" : "NO") << endl;
    }
}

signed main()
{
    ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    int testcase = 1;
    // cin >> testcase;
    for (int i = 1; i <= testcase; ++i) {
        solve();
    }
    return 0;
}