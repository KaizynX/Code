/*
 * @Author: Kaizyn
 * @Date: 2021-05-15 22:23:53
 * @LastEditTime: 2021-05-15 22:37:40
 */
#include <bits/stdc++.h>

// #define DEBUG

using namespace std;

const double eps = 1e-7;
const double PI = acos(-1);
typedef pair<int, int> pii;
typedef long long ll;
const int MOD = 998244353; // 1e9+7;
const int INF = 0x3f3f3f3f;
// const ll INF = 1e18;
const int N = 1e3+7;

int n;
int dp[N][N];

inline int solve() {
  cin >> n;
  for (int i = 1; i <= n; ++i) {
    for (int j = 1; j <= n; ++j) {
      dp[i][j] = -INF;
    }
  }
  for (int i = 3; i <= n; ++i) dp[i][i] = 1;
  for (int i = 3; i <= n; ++i) {
    for (int j = 3; j <= n; ++j) {
      for (int k = j+j; i+k <= n; k += j) {
        dp[i+k][k] = max(dp[i+k][k], dp[i][j]+1);
      }
    }
  }
  int res = 0;
  for (int i = 0; i <= n; ++i) res = max(res, dp[n][i]);
  return res;
}

signed main() {
#ifdef ONLINE_JUDGE
  ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
#endif
  int T = 1;
  cin >> T; // scanf("%d", &T);
  for (int t = 1; t <= T; ++t) {
    auto res = solve();
    cout << "Case #" << t << ": " << res << '\n';
  }
  return 0;
}