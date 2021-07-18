/*
 * @Author: Kaizyn
 * @Date: 2021-07-18 12:50:05
 * @LastEditTime: 2021-07-18 13:25:32
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
const int N = 10;

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

/*
inline void get_next(const string &s, int nex[]) { get_next(s.c_str(), nex); }
inline void get_next(const char *s, int nex[]) {
  nex[0] = nex[1] = 0;
  for (int i = 1, j = 0, l = strlen(s); i < l; ++i) {
    while (j && s[i] != s[j]) j = nex[j];
    nex[i+1] = s[i] == s[j] ? ++j : 0;
  }
}

inline void kmp(const string &s1, const string &s2, int nex[]) { kmp(s1.c_str(), s2.c_str(), nex); }
inline void kmp(const char *s1, const char *s2, int nex[]) {
  for (int i = 0, j = 0, l1 = strlen(s1), l2 = strlen(s2); i < l1; ++i){
    while (j && s1[i] != s2[j]) j = nex[j];
    if (s1[i] == s2[j]) ++j;
    if (j == l2) {
      cout << i-l2+2 << endl;
      j = nex[j];
    }
  }
}
*/

Martix<ll> A;
int nex[N] = {0, 0, 1, 0, 1};
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
#ifdef DEBUG
  cout << A;
#endif
}

inline void solve() {
  int n;
  cin >> n;
  #ifdef DEBUG
  Martix<ll> B;
  B.n = B.m = 5;
  B.init(1);
  for (int i = 1; i <= n; ++i) {
    B *= A;
    for (int j = 1; j <= 5; ++j) {
      cout << B[j][1] << " \n"[j==5];
    }
  }
  #endif
  cout << A.pow(n)[5][1] << '\n';
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