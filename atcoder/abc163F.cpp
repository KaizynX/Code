/*
 * @Author: Kaizyn
 * @Date: 2020-04-19 19:55:17
 * @LastEditTime: 2020-04-28 16:21:15
 */
#include <bits/stdc++.h>

#define DEBUG

using namespace std;

const int N = 2e5+7;
const int MOD = 998244353;
const int INF = 0x3f3f3f3f;
const double eps = 1e-7;
const double PI = acos(-1);
typedef pair<int, int> pii;

int n;
int c[N], num[N], col[N];
long long res[N];
vector<int> e[N];

inline long long calc(const int &x) {
    return x*(x+1ll)/2;
}

void dfs(const int &u, const int &fa) {
    num[u] = 1;
    int tmp = col[c[u]];
    for (int &v : e[u]) if (v != fa) {
        col[c[u]] = 0;
        dfs(v, u);
        num[u] += num[v];
        res[c[u]] -= calc(num[v]-col[c[u]]);
    }
    col[c[u]] = tmp+num[u];
    #ifdef DEBUG
    cout << u << ": ";
    for (int i = 1; i <= n; ++i) cout << res[i] << " \n"[i==n];
    cout << "   ";
    for (int i = 1; i <= n; ++i) cout << col[i] << " \n"[i==n];
    #endif
}

inline void solve()
{
    cin >> n;
    for (int i = 1; i <= n; ++i) cin >> c[i];
    for (int i = 1, u, v; i < n; ++i) {
        cin >> u >> v;
        e[u].emplace_back(v);
        e[v].emplace_back(u);
    }
    for (int i = 1; i <= n; ++i) {
        res[i] = calc(n);
    }
    dfs(1, 0);
    for (int i = 1; i <= n; ++i) {
        res[i] -= calc(n-col[i]);
    }
    for (int i = 1; i <= n; ++i) {
        cout << res[i] << endl;
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