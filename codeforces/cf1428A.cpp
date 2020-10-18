/*
 * @Author: Kaizyn
 * @Date: 2020-10-17 21:01:15
 * @LastEditTime: 2020-10-17 21:08:00
 */
#include <bits/stdc++.h>

// #define DEBUG

using namespace std;

const double eps = 1e-7;
const double PI = acos(-1);
typedef pair<int, int> pii;
const int MOD = 998244353;
const int INF = 0x3f3f3f3f;
// const int N = ;

int xl, xr, yl, yr;

inline int solve() {
  cin >> xl >> yl >> xr >> yr;
  int x = abs(xl-xr), y = abs(yl-yr);
  if (x > y) swap(x, y);
  if (x == 0) return y;
  else return x+y+2;
}

signed main() {
  ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
  int T = 1;
  cin >> T;
  for (int t = 1; t <= T; ++t) {
    cout << solve() << endl;
  }
  return 0;
}