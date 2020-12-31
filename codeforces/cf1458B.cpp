/*
 * @Author: Kaizyn
 * @Date: 2020-12-24 10:59:01
 * @LastEditTime: 2020-12-24 11:10:34
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
const int N = 1e2+7;
const int M = 1e4+7;

int n;
int dp[N][M];
// dp[j][k] choose j and with sum{a} = k

inline void solve() {
  cin >> n;
  int s = 0;
  memset(dp, 0x9f, sizeof dp);
  dp[0][0] = 0;
  for (int i = 1, a, b; i <= n; ++i) {
    cin >> a >> b;
    s += a;
    for (int j = i; j >= 0; --j) {
      for (int k = s; k >= 0; --k) {
        // dp[j][k] = max(dp[j][k], dp[j][k]+b);
        dp[j][k] += b;
        if (j && k >= a) dp[j][k] = max(dp[j][k], dp[j-1][k-a]+b*2);
      }
    }
  }
  for (int i = 1, res; i <= n; ++i) {
    res = 0;
    for (int j = 0; j <= s; ++j) {
      res = max(res, min(j*2, dp[i][j]));
    }
    cout << res/2.0 << " \n"[i==n];
  }
}

signed main() {
#ifdef ONLINE_JUDGE
  ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
#endif
  int T = 1;
  // cin >> T;
  for (int t = 1; t <= T; ++t) {
    solve();
  }
  return 0;
}