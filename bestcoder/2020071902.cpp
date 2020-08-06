/*
 * @Author: Kaizyn
 * @Date: 2020-07-19 14:08:43
 * @LastEditTime: 2020-07-19 14:12:49
 */ 
#include <bits/stdc++.h>

// #define DEBUG

using namespace std;

const double eps = 1e-7;
const double PI = acos(-1);
typedef pair<int, int> pii;
const int MOD = 998244353;
const int INF = 0x3f3f3f3f;

double f(const int &x) {
  if (x >= 95) return 4.3;
  if (x >= 90) return 4.0;
  if (x >= 85) return 3.7;
  if (x >= 80) return 3.3;
  if (x >= 75) return 3.0;
  if (x >= 70) return 2.7;
  if (x >= 67) return 2.3;
  if (x >= 65) return 2.0;
  if (x >= 62) return 1.7;
  if (x >= 60) return 1.0;
  return 0;
}

inline void solve() {
  int x;
  scanf("%d", &x);
  double res = 0;
  for (int x1 = 0; x1 <= x && x1 <= 100; ++x1) {
    for (int x2 = 0; x1+x2 <= x && x2 <= 100; ++x2) {
      for (int x3 = 0; x1+x2+x3 <= x && x3 <= 100; ++x3) {
        int x4 = x-x1-x2-x3;
        if (x4 < 0 || x4 > 100) continue;
        res = max(res, f(x1)+f(x2)+f(x3)+f(x4));
      }
    }
  }
  printf("%.1f\n", res);
}

signed main() {
  ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
  int T = 1;
  cin >> T;
  for (int t = 1; t <= T; ++t) {
    solve();
  }
  return 0;
}