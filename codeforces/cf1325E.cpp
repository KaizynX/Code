/*
 * @Author: Kaizyn
 * @Date: 2020-03-15 00:16:43
 * @LastEditors: Kaizyn
 * @LastEditTime: 2020-03-15 00:28:12
 * @FilePath: \Code\codeforces\cf1325E.cpp
 */
#include <bits/stdc++.h>

// #define DEBUG

using namespace std;

const int N = 1e5+7;
const int M = 7;
const int MOD = 1e9+7;
const double eps = 1e-7;
const int INF = 0x3f3f3f3f;
typedef pair<int, int> pii;

int n;
int a[N], v[N];
vector<pii> b[N];
vector<int> d;
int dp[2][1<<M];

inline void get_fac(const int &i)
{
    int x = a[i];
    for (int j = 2, k; j*j <= a[i]; ++j) {
        if (x%j) continue;
        k = 0;
        while (x%j == 0) x /= j, ++k;
        b[i].emplace_back(j, k&1);
        d.emplace_back(j);
    }
    if (x > 1) d.emplace_back(x), b[i].emplace_back(x, 1);
}

inline void solve()
{
    cin >> n;
    memset(dp, 0x3f, sizeof dp);
    for (int i = 1; i <= n; ++i) cin >> a[i];

    for (int i = 1; i <= n; ++i) {
        get_fac(i);
    }
    sort(d.begin(), d.end());
    d.erase(unique(d.begin(), d.end()), d.end());
    assert(d.size() <= M);
    for (int i = 1; i <= n; ++i) {
        for (pii p : b[i]) {
            int t = lower_bound(d.begin(), d.end(), p.first)-d.begin();
            if (p.second) v[i] |= 1<<t;
        }
    }
    for (int i = 1; i <= n; ++i) {
        memcpy(dp[i&1], dp[~i&1], sizeof dp[0]);
        dp[i&1][v[i]] = 1;
        for (int j = 0; j < 1<<M; ++j) {
            dp[i&1][j] = min(dp[i&1][j], dp[~i&1][j^v[i]]+1);
        }
    }
    if (dp[n&1][0] >= INF) cout << -1 << endl;
    else cout << dp[n&1][0] << endl;
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