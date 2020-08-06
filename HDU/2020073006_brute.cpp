/*
 * @Author: Kaizyn
 * @Date: 2020-07-30 16:25:11
 * @LastEditTime: 2020-07-30 18:04:18
 */ 
#include <bits/stdc++.h>

#define DEBUG

using namespace std;

const double eps = 1e-7;
const double PI = acos(-1);
typedef pair<int, int> pii;
const int MOD = 998244353;
const int INF = 0x3f3f3f3f;
const int N = 5e4+7;

int n;
double h[N], m[N], s[N];

inline void solve() {
  scanf("%d", &n);
  for (int i = 1, hh, mm, ss; i <= n; ++i) {
    scanf("%d:%d:%d", &hh, &mm, &ss);
    hh %= 12;
    s[i] = ss*6;
    m[i] = mm*6+s[i]/60.0;
    h[i] = hh*30+m[i]/12.0;
  }
  double theta = 180;
  for (int hh = 0; hh < 12; ++hh) {
    for (int mm = 0; mm < 60; ++mm) {
      for (int ss = 0; ss < 60; ++ss) {
        double ts = ss*6;
        double tm = mm*6+ts/60.0;
        double th = hh*30+tm/12.0;
        double cur = 0;
        for (int i = 1; i <= n; ++i) {
          if (m[i] > tm) cur = max(cur, min(m[i]-tm, tm-m[i]+360));
          else cur = max(cur, min(tm-m[i], m[i]-tm+360));
          if (h[i] > th) cur = max(cur, min(h[i]-th, th-h[i]+360));
          else cur = max(cur, min(th-h[i], h[i]-th+360));
        }
        if (cur < theta) {
          theta = cur;
          printf("%d:%d:%d %.7f\n", hh, mm, ss, cur);
        }
      }
    }
  }
}

signed main() {
  int T = 1;
  scanf("%d", &T);
  for (int t = 1; t <= T; ++t) {
    solve();
  }
  return 0;
}