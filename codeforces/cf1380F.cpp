/*
 * @Author: Kaizyn
 * @Date: 2020-07-14 16:22:14
 * @LastEditTime: 2020-07-14 20:48:21
 */ 
#include <bits/stdc++.h>

// #define DEBUG

using namespace std;

const double eps = 1e-7;
const double PI = acos(-1);
typedef pair<int, int> pii;
const int MOD = 998244353;
const int INF = 0x3f3f3f3f;
const int N = 5e5+7;

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

int count(const int &k) { return k > 18 ? 0 : min(k, 9)-max(0, k-9)+1; }

struct SegmentTree {
  struct TreeNode {
    int l, r, lval, rval;
    mint lcnt, rcnt, mcnt, scnt;
    void init(const int &k) {
      lval = rval = k;
      lcnt = rcnt = 1;
      mcnt = 0;
      // scnt = count(k);
      scnt = min(k, 9)-max(0, k-9)+1;
    }
  } tr[N<<2];
  int n;
  void build(const int *a, const int &_n) { _build(a, 1, n = _n); }
  mint query(const int &l, const int &r) { return _query(l, r).scnt; }
  /*
  void push_up(const int &i) {
    tr[i].lval = tr[i<<1].lval;
    tr[i].rval = tr[i<<1|1].rval;
    int k = count(tr[i<<1].rval*10+tr[i<<1|1].lval);
    tr[i].scnt = tr[i<<1].scnt*tr[i<<1|1].scnt+tr[i<<1].lcnt*tr[i<<1|1].rcnt*k;
    tr[i].lcnt = tr[i<<1].scnt*tr[i<<1|1].lcnt+tr[i<<1].lcnt*tr[i<<1|1].mcnt*k;
    tr[i].rcnt = tr[i<<1].rcnt*tr[i<<1|1].scnt+tr[i<<1].mcnt*tr[i<<1|1].rcnt*k;
    tr[i].mcnt = tr[i<<1].rcnt*tr[i<<1|1].lcnt+tr[i<<1].mcnt*tr[i<<1|1].mcnt*k;
    #ifdef DEBUG
    printf("tr[%d]:", i);
    cout << tr[i].scnt << " " << tr[i].lcnt << " " << tr[i].rcnt << " " << tr[i].mcnt << endl;
    #endif
  }
  */
  TreeNode merge(const TreeNode &ls, const TreeNode &rs) {
    TreeNode rt;
    rt.l = ls.l;
    rt.r = rs.r;
    rt.lval = ls.lval;
    rt.rval = rs.rval;
    // int k = count(ls.rval*10+rs.lval);
    int k = ls.rval*10+rs.lval;
    k = k < 10 || k > 18 ? 0 : min(k, 9)-max(0, k-9)+1;
    rt.scnt = ls.scnt*rs.scnt+ls.lcnt*rs.rcnt*k;
    rt.lcnt = ls.scnt*rs.lcnt+ls.lcnt*rs.mcnt*k;
    rt.rcnt = ls.rcnt*rs.scnt+ls.mcnt*rs.rcnt*k;
    rt.mcnt = ls.rcnt*rs.lcnt+ls.mcnt*rs.mcnt*k;
    #ifdef DEBUG
    printf("[%d %d] ", rt.l, rt.r);
    cout << rt.scnt << " " << rt.lcnt << " " << rt.rcnt << " " << rt.mcnt << endl;
    #endif
    return rt;
  }
  void push_up(const int &i) { tr[i] = merge(tr[i<<1], tr[i<<1|1]); }
  void _build(const int *a, const int &l, const int &r, const int &i = 1) {
    tr[i].l = l; tr[i].r = r;
    if (l == r) return tr[i].init(a[l]);
    int mid = (l+r)>>1;
    _build(a, l, mid, i<<1);
    _build(a, mid+1, r, i<<1|1);
    push_up(i);
  }
  void update(const int &x, const int &k, const int i = 1) {
    if (tr[i].l == x && tr[i].r == x) return tr[i].init(k);
    int mid = (tr[i].l+tr[i].r)>>1;
    if (x <= mid) update(x, k, i<<1);
    else update(x, k, i<<1|1);
    push_up(i);
  }
  TreeNode _query(const int &l, const int &r, const int &i = 1) {
    if (tr[i].l >= l && tr[i].r <= r) return tr[i];
    int mid = (tr[i].l+tr[i].r)>>1;
    if (r <= mid) return _query(l, r, i<<1);
    if (l > mid) return _query(l, r, i<<1|1);
    return merge(_query(l, r, i<<1), _query(l, r, i<<1|1));
  }
};

int n, m;
int a[N];
string str;
SegmentTree ST;
set<int> head;

inline void solve() {
  cin >> n >> m >> str;
  for (int i = 1; i <= n; ++i) {
    a[i] = str[i-1]-'0';
    if (a[i]) head.insert(i);
  }
  ST.build(a, n);
  for (int i = 1, x, d; i <= m; ++i) {
    cin >> x >> d;
    if (d && a[x] == 0) head.insert(x);
    if (!d && a[x]) head.erase(x);
    a[x] = d;
    ST.update(x, d);
    if (head.empty()) cout << 1 << endl;
    else cout << ST.query(*head.begin(), n) << endl;
  }
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
/*
3 1
237
2 0

24
*/