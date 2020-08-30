/*
 * @Author: Kaizyn
 * @Date: 2020-08-28 10:25:30
 * @LastEditTime: 2020-08-28 10:40:17
 */
#include <bits/stdc++.h>

// #define DEBUG

using namespace std;

const double eps = 1e-7;
const double PI = acos(-1);
typedef pair<int, int> pii;
const int MOD = 998244353;
const int INF = 0x3f3f3f3f;

template <typename T> inline T phi(T x) {
  T res = x;
  for (T i = 2; i*i <= x; ++i) {
    if (x%i) continue;
    res = res/i*(i-1);
    while (x%i == 0) x /= i;
  }
  if (x > 1) res = res/x*(x-1);
  return res;
}

template <typename T, typename H>
inline T qpow(const T &a, const H &p, const int &mo = MOD) {
  long long res = 1, x = a;
  for (H i = p; i; i >>= 1, x = x*x%mo)
    if (i&1) res = res*x%mo;
  return static_cast<T>(res);
}

inline int getG(const int &m) {
  static int q[100000+7];
  int _phi = phi(m), x = _phi, tot = 0;
  for (int i = 2; i*i <= _phi; ++i) {
    if (x%i) continue;
    q[++tot] = _phi/i;
    while (x%i == 0) x /= i;
  }
  if (x > 1) x = q[++tot] = _phi/x;
  for (int g = 2, flag; ; ++g) {
    flag = 1;
    if (qpow(g, _phi, m) != 1) continue;
    for (int i = 1; i <= tot; ++i) {
      if (qpow(g, q[i], m) == 1) {
        flag = 0;
        break;
      }
    }
    if (flag) return g;
  }
}

signed main() {
  ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
  int p;
  cin >> p;
  cout << getG(p) << endl;
  return 0;
}