/*
 * @Author: Kaizyn
 * @Date: 2020-05-31 16:49:01
 * @LastEditTime: 2020-05-31 16:51:03
 */ 
#include <bits/stdc++.h>

// #define DEBUG

using namespace std;

const double eps = 1e-7;
const double PI = 3.14;
typedef pair<int, int> pii;
const int MOD = 998244353;
const int INF = 0x3f3f3f3f;

inline void solve() {
  int x;
  cin >> x;
  printf("%.2f\n", (PI/2+1)*x*x);
}

signed main() {
  int T = 1;
  cin >> T;
  for (int t = 1; t <= T; ++t) {
    solve();
  }
  return 0;
}