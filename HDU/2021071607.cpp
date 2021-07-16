/*
 * @Author: Kaizyn
 * @Date: 2021-07-16 13:07:07
 * @LastEditTime: 2021-07-16 13:25:39
 */
#include <bits/stdc++.h>

// #define DEBUG

using namespace std;

const double eps = 1e-7;
const double PI = acos(-1);
typedef pair<int, int> pii;
typedef long long ll;
const int MOD = 998244353; // 1e9+7;
const int INF = 0x3f3f3f3f;
// const ll INF = 1e18;
const int N = 1e6+7;

template <typename T>
struct Martix {
  static const int N = 3;
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
          res.a[i][j] = (res.a[i][j]+1ll*m1.a[i][k]*m2.a[k][j])%MOD;
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

int n, x;
map<int, int> mmp;

Martix<int> mat() {
  Martix<int> A;
  A.n = A.m = 2;
  A[1][1] = n-2;
  A[1][2] = n-1;
  A[2][1] = 1;
  A[2][2] = 0;
  return A;
}

inline int f(int t) {
  return mat().pow(t)[2][2];
}

inline long long BSGS() { // a^n = x
  mmp.clear();
  int m = MOD, t = sqrt(m)+1, res = -1;
  Martix<int> a = mat(), b, c;
  b.n = b.m = c.n = c.m = 2;
  b.init(1); c.init(1);
  for(int i = 0; i < t; ++i, b *= a) mmp[1ll*x*b[2][2]%m] = i;
  for(int i = 0; i <= t; ++i, c *= b) { // b = a^t
    if(mmp.count(c[2][2])) {
      int tmp = t*i-mmp[c[2][2]];
      if (tmp <= 0) continue;
      if (res == -1 || tmp < res) res = tmp;
    }
  }
  return res;
}

inline void solve() {
  cin >> n >> x;
  for (int i = 0; i <= n; ++i) cout << f(i) << " \n"[i==n];
  cout << BSGS() << '\n';
}

signed main() {
#ifdef ONLINE_JUDGE
  ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
#endif
  int T = 1;
  cin >> T; // scanf("%d", &T);
  for (int t = 1; t <= T; ++t) {
    solve();
  }
  return 0;
}