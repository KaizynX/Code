/*
 * @Author: Kaizyn
 * @Date: 2020-04-12 12:25:55
 * @LastEditTime: 2020-04-12 13:38:44
 */
#include <bits/stdc++.h>

#define DEBUG

using namespace std;

const int N = 5e3+7;
const int MOD = 998244353;
const long long INF = 1e18;
const double eps = 1e-7;
const double PI = acos(-1);
typedef pair<int, int> pii;

int n, m;
int a[N], p[N], b[N];
int vis[N][N];
long long dp[N][N];

inline void solve()
{
    cin >> n;
    for (int i = 1; i <= n; ++i) cin >> a[i];
    for (int i = 1; i <= n; ++i) cin >> p[i];
    cin >> m;
    for (int i = 1; i <= m; ++i) cin >> b[i];

    fill(dp[0], dp[0]+N*N, INF);
    dp[0][0] = 0;
    vis[0][0] = 1;
    for (int i = 1; i <= n; ++i) {
        dp[i][0] = dp[i-1][0]+p[i];
        vis[i][0] = 1;
        for (int j = 1; j <= m; ++j) {
            if (vis[i-1][j]) {
                dp[i][j] = dp[i-1][j]+p[i]; // delte it
                if (a[i] <= b[j]) dp[i][j] = min(dp[i][j], dp[i-1][j]); // keep it
                vis[i][j] = 1;
            }
            if (a[i] == b[j] && vis[i-1][j-1]) { // add it
                dp[i][j] = min(dp[i][j], dp[i-1][j-1]);
                vis[i][j] = 1;
            }
        }
        #ifdef DEBUG
        for (int j = 0; j <= m; ++j) {
            if (vis[i][j]) cout << dp[i][j] << " ";
        }
        cout << endl;
        #endif
    }
    if (!vis[n][m]) return void(cout << "NO" << endl);
    cout << "YES\n" << dp[n][m] << endl; 
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