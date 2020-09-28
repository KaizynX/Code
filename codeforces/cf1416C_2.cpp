/*
 * @Author: Kaizyn
 * @Date: 2020-09-28 00:19:55
 * @LastEditTime: 2020-09-28 00:59:56
 */
#pragma GCC optimize("Ofast,no-stack-protector")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,avx2,tune=native")
#include <bits/stdc++.h>

// #define DEBUG

using namespace std;

const double eps = 1e-7;
const double PI = acos(-1);
typedef pair<int, int> pii;
const int MOD = 998244353;
const int INF = 0x3f3f3f3f;
const int N = 3e5+7;

int n, x, bit;
int a[N], b[N], c[N];

long long inversion(int u = 30, int l = 1, int r = n) {
  if (l > r) return 0;
  if (u == bit) {
    int res = 0;
    for (int i = l, c0 = 0, c1 = 0; i <= r; ++i) {
      if (((a[i]>>u)&1)^((x>>u)&1))
    }
    return;
  }
  int ll = 1, rr = r, mm;
  while (ll < rr) {
    mm = (ll+rr)>>1;
    if ((a[mm]>>u)&1) rr = mm;
    else ll = mm+1;
  }
  return inversion(u-1, l, p-1)+inversion(u-1, p, r);
}

inline void solve() {
  scanf("%d", &n);
  for (int i = 1; i <= n; ++i) scanf("%d", a+i);
  for (bit = 30; bit >= 0; --bit) {
    long long cnt0 = inversion();
    x |= 1<<bit;
    long long cnt1 = inversion();
    if (cnt0 <= cnt1) {
      x ^= 1<<bit;
    } else {
      ;
    }
  }
  cout << inversion(b) << " " << x << endl;
}

signed main() {
  solve();
  return 0;
}