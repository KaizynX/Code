/*
 * @Author: Kaizyn
 * @Date: 2020-05-28 22:21:09
 * @LastEditTime: 2020-05-28 22:45:34
 */ 
#include <bits/stdc++.h>

// #define DEBUG

using namespace std;

const double eps = 1e-7;
const double PI = acos(-1);
typedef pair<int, int> pii;
const int MOD = 998244353;
const int INF = 0x3f3f3f3f;

int h, c, t;

inline double dis(const int &x) {
  return abs(t-(h*(x+1.0)+1.0*c*x)/(2*x+1.0));
}

inline void solve() {
  cin >> h >> c >> t;
  if (t*2 <= (h+c)) return cout << 2 << endl, void();
  double x = (h-t)/(2.0*t-h-c);
  int l = (int)floor(x), r = (int)ceil(x);
  cout << (dis(l) <= dis(r) ? l : r)*2+1 << endl;
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