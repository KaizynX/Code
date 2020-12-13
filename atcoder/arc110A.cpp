/*
 * @Author: Kaizyn
 * @Date: 2020-12-05 19:55:46
 * @LastEditTime: 2020-12-05 20:05:54
 */
#include <bits/stdc++.h>

// #define DEBUG

using namespace std;

const double eps = 1e-7;
const double PI = acos(-1);
typedef pair<int, int> pii;
const int MOD = 998244353;
const int INF = 0x3f3f3f3f;
const int N = 100;

int n;
long long a[N], m[N];

template <typename T>
T exgcd(const T a, const T b, T &x, T &y) {
  if (!b) return x = 1, y = 0, a;
  T d = exgcd(b, a%b, y, x);
  y -= a/b*x;
  return d;
}

inline long long EXCRT(long long a[], long long m[]) {
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

inline void solve() {
  cin >> n;
  /*
  --n;
  for (int i = 1; i <= n; ++i) a[i] = 1, m[i] = i+1;
  cout << EXCRT(a, m) << endl;
  */
  long long res = 1;
  for (int i = 2; i <= n; ++i) {
    res *= i/__gcd(res, 1ll*i);
  };
  cout << res+1 << endl;
}

signed main() {
  ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
  int T = 1;
  // cin >> T;
  for (int t = 1; t <= T; ++t) {
    solve();
  }
  return 0;
}