/*
 * @Author: Kaizyn
 * @Date: 2020-05-30 12:11:43
 * @LastEditTime: 2020-05-30 12:12:56
 */ 
#include <bits/stdc++.h>

// #define DEBUG

using namespace std;

const double eps = 1e-7;
const double PI = acos(-1);
typedef pair<int, int> pii;
const int MOD = 998244353;
const int INF = 0x3f3f3f3f;

int n, x, y, z;

inline void solve() {
  scanf("%d", &n);
  double res = 1e10;
  for (int i = 1; i <= n; ++i) {
    scanf("%d %d %d", &x, &y, &z);
    res = min(res, sqrt(x*x+y*y+z*z));
  }
  printf("%.3f\n", res);
}

signed main() {
  int T = 1;
  // cin >> T;
  for (int t = 1; t <= T; ++t) {
    solve();
  }
  return 0;
}