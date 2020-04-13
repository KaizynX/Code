/*
 * @Author: Kaizyn
 * @Date: 2020-04-12 19:55:49
 * @LastEditTime: 2020-04-12 20:51:44
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

int n, m;
int a[N];
map<int, long long> dp[2][N];

inline void solve()
{
    cin >> n;
    for (int i = 1; i <= n; ++i) {
        cin >> a[i];
    }
    dp[0][0][0] = 0;
    for (int i = 0; i < n; ++i) {
        for (int j = i/2-1; j <= i/2+1; ++j) {
            if (dp[0][i].count(j)) {
                if (dp[0][i+1].count(j)) dp[0][i+1][j] = max(dp[0][i+1][j], dp[0][i][j]);
                else dp[0][i+1][j] = dp[0][i][j];
                if (dp[1][i+1].count(j+1)) dp[1][i+1][j+1] = max(dp[1][i+1][j+1], dp[0][i][j]+a[i+1]);
                else dp[1][i+1][j+1] = dp[0][i][j]+a[i+1];
            }
            if (dp[1][i].count(j)) {
                if (dp[0][i+1].count(j)) dp[0][i+1][j] = max(dp[0][i+1][j], dp[1][i][j]);
                else dp[0][i+1][j] = dp[1][i][j];
            }
        }
    }
    /*
    for (int i = 1; i <= n; ++i) {
        for (int j = 0; j <= n/2; ++j) {
            cout << "[" << dp[0][i][j] << " " << dp[1][i][j]  << "]" << " \n"[j==n/2];
        }
    }
    */
    cout << max(dp[0][n][n/2], dp[1][n][n/2]) << endl;
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