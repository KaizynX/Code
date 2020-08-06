/*
 * @Author: Kaizyn
 * @Date: 2020-08-01 11:51:25
 * @LastEditTime: 2020-08-01 12:47:48
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
// const int N = ;

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

// sigma n/i i=[1, min(n, k)]
mint calc(ll n, ll k) {
  mint res = 0;
  ll lim;
  for (ll i = 1, l, r; i*i <= n; ++i) {
    lim = i;
    // n/j == i
    l = max(1ll, n/(i+1));
    while (l-1 >= 1 && n/(l-1) == i) --l;
    while (n/l > i) ++l;
    r = n/i;
    while (r+1 <= n && n/(r+1) == i) ++r;
    while (n/r < i) --r;
    r = min(r, k);

    if (r >= l) res += i*(r-l+1);
    #ifdef DEBUG
    cout << i << " " << l << " " << r << endl;
    #endif
  }
  for (ll i = 1, t; i*i <= n && i <= k; ++i) {
    t = n/i;
    if (t > lim) res += t;
  }
  #ifdef DEBUG
  cout << n << " " << k << " " << res << endl;
  cout << "*******" << endl;
  #endif
  return res;
}

inline void solve() {
  ll n, k;
  cin >> n >> k;
  // for (n = 1; n <= 10; ++n) for (k = 1; k <= 10; ++k) {
  mint res = calc(n, k)+calc(n-1, k)-(n-1)+(k-1);
  cout << res << endl;
  // }
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