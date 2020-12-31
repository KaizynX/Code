/*
 * @Author: Kaizyn
 * @Date: 2020-12-14 19:33:08
 * @LastEditTime: 2020-12-14 19:37:14
 */
#include <bits/stdc++.h>

// #define DEBUG

using namespace std;

const double eps = 1e-7;
const double PI = acos(-1);
typedef pair<int, int> pii;
const int MOD = 998244353;
const int INF = 0x3f3f3f3f;
const int N = 3e3+7;

int n;
int a[N], dp[N][N];

inline void solve() {
  cin >> n;
  for (int i = 1; i <= n; ++i) cin >> a[i];
  memset(dp, 0x3f, sizeof dp);
  memset(dp[1], 0, sizeof(dp[1]));
  for (int i = 2; i <= n; ++i) {
    for (int j = i-1, cnt = 0; j; --j) {
      if (j+a[j] >= i) {
        dp[i][j+a[j]] = min(dp[i][j+a[j]], dp[j][i-1]+cnt);
        ++cnt;
      }
    }
    for (int j = i; j <= n; ++j) {
      dp[i][j] = min(dp[i][j], dp[i][j-1]);
    }
  }
  cout << dp[n][n] << endl;
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