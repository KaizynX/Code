/*
 * @Author: Kaizyn
 * @Date: 2020-08-30 13:29:45
 * @LastEditTime: 2020-08-30 14:25:38
 */
#include <bits/stdc++.h>

// #define DEBUG

using namespace std;

const double eps = 1e-7;
const double PI = acos(-1);
typedef pair<int, int> pii;
const int MOD = 998244353;
const int INF = 0x3f3f3f3f;
const int N = 53;
const int M = 1e2+3;

int n;
int a[N];
int dp[N][N][M];

inline void solve() {
  cin >> n;
  for (int i = 1; i <= n; ++i) cin >> a[i];

  for (int i = 1; i <= n; ++i) {
    dp[i][i][a[i]] = 1;
  }
  for (int len = 2; len <= n; ++len) {
    for (int l = 1, r = len; r <= n; r = ++l+len-1) {
      for (int i = 1; i <= 100; ++i) {
        for (int k = l; k < r; ++k) {
          if ((dp[l][k][i] && dp[k+1][r][i]) ||
              (dp[l][k][i-1] && dp[k+1][r][i]) ||
              (dp[l][k][i] && dp[k+1][r][i-1])) {
            dp[l][r][i] = 1;
            break;
          }
        }
      }
    }
  }
  int res = 0;
  for (int i = 1; i <= 100; ++i) res |= dp[1][n][i];
  cout << (res ? "YES" : "NO") << endl;
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