/*
 * @Author: Kaizyn
 * @Date: 2020-06-20 20:58:20
 * @LastEditTime: 2020-06-21 15:37:03
 */ 
#include <bits/stdc++.h>

// #define DEBUG

using namespace std;

const double eps = 1e-7;
const double PI = acos(-1);
typedef pair<int, int> pii;
const int MOD = 998244353;
const int INF = 0x3f3f3f3f;
const int N = 3e2+7;

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

int n, k;
string s;
int cnt[N];
mint dp[N][N][N];
// dp[i][j][l] come to i'th, take j's 1, l's dif
vector<int> p;

inline void solve() {
  cin >> s >> k;
  while (s.size() && s.back() == '0') s.pop_back();
  s.push_back('0');
  p.emplace_back(0);
  for (int i = 0; i < (int)s.size(); ++i) {
    if (s[i] == '0') {
      p.emplace_back(i+1);
    }
  }
  n = p.size()-1;
  dp[0][0][0] = 1;
  int all_ones = p[n]-n;
  k = min(k, all_ones);
  for (int i = 1; i <= n; ++i) {
    int sum_ones = p[i]-i, pre_ones = p[i]-p[i-1]-1;
    for (int j = sum_ones; j <= all_ones; ++j) {
      for (int jj = 0; jj <= j; ++jj) {
        for (int l = 0; l <= k; ++l) {
          if (jj <= pre_ones) dp[i][j][l] += dp[i-1][j-jj][l];
          else if (l >= jj-pre_ones) dp[i][j][l] += dp[i-1][j-jj][l-(jj-pre_ones)];
        }
      }
    }
  }
  mint res = 0;
  for (int i = 0; i <= k; ++i) {
    res += dp[n][all_ones][i];
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