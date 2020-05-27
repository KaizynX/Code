/*
 * @Author: Kaizyn
 * @Date: 2020-05-25 19:18:51
 * @LastEditTime: 2020-05-25 21:10:17
 */ 
#include <bits/stdc++.h>

// #define DEBUG

using namespace std;

const double eps = 1e-7;
const double PI = acos(-1);
typedef pair<int, int> pii;
typedef unsigned long long ull;
const int MOD = 998244353;
const int INF = 0x3f3f3f3f;
const int N = 40;

template <typename T>
struct Martix {
  int n;
  T a[N][N];
  Martix(){}
  Martix(const int &_n) : n(_n) { init(); }
  T* operator [] (const int &i) { return a[i]; }
  void init(const int &tag = 0) {
    for (int i = 1; i <= n; ++i) memset(a[i], 0, sizeof(T)*(n+1));
    for (int i = 1; i <= n; ++i) a[i][i] = tag;
  }
  friend Martix operator * (const Martix &m1, const Martix &m2) {
    int sz = m1.n;
    Martix res(sz);
    for (int i = 1; i <= sz; ++i)
      for (int j = 1; j <= sz; ++j)
        for (int k = 1; k <= sz; ++k)
          res.a[i][j] += m1.a[i][k]*m2.a[k][j];
    return res;
  }
  Martix& operator *= (const Martix &mx) { return *this = *this*mx; }
  template <typename TT>
  Martix pow(const TT &p) const {
    Martix res(n), a = *this;
    res.init(1);
    for (TT i = p; i; i >>= 1, a *= a) if (i&1) res *= a;
    return res;
  }
  friend ostream& operator << (ostream &os, Martix<T> &mx) {
    for (int i = 1; i <= mx.n; ++i)
      for (int j = 1; j <= mx.n; ++j)
        os << mx[i][j] << " \n"[j==mx.n];
    return os;
  }
};

struct Aho_Corasick_Automaton {
  static const int NN = 1e2+7;
  static const int SZ = 26;
  char beg;
  int nex[NN][SZ], num[NN], fail[NN], cnt;
  Aho_Corasick_Automaton(const char &_beg = 'a') : beg(_beg) {}
  void clear() {
    memset(nex, 0, sizeof(nex[0])*(cnt+1));
    memset(num, 0, sizeof(int)*(cnt+1));
    memset(fail, 0, sizeof(int)*(cnt+1));
    cnt = 0;
  }
  void insert(const char *s) {
    int len = strlen(s), p = 0;
    for (int i = 0, c; i < len; ++i) {
      c = s[i]-beg;
      if (!nex[p][c]) nex[p][c] = ++cnt;
      p = nex[p][c];
    }
    ++num[p];
  }
  void build() {
    static queue<int> q;
    for (int i = 0; i < SZ; ++i) if (nex[0][i]) q.push(nex[0][i]);
    while (q.size()) {
      int u = q.front();
      q.pop();
      for (int i = 0; i < SZ; ++i) {
        if (nex[u][i]) {
          fail[nex[u][i]] = nex[fail[u]][i];
          q.push(nex[u][i]);
        } else {
          nex[u][i] = nex[fail[u]][i];
        }
      }
    }
    for (int i = 0; i <= cnt; ++i) {
      for (int j = i; j; j = fail[j]) {
        num[i] |= num[j];
      }
    }
  }
};

int n, L;
char s[N];
ull dp[100][64];
Aho_Corasick_Automaton ac;
Martix<ull> mat;

inline void solve() {
  ac.clear();
  for (int i = 1; i <= n; ++i) {
    scanf("%s", s);
    ac.insert(s);
  }
  ac.build();
  memset(dp, 0, sizeof dp);
  dp[0][0] = 1;
  ull res = 0;
  for (int l = 1; l <= L; ++l) {
    for (int i = 0; i <= ac.cnt; ++i) {
      for (int j = 0; j < 26; ++j) {
        int k = ac.nex[i][j];
        dp[l][k+32] += dp[l-1][i+32];
        if (ac.num[k]) k += 32;
        dp[l][k] += dp[l-1][i];
      }
    }
    for (int i = 32; i <= 32+ac.cnt; ++i) {
      res += dp[l][i];
    }
  }
  cout << res << endl;
}

signed main() {
  while (scanf("%d %d", &n, &L) == 2) solve();
  return 0;
}