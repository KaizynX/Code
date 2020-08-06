/*
 * @Author: Kaizyn
 * @Date: 2020-07-28 10:26:21
 * @LastEditTime: 2020-07-31 16:36:48
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


namespace PST {
typedef int T;
typedef unsigned long long ull;
typedef pair<long long, long long> pll;
const int P = 50331653;
const int N = 160000+7;
const int NN = N*(log2(N)+5);
int rt[2][N], _sum[2][NN], _ls[2][NN], _rs[2][NN], _tot[2], sz;
ull _hash_val[2][NN], pw[N];

int _build(const int &id, const int &l, const int &r) {
  int &tot = _tot[id], *sum = _sum[id], *ls = _ls[id], *rs = _rs[id];
  ull *hash_val = _hash_val[id];

  int cur = ++tot;
  hash_val[cur] = sum[cur] = 0;
  if (l >= r) return cur;
  int mid = (l+r)>>1;
  ls[cur] = _build(id, l, mid);
  rs[cur] = _build(id, mid+1, r);
  return cur;
}
int _update(const int &id, const int &pre, const int &l, const int &r, const int &k) {
  int &tot = _tot[id], *sum = _sum[id], *ls = _ls[id], *rs = _rs[id];
  ull *hash_val = _hash_val[id];

  int cur = ++tot;
  ls[cur] = ls[pre]; rs[cur] = rs[pre]; sum[cur] = sum[pre]+1;
  if (l >= r) return hash_val[cur] = sum[cur], cur;
  int mid = (l+r)>>1;
  if (k <= mid) ls[cur] = _update(id, ls[pre], l, mid, k);
  else rs[cur] = _update(id, rs[pre], mid+1, r, k);
  hash_val[cur] = hash_val[rs[cur]]*pw[mid-l+1]+hash_val[ls[cur]];
  return cur;
}
bool _cmp(const int &id, const int &u, const int &v, const int &l, const int &r) {
  int *sum = _sum[id], *ls = _ls[id], *rs = _rs[id];
  ull *hash_val = _hash_val[id];

  if (l >= r) return sum[u] < sum[v];
  int mid = (l+r)>>1;
  if (hash_val[rs[u]] != hash_val[rs[v]]) return _cmp(id, rs[u], rs[v], mid+1, r);
  else return _cmp(id, ls[u], ls[v], l, mid);
}
bool _cmp(const int &u0, const int &u1, const int &v0, const int &v1, const int &l, const int &r) {
  if (l >= r) return _sum[0][u0]+_sum[1][u1] < _sum[0][v0]+_sum[1][v1];
  int mid = (l+r)>>1;
  if (_hash_val[0][_rs[0][u0]]+_hash_val[1][_rs[1][u1]] !=
      _hash_val[0][_rs[0][v0]]+_hash_val[1][_rs[1][v1]])
    return _cmp(_rs[0][u0], _rs[1][u1], _rs[0][v0], _rs[1][v1], mid+1, r);
  else return _cmp(_ls[0][u0], _ls[1][u1], _ls[0][v0], _ls[1][v1], l, mid);
}

void build(const int &n) {
  sz = n;
  pw[0] = 1;
  for (int i = 1; i <= n; ++i) pw[i] = pw[i-1]*P;
  _tot[0] = _tot[1] = 0;
  rt[0][0] = _build(0, 1, sz);
  rt[1][0] = _build(1, 1, sz);
}
void update(const int &id, const int &cur, const int &pre, const T &k) {
  rt[id][cur] = _update(id, rt[id][pre], 1, sz, k);
}
bool cmp(const int &id, const int &u, const int &v) {
  return _cmp(id, rt[id][u], rt[id][v], 1, sz);
}
bool cmp(const int &u0, const int &u1, const int &v0, const int &v1) {
  return _cmp(rt[0][u0], rt[1][u1], rt[0][v0], rt[1][v1], 1, sz);
}

}; // namespace PST

int n, q;
int a[N][N], lv[N][N], rv[N][N];
int sc[N][N], tc[N][N];
mint b[N][N], sv[N][N], tv[N][N], mv[N][N];

#ifdef DEBUG
template <typename T>
void print(T *a) {
  for (int i = 1; i <= n; ++i) {
    for (int j = 1; j <= n; ++j) {
      cout << a[i][j] << " \n"[j==n];
    }
  }
}
#endif

inline void solve() {
  cin >> n >> q;
  mint base = n*n;
  for (int i = 1; i <= n; ++i) {
    for (int j = 1; j <= n; ++j) {
      cin >> a[i][j];
      b[i][j] = base.pow(a[i][j]);
      sc[i][j] = tc[i][j] = 0;
      sv[i][j] = tv[i][j] = mv[i][j] = 0;
    }
  }
  PST::build(n*n);
  for (int i = 1; i <= n; ++i) {
    for (int j = 1; j <= n; ++j) {
      if (i > 1 && PST::cmp(0, sc[i][j], sc[i-1][j])) {
        sc[i][j] = sc[i-1][j];
        sv[i][j] = sv[i-1][j];
      }
      if (j > 1 && PST::cmp(0, sc[i][j], sc[i][j-1])) {
        sc[i][j] = sc[i][j-1];
        sv[i][j] = sv[i][j-1];
      }
      PST::update(0, (i-1)*n+j, sc[i][j], a[i][j]);
      sc[i][j] = (i-1)*n+j;
      sv[i][j] += b[i][j];
    }
  }
  for (int i = n; i; --i) {
    for (int j = n; j; --j) {
      if (i < n && PST::cmp(1, tc[i][j], tc[i+1][j])) {
        tc[i][j] = tc[i+1][j];
        tv[i][j] = tv[i+1][j];
      }
      if (j < n && PST::cmp(1, tc[i][j], tc[i][j+1])) {
        tc[i][j] = tc[i][j+1];
        tv[i][j] = tv[i][j+1];
      }
      PST::update(1, (i-1)*n+j, tc[i][j], a[i][j]);
      tc[i][j] = (i-1)*n+j;
      tv[i][j] += b[i][j];
    }
  }
  for (int i = 1; i <= n; ++i) {
    for (int j = 1; j <= n; ++j) mv[i][j] = sv[i][j]+tv[i][j]-b[i][j];
    lv[i][1] = 1;
    for (int j = 2; j <= n; ++j) {
      lv[i][j] = PST::cmp(sc[i][j], tc[i][j], sc[i][j-1], tc[i][j-1]) ? lv[i][j-1] : j;
    }
    rv[i][n] = n;
    for (int j = n-1; j; --j) {
      rv[i][j] = PST::cmp(sc[i][j], tc[i][j], sc[i][j+1], tc[i][j+1]) ? rv[i][j+1] : j;
    }
  }
#ifdef DEBUG
  cout << "************b************" << endl;
  print(b);
  cout << "************sv***********" << endl;
  print(sv);
  cout << "************tv***********" << endl;
  print(tv);
  cout << "************mv***********" << endl;
  print(mv);
  cout << "************lv***********" << endl;
  print(lv);
  cout << "************rv***********" << endl;
  print(rv);
  cout << "*************************" << endl;
#endif
  for (int i = 1, xl, xr, yl, yr, x, y; i <= q; ++i) {
    cin >> xl >> xr >> yl >> yr;
    x = y = -1;
    if (yl > 1 && xr < n) {
      x = xr+1;
      y = lv[x][yl-1];
    }
    if (yr < n && xl > 1) {
      int xx = xl-1, yy = rv[xx][yr+1];
      if (x == -1 || PST::cmp(sc[x][y], tc[x][y], sc[xx][yy], tc[xx][yy])) {
        x = xx;
        y = yy;
      }
    }
    cout << mv[x][y] << endl;
  }
}

signed main() {
  // freopen("1004.in", "r", stdin);
  // freopen("my.out", "w", stdout);
  ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
  int T = 1;
  cin >> T;
  for (int t = 1; t <= T; ++t) {
    solve();
  }
  return 0;
}