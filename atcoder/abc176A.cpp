/*
 * @Author: Kaizyn
 * @Date: 2020-08-22 21:16:23
 * @LastEditTime: 2020-08-22 21:19:09
 */
#include <bits/stdc++.h>

// #define DEBUG

using namespace std;

const double eps = 1e-7;
const double PI = acos(-1);
typedef pair<int, int> pii;
const int MOD = 998244353;
const int INF = 0x3f3f3f3f;

int n, x, t;

inline void solve() {
  cin >> n >> x >> t;
  int y = (n+x-1)/x;
  cout << y*t << endl;
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