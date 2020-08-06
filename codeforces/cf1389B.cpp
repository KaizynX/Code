/*
 * @Author: Kaizyn
 * @Date: 2020-07-29 22:31:19
 * @LastEditTime: 2020-07-29 22:45:00
 */ 
#include <bits/stdc++.h>

// #define DEBUG

using namespace std;

const double eps = 1e-7;
const double PI = acos(-1);
typedef pair<int, int> pii;
const int MOD = 998244353;
const int INF = 0x3f3f3f3f;
const int N = 2e5+7;

int n, k, z;
int a[N];
int dp[N][6];

inline void solve() {
  cin >> n >> k >> z;
  for (int i = 1; i <= n; ++i) {
    cin >> a[i];
    memset(dp[i], -1, sizeof dp[i]);
  }
  dp[0][0] = a[1];
  for (int i = 1; i <= k; ++i) {
    dp[i][0] = dp[i-1][0]+a[1+i];
    for (int j = 1; j <= z; ++j) {
      int p = 1+i-j-j;
      if (p < 1) break;
      if (dp[i-1][j] != -1)
        dp[i][j] = max(dp[i][j], dp[i-1][j]+a[p]);
      if (dp[i-1][j-1] != -1)
        dp[i][j] = max(dp[i][j], dp[i-1][j-1]+a[p]);
    }
  }
  int res = 0;
  for (int i = 0; i <= z; ++i) {
    res = max(res, dp[k][i]);
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