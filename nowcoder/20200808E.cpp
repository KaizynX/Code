/*
 * @Author: Kaizyn
 * @Date: 2020-08-08 12:46:42
 * @LastEditTime: 2020-08-08 13:02:02
 */
#include <bits/stdc++.h>

// #define DEBUG

using namespace std;

const double eps = 1e-7;
const double PI = acos(-1);
typedef pair<int, int> pii;
const int MOD = 998244353;
const int INF = 0x3f3f3f3f;
const int N = 3e6+7;

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

int a, b, c, d, x, y;
map<int, int> mx, my;

void fac(int n, map<int, int> &mp) {
  mp.clear();
  for (int i = 2; i*i <= n; ++i) {
    if (n%i) continue;
    mp[i] = 0;
    while (n%i == 0) n/= i, ++mp[i];
  }
  if (n > 1) mp[n] = 1;
}

inline void solve() {
  cin >> a >> b >> c >> d >> x >> y;
  fac(x, mx);
  fac(y, my);
  mint res = 1, base, pw;
  for (const auto &p : mx) {
    int n = p.first;
    if (!my.count(n)) continue;
    int nx = mx[n], ny = my[n];
    // 公共的质因数 n
    base = mint(n).pow(nx);
    pw = base.pow(a);
    for (int i = a, j = c; i <= b; ++i, pw *= base) {
      // i*nx <= j*ny
      while (j <= d && j*ny < i*nx) ++j;
      res *= pw.pow(d-j+1);
    }
    base = mint(n).pow(ny);
    pw = base.pow(c);
    for (int j = c, i = a; j <= d; ++j, pw *= base) {
      // j*ny < i*nx
      while (i <= b && i*nx <= j*ny) ++i;
      // res *= mint(n).pow(j*ny).pow(b-i+1);
      res *= pw.pow(b-i+1);
    }
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