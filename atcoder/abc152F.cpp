#include <bits/stdc++.h>

#define DEBUG

using namespace std;

const int N = 50+7;
const int M = 20+7;
const int MOD = 1e9+7;
const double eps = 1e-11;
typedef pair<int, int> pii;

int n, m;
long long res;
int f[N], d[N];
long long pt[N];
list<int> e[N];
pii a[N];

void build_tree(const int &u = 1, const int &fa = 0)
{
    f[u] = fa;
    d[u] = d[fa]+1;
    for (int v : e[u]) if (v != fa)
        build_tree(v, u);
}

// edge u is the edge bewteen u and f[u]
inline void get_path(const int &i)
{
    int u = a[i].first, v = a[i].second;
    if (d[u] < d[v]) swap(u, v);
    while (d[u] > d[v]) pt[i] |= 1ll<<u, u = f[u];
    while (u != v) {
        pt[i] |= 1ll<<u; u = f[u];
        pt[i] |= 1ll<<v; v = f[v];
    }
}

void dfs(const int &id, const int &num, const long long &val)
{
    if (id > m) {
        if (num) res += (num&1 ? 1 : -1)*1ll<<(n-1-__builtin_popcountll(val));
        return;
    }
    dfs(id+1, num, val);
    dfs(id+1, num+1, val|pt[id]);
}

inline void solve()
{
    cin >> n;
    for (int i = 1, u, v; i < n; ++i) {
        cin >> u >> v;
        e[u].push_back(v);
        e[v].push_back(u);
    }
    cin >> m;
    for (int i = 1, u, v; i <= m; ++i) {
        cin >> u >> v;
        a[i] = {u, v};
    }

    build_tree(1, 0);
    for (int i = 1; i <= m; ++i)
        get_path(i);
    dfs(1, 0, 0);
    #ifdef DEBUG
    for (int i = 1; i <= m; ++i)
        cout << bitset<64>(pt[i]) << endl;
    cout << res << endl;
    #endif
    res = (1ll<<(n-1))-res;
    cout << res << endl;
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