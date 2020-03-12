/*
 * @Author: Kaizyn
 * @Date: 2020-03-12 21:32:15
 * @LastEditors: Kaizyn
 * @LastEditTime: 2020-03-12 21:43:36
 * @FilePath: \Code\codeforces\cf1324E.cpp
 */
#include <bits/stdc++.h>

// #define DEBUG

using namespace std;

const int N = 2e3+7;
const int MOD = 1e9+7;
const double eps = 1e-7;
const int INF = 0x3f3f3f3f;
typedef pair<int, int> pii;

int n, h, l, r;
int a[N], dp[N][N];

inline void solve()
{
    cin >> n >> h >> l >> r;
    for (int i = 1; i <= n; ++i) {
        cin >> a[i];
    }
    memset(dp, 0x8f, sizeof dp);
    dp[0][0] = 0;
    for (int i = 1; i <= n; ++i) {
        for (int j = 0; j < h; ++j) {
            dp[i][j] = max(dp[i-1][(j-a[i]+h)%h], dp[i-1][(j-a[i]+1+h)%h])+(j >= l && j <= r);
        }
    }
    int res = 0;
    for (int i = 0; i < h; ++i) res = max(res, dp[n][i]);
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