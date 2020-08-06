/*
 * @Author: Kaizyn
 * @Date: 2020-07-30 16:25:11
 * @LastEditTime: 2020-07-30 21:37:07
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

bool update(double &l, double &r, const double &cl, const double cr) {
  if (cl > r || cr < l) {
    l = 360;
    r = 0;
    return false;
  }
  l = max(l, cl);
  r = min(r, cr);
  return true;
}

bool check(const double &err) {
  double shl = 0, shr = 360, thl = 0, thr = 360;
  double sml = 0, smr = 360, tml = 0, tmr = 360;
  double l, r;
  bool f1, f2;
  for (int i = 1; i <= n; ++i) {
    l = h[i]-err;
    r = h[i]+err;
    if (l < 0) {
      f1 = update(thl, thr, l+360, 360);
      f2 = update(shl, shr, 0, r);
    } else if (r > 360) {
      f1 = update(thl, thr, l, 360);
      f2 = update(shl, shr, 0, r-360);
    } else {
      f1 = update(thl, thr, l, r);
      f2 = update(shl, shr, l, r);
    }
    if (!f1 && !f2) return false;

    l = m[i]-err;
    r = m[i]+err;
    if (l < 0) {
      f1 = update(tml, tmr, l+360, 360);
      f2 = update(sml, smr, 0, r);
    } else if (r > 360) {
      f1 = update(tml, tmr, l, 360);
      f2 = update(sml, smr, 0, r-360);
    } else {
      f1 = update(tml, tmr, l, r);
      f2 = update(sml, smr, l, r);
    }
    if (!f1 && !f2) return false;
  }
#ifdef DEBUG
  printf("err:%.3f\n", err);
  printf("(%.3f %.3f)(%.3f %.3f)\n", shl, shr, thl, thr);
  printf("(%.3f %.3f)(%.3f %.3f)\n", sml, smr, tml, tmr);
#endif
  /*
  for (int hh = 0; hh < 12; ++hh) {
    for (int mm = 0; mm < 60; ++mm) {
      double tm = mm*6; // +s/10 [0, 6]
      double th = hh*30+tm/12;
      double kl, kr;
      if (tm <= smr && tm+6 >= sml) {
        kl = sml > tm ? (sml-tm)*10 : 0;
        kr = smr < tm+6 ? (smr-tm)*10 : 60;
        kl /= 120; kr /= 120;
        if (!(th+kl > smr || th+kr < sml) ||
            !(th+kl > tmr || th+kr < thl)) return true;
      }
      if (tm <= tmr && tm+6 >= tml) {
        kl = tml > tm ? (tml-tm)*10 : 0;
        kr = tmr < tm+6 ? (tmr-tm)*10 : 60;
        kl /= 120; kr /= 120;
        if (!(th+kl > smr || th+kr < sml) ||
            !(th+kl > tmr || th+kr < thl)) return true;
      }
      for (int ss = 0; ss < 60; ++ss) {
        double ts = ss*6;
        double tm = mm*6+ts/60.0;
        double th = hh*30+tm/12.0;
        if (((tm >= sml && tm <= smr) || (tm >= tml && tm <= tmr)) &&
            ((th >= shl && th <= shr) || (th >= thl && th <= thr)))
          return true;
      }
    }
  }
  */
  for (int hh = 0; hh < 12; ++hh) {
    if (sml <= smr) {
      double hl = hh*30+sml/12;
      double hr = hh*30+smr/12;
      if ((hl <= shr && hr >= shl) || (hl <= thr && hr >= thl)) return true;
    }
    if (tml <= tmr) {
      double hl = hh*30+tml/12;
      double hr = hh*30+tmr/12;
      if ((hl <= shr && hr >= shl) || (hl <= thr && hr >= thl)) return true;
    }
  }
  return false;
}

inline void solve() {
  scanf("%d", &n);
  for (int i = 1, hh, mm, ss; i <= n; ++i) {
    scanf("%d:%d:%d", &hh, &mm, &ss);
    hh %= 12;
    s[i] = ss*6;
    m[i] = mm*6+s[i]/60.0;
    h[i] = hh*30+m[i]/12.0;
  }
#ifdef DEBUG
  for (int i = 1; i <= n; ++i) {
    printf("%.3f %.3f %.3f\n", h[i], m[i], s[i]);
  }
#endif
  double l = 0, r = 180, mid;
  while (r-l > eps) {
    mid = (l+r)/2;
    if (check(mid)) r = mid;
    else l = mid;
  }
  printf("%.7f\n", l);
}

signed main() {
  int T = 1;
  scanf("%d", &T);
  for (int t = 1; t <= T; ++t) {
    solve();
  }
  return 0;
}