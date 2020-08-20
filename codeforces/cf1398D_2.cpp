/*
 * @Author: Kaizyn
 * @Date: 2020-08-14 22:33:19
 * @LastEditTime: 2020-08-14 23:14:52
 */
#include <bits/stdc++.h>

// #define DEBUG

using namespace std;

const double eps = 1e-7;
const double PI = acos(-1);
typedef pair<int, int> pii;
const int MOD = 998244353;
const int INF = 0x3f3f3f3f;
const int N = 2e2+7;

int n[3];
int a[3][N];
int dp[N][N][N];

inline void solve() {
  for (int i = 0; i < 3; ++i) cin >> n[i];
  for (int i = 0; i < 3; ++i) {
    for (int j = 1; j <= n[i]; ++j) {
      cin >> a[i][j];
    }
    sort(a[i]+1, a[i]+n[i]+1);
    reverse(a[i]+1, a[i]+n[i]+1);
  }
  int res = 0;
  memset(dp, -1, sizeof dp);
  dp[0][0][0] = 0;
  for (int i = 0; i <= n[0]; ++i) {
    for (int j = 0; j <= n[1]; ++j) {
      for (int k = 0; k <= n[2]; ++k) {
        if ((i+j+k)&1) continue;
        if (i && j && ~dp[i-1][j-1][k]) dp[i][j][k] = max(dp[i][j][k], dp[i-1][j-1][k]+a[0][i]*a[1][j]);
        if (i && k && ~dp[i-1][j][k-1]) dp[i][j][k] = max(dp[i][j][k], dp[i-1][j][k-1]+a[0][i]*a[2][k]);
        if (j && k && ~dp[i][j-1][k-1]) dp[i][j][k] = max(dp[i][j][k], dp[i][j-1][k-1]+a[1][j]*a[2][k]);
        res = max(res, dp[i][j][k]);
      }
    }
  }
  cout << res << endl;
}

signed main() {
  ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
  int T = 1;
  // cin >> T;
  for (int t = 1; t <= T; ++t) {
    solve();
  }
  return 0;
}