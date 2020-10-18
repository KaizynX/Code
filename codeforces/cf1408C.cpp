/*
 * @Author: Kaizyn
 * @Date: 2020-09-30 22:32:47
 * @LastEditTime: 2020-09-30 23:06:10
 */
#include <bits/stdc++.h>

// #define DEBUG

using namespace std;

const double eps = 1e-7;
const double PI = acos(-1);
typedef pair<int, int> pii;
const int MOD = 998244353;
const int INF = 0x3f3f3f3f;
const int N = 1e5+7;

int n, l;
int a[N];
double lt[N], rt[N];

inline void solve() {
  scanf("%d %d", &n, &l);
  for (int i = 1; i <= n; ++i) scanf("%d", a+i);
  a[0] = 0; a[n+1] = l;
  lt[0] = rt[n+1] = 0;
  for (int i = 1; i <= n; ++i) {
    lt[i] = lt[i-1]+1.0*(a[i]-a[i-1])/i;
  }
  for (int i = n; i; --i) {
    rt[i] = rt[i+1]+1.0*(a[i+1]-a[i])/(n-i+1);
  }
  double res = l;
  for (int i = 0; i <= n; ++i) {
    // meet between a[i] a[i+1]
    double d = a[i+1]-a[i];
    if (lt[i] < rt[i+1]) {
      d -= (rt[i+1]-lt[i])*(i+1);
    } else {
      d -= (lt[i]-rt[i+1])*(n+1-i);
    }
    if (d < 0) continue;
    res = min(res, max(lt[i], rt[i+1])+d/(n+2));
  }
  for (int i = 1; i <= n; ++i) {
    // meet at a[i]
    if (abs(lt[i]-rt[i]) < eps) res = min(res, lt[i]);
  }
  printf("%7f\n", res);
}

signed main() {
  int T = 1;
  scanf("%d", &T);
  for (int t = 1; t <= T; ++t) {
    solve();
  }
  return 0;
}