/*
 * @Author: Kaizyn
 * @Date: 2020-12-26 19:22:17
 * @LastEditTime: 2020-12-26 19:31:34
 */
#include <bits/stdc++.h>

// #define DEBUG

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
ll dp[2][8];

inline void solve() {
  scanf("%lld", &m);
  memset(dp, 0, sizeof dp);
  dp[0][0] = 1;
  int i = 0;
  for (int j, k; 1ll<<i <= m; ++i) {
    ll *pre = dp[i&1], *nex = dp[~i&1];
    memset(nex, 0, 56);
    for (j = 0; j < 7; ++j) if (pre[j]) {
      for (k = (j&1)^((m>>i)&1); k < 8; k += 2) {
        nex[(j+k)>>1] += pre[j];
      }
    }
    for (j = 0; j < 7; ++j) nex[j] %= MOD;
  }
  printf("%lld\n", dp[i&1][0]);
}

signed main() {
  int T = 1;
  scanf("%d", &T);
  while (T--) solve();
  return 0;
}