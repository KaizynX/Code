/*
 * @Author: Kaizyn
 * @Date: 2020-07-08 20:28:34
 * @LastEditTime: 2020-07-11 21:09:23
 */ 
#include <bits/stdc++.h>

// #define DEBUG

using namespace std;

const double eps = 1e-7;
const double PI = acos(-1);
typedef pair<int, int> pii;
const int MOD = 1e9+7;
const int INF = 0x3f3f3f3f;
const int N = 2e5+7;

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
long long a[N];

inline void solve() {
  cin >> n >> k;
  for (int i = 1; i <= n; ++i) {
    cin >> a[i];
  }
  sort(a+1, a+n+1, [](const int &x, const int &y) {
      return abs(x) > abs(y);
  });

  if (a[k] == 0) return cout << 0 << endl, void();
  mint res = 1;
  int tag = 0;
  long long lp = 0, rp = 0, ln = 0, rn = 0;
  for (int i = 1; i <= k; ++i) {
    res *= a[i];
    if (a[i] < 0) {
      tag ^= 1;
      ln = ln == 0 ? a[i] : max(ln, a[i]);
    } else {
      lp = lp == 0 ? a[i] : min(lp, a[i]);
    }
  }
  for (int i = k+1; i <= n; ++i) {
    if (a[i] == 0) break;
    else if (a[i] < 0) {
      rn = min(rn, a[i]);
    } else {
      rp = max(rp, a[i]);
    }
  }
  if (tag) {
    if (ln && rp && lp && rn) {
      // max(-rp/ln, -rn/lp)
      if (-rp*lp > -rn*ln) res *= rp, res /= ln;
      else res *= rn, res /= lp;
    } else if (ln && rp) {
      res /= ln;
      res *= rp;
    } else if (lp && rn) {
      res /= lp;
      res *= rn;
    } else {
      ;
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