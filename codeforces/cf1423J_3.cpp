/*
 * @Author: Kaizyn
 * @Date: 2020-12-26 19:34:17
 * @LastEditTime: 2020-12-26 20:18:02
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
int cnt[2][8][8], l[2][8], r[2][8];
int dp[2][8], sum[2][10];

inline void init() {
  for (int i = 0; i < 7; ++i) { // last is i
    for (int j = 0; j < 8; ++j) { // now choose j
      assert((i+1)>>1 < 7);
      ++cnt[(i+j)&1][(i+j)>>1][i];
    }
  }
  for (int k = 0; k < 2; ++k) {
    for (int i = 0; i < 7; ++i) {
      l[k][i] = 8; r[k][i] = -1;
      for (int j = 0; j < 7; ++j) if (cnt[k][i][j]) {
        l[k][i] = min(l[k][i], j);
        r[k][i] = max(r[k][i], j);
      }
    }
  }
#ifdef DEBUG
  for (int k = 0; k < 2; ++k) {
    for (int i = 0; i < 7; ++i) {
      for (int j = 0; j < 7; ++j) {
        cout << cnt[k][i][j];
      }
      cout << " " << l[k][i] << " " << r[k][i] << endl;
    }
    cout << endl;
  }
#endif
}

inline void solve() {
  scanf("%lld", &m);
  dp[0][0] = 1;
  fill(sum[0]+1, sum[0]+8, 1);
  int i;
  for (i = 0; 1ll<<i <= m; ++i) {
    for (int j = 0; j < 7; ++j) {
      dp[~i&1][j] = (sum[i&1][r[(m>>i)&1][j]+1]-sum[i&1][l[(m>>i)&1][j]]+MOD)%MOD;
      sum[~i&1][j+1] = (sum[~i&1][j]+dp[~i&1][j])%MOD;
    }
#ifdef DEBUG
    cout << i << endl;
    for (int j = 0; j < 7; ++j) cout << sum[~i&1][j+1] << " \n"[j==6];
    for (int j = 0; j < 7; ++j) cout << dp[~i&1][j] << " \n"[j==6];
#endif
  }
  printf("%d\n", dp[i&1][0]);
}

signed main() {
  init();
  int T = 1;
  scanf("%d", &T);
  while (T--) solve();
  return 0;
}