/*
 * @Author: Kaizyn
 * @Date: 2020-05-09 17:01:05
 * @LastEditTime: 2020-05-12 13:08:41
 */
#include <bits/stdc++.h>

#define DEBUG

using namespace std;

const double eps = 1e-7;
const double PI = acos(-1);
typedef pair<int, int> pii;
const int MOD = 1e9+7;
const int INF = 0x3f3f3f3f;
const int N = 5;

template <typename T>
struct Martix {
  int n, m;
  T a[N][N];
  Martix(){}
  Martix(const int &_n) : n(_n), m(_n) { init(); }
  Martix(const int &_n, const int &_m) : n(_n), m(_m) { init(); }
  T* operator [] (const int &i) { return a[i]; }
  void init(const int &tag = 0) {
    for (int i = 1; i <= n; ++i) memset(a[i], 0, sizeof(T)*(n+1));
    for (int i = 1; i <= n; ++i) a[i][i] = tag;
  }
  friend Martix operator * (const Martix &m1, const Martix &m2) {
    Martix res(m1.n, m2.m);
    for (int i = 1; i <= res.n; ++i)
      for (int j = 1; j <= res.m; ++j)
        for (int k = 1; k <= m1.m; ++k)
          res.a[i][j] = (res.a[i][j]+m1.a[i][k]*m2.a[k][j])%MOD;
    return res;
  }
  Martix& operator *= (const Martix &mx) { return *this = *this*mx; }
  template <typename TT>
  Martix pow(const TT &p) const {
    Martix res(n, m), a = *this;
    res.init(1);
    for (TT i = p; i; i >>= 1, a *= a) if (i&1) res *= a;
    return res;
  }
  friend ostream& operator << (ostream &os, Martix<T> &mx) {
    for (int i = 1; i <= mx.n; ++i)
      for (int j = 1; j <= mx.m; ++j)
        os << mx[i][j] << " \n"[j==mx.m];
    return os;
  }
};

int a, b, c, d, p, n;
Martix<long long> k(3), mat(3);

inline void init_mat(const int &v) {
  mat.init(0);
  mat[1][1] = 1;
  mat[3][2] = 1;
  mat[1][3] = v;
  mat[2][3] = c;
  mat[3][3] = d;
}

inline void print() {
  cout << (k[1][3]+a*k[2][3]+b*k[3][3])%MOD << endl;
}

inline void solve() {
  cin >> a >> b >> c >> d >> p >> n;
#ifndef DEBUG
  if (n <= 1000000) {
    long long f[3] = {1, a, b};
    for (int i = 3; i <= n; ++i) {
      f[i%3] = (c*f[(i+1)%3]+d*f[(i+2)%3]+p/i)%MOD;
    }
    cout << f[n%3] << endl;
    return;
  }
#endif
  k.init(1);
  int q;
  for (q = 3; q <= sqrt(p)+.5 && q <= n; ++q) {
    init_mat(p/q);
    k *= mat;
  }
  #ifdef DEBUG
  print();
  #endif
  for (int i = sqrt(p)+.5, l, r;
      i >= max(1, p/n); --i) {
    // p/j == i
    l = max(1, p/(i+1));
    while (l-1 >= 1 && p/(l-1) == i) --l;
    while (p/l > i) ++l;
    r = p/i;
    while (r+1 <= p && p/(r+1) == i) ++r;
    while (p/r < i) --r;
    l = max(q, l);
    r = min(n, r);
    #ifdef DEBUG
    cout << i << " " << l << " " << r << endl;
    #endif
    if (l > r) continue;

    init_mat(i);
    k *= mat.pow(r-l+1);
    #ifdef DEBUG
    // cout << k;
    print();
    #endif
  }
  if (p < n) {
    init_mat(0);
    k *= mat.pow(n-max(2, p));
  }
  print();
}

signed main() {
  ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
  int T = 1;
  cin >> T;
  for (int t = 1; t <= T; ++t) {
    solve();
  }
  return 0;
}