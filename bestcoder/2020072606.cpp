/*
 * @Author: Kaizyn
 * @Date: 2020-07-26 15:17:13
 * @LastEditTime: 2020-07-26 16:02:03
 */ 
#include <bits/stdc++.h>

// #define DEBUG

using namespace std;

const double eps = 1e-7;
const double PI = acos(-1);
typedef pair<int, int> pii;
const int MOD = 1e9+7;
const int INF = 0x3f3f3f3f;
const int N = 1e5+7;

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

int n, m;
int fa[N];
mint pm[N], p1[N];
vector<int> e[N];

void build(const int &u) {
  int t = e[u].size();
  for (const int &v : e[u]) if (v != fa[u]) {
    p1[v] = p1[u]/t;
    fa[v] = u;
    build(v);
  }
}

inline void solve() {
  cin >> n >> m;
  for (int i = 1, u, v; i < n; ++i) {
    cin >> u >> v;
    e[u].emplace_back(v);
    e[v].emplace_back(u);
  }
  p1[1] = 1;
  build(1);
  pm[m] = 1;
  mint res = p1[m];
  for (int i = m, t; fa[i]; i = fa[i]) {
    t = e[fa[i]].size();
    pm[fa[i]] = pm[i]/t;
    if (fa[i] == 1) {
      if (t != 1) res += pm[i]/t;
    } else {
      if (t != 2) res += p1[fa[i]]*(t-2)/t/(t-1)*pm[i];
    }
  }
  cout << res << endl;
  for (int i = 1; i <= n; ++i) {
    fa[i] = 0;
    vector<int>().swap(e[i]);
  }
}

signed main() {
  ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
  int T = 1;
  // cout << (mint)2/3 << endl;
  // cout << (mint)5/12 << endl;
  // cout << (mint)1/2 << endl;
  // cout << (mint)1/3 << endl;
  // cout << (mint)1/6 << endl;
  cin >> T;
  for (int t = 1; t <= T; ++t) {
    solve();
  }
  return 0;
}