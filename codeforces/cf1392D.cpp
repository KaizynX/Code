/*
 * @Author: Kaizyn
 * @Date: 2020-08-16 22:50:12
 * @LastEditTime: 2020-08-16 23:22:19
 */
#include <bits/stdc++.h>

#define DEBUG

using namespace std;

const double eps = 1e-7;
const double PI = acos(-1);
typedef pair<int, int> pii;
const int MOD = 998244353;
const int INF = 0x3f3f3f3f;
const int N = 2e5+7;

int n;
string s;
int a[N<<1];
int dp[N<<1][2][2]; // dp[i][j][k] a[i]==j, a[i-1]==k

inline void solve() {
  cin >> n >> s;
  for (int i = 0; i < n; ++i) {
    a[i+n] = a[i] = s[i] == 'L';
  }
  for (int i = 0; i < 2; ++i) {
    for (int j = 0; j < 2; ++j) {
      dp[1][i][j] = (a[1] != i)+(a[0] != j);
    }
  }
  // int res = n;
  // int res = 0;
  for (int i = 2; i < 2*n; ++i) {
    // int tmp = n;
#ifdef DEBUG
    cout << i << ":";
#endif
    for (int j = 0; j < 2; ++j)
    for (int k = 0; k < 2; ++k) {
      if (j == k) dp[i][j][k] = (a[i] != j)+dp[i-1][k][k^1];
      else dp[i][j][k] = (a[i] != j)+min(dp[i-1][k][0], dp[i-1][k][1]);
      // if (i > n) tmp = min(tmp, dp[i][j][k]-dp[i-n][j][k]);
      // if (i > n) res = min(res, dp[i][j][k]-dp[i-n][j][k]);
#ifdef DEBUG
      cout << dp[i][j][k] << " ";
#endif
    }
#ifdef DEBUG
    cout << endl;
#endif
    // if (i > n) res = max(tmp, res);
  }
  int res = n;
  for (int i = 0; i < 2; ++i) {
    for (int j = 0; j < 2; ++j) {
      res = min(res, dp[2*n-1][i][j]-dp[n-1][i][j]);
    }
  }
  cout << res << endl;
}

signed main() {
  ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
  int T = 1;
  cin >> T;
  for (int t = 1; t <= T; ++t) {
    solve();
  }
  return 0;
}