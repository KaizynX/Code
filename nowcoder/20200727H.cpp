/*
 * @Author: Kaizyn
 * @Date: 2020-07-27 11:58:57
 * @LastEditTime: 2020-07-27 20:45:47
 */ 
#include <bits/stdc++.h>

// #define DEBUG

using namespace std;

const double eps = 1e-7;
const double PI = acos(-1);
typedef pair<int, int> pii;
const int MOD = 1e9+7;
const int INF = 0x3f3f3f3f;
const int N = 1e2+7;
const int M = 1e3;

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

int n;
int s[N];
mint dp[2][2][N][M<<1]; // [b == n][a == b][][a-b]
string str;

inline void solve() {
  cin >> str;
  n = str.size();
  for (int i = 1; i <= n; ++i) s[i] = str[i-1]-'0';
  dp[1][1][0][M] = 1;
  for (int i = 1, a, b; i <= n; ++i) {
    for (int j = M-900; j <= M+900; ++j) {
      for (b = 0; b <= 9; ++b) {
        for (a = 0; a <= 9; ++a) {
          dp[0][0][i][j+a-b] += dp[0][0][i-1][j];
          if (a == b) dp[0][1][i][j+a-b] += dp[0][1][i-1][j];
          if (a <  b) dp[0][0][i][j+a-b] += dp[0][1][i-1][j];
          if (b == s[i]) dp[1][0][i][j+a-b] += dp[1][0][i-1][j];
          if (b <  s[i]) dp[0][0][i][j+a-b] += dp[1][0][i-1][j];
          if (b == s[i] && a == b) dp[1][1][i][j+a-b] += dp[1][1][i-1][j];
          if (b == s[i] && a <  b) dp[1][0][i][j+a-b] += dp[1][1][i-1][j];
          if (b <  s[i] && a == b) dp[0][1][i][j+a-b] += dp[1][1][i-1][j];
          if (b <  s[i] && a <  b) dp[0][0][i][j+a-b] += dp[1][1][i-1][j];
        }
      }
    }
  }
  mint res = 0;
  for (int i = M+1; i <= M+900; ++i) {
    res += dp[0][0][n][i];
    res += dp[0][1][n][i];
    res += dp[1][0][n][i];
    res += dp[1][1][n][i];
  }
  cout << res << endl;
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