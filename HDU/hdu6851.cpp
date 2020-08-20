/*
 * @Author: Kaizyn
 * @Date: 2020-08-15 13:28:43
 * @LastEditTime: 2020-08-15 15:48:07
 */
#include <bits/stdc++.h>

#define DEBUG

using namespace std;

const double eps = 1e-7;
const double PI = acos(-1);
typedef pair<int, int> pii;
const int MOD = 998244353;
const int INF = 0x3f3f3f3f;
const int N = 1e6+7;
const int B = 21;

namespace FST {
  const int W = 21;
  const int N = 1<<W;
  int len, bit;
  int f[W+1][N], g[W+1][N], h[W+1][N];
  template <class T> void fwt(T a[], const int x = 1) {
    for (int l = 2; l <= len; l <<= 1)
    for (int i = 0, k = l>>1; i < len; i += l)
    for (int j = 0; j < k; ++j)
      a[i+j+k] = (a[i+j+k]+1ll*a[i+j]*x)%MOD;
  }
  template <class T> void work(const T a[], const int &n, const T b[], const int &m) {
    len = 1; bit = 0;
    while (len < max(n, m)) len <<= 1, ++bit;
    for (int i = 0; i <= bit; ++i)
      for (int j = 0; j < len; ++j)
        f[i][j] = g[i][j] = h[i][j] = 0;
    for (int i = 0; i < n; ++i) f[__builtin_popcount(i)][i] = a[i];
    for (int i = 0; i < m; ++i) g[__builtin_popcount(i)][i] = b[i];
    for (int i = 0; i <= bit; ++i) fwt(f[i]), fwt(g[i]);
    for (int i = 0; i <= bit; ++i)
      for (int j = 0; j <= i; ++j)
        for (int k = 0; k < len; ++k)
          h[i][k] = (h[i][k]+1ll*f[j][k]*g[i-j][k])%MOD;
    for (int i = 0; i <= bit; ++i) fwt(h[i], MOD-1); // fwt(h[i], -1)
    // return h[__builtin_popcount(i)][i]
  }
} // namespace FWT

template <typename T> void vip_fst(T a[], const int &n) { // return a
  static int b[1<<B]; // warning: the type of b
  int len = 1; while (len < n) len <<= 1;
  memcpy(b, a, sizeof(T)*len);
  memset(a, 0, sizeof(T)*len); a[0] = 1;
  for (int i = 1; i < len; i <<= 1) {
    FST::work(a, i, b+i, i);
    for (int j = 0; j < i; ++j)
      a[i+j] = FST::h[__builtin_popcount(j)][j];
  }
}

int n, m;
int a[1<<B];

signed main() {
  scanf("%d", &n);
  for (int i = 1, p, b; i <= n; ++i) {
    scanf("%d %d", &p, &b);
    (a[b] += p) %= MOD;
  }
  vip_fst(a, 1<<21);
  scanf("%d", &m);
  for (int i = 1, x; i <= m; ++i) {
    scanf("%d", &x);
    printf("%d\n", a[x]);
  }
  return 0;
}