/*
 * @Author: Kaizyn
 * @Date: 2020-08-16 13:52:46
 * @LastEditTime: 2020-08-16 14:46:15
 */
#include <bits/stdc++.h>

#define DEBUG

using namespace std;

const double eps = 1e-7;
const double PI = acos(-1);
typedef pair<int, int> pii;
const int MOD = 1e9+7;
const int INF = 0x3f3f3f3f;
const int N = 1e6+7;
#ifdef DEBUG
const int B = 6;
#else
const int B = 17;
#endif

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

  const int SIZE = 1<<17;
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

namespace FST {
  const int W = 17;
  const int N = 1<<W;
  int len, bit;
  int f[W+1][N], g[W+1][N], h[W+1][N], res[N];
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
    for (int i = 0; i <= bit; ++i) {
      fwt(f[i]); fwt(g[i]);
      for (int j = 0; j <= i; ++j)
        for (int k = 0; k < len; ++k)
          h[i][k] = (h[i][k]+1ll*f[j][k]*g[i-j][k])%MOD;
      fwt(h[i], MOD-1); // fwt(h[i], -1)
    }
    for (int i = 0; i < len; ++i) res[i] = h[__builtin_popcount(i)][i];
  }
} // namespace FWT

int n;
int s[1<<B], a[1<<B], b[1<<B], fib[1<<B], aor[1<<B], axor[1<<B], aand[1<<B];

#ifdef DEBUG
void print(int *arr) {
  for (int i = 0; i < 1<<B; ++i) printf("%d%c", arr[i], " \n"[i+1==(1<<B)]);
}
#endif

signed main() {
  ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
  fib[0] = 0; fib[1] = 1;
  for (int i = 2; i < 1<<B; ++i) fib[i] = (fib[i-2]+fib[i-1])%MOD;

  cin >> n;
  for (int i = 1, si; i <= n; ++i) {
    cin >> si;
    ++s[si];
  }
  // aor[i] the number of pair sa|ab == i && sa&sb == 0
  FST::work(s, 1<<B, s, 1<<B);
  // aor[i] the sum val of f(sa|ab) when sa|ab == i && sa&sb == 0
  for (int i = 0; i < 1<<B; ++i) aor[i] = 1ll*FST::res[i]*fib[i]%MOD;
  // axor[i] the number of pair sa^ab == i
  FWT::work_xor(s, 1<<B, s, 1<<B);
  // axor[i] the sum val of f(sa^ab) when sa^ab == i
  for (int i = 0; i < 1<<B; ++i) axor[i] = 1ll*FWT::f[i]*fib[i]%MOD;
  // aand[i] the val of f(sa|sb)*f(sd^sc) when (sa|sb)&(sd^sc) == i
  FWT::work_and(aor, 1<<B, axor, 1<<B);
  memcpy(aand, FWT::f, sizeof aand);
  for (int i = 0; i < 1<<B; ++i) s[i] = 1ll*s[i]*fib[i]%MOD;
#ifdef DEBUG
  printf("aand:"); print(aand);
  printf("s:"); print(s);
#endif
  int res = 0;
  for (int bit = 0; bit < B; ++bit) {
    // (sa|sb)&sc&(sd^se) == 1<<bit
    memset(a, 0, sizeof a);
    memset(b, 0, sizeof b);
    for (int i = 0; i < 1<<B; ++i) if ((i>>bit)&1) {
      a[i^(1<<bit)] = aand[i];
      b[i^(1<<bit)] = s[i];
    }
    FST::work(a, 1<<B, b, 1<<B);
    for (int i = 0; i < 1<<B; ++i) (res += FST::res[i]) %= MOD;
#ifdef DEBUG
    printf("a:"); print(a);
    printf("b:"); print(b);
    printf("res:"); print(FST::res);
#endif
  }
  cout << res << endl;
  return 0;
}