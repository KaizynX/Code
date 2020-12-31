/*
 * @Author: Kaizyn
 * @Date: 2020-12-23 22:52:34
 * @LastEditTime: 2020-12-23 23:16:14
 */
#include <bits/stdc++.h>

// #define DEBUG

using namespace std;

const double eps = 1e-7;
const double PI = acos(-1);
typedef pair<int, int> pii;
typedef long long ll;
const int MOD = 998244353;
const int INF = 0x3f3f3f3f;
// const ll INF = 1e18;
const int N = 5e3+7;

// #define int ll

int n;
int t[N], x[N], mit[N];
int dp[N][N];

inline bool solve() {
  cin >> n;
  for (int i = 1; i <= n; ++i) cin >> t[i] >> x[i];
  memset(mit+1, 0x3f, sizeof(int)*n);
  dp[0][0] = 1;
  for (int i = 0; i < n; ++i) {
    if (mit[i] <= t[i]) {
      mit[i+1] = min(mit[i+1], max(mit[i]+abs(x[i+1]-x[i]), t[i]));
      for (int j = i+2; j <= n; ++j) {
        dp[i][j] |= 2*abs(x[j]-x[i])+mit[i] <= t[i];
        dp[i+1][j] |= max(t[i], abs(x[j]-x[i])+mit[i])+abs(x[j]-x[i+1]) <= t[i+1];
      }
    }
    if (abs(x[i+1]-x[i]) <= t[i+1]-t[i]) {
      for (int j = i+2; j <= n; ++j) dp[i+1][j] |= dp[i][j];
    }
    if (dp[i][i+1] && i+2 <= n) {
      mit[i+2] = min(mit[i+2], max(t[i]+abs(x[i+2]-x[i]), t[i+1]));
      for (int j = i+3; j <= n; ++j) {
        dp[i+2][j] |= max(t[i]+abs(x[j]-x[i]), t[i+1])+abs(x[j]-x[i+2]) <= t[i+2];
      }
    }
  }
  return mit[n] <= t[n] || dp[n-1][n];
}

signed main() {
#ifndef DEBUG
  ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
#endif
  int T = 1;
  // cin >> T;
  for (int t = 1; t <= T; ++t) {
    cout << (solve() ? "YES" : "NO") << endl;
  }
  return 0;
}