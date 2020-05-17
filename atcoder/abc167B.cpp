/*
 * @Author: Kaizyn
 * @Date: 2020-05-10 20:58:25
 * @LastEditTime: 2020-05-10 21:02:00
 */
#include <bits/stdc++.h>

// #define DEBUG

using namespace std;

const double eps = 1e-7;
const double PI = acos(-1);
typedef pair<int, int> pii;
const int MOD = 998244353;
const int INF = 0x3f3f3f3f;

int a, b, c, k;

inline void solve() {
  cin >> a >> b >> c >> k;
  int res = 0, g;
  g = min(a, k);
  a -= g;
  k -= g;
  res += g;
  g = min(b, k);
  b -= g;
  k -= g;
  g = min(c, k);
  c -= g;
  k -= g;
  res -= g;
  cout << res << endl;
}

signed main() {
  ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
  int T = 1;
  // cin >> T;
  for (int t = 1; t <= T; ++t) {
    solve();
  }
  return 0;
}