/*
 * @Author: Kaizyn
 * @Date: 2021-07-18 13:29:47
 * @LastEditTime: 2021-07-18 13:42:25
 */
#include <bits/stdc++.h>

// #define DEBUG

using namespace std;

const double eps = 1e-7;
const double PI = acos(-1);
typedef pair<int, int> pii;
typedef long long ll;
const int MOD = 1e9+7;
const int INF = 0x3f3f3f3f;
// const ll INF = 1e18;
const int N = 6;

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
  friend ostream& operator << (ostream &os, const Martix<T> &mx) {
    for (int i = 1; i <= mx.n; ++i)
      for (int j = 1; j <= mx.m; ++j)
        os << mx.a[i][j] << " \n"[j==mx.m];
    return os;
  }
};

Martix<ll> A, B[30];
int nex[N] = {0, 0, 1, 0, 1};
ll f[N], g[N];
char s[] = "CCPC";

void init() {
  A.n = A.m = 5;
  for (int i = 0; i < 4; ++i) {
    for (int ch : {'C', 'P'}) {
      int j = i;
      while (j && s[j] != ch) j = nex[j];
      j += s[j] == ch;
      if (j == 4) {
        A[5][i+1]++;
        j = 0;
      }
      A[j+1][i+1]++;
    }
  }
  A[5][5] += 2;
  B[0] = A;
  for (int i = 1; i < 30; ++i) {
    B[i] = B[i-1]*B[i-1];
  }
#ifdef DEBUG
  cout << A;
#endif
}

inline void solve() {
  int n;
  cin >> n;
  memset(f+1, 0, sizeof(ll)*5);
  f[1] = 1;
  for (int b = 29; b >= 0; --b) if ((n>>b)&1) {
    memset(g+1, 0, sizeof(ll)*5);
    for (int i = 1; i <= 5; ++i) {
      for (int j = 1; j <= 5; ++j) {
        g[i] = (g[i]+B[b][i][j]*f[j])%MOD;
      }
    }
    memcpy(f+1, g+1, sizeof(ll)*5);
#ifdef DEBUG
    for (int i = 1; i <= 5; ++i) cout << f[i] << " \n"[i==5];
#endif
  }
  cout << f[5] << '\n';
  // cout << A.pow(n)[5][1] << '\n';
}

signed main() {
#ifdef ONLINE_JUDGE
  ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
#endif
  init();
  int T = 1;
  cin >> T; // scanf("%d", &T);
  for (int t = 1; t <= T; ++t) {
    solve();
  }
  return 0;
}