/*
 * @Author: Kaizyn
 * @Date: 2020-10-04 19:53:55
 * @LastEditTime: 2020-10-05 10:36:23
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

inline long long EXCRT(int n, long long a[], long long m[]) {
  // M*x + m[i]*y = a[i]-res (mod m[i])
  // res = res+x*M;
  long long M = m[1], res = a[1], x, y, c, d;
  for (int i = 2; i <= n; ++i) {
    d = exgcd(M, m[i], x, y);
    c = (a[i]-res%m[i]+m[i])%m[i];
    if (c%d != 0) return -1;
    x = (c/d)*x%(m[i]/d);
    res += x*M;
    M *= m[i]/d;
    res = (res%M+M)%M;
  }
  return res;
}

long long n;
long long a[3], m[3];

long long check(long long x) {
  // k%x == 0
  // (k+1)%(2n/x) == 0
  m[1] = x;
  a[1] = 0;
  m[2] = n/x;
  a[2] = m[2]-1;
  long long res = EXCRT(2, a, m);
  // cout << x << " " << res << endl;
  return ~res ? res : n;
}

signed main() {
  ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
  cin >> n;
  n *= 2;
  long long k = check(1);
  for (long long i = 2; i*i <= n; ++i) {
    if (n%i) continue;
    k = min(k, check(i));
    k = min(k, check(n/i));
  }
  cout << k << endl;
  return 0;
}