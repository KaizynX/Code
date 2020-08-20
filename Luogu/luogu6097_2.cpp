/*
 * @Author: Kaizyn
 * @Date: 2020-08-12 14:21:39
 * @LastEditTime: 2020-08-12 14:54:31
 */
#include <bits/stdc++.h>

// #define DEBUG

using namespace std;

const double eps = 1e-7;
const double PI = acos(-1);
typedef pair<int, int> pii;
const int MOD = 1e9+9;
const int INF = 0x3f3f3f3f;
const int N = 1<<20;

namespace FST {
  const int W = 20;
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

signed main() {
  int n;
  static int a[N], b[N];
  scanf("%d", &n);
  n = 1<<n;
  for (int i = 0; i < n; ++i) scanf("%d", a+i);
  for (int i = 0; i < n; ++i) scanf("%d", b+i);
  FST::work(a, n, b, n);
  for (int i = 0; i < n; ++i)
    printf("%d%c", FST::h[__builtin_popcount(i)][i], " \n"[i==n-1]);
  return 0;
}