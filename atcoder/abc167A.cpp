/*
 * @Author: Kaizyn
 * @Date: 2020-05-10 20:57:59
 * @LastEditTime: 2020-05-10 20:59:58
 */
#include <bits/stdc++.h>

// #define DEBUG

using namespace std;

const double eps = 1e-7;
const double PI = acos(-1);
typedef pair<int, int> pii;
const int MOD = 998244353;
const int INF = 0x3f3f3f3f;

string s, t;

inline void solve() {
  cin >> s >> t;
  cout << (t.substr(0, s.size()) == s ? "Yes" : "No") << endl;
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