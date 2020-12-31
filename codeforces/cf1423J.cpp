/*
 * @Author: Kaizyn
 * @Date: 2020-12-26 18:42:51
 * @LastEditTime: 2020-12-26 19:21:02
 */
#include <bits/stdc++.h>

#define DEBUG

using namespace std;

const double eps = 1e-7;
const double PI = acos(-1);
typedef pair<int, int> pii;
typedef long long ll;
const int MOD = 1e9+7;
const int INF = 0x3f3f3f3f;
// const ll INF = 1e18;
const int N = 1e2+7;

ll m;
int dp[64][8];

inline void solve() {
  cin >> m;
  dp[0][0] = 1;
  int i = 0;
  for (i = 0; 1ll<<i <= m; ++i) {
    memset(dp[i+1], 0, sizeof dp[i+1]);
    for (int j = 0; j < 8; ++j) {
      for (int k = (j&1)^((m>>i)&1); k < 8; k += 2) {
        (dp[i+1][(j+k)>>1] += dp[i][j]) %= MOD;
      }
    }
  }
  cout << dp[i][0] << endl;
}

signed main() {
#ifdef ONLINE_JUDGE
  ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
#endif
  int T = 1;
  cin >> T;
  for (int t = 1; t <= T; ++t) {
    solve();
  }
  return 0;
}