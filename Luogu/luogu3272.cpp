/*
 * @Author: Kaizyn
 * @Date: 2020-07-17 13:06:13
 * @LastEditTime: 2020-07-22 13:20:08
 */ 
#include <bits/stdc++.h>

// #define DEBUG

using namespace std;

const double eps = 1e-7;
const double PI = acos(-1);
typedef pair<int, int> pii;
const int MOD = 20110520;
const int INF = 0x3f3f3f3f;
const int N = 1e2+7;

template <int _MOD> struct Mint {
  int v = 0;
  Mint() {}
  Mint(int _v) : v((_v%_MOD+_MOD)%_MOD) {}
  Mint(long long _v) : v(static_cast<int>((_v%_MOD+_MOD)%_MOD)) {}
  Mint operator = (const int &_v) { return *this = Mint(_v); }
  Mint operator = (const long long &_v) { return *this = Mint(_v); }
  bool operator ! () const { return !this->v; }
  bool operator < (const Mint &b) const { return v < b.v; }
  bool operator > (const Mint &b) const { return v > b.v; }
  bool operator == (const Mint &b) const { return v == b.v; }
  bool operator != (const Mint &b) const { return v != b.v; }
  bool operator <= (const Mint &b) const { return v < b.v || v == b.v; }
  bool operator >= (const Mint &b) const { return v > b.v || v == b.v; }
  Mint operator + (const Mint &b) const { return Mint(v+b.v); }
  Mint operator - (const Mint &b) const { return Mint(v-b.v); }
  Mint operator * (const Mint &b) const { return Mint(1ll*v*b.v); }
  Mint operator / (const Mint &b) const { return Mint(b.inv()*v); }
  Mint& operator += (const Mint &b) { return *this = *this+b; }
  Mint& operator -= (const Mint &b) { return *this = *this-b; }
  Mint& operator *= (const Mint &b) { return *this = *this*b; }
  Mint& operator /= (const Mint &b) { return *this = *this/b; }
  Mint operator - () const { return Mint(-v); }
  Mint& operator ++ () { return *this += 1; }
  Mint& operator -- () { return *this -= 1; }
  Mint operator ++ (int) { Mint tmp = *this; *this += 1; return tmp; }
  Mint operator -- (int) { Mint tmp = *this; *this -= 1; return tmp; }
  Mint pow(int p) const {
    Mint res(1), x(*this);
    while (p) {
      if (p&1) res = res*x;
      x *= x;
      p >>= 1;
    }
    return res;
  }
  Mint inv() const { return pow(_MOD-2); }
  friend istream& operator >> (istream &is, Mint &mt) { return is >> mt.v; }
  friend ostream& operator << (ostream &os, const Mint &mt) { return os << mt.v; }
};
using mint = Mint<MOD>;

int n, m, u;
int a[N][N];
// map<int, mint> dp[2];
unordered_map<int, mint> dp[2];

#ifdef DEBUG
inline void print() {
  for (int i = 1; i <= n; ++i) {
    for (int j = 1; j <= m; ++j) {
      cout << a[i][j] << " \n"[j==m];
    }
  }
}
#endif

inline void my_rotate() {
  static int b[N][N];
  for (int i = 1; i <= n; ++i) {
    for (int j = 1; j <= m; ++j) {
      b[i][j] = a[i][j];
    }
  }
  swap(n, m);
  for (int i = 1; i <= n; ++i) {
    for (int j = 1; j <= m; ++j) {
      a[i][j] = b[m-j+1][i];
    }
  }
}

inline mint solve() {
  int ex, ey;
  cin >> n >> m;
  for (int i = 1; i <= n; ++i) {
    static string str;
    cin >> str;
    for (int j = 1; j <= m; ++j) {
      a[i][j] = str[j-1] == '_';
    }
  }
  if (n < m) my_rotate();
  for (int i = 1; i <= n; ++i) {
    for (int j = 1; j <= m; ++j) {
      if (a[i][j]) ex = i, ey = j;
    }
  }
  #ifdef DEBUG
  print();
  #endif
  int base = (1<<m*2+2)-1;
  // 0 none 1 unturned edge 2 turned edge
  dp[u = 0].clear();
  dp[u][0] = 1;
  for (int i = 1; i <= n; ++i) {
    dp[u ^= 1].clear();
    for (const auto &p : dp[u^1]) dp[u].insert({(p.first<<2)&base, p.second});
    // for (const auto &p : dp[u^1]) dp[u][(p.first<<2)&base] += p.second;
    for (int j = 1; j <= m; ++j) {
      dp[u ^= 1].clear();
      for (const auto &p : dp[u^1]) {
        int state = p.first;
        mint val = p.second;
        int b1 = (state>>j*2-2)%4, b2 = (state>>j*2)%4;
        if (!a[i][j]) {
          if (!b1 && !b2) dp[u][state] += val;
        } else if (!b1 && !b2) {
          if (i < n) dp[u][state+(1<<j*2-2)] += val;
          if (j < m) dp[u][state+(1<<j*2)] += val;
          if (i < n && j < m) dp[u][state+(2<<j*2-2)+(2<<j*2)] += val;
        } else if (!b1 && b2 == 1) {
          if (i < n) dp[u][state+(1<<j*2-2)-(1<<j*2)] += val;
          if (j < m) dp[u][state+(2<<j*2)-(1<<j*2)] += val;
        } else if (!b1 && b2 == 2) {
          dp[u][state-(2<<j*2)] += val;
          if (i < n) dp[u][state+(2<<j*2-2)-(2<<j*2)] += val;
        } else if (b1 == 1 && !b2) {
          if (j < m) dp[u][state-(1<<j*2-2)+(1<<j*2)] += val;
          if (i < n) dp[u][state-(1<<j*2-2)+(2<<j*2-2)] += val;
        } else if (b1 == 2 && !b2) {
          dp[u][state-(2<<j*2-2)] += val;
          if (j < m) dp[u][state-(2<<j*2-2)+(2<<j*2)] += val;
        } else if (b1 == 1 && b2 == 1) {
          dp[u][state-(1<<j*2-2)-(1<<j*2)] += val;
        }
      }
      if (i == ex && j == ey) return dp[u][0];
    }
  }
  return 0;
}

signed main() {
  ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
  int T = 1;
  // cin >> T;
  for (int t = 1; t <= T; ++t) {
    cout << solve() << endl;
  }
  return 0;
}