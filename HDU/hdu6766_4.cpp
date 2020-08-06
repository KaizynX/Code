/*
 * @Author: Kaizyn
 * @Date: 2020-07-31 19:59:02
 * @LastEditTime: 2020-07-31 22:46:03
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

typedef unsigned int U;
typedef unsigned long long ull;
U SX=335634763,SY=873658265,SZ=192849106,SW=746126501;
inline ull xorshift128(){
  U t=SX^(SX<<11);
  SX=SY;
  SY=SZ;
  SZ=SW;
  return SW=SW^(SW>>19)^t^(t>>8);
}
inline ull myrand(){return (xorshift128()<<32)^xorshift128();}

template <typename T>
struct PersistenceSegmentTree {
  static const int M = N*N*2;
  static const int NN = M*(log2(M)+5);
  int sum[NN], ls[NN], rs[NN], tot, sz;
  ull w[M], val[NN];
  void build(const int &n) {
    sz = n;
    tot = 0;
    for (int i = 1; i <= n; ++i) w[i] = myrand();
  }
  int insert(const int &pre, const T &k) {
    return _insert(pre, 1, sz, k);
  }
  bool cmp(const int &u0, const int &u1, const int &v0, const int &v1) {
    if (val[u0]+val[u1] == val[v0]+val[v1]) return false;
    return _cmp(u0, u1, v0, v1, 1, sz);
  }
private:
  int _insert(const int &pre, const int &l, const int &r, const int &k) {
    int cur = ++tot;
    ls[cur] = ls[pre]; rs[cur] = rs[pre];
    sum[cur] = sum[pre]+1; val[cur] = val[pre]+w[k];
    if (l >= r) return cur;
    int mid = (l+r)>>1;
    if (k <= mid) ls[cur] = _insert(ls[pre], l, mid, k);
    else rs[cur] = _insert(rs[pre], mid+1, r, k);
    return cur;
  }
  bool _cmp(const int &u0, const int &u1, const int &v0, const int &v1, const int &l, const int &r) {
    if (l >= r) return sum[u0]+sum[u1] < sum[v0]+sum[v1];
    int mid = (l+r)>>1;
    if (val[rs[u0]]+val[rs[u1]] == val[rs[v0]]+val[rs[v1]])
      return _cmp(ls[u0], ls[u1], ls[v0], ls[v1], l, mid);
    else return _cmp(rs[u0], rs[u1], rs[v0], rs[v1], mid+1, r);
  }
};

int n, q;
int a[N][N], lv[N][N], rv[N][N], sc[N][N], tc[N][N];
mint b[N][N], sv[N][N], tv[N][N], mv[N][N];
PersistenceSegmentTree<int> pst;

inline void solve() {
  cin >> n >> q;
  for (int i = 1; i <= n; ++i) {
    for (int j = 1; j <= n; ++j) {
      cin >> a[i][j];
    }
  }

  mint base = n*n;
  for (int i = 0; i <= n+1; ++i) {
    for (int j = 0; j <= n+1; ++j) {
      b[i][j] = base.pow(a[i][j]);
      sc[i][j] = tc[i][j] = lv[i][j], rv[i][j] = 0;
      sv[i][j] = tv[i][j] = mv[i][j] = 0;
    }
  }
  pst.build(n*n);
  for (int i = 1; i <= n; ++i) {
    for (int j = 1; j <= n; ++j) {
      // sc[i][j] = pst.cmp(sc[i-1][j], 0, sc[i][j-1], 0) ? sc[i][j-1] : sc[i-1][j];
      // sc[i][j] = pst.insert(sc[i][j], a[i][j]);
      if (pst.cmp(sc[i-1][j], 0, sc[i][j-1], 0)) {
        sc[i][j] = pst.insert(sc[i][j-1], a[i][j]);
        sv[i][j] = sv[i][j-1]+b[i][j];
      } else {
        sc[i][j] = pst.insert(sc[i-1][j], a[i][j]);
        sv[i][j] = sv[i-1][j]+b[i][j];
      }
    }
  }
  for (int i = n; i; --i) {
    for (int j = n; j; --j) {
      if (pst.cmp(tc[i+1][j], 0, tc[i][j+1], 0)) {
        tc[i][j] = pst.insert(tc[i][j+1], a[i][j]);
        tv[i][j] = tv[i][j+1]+b[i][j];
      } else {
        tc[i][j] = pst.insert(tc[i+1][j], a[i][j]);
        tv[i][j] = tv[i+1][j]+b[i][j];
      }
    }
  }
  for (int i = 1; i <= n; ++i) {
    for (int j = 1; j <= n; ++j)
      mv[i][j] = sv[i][j]+tv[i][j]-b[i][j];
    for (int j = 1; j <= n; ++j)
      lv[i][j] = pst.cmp(sc[i][j], tc[i][j], sc[i][j-1], tc[i][j-1]) ? lv[i][j-1] : j;
    for (int j = n; j; --j)
      rv[i][j] = pst.cmp(sc[i][j], tc[i][j], sc[i][j+1], tc[i][j+1]) ? rv[i][j+1] : j;
  }
  for (int i = 1, xl, xr, yl, yr; i <= q; ++i) {
    cin >> xl >> xr >> yl >> yr;
    --yl; ++xr; --xl; ++yr;
    yl = lv[++xr][yl-1];
    yr = rv[--xl][yr+1];
    cout << (pst.cmp(sc[xr][yl], tc[xr][yl], sc[xl][yr], tc[xl][yr]) ?
        mv[xl][yr] : mv[xr][yl]) << endl;
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