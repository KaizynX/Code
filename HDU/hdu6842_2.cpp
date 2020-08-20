/*
 * @Author: Kaizyn
 * @Date: 2020-08-11 10:02:07
 * @LastEditTime: 2020-08-14 15:02:58
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

int n, m;
long long p, q, p0, p1, p2, p3;
long long sum[N], pw1[N], pw2[N], pw3[N], fac[N<<1], inv[N<<1];
// p0 n, m
// p1 n-1, m
// p2 n, m-1
// p3 n-1, m-1

void init(const int &n) {
  fac[0] = inv[0] = fac[1] = inv[1] = 1;
  for (int i = 2; i <= n; ++i) {
    fac[i] = fac[i-1]*i%MOD;
    inv[i] = (MOD-MOD/i)*inv[MOD%i]%MOD;
  }
  for (int i = 2; i <= n; ++i) {
    inv[i] = inv[i]*inv[i-1]%MOD;
  }
}
long long A(const int &p, const int &q) {
  return p >= q ? fac[p]*inv[p-q]%MOD : 0;
}
long long C(const int &p, const int &q) {
  return p >= q ? fac[p]*inv[q]%MOD*inv[p-q]%MOD : 0;
}

inline void solve() {
  cin >> n >> m >> p >> q;
  p = p*mul_inverse(100)%MOD;
  q = q*mul_inverse(100)%MOD;
  p0 = mul_inverse((1-(1-p)*(1-q)%MOD+MOD)%MOD);
  p1 = ((1-p)*q%MOD+MOD)*p0%MOD;
  p2 = (p*(1-q)%MOD+MOD)*p0%MOD;
  p3 = p*q%MOD*p0%MOD;
#ifdef DEBUG
  cout << p0 << " " << p1 << " " << p2 << " " << p3 << endl;
#endif
  // put i's to m-1
  sum[0] = pw1[0] = pw2[0] = pw3[0] = 1;
  for (int i = 1; i < n; ++i) {
    pw1[i] = pw1[i-1]*p1%MOD;
    sum[i] = (pw1[i]*fac[m+i-1]%MOD*inv[m-1]%MOD*inv[i]+sum[i-1])%MOD;
  }
  for (int i = 1; i < m; ++i) {
    pw2[i] = pw2[i-1]*p2%MOD;
    pw3[i] = pw3[i-1]*p3%MOD;
  }
  long long res = 0;
  for (int t1, t2, t3 = 0; t3 < m && t3 < n; ++t3) {
    // t2+t3 == m-1
    // t1+t3 < n
    t2 = m-1-t3;
    t1 = n-1-t3;
    res = (res+sum[t1]*pw2[t2]%MOD*pw3[t3]%MOD*C(m-1, t2))%MOD;
  }
  // res = sum [n=i, m=1]
  cout << res*p0%MOD*p%MOD << endl;
}

signed main() {
  ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
  init(200000);
  int T = 1;
  cin >> T;
  while (T--) solve();
  return 0;
}