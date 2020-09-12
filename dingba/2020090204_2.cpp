/*
 * @Author: Kaizyn
 * @Date: 2020-09-03 14:37:17
 * @LastEditTime: 2020-09-03 15:18:57
 */
#include <bits/stdc++.h>

// #define DEBUG

using namespace std;

const double eps = 1e-7;
const double PI = acos(-1);
typedef pair<int, int> pii;
const int MOD = 998244353;
const int INF = 0x3f3f3f3f;
const int N = 5e4+7;

template <typename T, typename H>
inline T qpow(const T &a, const H &p, const int &mo = MOD) {
  long long res = 1, x = a;
  for (H i = p; i; i >>= 1, x = x*x%mo)
    if (i&1) res = res*x%mo;
  return static_cast<T>(res);
}

template <typename T>
inline T mul_inverse(const T &a, const int &mo = MOD) {
  return qpow(a, mo-2);
}

int k;
int a[N];
long long n;
long long f[N], fac[N];

template <typename T, typename P> // x[i] = i -> y[i] = f(i)
long long Largrange(T k, const int &n, const P y[]) {
  if ((k %= MOD) <= n) return y[k];
  static long long pre[N], suf[N];
  long long res = 0;
  pre[0] = suf[n+1] = 1;
  for (int i = 1; i <= n; ++i) pre[i] = pre[i-1]*(k-i)%MOD;
  for (int i = n; i >= 1; --i) suf[i] = suf[i+1]*(k-i)%MOD;
  for (int i = 1; i <= n; ++i) {
    (res += y[i]*pre[i-1]%MOD*suf[i+1]%MOD
      *mul_inverse(((n-i)&1 ? -1 : 1)*fac[i-1]*fac[n-i]%MOD)) %= MOD;
  }
  return (res+MOD)%MOD;
}

signed main() {
  ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
  cin >> k >> n;
  for (int i = 1; i <= k; ++i) cin >> a[i];

  int m = 0;
  for (int i = 1; i <= k; ++i) m = max(a[i], m);
  m += 2;
  fac[0] = 1;
  for (int i = 1; i <= m; ++i) {
    fac[i] = fac[i-1]*i%MOD;
    f[i] = f[i-1];
    for (int j = 1; j <= k; ++j)
      (f[i] += 1ll*a[j]*qpow(i, a[j])) %= MOD;
  }
  cout << Largrange(n, m, f) << endl;
  return 0;
}