/*
 * @Author: Kaizyn
 * @Date: 2020-06-20 19:56:11
 * @LastEditTime: 2020-06-20 20:02:18
 */ 
#include <bits/stdc++.h>

// #define DEBUG

using namespace std;

const double eps = 1e-7;
const double PI = acos(-1);
typedef pair<int, int> pii;
const int MOD = 998244353;
const int INF = 0x3f3f3f3f;

int x;

inline void solve() {
  cin >> x;
  for (int i = 1; i <= 360; ++i) {
    if (i*x%360 == 0) {
      cout << i << endl;
      return;
    }
  }
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