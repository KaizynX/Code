/*
 * @Author: Kaizyn
 * @Date: 2020-04-05 13:58:34
 * @LastEditTime: 2020-04-05 14:14:07
 */
#include <bits/stdc++.h>

// #define DEBUG

using namespace std;

const int N = 5e4+7;
const int MOD = 998244353;
const int INF = 0x3f3f3f3f;
const double eps = 1e-7;
const double PI = acos(-1);
typedef pair<int, int> pii;

int n, res;
int a[N];
vector<int> e[N], d[N];
multiset<int> st[N];

int dfs1(const int &u, const int &fa)
{
    for (int i = 0, v; i < (int)e[u].size(); ++i) {
        if ((v = e[u][i]) == fa) continue;
        d[u][i] = dfs1(v, u);
        st[u].insert(d[u][i]);
    }
    return st[u].size() ? 1+*st[u].rbegin(): 1;
}

void dfs2(const int &u, const int &fa, const int &dep)
{
    st[u].insert(dep);
    res = max(res, *st[u].rbegin()*a[u]);
    for (int i = 0, v; i < (int)e[u].size(); ++i) {
        if ((v = e[u][i]) == fa) continue;
        st[u].erase(st[u].find(d[u][i]));
        dfs2(v, u, 1+*st[u].rbegin());
        st[u].insert(d[u][i]);
    }
}

inline void solve()
{
    cin >> n;
    for (int i = 1; i <= n; ++i) cin >> a[i];
    for (int i = 1, u, v; i < n; ++i) {
        cin >> u >> v;
        e[u].emplace_back(v);
        e[v].emplace_back(u);
    }
    for (int i = 1; i <= n; ++i) d[i].resize(e[i].size());
    dfs1(1, 0);
    dfs2(1, 0, 0);
    cout << res << endl;
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