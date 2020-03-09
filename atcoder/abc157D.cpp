#include <bits/stdc++.h>

#define DEBUG

using namespace std;

const int N = 1e5+7;
const int INF = 0x3f3f3f3f;
const int MOD = 1e9+7;
const double eps = 1e-11;
typedef pair<int, int> pii;

struct DSU
{
    int fa[N], num[N];
    void init(int sz) { for (int i = 0; i <= sz; ++i) fa[i] = i, num[i] = 1; }
    int get(int s) { return s == fa[s] ? s : fa[s] = get(fa[s]); }
    int& operator [] (int i) { return fa[get(i)]; }
    bool merge(int x, int y) {
        int fx = get(x), fy = get(y);
        if (fx == fy) return false;
        if (num[fx] >= num[fy]) num[fx] += num[fy], fa[fy] = fx;
        else num[fy] += num[fx], fa[fx] = fy;
        return true;
    }
} dsu;

int n, m, k;
vector<int> fp[N], bp[N];
map<int, int> vis;

inline void solve()
{
    cin >> n >> m >> k;
    dsu.init(n);
    for (int i = 1, u, v; i <= m; ++i) {
        cin >> u >> v;
        dsu.merge(u, v);
        fp[u].emplace_back(v);
        fp[v].emplace_back(u);
    }
    for (int i = 1, u, v; i <= k; ++i) {
        cin >> u >> v;
        bp[u].emplace_back(v);
        bp[v].emplace_back(u);
    }
    for (int i = 1; i <= n; ++i) {
        int res = dsu.num[dsu[i]]-1;
        vis.clear();
        for (int j : fp[i]) {
            if (vis.count(j)) continue;
            vis.insert({j, 1});
            if (dsu[i] == dsu[j]) --res;
        }
        for (int j : bp[i]) {
            if (vis.count(j)) continue;
            vis.insert({j, 1});
            if (dsu[i] == dsu[j]) --res;
        }
        cout << res << " \n"[i==n];
    }
}

int main()
{
    ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    int T = 1;
    while (T--) {
        solve();
    }
    return 0;
}