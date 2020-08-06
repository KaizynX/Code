/*
 * @Author: Kaizyn
 * @Date: 2020-07-26 14:44:43
 * @LastEditTime: 2020-07-26 15:17:18
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

int calc(int lx, int ly, int x, int y) {
  return min((ly+x-1)/x, (lx+y-1)/y);
}

int f(int lx, int ly, int lz, int x, int y, int z) {
  int t = calc(ly, lz, y, z);
  ly -= t*z;
  lz -= t*y;
  if (ly <= 0) swap(ly, lz), swap(y, z);
  if (ly <= 0) return t;
  return t+calc(lx, ly, x, y);
}

int a[3];

inline void solve() {
  cin >> a[0] >> a[1] >> a[2];
  sort(a, a+3);
  int t = 1000/a[2];
  int ly = 1000-t*a[2], lz = 1000-t*a[1];
  cout << t+min({f(1000, ly, lz, a[0], a[1], a[2]),
      f(ly, 1000, lz, a[1], a[0], a[2]),
      f(lz, ly, 1000, a[2], a[1], a[0])}) << endl;
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