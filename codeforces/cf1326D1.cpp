/*
 * @Author: Kaizyn
 * @Date: 2020-03-19 23:37:31
 * @LastEditTime: 2020-03-20 00:23:36
 */
#include <bits/stdc++.h>

// #define DEBUG

using namespace std;

const int N = 5e3+7;
const int MOD = 1e9+7;
const double eps = 1e-7;
const int INF = 0x3f3f3f3f;
typedef pair<int, int> pii;

string s;
int n;
int dp[N][N];

inline void solve()
{
    cin >> s;
    n = s.size();
    // for (int i = 1; i <= n; ++i) dp[i][i] = 1;
    for (int len = 1; len <= n; ++len) {
        for (int l = 1, r; (r = l+len-1) <= n; ++l) {
            if (s[l-1] == s[r-1]) dp[l][r] = dp[l+1][r-1];
            else dp[l][r] = 0;
        }
    }
    int resi, resj, res = 0;
    // prefix or suffix
    for (int i = 1; i <= n; ++i) {
        if (dp[1][i] && i > res) {
            res = i;
            resi = i;
            resj = n+1;
        }
        if (dp[i][n] && n-i+1 > res) {
            res = n-i+1;
            resi = 0;
            resj = i;
        }
    }
    #ifdef DEBUG
    cout << resi << " " << resj << " " << res << endl;
    #endif
    // prefix + suffix
    for (int i = 1; i <= n; ++i) {
        if (s[i-1] != s[n-i]) break;
        for (int j = i+1; j < n-i+1; ++j) {
            if (dp[i+1][j] && j+i > res) {
                res = j+i;
                resi = j;
                resj = n-i+1;
            }
        }
        for (int j = n-i; j > i; --j) {
            if (dp[j][n-i] && n-j+1+i > res) {
                res = n-j+1+i;
                resi = i;
                resj = j;
            }
        }
    }
    string str;
    for (int i = 1; i <= resi; ++i) str += s[i-1];
    for (int i = resj; i <= n; ++i) str += s[i-1];
    cout << str << endl;
}

signed main()
{
    ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    for (int i = 0; i < N; ++i) {
        for (int j = 0; j <= i; ++j) {
            dp[i][j] = 1;
        }
    }
    int testcase = 1;
    cin >> testcase;
    for (int i = 1; i <= testcase; ++i) {
        solve();
    }
    return 0;
}