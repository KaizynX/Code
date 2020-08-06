/*
 * @Author: Kaizyn
 * @Date: 2020-08-01 14:54:01
 * @LastEditTime: 2020-08-01 15:15:10
 */ 
#include <bits/stdc++.h>

// #define DEBUG

using namespace std;

const double eps = 1e-7;
const double PI = acos(-1);
typedef pair<int, int> pii;
const int MOD = 998244353;
const int INF = 0x3f3f3f3f;
const int N = 5e4+7;

template <typename T>
struct SegmentTree {
  int sz;
  T tr[N<<2], lazy[N<<2];
  SegmentTree(){}
  void build(const int &n, const T &k = 0) { sz = n; _build(1, n, k); }
  template <typename TT>
  void build(const TT a[], const int &n) { sz = n; _build(a, 1, n); }
  void modify(const int &x, const T &k) { _modify(x, k, 1, sz); }
  void add(const int &x, const T &k) { _add(x, x, k, 1, sz); }
  void add(int l, int r, const T &k) { if (l > r) swap(l, r); _add(l, r, k, 1, sz); }
  T query(const int &x) { return _query(x, x, 1, sz); }
  T query(int l, int r) { if (l > r) swap(l, r); return _query(l, r, 1, sz); }
private :
  void push_up(const int &i) { tr[i] = tr[i<<1]+tr[i<<1|1]; }
  void push_down(const int &i, const int &len) {
    if (!lazy[i]) return;
    tr[i<<1] += lazy[i]*(len-len/2);
    tr[i<<1|1] += lazy[i]*(len/2);
    lazy[i<<1] += lazy[i];
    lazy[i<<1|1] += lazy[i];
    lazy[i] = 0;
  }
  void _build(const int &l, const int &r, const T &k = 0, const int &i = 1) {
    lazy[i] = 0;
    if (l == r) { tr[i] = k; return; }
    int mid = (l+r)>>1;
    _build(l, mid, k, i<<1);
    _build(mid+1, r, k, i<<1|1);
    push_up(i);
  }
  template <typename TT>
  void _build(const TT a[], const int &l, const int &r, const int &i = 1) {
    lazy[i] = 0;
    if (l == r) { tr[i] = a[l]; return; }
    int mid = (l+r)>>1;
    _build(a, l, mid, i<<1);
    _build(a, mid+1, r, i<<1|1);
    push_up(i);
  }
  void _modify(const int &x, const T &k, const int &trl, const int &trr, const int &i = 1) {
    if (trl == x && trr == x) {
      tr[i] = k;
      lazy[i] = 0;
      return;
    }
    push_down(i, trr-trl+1);
    int mid = (trl+trr)>>1;
    if (x <= mid) _modify(x, k, trl, mid, i<<1);
    else _modify(x, k, mid+1, trr, i<<1|1);
    push_up(i);
  }
  void _add(const int &l, const int &r, const T &k, const int &trl, const int &trr, const int &i = 1) {
    if (trl >= l && trr <= r) {
      tr[i] += k*(trr-trl+1);
      lazy[i] += k;
      return;
    }
    push_down(i, trr-trl+1);
    int mid = (trl+trr)>>1;
    if (l <= mid) _add(l, r, k, trl, mid, i<<1);
    if (r >  mid) _add(l, r, k, mid+1, trr, i<<1|1);
    push_up(i);
  }
  T _query(const int &l, const int &r, const int &trl, const int &trr, const int &i = 1) {
    if (trl >= l && trr <= r) return tr[i];
    push_down(i, trr-trl+1);
    int mid = (trl+trr)>>1;
    T res = 0;
    if (l <= mid) res += _query(l, r, trl, mid, i<<1);
    if (r >  mid) res += _query(l, r, mid+1, trr, i<<1|1);
    return res;
  }
};

template <typename T>
struct ShuPou {
  int dfn;
  int fa[N], d[N], num[N], son[N], id[N], tp[N];
  SegmentTree<T> cnt, sum;
  template <typename Edge>
  void build(const Edge e[], const int &n, const int &rt = 1) {
    fa[rt] = dfn = 0;
    dfs1(e, rt);
    dfs2(e, rt);
    ST.build(n);
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
  void add_cnt(int x, const T &k) {
    while (x) {
      cnt.add(id[tp[x]], id[x], k);
      x = fa[tp[x]];
    }
  }
  void add_sum(const int &x) {
    sum.add(id[x], d[x]);
  }
  T query_cnt(const int &x) {
    return cnt.query(x);
  }
  T query_sum(const int &x) {
    return sum.query(x);
  }
  T query(int x) {
    int son_cnt = cnt.query(x);
    int son_sum = sum.query(x);
    int rt_cnt = -son_cnt*(d[x]-1)-cnt.query(1);
    while (x) {
      rt_cnt += cnt.query(id[tp[x]], id[x]);
      x = fa[tp[x]];
    }
  }
  void add(int x, int y, const T &k/*, const int &is_edge = 0*/)) {
    while (tp[x] != tp[y]) {
      if (d[tp[x]] < d[tp[y]]) swap(x, y);
      sum.add(id[tp[x]], id[x], k);
      x = fa[tp[x]];
    }
    if (d[x] > d[y]) swap(x, y);
    sum.add(id[x], id[y], k);
    // if (is_edge) ST.add(id[x], -k);
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
int a[N];
vector<int> e[N];
ShuPou<int> tree;

int query(const int &x) {
  int cnt = tree.query_cnt(x);
  int sum = tree.query_sum(x);
  int all = tree.query_sum(1);
}

inline void solve() {
  cin >> n >> m;
  for (int i = 1, u, v; i < n; ++i) {
    cin >> u >> v;
    e[u].emplace_back(v);
    e[v].emplace_back(u);
  }
  tree.build(e);
  for (int i = 1, opt, x, w; i <= m; ++i) {
    cin >> opt >> x;
    if (opt == 1) {
      cin >> w;
      tree.add_cnt(x);
      tree.add_sum(x, w);
    } else if (opt == 2) {
      ;
    } else if (opt == 3) {
      ;
    }
  }
  // clear
  for (int i = 1; i <= n; ++i) {
    e[i].clear();
    a[i] = 0;
  }
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