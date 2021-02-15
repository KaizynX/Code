/*
 * @Author: Kaizyn
 * @Date: 2021-02-09 18:45:27
 * @LastEditTime: 2021-02-09 18:54:23
 */
#include <bits/stdc++.h>

// #define DEBUG

using namespace std;

const double eps = 1e-7;
const double PI = acos(-1);
typedef pair<int, int> pii;
typedef long long ll;
const int MOD = 998244353;
const int INF = 0x3f3f3f3f;
// const ll INF = 1e18;
const int N = 1e5+7;

struct DSU {
  int fa[N];
  void init(int n) { iota(fa, fa+n+1, 0); }
  int get(int s) { return s == fa[s] ? s : fa[s] = get(fa[s]); }
  int& operator [] (int i) { return fa[get(i)]; }
  bool merge(int x, int y) { // merge x to y
    int fx = get(x), fy = get(y);
    if (fx == fy) return false;
    fa[fx] = fy; return true;
  }
};

template <typename T, typename U = greater<T>>
struct SegmentTree {
  SegmentTree(){}
  void build(const int &_n, const T &k = 0) { n = _n; _build(1, n, k); }
  template <typename TT>
  void buiil(const int _n, const TT a[]) { n = _n; _build(1, n, a); }
  void modify(const int &x, const T &k) { _modify(x, x, k); }
  void modify(const int &l, const int &r, const T &k) { _modify(l, r, k); }
  void add(const int &x, const T &k) { _add(x, k); }
  T query(const int &x) { return _query(x, x); }
  T query(const int &l, const int &r) { return _query(l, r); }
private:
  struct TreeNode
  {
    int l, r;
    T v, lazy;
  } tr[N<<2];
  int n;
  T init_val = cmp(0, 1) ? INF : -INF;
  U cmp = U();
  T mv(const T &x, const T &y) { return cmp(x, y) ? x : y;}
  void update(const int &i, const T &k) { tr[i].v = mv(tr[i].v, k); tr[i].lazy = mv(tr[i].lazy, k); }
  void push_up(const int &i) { tr[i].v = mv(tr[i<<1].v, tr[i<<1|1].v); }
  void push_down(const int &i) {
    if (tr[i].lazy == init_val) return;
    update(i<<1, tr[i].lazy);
    update(i<<1|1, tr[i].lazy);
    tr[i].lazy = init_val;
  }
  void _build(const int &l, const int &r, const T &k = 0, const int &i = 1) {
    tr[i].lazy = init_val;
    tr[i].l = l; tr[i].r = r;
    if (l == r) { tr[i].v = k; return; }
    int mid = (l+r)>>1;
    _build(l, mid, k, i<<1);
    _build(mid+1, r, k, i<<1|1);
    push_up(i);
  }
  template <typename TT>
  void _build(const int &l, const int &r, const TT a[], const int &i = 1) {
    tr[i].lazy = init_val;
    tr[i].l = l; tr[i].r = r;
    if (l == r) { tr[i].v = a[l]; return; }
    int mid = (l+r)>>1;
    _build(l, mid, a, i<<1);
    _build(mid+1, r, a, i<<1|1);
    push_up(i);
  }
  void _modify(const int &l, const int &r, const T &k, const int &i = 1) {
    if (tr[i].l  >= l && tr[i].r <= r) { update(i, k); return; }
    push_down(i);
    int mid = (tr[i].l+tr[i].r)>>1;
    if (l <= mid) _modify(l, r, k, i<<1);
    if (r >  mid) _modify(l, r, k, i<<1|1);
    push_up(i);
  }
  void _add(const int &x, const T &k, const int &i = 1) {
    if (tr[i].l == x && tr[i].r == x) { tr[i].v += k; return; }
    push_down(i);
    int mid = (tr[i].l+tr[i].r)>>1;
    if (x <= mid) _add(x, k, i<<1);
    else _add(x, k, i<<1|1);
    push_up(i);
  }
  T _query(const int &l, const int &r, const int &i = 1) {
    if (tr[i].l  >= l && tr[i].r <= r) return tr[i].v;
    push_down(i);
    int mid = (tr[i].l+tr[i].r)>>1;
    T res = init_val;
    if (l <= mid) res = mv(res, _query(l, r, i<<1));
    if (r >  mid) res = mv(res, _query(l, r, i<<1|1));
    return res;
  }
};

template <typename T>
struct HLD {
  int dfn;
  int fa[N], d[N], num[N], son[N], id[N], tp[N];
  T init_val[N];
  SegmentTree<T> ST;
  template <typename Edge, typename TT>
  void build(const Edge e[], const TT a[], const int &n, const int &rt = 1) {
    fa[rt] = dfn = 0;
    dfs1(e, rt);
    dfs2(e, rt);
    for (int i = 1; i <= n; ++i)
      init_val[id[i]] = a[i];
    ST.build(init_val, n);
  }
  template <typename Edge>
  void dfs1(const Edge e[], const int &u = 1) {
    d[u] = d[fa[u]]+1;
    num[u] = 1;
    son[u] = 0;
    for (const int &v : e[u]) if (v != fa[u]) {
      fa[v] = u;
      dfs1(e, v);
      num[u] += num[v];
      if (num[v] > num[son[u]]) son[u] = v;
    }
  }
  template <typename Edge>
  void dfs2(const Edge e[], const int &u = 1) {
    tp[u] = son[fa[u]] == u ? tp[fa[u]] : u;
    id[u] = ++dfn;
    if (son[u]) dfs2(e, son[u]);
    for (const int &v : e[u]) if (v != son[u] && v != fa[u])
      dfs2(e, v);
  }
  void add_sons(const int &x, const T &k) { ST.add(id[x], id[x]+num[x]-1, k); }
  void add(int x, int y, const T &k, const int &is_edge = 0) {
    while (tp[x] != tp[y]) {
      if (d[tp[x]] < d[tp[y]]) swap(x, y);
      ST.add(id[tp[x]], id[x], k);
      x = fa[tp[x]];
    }
    if (d[x] > d[y]) swap(x, y);
    ST.add(id[x], id[y], k);
    if (is_edge) ST.add(id[x], -k);
  }
  T query_sons(const int &x) { return ST.query(id[x], id[x]+num[x]-1); }
  T query(const int &x) { return ST.query(id[x]); }
  T query(int x, int y) {
    T res = 0;
    while (tp[x] != tp[y]) {
      if (d[tp[x]] < d[tp[y]]) swap(x, y);
      res += ST.query(id[tp[x]], id[x]);
      x = fa[tp[x]];
    }
    if (d[x] > d[y]) swap(x, y);
    return res+ST.query(id[x], id[y]);
  }
};

int n, m;
int u[N], v[N], w[N], rk[N], a[N];
vector<int> e[N];
DSU dsu;
HLD<int> hld;

inline void solve() {
  // cin >> n >> m;
  scanf("%d%d", &n, &m);
  for (int i = 1; i <= m; ++i) {
    // cin >> u[i] >> v[i] >> w[i];
    scanf("%d%d%d", u+i, v+i, w+i);
    if (u[i] > v[i]) swap(u[i], v[i]);
  }
  dsu.init(n);
  iota(rk+1, rk+m+1);
  sort(rk+1, rk+m+1, [&](int x, int y) {
    return w[x] < w[y];
  });
  ll base = 0;
  for (int _ = 1, i; _ <= m; ++_) {
    i = rk[_];
    if (dsu[u[i]] == dsu[v[i]]) continue;
    dsu.merge(u[i], v[i]);
    base += w[i];
    e[u[i]].emplace_back(v[i]);
    e[v[i]].emplace_back(u[i]);
  }
  hld.build(e, a, n);
  for (int i = 1; i <= m; ++i) {
    printf("%lld\n", base+w[i]-hld.query(u[i], v[i]));
  }
}

signed main() {
#ifdef ONLINE_JUDGE
  ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
#endif
  int T = 1;
  // cin >> T;
  for (int t = 1; t <= T; ++t) {
    solve();
  }
  return 0;
}