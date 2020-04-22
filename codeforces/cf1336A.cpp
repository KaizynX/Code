/*
 * @Author: Kaizyn
 * @Date: 2020-04-15 22:27:07
 * @LastEditTime: 2020-04-15 22:47:55
 */
#include <bits/stdc++.h>

// #define DEBUG

using namespace std;

const int N = 2e5+7;
const int MOD = 998244353;
const int INF = 0x3f3f3f3f;
const double eps = 1e-7;
const double PI = acos(-1);
typedef pair<int, int> pii;

struct Node {
    int d, t;
    friend bool operator < (const Node &lhs, const Node &rhs) {
        return lhs.d-lhs.t > rhs.d-rhs.t;
    }
} a[N];

int n, k;
vector<int> e[N];

int dfs(const int &u, const int &fa) {
    a[u].d = a[fa].d+1;
    for (int &v : e[u]) if (v != fa) {
        a[u].t += dfs(v, u);
    }
    return a[u].t+1;
}

inline void solve()
{
    cin >> n >> k;
    for (int i = 1, u, v; i < n; ++i) {
        cin >> u >> v;
        e[u].emplace_back(v);
        e[v].emplace_back(u);
    }
    a[0].d = -1;
    dfs(1, 0);
    sort(a+1, a+n+1);
    long long res = 0;
    for (int i = 1; i <= k; ++i) {
        res += a[i].d-a[i].t;
    }
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