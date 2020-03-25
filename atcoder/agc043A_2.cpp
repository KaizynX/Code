/*
 * @Author: Kaizyn
 * @Date: 2020-03-21 20:28:53
 * @LastEditTime: 2020-03-21 20:32:34
 */
#include <bits/stdc++.h>

// #define DEBUG

using namespace std;

const int N = 1e2+7;
const int MOD = 1e9+7;
const double eps = 1e-7;
const int INF = 0x3f3f3f3f;
typedef pair<int, int> pii;

int n, m;
int a[N][N], dp[N][N];

inline void solve()
{
    string str;
    cin >> n >> m;
    for (int i = 1; i <= n; ++i) {
        cin >> str;
        for (int j = 1; j <= m; ++j) {
            a[i][j] = str[j-1] == '#';
        }
    }
    for (int i = 1; i <= n; ++i) a[i][0] = a[i][1]; 
    for (int i = 1; i <= m; ++i) a[0][i] = a[1][i];
    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= m; ++j) {
            dp[i][j] = min(dp[i-1][j]+(a[i][j]^a[i-1][j]), dp[i][j-1]+(a[i][j]^a[i][j-1]));
        }
    }
    cout << dp[n][m]/2+(a[1][1]|a[n][m]) << endl;
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