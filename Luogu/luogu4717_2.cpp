/*
 * @Author: Kaizyn
 * @Date: 2020-08-11 21:41:02
 * @LastEditTime: 2020-08-15 17:07:37
 */
#include <bits/stdc++.h>

// #define DEBUG

using namespace std;

const double eps = 1e-7;
const double PI = acos(-1);
typedef pair<int, int> pii;
const int MOD = 998244353;
const int INF = 0x3f3f3f3f;
const int N = 1<<17;

template <typename T>
T exgcd(const T a, const T b, T &x, T &y) {
  if (!b) { x = 1; y = 0; return a; }
  T d = exgcd(b, a%b, y, x);
  y -= a/b*x;
  return d;
}

template <typename T>
inline T mul_inverse(const T &a, const T &mo = MOD) {
  T x, y;
  exgcd(a, mo, x, y);
  return (x%mo+mo)%mo;
}

namespace FWT {
#define forforfor for (int l = 2; l <= len; l <<= 1)\
                  for (int i = 0, k = l>>1; i < len; i += l)\
                  for (int j = 0; j < k; ++j)

  const int SIZE = (1<<17)+3;
  int len;
  int f[SIZE], g[SIZE];
  template <class T> void init(T a[], const int &n, T b[], const int &m) {
    len = 1;
    while (len < max(n, m)) len <<= 1;
    for (int i = 0; i < n; ++i) f[i] = a[i];
    for (int i = n; i < len; ++i) f[i] = 0;
    for (int i = 0; i < m; ++i) g[i] = b[i];
    for (int i = m; i < len; ++i) g[i] = 0;
  }
  template <class T> void fwt_or(T a[], const int x = 1) {
    forforfor a[i+j+k] = (a[i+j+k]+1ll*a[i+j]*x)%MOD;
  }
  template <class T> void fwt_and(T a[], const int x = 1) {
    forforfor a[i+j] = (a[i+j]+1ll*a[i+j+k]*x)%MOD;
  }
  template <class T> void fwt_xor(T a[], const int x = 1) {
    forforfor {
      (a[i+j] += a[i+j+k]) %= MOD;
      a[i+j+k] = (a[i+j]-2*a[i+j+k]%MOD+MOD)%MOD;
      a[i+j] = 1ll*a[i+j]*x%MOD; a[i+j+k] = 1ll*a[i+j+k]*x%MOD;
    }
  }
  template <class T> void work_or(const T a[], const int &n, const T b[], const int &m) {
    init(a, n, b, m); fwt_or(f); fwt_or(g);
    for (int i = 0; i < len; ++i) f[i] = 1ll*f[i]*g[i]%MOD;
    fwt_or(f, MOD-1); // fwt_or(x, -1)
  }
  template <class T> void work_and(const T a[], const int &n, const T b[], const int &m) {
    init(a, n, b, m); fwt_and(f); fwt_and(g);
    for (int i = 0; i < len; ++i) f[i] = 1ll*f[i]*g[i]%MOD;
    fwt_and(f, MOD-1); // fwt_and(x, -1)
  }
  template <class T> void work_xor(const T a[], const int &n, const T b[], const int &m) {
    init(a, n, b, m); fwt_xor(f); fwt_xor(g);
    for (int i = 0; i < len; ++i) f[i] = 1ll*f[i]*g[i]%MOD;
    fwt_xor(f, mul_inverse(2)); // fwt_xor(x, 1/2)
  }
#undef forforfor
} // namespace FWT


signed main() {
  ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
  int n;
  static int a[N], b[N];
  cin >> n;
  n = 1<<n;
  for (int i = 0; i < n; ++i) cin >> a[i];
  for (int i = 0; i < n; ++i) cin >> b[i];
  FWT::work_or(a, n, b, n);
  for (int i = 0; i < n; ++i) cout << FWT::f[i] << " \n"[i==n-1];
  FWT::work_and(a, n, b, n);
  for (int i = 0; i < n; ++i) cout << FWT::f[i] << " \n"[i==n-1];
  FWT::work_xor(a, n, b, n);
  for (int i = 0; i < n; ++i) cout << FWT::f[i] << " \n"[i==n-1];
  return 0;
}