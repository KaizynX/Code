/*
 * @Author: Kaizyn
 * @Date: 2020-07-27 23:35:24
 * @LastEditTime: 2020-07-28 00:06:42
 */ 
#include <bits/stdc++.h>

// #define DEBUG

using namespace std;

const double eps = 1e-7;
const double PI = acos(-1);
typedef pair<int, int> pii;
const int MOD = 1e9+7;
const int INF = 0x3f3f3f3f;
const int N = 4e2+7;

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

int n, q;
int a[N][N], lv[N][N], rv[N][N];
vector<int> sc[N][N], tc[N][N], mc[N][N];
mint b[N][N], sv[N][N], tv[N][N], mv[N][N];

void add(vector<int> &v0, const vector<int> &v1, const vector<int> &v2) {
  for (int i = 0; i < n*n; ++i) v0[i] = v1[i]+v2[i];
}

inline void solve() {
  cin >> n >> q;
  for (int i = 1; i <= n; ++i) {
    for (int j = 1; j <= n; ++j) {
      static mint base = n*n;
      cin >> a[i][j];
      b[i][j] = base.pow(a[i][j]);
      vector<int>(n*n, 0).swap(sc[i][j]);
      vector<int>(n*n, 0).swap(tc[i][j]);
      vector<int>(n*n, 0).swap(mc[i][j]);
    }
  }
  for (int i = 1; i <= n; ++i) {
    for (int j = 1; j <= n; ++j) {
      if (i > 1 && sc[i-1][j] > sc[i][j]) {
        sc[i][j] = sc[i-1][j];
        sv[i][j] = sv[i-1][j];
      }
      if (j > 1 && sc[i][j-1] > sc[i][j]) {
        sc[i][j] = sc[i][j-1];
        sv[i][j] = sv[i][j-1];
      }
      ++sc[i][j][n*n-a[i][j]];
      sv[i][j] += b[i][j];
    }
  }
  for (int i = n; i; --i) {
    for (int j = n; j; --j) {
      if (i < n && tc[i+1][j] > tc[i][j]) {
        tc[i][j] = tc[i+1][j];
        tv[i][j] = tv[i+1][j];
      }
      if (j < n && tc[i][j+1] > tc[i][j]) {
        tc[i][j] = tc[i][j+1];
        tv[i][j] = tv[i][j+1];
      }
      ++tc[i][j][n*n-a[i][j]];
      tv[i][j] += b[i][j];
    }
  }
  for (int i = 1; i <= n; ++i) {
    for (int j = 1; j <= n; ++j) {
      add(mc[i][j], sc[i][j], tc[i][j]);
      --mc[i][j][n*n-a[i][j]];
      mv[i][j] = sv[i][j]+tv[i][j]-b[i][j];
    }
    lv[i][1] = 1;
    for (int j = 2; j <= n; ++j) {
      lv[i][j] = mc[i][j] > mc[i][j-1] ? j : lv[i][j-1];
    }
    rv[i][n] = n;
    for (int j = n-1; j; --j) {
      rv[i][j] = mc[i][j] > mc[i][j+1] ? j : rv[i][j+1];
    }
  }
  for (int i = 1, xl, xr, yl, yr, x, y; i <= q; ++i) {
    cin >> xl >> xr >> yl >> yr;
    x = y = -1;
    if (yl > 1 && xr < n) {
      x = xr+1;
      y = lv[x][yl-1];
    }
    if (yr < n && xl > 1) {
      if (x == -1 || mc[xl-1][rv[xl-1][yr+1]] > mc[x][y]) {
        x = xl-1;
        y = rv[x][yr+1];
      }
    }
    cout << mv[x][y] << endl;
  }
  // clear
  for (int i = 1; i <= n; ++i) {
    for (int j = 1; j <= n; ++j) {
      vector<int>().swap(sc[i][j]);
      vector<int>().swap(tc[i][j]);
      vector<int>().swap(mc[i][j]);
    }
  }
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