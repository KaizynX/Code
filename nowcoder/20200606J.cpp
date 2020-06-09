/*
 * @Author: Kaizyn
 * @Date: 2020-06-06 14:43:36
 * @LastEditTime: 2020-06-06 15:07:12
 */ 
#include <bits/stdc++.h>

// #define DEBUG

using namespace std;

const double eps = 1e-7;
const double PI = acos(-1);
typedef pair<int, int> pii;
const int MOD = 998244353;
const int INF = 0x3f3f3f3f;

int L, xp, yp, zp;
int x[5], y[5], z[5];

inline void solve() {
  cin >> L >> xp >> yp >> zp;
  for (int i = 1; i <= 3; ++i) cin >> x[i] >> y[i] >> z[i];
  double a = (y[2]-y[1])*(z[3]-z[1])-(y[3]-y[1])*(z[2]-z[1]),
         b = (x[2]-x[1])*(z[3]-z[1])-(x[3]-x[1])*(z[2]-z[1]),
         c = (x[2]-x[1])*(y[3]-y[1])-(x[3]-x[1])*(y[2]-y[1]),
         d = -a*x[1]-b*y[1]-c*z[1];
  double r = abs(a*xp+b*yp+c*zp+d)/sqrt(a*a+b*b+c*c)/2;
#ifdef DEBUG
  cout << a << " " << b << " " << c << " " << d << " " << r << endl;
#endif
  double t = 4*PI*r*r*r/3/L;
  printf("%.10lf\n", t);
}

signed main() {
  // ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
  int T = 1;
  // cin >> T;
  for (int t = 1; t <= T; ++t) {
    solve();
  }
  return 0;
}