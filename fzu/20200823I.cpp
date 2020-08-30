/*
 * @Author: Kaizyn
 * @Date: 2020-08-23 12:40:06
 * @LastEditTime: 2020-08-23 16:21:15
 */
#include <set>
#include <map>
#include <list>
#include <queue>
#include <cmath>
#include <ctime>
#include <string>
#include <cstdio>
#include <cctype>
#include <vector>
#include <cstring>
#include <cstdlib>
#include <iostream>
#include <algorithm>
//#include<chrono>
//#include<unordered_set>
//#include<unordered_map>

// #define DEBUG
using namespace std;

const double eps = 1e-7;
const double PI = acos(-1);
typedef pair<int, int> pii;
const int MOD = 998244353;
const int INF = 0x3f3f3f3f;
const int N = 1e6+7;

template <int _MOD> struct Mint {
  int v;
  Mint(long long _v = 0) : v(static_cast<int>((_v%_MOD+_MOD)%_MOD)) {}
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

struct Combination {
  int fac[N], inv[N];
  void init(const int &n) {
    fac[0] = inv[0] = fac[1] = inv[1] = 1;
    for (int i = 2; i <= n; ++i) {
      fac[i] = 1ll*fac[i-1]*i%MOD;
      inv[i] = 1ll*(MOD-MOD/i)*inv[MOD%i]%MOD;
    }
    for (int i = 2; i <= n; ++i) {
      inv[i] = 1ll*inv[i]*inv[i-1]%MOD;
    }
  }
  int A(const int &p, const int &q) {
    return p >= q ? 1ll*fac[p]*inv[p-q]%MOD : 0;
  }
  int C(const int &p, const int &q) {
    return p >= q ? 1ll*fac[p]*inv[q]%MOD*inv[p-q]%MOD : 0;
  }
};

int n;
mint res[N];

inline void init() {
  res[1] = 6; res[2] = 30;
  for (int i = 3; i <= 1000000; ++i) {
    res[i] = res[i-1]*(i+1)*(7*i-4)+res[i-2]*8*(i-2)*(i-2);
    res[i] /= i*(i+1ll);
  }
}

signed main() {
  // comb.init(3000000);
  init();
  ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
  while (cin >> n) cout << res[n] << endl;
  /*
  int T = 1;
  // cin >> T;
  for (int t = 1; t <= T; ++t) {
    solve();
  }
  */
  return 0;
}