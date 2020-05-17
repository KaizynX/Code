/*
 * @Author: Kaizyn
 * @Date: 2020-05-15 09:39:58
 * @LastEditTime: 2020-05-15 10:11:06
 */
#include <bits/stdc++.h>

// #define DEBUG

using namespace std;

const double eps = 1e-7;
const double PI = acos(-1);
typedef pair<int, int> pii;
const int MOD = 998244353;
const long long INF = 1e18;
const int N = 1e2+7;

int n, m;
long long a[N][N], dp[N][N];

inline void solve() {
  cin >> n >> m;
  long long mina = INF;
  for (int i = 1; i <= n; ++i) {
    for (int j = 1; j <= m; ++j) {
      cin >> a[i][j];
      a[i][j] -= i+j;
      mina = min(mina, a[i][j]);
    }
  }
  for (int i = 1; i <= n; ++i) {
    for (int j = 1; j <= m; ++j) {
      a[i][j] -= mina;
    }
  }
  #ifdef DEBUG
  for (int i = 1; i <= n; ++i) {
    for (int j = 1; j <= m; ++j) {
      cout << a[i][j] << " \n"[j==m];
    }
  }
  #endif
  long long res = INF;
  for (int ii = 1; ii <= n; ++ii) {
    for (int jj = 1; jj <= m; ++jj) {
      for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= m; ++j) {
          if (a[i][j] < a[ii][jj]) {
            dp[i][j] = INF;
          } else {
            dp[i][j] = min(dp[i-1][j], dp[i][j-1])+a[i][j];
          }
        }
      }
      #ifdef DEBUG
      // cout << ii << " " << jj << " " << dp[n][m] << endl;
      #endif
      res = min(res, dp[n][m]-a[ii][jj]*(n+m-1));
    }
  }
  cout << res << endl;
}

signed main() {
  ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
  for (int i = 0; i < N; ++i) dp[i][0] = dp[0][i] = INF;
  dp[1][0] = dp[0][1] = 0;
  int T = 1;
  cin >> T;
  for (int t = 1; t <= T; ++t) {
    solve();
  }
  return 0;
}