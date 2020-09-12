/*
 * @Author: Kaizyn
 * @Date: 2020-08-31 15:59:13
 * @LastEditTime: 2020-08-31 22:57:37
 */
#include <bits/stdc++.h>

// #define DEBUG

using namespace std;

const double eps = 1e-7;
const double PI = acos(-1);
typedef pair<int, int> pii;
const int MOD = 998244353;
const int inv2 = 499122177;
const int INF = 0x3f3f3f3f;
const int N = 1e5+7;
const int K = 17;

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

int n, k, x, y, z, len;
int f[1<<K], f1[1<<K], f2[1<<K], f3[1<<K];;

template <class T> void fwt(T a[], const int x = 1) {
  for (int l = 2; l <= len; l <<= 1)
  for (int i = 0, k = l>>1; i < len; i += l)
  for (int j = 0; j < k; ++j) {
    T tmp = a[i+j];
    (a[i+j] += a[i+j+k]) %= MOD;
    a[i+j+k] = (tmp-a[i+j+k])%MOD;
    a[i+j] = 1ll*a[i+j]*x%MOD;
    a[i+j+k] = 1ll*a[i+j+k]*x%MOD;
  }
}

signed main() {
  ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
  cin >> n >> k >> x >> y >> z;
  len = 1<<k;
  int shift = 0;
  for (int i = 1, a, b, c; i <= n; ++i) {
    cin >> a >> b >> c;
    shift ^= a; b ^= a; c ^= a;
    ++f1[b]; ++f2[c]; ++f3[b^c];
  }
  fwt(f1); fwt(f2); fwt(f3);
  int s1 = (0ll+x+y+z)%MOD,
      s2 = (0ll+x+y-z)%MOD,
      s3 = (0ll+x-y+z)%MOD,
      s4 = (0ll+x-y-z)%MOD;
  for (int i = 0; i < len; ++i) {
    int c1 = (0ll+n+f1[i]+f2[i]+f3[i])/4;
    assert(n+f1[i] >= 2*c1);
    assert(n+f2[i] >= 2*c1);
    assert(n+f3[i] >= 2*c1);
    f[i] = 1ll*qpow(s1, c1)*
        qpow(s2, (0ll+n+f1[i]-c1-c1)/2)%MOD*
        qpow(s3, (0ll+n+f2[i]-c1-c1)/2)%MOD*
        qpow(s4, (0ll+n+f3[i]-c1-c1)/2)%MOD;
  }
  fwt(f, mul_inverse(2));
  for (int i = 0; i < len; ++i)
    cout << (f[i^shift]+MOD)%MOD << " \n"[i==len-1];
  return 0;
}