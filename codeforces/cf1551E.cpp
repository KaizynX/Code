/*
 * @Author: Kaizyn
 * @Date: 2021-07-23 22:41:24
 * @LastEditTime: 2021-07-23 22:52:34
 */
#include <bits/stdc++.h>

// #define DEBUG

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
const double eps = 1e-7;
const double PI = acos(-1);
const int MOD = 998244353; // 1e9+7;
const int INF = 0x3f3f3f3f;
// const ll INF = 1e18;
const int N = 2e3+7;

int n, k;
int a[N];
// dp[i][j] on i'th del j s number
int dp[N][N];

void update(int &x, int y) {
  if (x == -1 || y < x) x = y;
}

inline void solve() {
  cin >> n >> k;
  for (int i = 1; i <= n; ++i) cin >> a[i];
  int res = -1;
  for (int i = 0; i <= n; ++i) {
    for (int j = 0; j <= n; ++j) {
      dp[i][j] = -1;
    }
  }
  dp[0][0] = 0;
  for (int i = 1; i <= n; ++i) {
    for (int j = 0; j <= n; ++j) {
      if (~dp[i-1][j]) dp[i][j] = dp[i-1][j]+(a[i]==i-j);
      if (j && ~dp[i-1][j-1]) dp[i][j] = max(dp[i][j], dp[i-1][j-1]);
      if (dp[i][j] >= k) update(res, j);
      #ifdef DEBUG
      // printf("dp[%d][%d]=%d\n", i, j, dp[i][j]);
      cout << dp[i][j] << " \n"[j==n];
      #endif
    }
  }
  cout << res << '\n';
}

signed main() {
#ifdef ONLINE_JUDGE
  ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
#endif
  int T = 1;
  cin >> T; // scanf("%d", &T);
  for (int t = 1; t <= T; ++t) {
    solve();
  }
  return 0;
}