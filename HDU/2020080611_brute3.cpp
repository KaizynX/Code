/*
 * @Author: Kaizyn
 * @Date: 2020-08-06 15:31:49
 * @LastEditTime: 2020-08-06 21:35:21
 */
#include <bits/stdc++.h>

// #define DEBUG

using namespace std;

const double eps = 1e-7;
const double PI = acos(-1);
typedef pair<int, int> pii;
const int MOD = 31607;
const int INF = 0x3f3f3f3f;
const int N = 1e3+7;

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
int x[N], y[N];
mint p[N];

int cj(int x1, int y1, int x2, int y2) {
  return x1*y2-y1*x2;
}

inline void solve() {
  cin >> n;
  for (int i = 0, v; i < n; ++i) {
    cin >> x[i] >> y[i] >> p[i] >> v;
    p[i] /= v;
  }
  mint res = 0;
  for (int i = 0; i < n; ++i) {
    for (int j = 0; j < n; ++j) if (i != j) {
      mint tmp = p[i]*p[j]*cj(x[i], y[i], x[j], y[j]);
      for (int k = 0; k < n; ++k) if (k != i && k != j) {
        if (cj(x[k]-x[i], y[k]-y[i], x[j]-x[i], y[j]-y[i]) <= 0)
          tmp *= -p[k]+1;
      }
      res += tmp;
    }
  }
  cout << res/2 << endl; // abs???
  cout << -res/2 << endl; // abs???
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