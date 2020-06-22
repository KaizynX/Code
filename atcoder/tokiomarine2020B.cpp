/*
 * @Author: Kaizyn
 * @Date: 2020-06-13 19:58:00
 * @LastEditTime: 2020-06-13 20:05:30
 */ 
#include <bits/stdc++.h>

// #define DEBUG

using namespace std;

const double eps = 1e-7;
const double PI = acos(-1);
typedef pair<int, int> pii;
const int MOD = 998244353;
const int INF = 0x3f3f3f3f;

int a, b, v, w, t;

inline void solve() {
  cin >> a >> v >> b >> w >> t;
  if (v < w || (v == w && a != b)) return cout << "NO" << endl, void();
  cout << (abs(a-b) <= 1ll*(v-w)*t ? "YES" : "NO") << endl;
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