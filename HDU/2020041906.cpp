/*
 * @Author: Kaizyn
 * @Date: 2020-04-19 14:34:52
 * @LastEditTime: 2020-04-19 14:41:25
 */
#include <bits/stdc++.h>

// #define DEBUG

using namespace std;

const int N = 1e5+7;
const int MOD = 998244353;
const int INF = 0x3f3f3f3f;
const double eps = 1e-7;
const double PI = acos(-1);
typedef pair<int, int> pii;

int n;
int p[N], c[N];
vector<int> e[N];

long long dfs(const int &u, const int &fa) {
    long long d = p[u]-c[u];
    for (int &v : e[u]) if (v != fa) {
        d += dfs(v, u);
    }
    return max(d, 0ll);
}

inline void solve()
{
    cin >> n;
    for (int i = 1; i <= n; ++i) vector<int>().swap(e[i]);
    for (int i = 1, u, v; i < n; ++i) {
        cin >> u >> v;
        e[u].emplace_back(v);
        e[v].emplace_back(u);
    }
    for (int i = 1; i <= n; ++i) {
        cin >> p[i] >> c[i];
    }
    cout << (dfs(1, 0) ? "NO" : "YES") << endl;
}

signed main()
{
    ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    int testcase = 1;
    cin >> testcase;
    for (int i = 1; i <= testcase; ++i) {
        solve();
    }
    return 0;
}