/*
 * @Author: Kaizyn
 * @Date: 2020-10-04 19:53:55
 * @LastEditTime: 2020-10-06 16:33:08
 */
#include <bits/stdc++.h>

// #define DEBUG

using namespace std;

const double eps = 1e-7;
const double PI = acos(-1);
typedef pair<int, int> pii;
const int MOD = 998244353;
const int INF = 0x3f3f3f3f;
// const int N = ;

template <typename T>
T exgcd(const T a, const T b, T &x, T &y) {
  if (!b) return x = 1, y = 0, a;
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

inline long long CRT(int n, long long a[], long long m[]) {
  long long res = 0, M = 1;
  for (int i = 1; i <= n; ++i) M *= m[i];
  for (int i = 1; i <= n; ++i)
    res = (res + a[i]*(M/m[i])%M*mul_inverse(M/m[i], m[i]))%M;
  return (res+M)%M;
}

long long n;
long long a[3], m[3];

long long f1(long long x, long long y) {
  a[1] = 1; a[2] = 0;
  m[1] = x; m[2] = y;
  long long res = CRT(2, a, m);
  return res > 1 ? res-1 : 2*n;
}

long long f2(long long x, long long y) {
  a[1] = x-1; a[2] = 0;
  m[1] = x; m[2] = y;
  long long res = CRT(2, a, m);
  return res > 1 ? res : 2*n;
}

long long f(long long x) {
  long long y = n/x;
  x *= 2;
  if (__gcd(x, y) != 1) return 2*n;
  return min(f1(x, y), f2(x, y));
}

signed main() {
  ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
  cin >> n;
  long long k = n&1 ? n : n*2;
  for (long long i = 1; i*i <= n; ++i) {
    if (n%i) continue;
    k = min(k, f(i));
    k = min(k, f(n/i));
  }
  cout << k << endl;
  return 0;
}