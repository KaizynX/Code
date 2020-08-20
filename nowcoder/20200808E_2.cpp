/*
 * @Author: Kaizyn
 * @Date: 2020-08-08 12:46:42
 * @LastEditTime: 2020-08-08 14:14:47
 */
#include <bits/stdc++.h>

// #define DEBUG

using namespace std;

const double eps = 1e-7;
const double PI = acos(-1);
typedef pair<int, int> pii;
const int MOD = 998244353;
const int INF = 0x3f3f3f3f;
const int N = 3e6+7;

int a, b, c, d, x, y;
int res = 1;

template <typename T, typename H>
inline T qpow(const T &a, const H &p, const int &mo = MOD) {
  long long res = 1, x = a;
  for (H i = p; i; i >>= 1, x = x*x%mo)
    if (i&1) res = res*x%mo;
  return static_cast<T>(res);
}

void f(const int &n, const int &nx, const int &ny) {
  // 公共的质因数 n
  int base = qpow(n, nx), pw = qpow(base, a);
  for (int i = a, j = c; i <= b; ++i) {
    // i*nx <= j*ny
    while (j <= d && j*ny < i*nx) ++j;
    res = 1ll*res*qpow(pw, d-j+1)%MOD;
    pw = 1ll*pw*base%MOD;
  }
  base = qpow(n, ny);
  pw = qpow(base, c);
  for (int j = c, i = a; j <= d; ++j) {
    // j*ny < i*nx
    while (i <= b && i*nx <= j*ny) ++i;
    res = 1ll*res*qpow(pw, b-i+1)%MOD;
    pw = 1ll*pw*base%MOD;
  }
}

signed main() {
  ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
  cin >> a >> b >> c >> d >> x >> y;
  int n, nx, ny;
  int same_p = 1;
  for (n = 2; n*n <= x; ++n) {
    if (x%n) continue;
    nx = 0;
    while (x%n == 0) x /= n, ++nx;
    if (y%n) continue;
    ny = 0;
    while (y%n == 0) y /= n, ++ny;
    if (nx == ny) same_p = 1ll*same_p*qpow(n, nx)%MOD;
    else f(n, nx, ny);
  }
  if (x > 1 && y%x == 0) {
    n = x;
    nx = 1;
    ny = 0;
    while (y%n == 0) y /= n, ++ny;
    if (nx == ny) same_p = 1ll*same_p*qpow(n, nx)%MOD;
    else f(n, nx, ny);
  }
  f(same_p, 1, 1);
  cout << res << endl;
  return 0;
}