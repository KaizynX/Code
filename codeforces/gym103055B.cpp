/*
 * @Author: Kaizyn
 * @Date: 2021-04-22 13:56:39
 * @LastEditTime: 2021-04-23 22:28:00
 */
#include <bits/stdc++.h>

// #define DEBUG

using namespace std;

const double eps = 1e-7;
const double PI = acos(-1);
typedef pair<int, int> pii;
typedef long long ll;
const int MOD = 998244353; // 1e9+7;
const int INF = 0x3f3f3f3f;
// const ll INF = 1e18;
const int N = 1e5+7;
const int C = 2e3+7;

template <typename T>
struct BinaryIndexedTree {
  int n;
  vector<T> tr;
  void init(const int &n) { this->n = n; tr = vector<T>(n+1, 0); }
  void add(const int &x, const T &v) { for (int i = x; i <= n; i += i&-i) tr[i] += v; }
  void add(const int &x, const int &y, const T &v) { add(x, v); add(y+1, -v); }
  T query(const int &x) { T res = 0; for (int i = x ; i; i -= i&-i) res += tr[i]; return res; }
  T query(const int &x, const int &y) { return query(y)-query(x-1); }
};

struct Rec {
  int xl, xr, yl, yr, id;
};

int n, m, q, tot;
int res[N];
vector<int> pt[N];
vector<pii> qq[N];
vector<Rec> r[C];
BinaryIndexedTree<int> bit;

struct SegmentTree {
  struct TreeNode {
    int l, r;
    priority_queue<pii, vector<pii>, greater<pii>> ql;
    priority_queue<pii, vector<pii>, less<pii>> qr;
    set<int> st;
  } tr[C<<2];
  set<int> stt;
  void build(int l, int r, int i = 1) {
    tr[i].l = l; tr[i].r = r;
    if (l == r) return;
    int mid = (l+r)/2;
    build(l, mid, i<<1);
    build(mid+1, r, i<<1|1);
  }
  void update(int l, int r, pii k, int i = 1) {
    if (tr[i].l >= l && tr[i].r <= r) {
      tr[i].ql.push(k);
      tr[i].qr.push(k);
      return;
    }
    int mid = (tr[i].l+tr[i].r)/2;
    if (l <= mid) update(l, r, k, i<<1);
    if (r >  mid) update(l, r, k, i<<1|1);
  }
  void dfs(int x, int mn = INF, int mx = -INF, int i = 1) {
    while (tr[i].ql.size() && tr[i].ql.top().second < x) tr[i].ql.pop();
    while (tr[i].qr.size() && tr[i].qr.top().second < x) tr[i].qr.pop();
    if (tr[i].ql.size()) mn = min(mn, tr[i].ql.top().first);
    if (tr[i].qr.size()) mx = max(mx, tr[i].qr.top().first);
    if (tr[i].l == tr[i].r) {
      if (mn <= n) {
        ++tot;
        pt[mn].emplace_back(mx);
      }
      return;
    }
    dfs(x, mn, mx, i<<1);
    dfs(x, mn, mx, i<<1|1);
  }
} tree;

inline void solve() {
  m = 2000;
  tree.build(1, m);
  scanf("%d%d", &n, &q);
  for (int i = 1; i <= n; ++i) {
    static Rec tmp;
    tmp.id = i;
    scanf("%d%d%d%d", &tmp.xl, &tmp.yl, &tmp.xr, &tmp.yr);
    ++tmp.xl; ++tmp.yl;
    r[tmp.xl].emplace_back(tmp);
  }
  for (int i = 1; i <= m; ++i) {
    for (auto &a : r[i]) {
      tree.update(a.yl, a.yr, pii{a.id, a.xr});
    }
    tree.dfs(i);
  }
  for (int i = 1, s, t; i <= q; ++i) {
    scanf("%d%d", &s, &t);
    qq[s].emplace_back(t, i);
  }
  bit.init(n);
  for (int i = n; i; --i) {
    for (auto &p : pt[i]) {
      bit.add(p, 1);
    }
    for (auto &p : qq[i]) {
      res[p.second] = tot-bit.query(p.first);
    }
  }
  for (int i = 1; i <= q; ++i) {
    printf("%d\n", res[i]);
  }
}

signed main() {
#ifdef ONLINE_JUDGE
  ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
#endif
  int T = 1;
  // cin >> T; // scanf("%d", &T);
  for (int t = 1; t <= T; ++t) {
    solve();
  }
  return 0;
}
/*
3 6
10 10 20 20
12 12 22 22
15 15 25 25
1 1
2 2
3 3
1 2
2 3
1 3
*/