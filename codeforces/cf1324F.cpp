/*
 * @Author: Kaizyn
 * @Date: 2020-03-12 21:20:34
 * @LastEditors: Kaizyn
 * @LastEditTime: 2020-03-12 21:31:22
 * @FilePath: \Code\codeforces\cf1324F.cpp
 */
#include <bits/stdc++.h>

// #define DEBUG

using namespace std;

const int N = 2e5+7;
const int MOD = 1e9+7;
const double eps = 1e-7;
const int INF = 0x3f3f3f3f;
typedef pair<int, int> pii;

int n;
int a[N], res[N];
vector<int> e[N], dp[N];

int dfs1(const int &u, const int &fa)
{
    dp[u].resize(e[u].size(), 0);
    res[u] = a[u];
    for (int i = 0, v; i < (int)e[u].size(); ++i) {
        v = e[u][i];
        if (v == fa) continue;
        dp[u][i] = max(dp[u][i], dfs1(v, u));
        res[u] += dp[u][i];
    }
    return res[u];
}

void dfs2(const int &u, const int &fa, const int &val)
{
    res[u] += max(0, val);
    for (int i = 0, v; i < (int)e[u].size(); ++i) {
        v = e[u][i];
        if (v == fa) continue;
        dfs2(v, u, res[u]-dp[u][i]);
    }
}

inline void solve()
{
    cin >> n;
    for (int i = 1; i <= n; ++i) {
        cin >> a[i];
        if (!a[i]) a[i] = -1;
    }
    for (int i = 1, u, v; i < n; ++i) {
        cin >> u >> v;
        e[u].emplace_back(v);
        e[v].emplace_back(u);
    }
    dfs1(1, 0);
    dfs2(1, 0, 0);
    for (int i = 1; i <= n; ++i) {
        cout << res[i] << " \n"[i==n];
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