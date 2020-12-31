/*
 * @Author: Kaizyn
 * @Date: 2020-12-26 20:47:24
 * @LastEditTime: 2020-12-26 20:57:29
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
// const int N = ;

inline void solve() {
  ll m;
  scanf("%lld", &m);
  printf("%lld\n", (m/4+1)%MOD*((m/2-m/4+1)%MOD)%MOD);
}

signed main() {
  int T = 1;
  scanf("%d", &T);
  for (int t = 1; t <= T; ++t) {
    solve();
  }
  return 0;
}