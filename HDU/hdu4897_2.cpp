/*
 * @Author: Kaizyn
 * @Date: 2020-06-09 15:48:30
 * @LastEditTime: 2020-06-09 22:58:35
 */ 
#include <bits/stdc++.h>

// #define DEBUG

using namespace std;

const double eps = 1e-7;
const double PI = acos(-1);
typedef pair<int, int> pii;
const int MOD = 998244353;
const int INF = 0x3f3f3f3f;
const int N = 1e5+7;

template <typename T>
struct SegmentTree {
  int sz;
  T tr[N<<2], lazy[N<<2];
  SegmentTree(){}
  void build(const int &n, const T &k = 0) { sz = n; _build(1, n, k); }
  void update(const int &x) { _update(x, x, 1, sz); }
  void update(int l, int r) { if (l > r) swap(l, r); _update(l, r, 1, sz); }
  T query(const int &x) { return _query(x, x, 1, sz); }
  T query(int l, int r) { if (l > r) swap(l, r); return _query(l, r, 1, sz); }
private :
  void push_up(const int &i) { tr[i] = tr[i<<1]+tr[i<<1|1]; }
  void push_down(const int &i, const int &len) {
    if (!lazy[i]) return;
    tr[i<<1] = (len-len/2)-tr[i<<1];
    tr[i<<1|1] = (len/2)-tr[i<<1|1];
    lazy[i<<1] ^= lazy[i];
    lazy[i<<1|1] ^= lazy[i];
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
  void _update(const int &l, const int &r, const int &trl, const int &trr, const int &i = 1) {
    if (trl >= l && trr <= r) {
      tr[i] = (trr-trl+1)-tr[i];
      lazy[i] ^= 1;
      return;
    }
    push_down(i, trr-trl+1);
    int mid = (trl+trr)>>1;
    if (l <= mid) _update(l, r, trl, mid, i<<1);
    if (r >  mid) _update(l, r, mid+1, trr, i<<1|1);
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
  SegmentTree<T> hv, lt;
  template <typename Edge>
  void build(const Edge e[], const int &n, const int &rt = 1) {
    fa[rt] = dfn = 0;
    dfs1(e, rt);
    dfs2(e, rt);
    hv.build(n, 0);
    lt.build(n, 0);
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
  void update1(int x, int y) {
    while (tp[x] != tp[y]) {
      if (d[tp[x]] < d[tp[y]]) swap(x, y);
      hv.update(id[tp[x]], id[x]);
      x = fa[tp[x]];
    }
    if (d[x] > d[y]) swap(x, y);
    if (x != y) hv.update(id[son[x]], id[y]);
  }
  void update2(int x, int y) {
    while (tp[x] != tp[y]) {
      if (d[tp[x]] < d[tp[y]]) swap(x, y);
      lt.update(id[tp[x]], id[x]);
      hv.update(id[tp[x]]);
      if (son[x]) hv.update(id[son[x]]);
      x = fa[tp[x]];
    }
    if (d[x] > d[y]) swap(x, y);
    lt.update(id[x], id[y]);
    hv.update(id[x]);
    if (son[y]) hv.update(id[son[y]]);
  }
  T query(int x, int y) {
    T res = 0;
    while (tp[x] != tp[y]) {
      if (d[tp[x]] < d[tp[y]]) swap(x, y);
      if (tp[x] != x) res += hv.query(id[son[tp[x]]], id[x]);
      // res += hv.query(id[tp[x]])^lt.query(id[tp[x]])^lt.query(id[fa[tp[x]]]);
      res += hv.query(id[tp[x]])^lt.query(id[fa[tp[x]]]);
      x = fa[tp[x]];
    }
    // must be heavy chain
    if (d[x] > d[y]) swap(x, y);
    if (x != y) res += hv.query(id[son[x]], id[y]);
    return res;
  }
};

int n, q;
vector<int> e[N];
ShuPou<int> tree;

inline void solve() {
  scanf("%d", &n);
  for (int i = 1, u, v; i < n; ++i) {
    scanf("%d %d", &u, &v);
    e[u].emplace_back(v);
    e[v].emplace_back(u);
  }
  tree.build(e, n);
  scanf("%d", &q);
  for (int i = 1, op, x, y; i <= q; ++i) {
    scanf("%d%d%d", &op, &x, &y);
    if (op == 1) {
      tree.update1(x, y);
    } else if (op == 2) {
      tree.update2(x, y);
    } else {
      printf("%d\n", tree.query(x, y));
    }
  }
  for (int i = 1; i <= n; ++i) {
    vector<int>().swap(e[i]);
  }
}

signed main() {
  int T = 1;
  scanf("%d", &T);
  for (int t = 1; t <= T; ++t) {
    solve();
  }
  return 0;
}