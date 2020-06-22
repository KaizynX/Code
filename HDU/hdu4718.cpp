/*
 * @Author: Kaizyn
 * @Date: 2020-06-10 11:25:55
 * @LastEditTime: 2020-06-10 14:51:29
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

struct Node {
  int l, r;
  int lval, rval;
  int lcis, rcis, mcis;
  int lcds, rcds, mcds;
  Node() {}
  int len() { return r-l+1; }
  void init(const int &val = 0) {
    tr[i].lval = tr[i].rval = val;
    tr[i].lcis = tr[i].rcis = tr[i].mcis = 1;
    tr[i].lcds = tr[i].rcds = tr[i].mcds = 1;
  }
  Node merge(const Node &ls, const Node &rs) {
    Node rt;
    rt.l = ls.l;
    rt.r = rs.r;
    rt.lval = ls.lval;
    rt.rval = rs.rval;

    rt.lcis = ls.lcis;
    rt.rcis = rs.rcis;
    rt.mcis = max(ls.mcis, rs.mcis);
    if (ls.rval < rs.lval) {
      if (ls.lcis == ls.len()) rt.rcis += rs.lcis;
      if (rs.rcis == rs.len()) rt.rcis += ls.rcis;
      rt.mcis = max(rt.mcis, ls.rcis+rs.lcis);
    }
    rt.lcds = ls.lcds;
    rt.rcds = rs.rcds;
    rt.mcds = max(ls.mcds, rs.mcds);
    if (ls.rval > rs.lval) {
      if (ls.lcds == ls.len()) rt.rcds += rs.lcds;
      if (rs.rcds == rs.len()) rt.rcds += ls.rcds;
      rt.mcds = max(rt.mcds, ls.rcds+rs.lcds);
    }
    return rt;
  }
};

struct SegmentTree {
  Node tr[N<<2];
  int n;
  template <typename TT>
  void build(const TT a[], const int &_n) { _build(a, 1, n = _n, i); }
  template <typename TT>
  void _build(const TT a[], const int &l, const int &r, const int &i = 1) {
    if (l == r) return tr[i].l = l, tr[i].r = r, tr[i].init(a[l]);
    int mid = (l+r)>>1;
    _build(a, l, mid, i<<1);
    _build(a, mid+1, r, i<<1|1);
    tr[i] = merge(tr[i<<1], tr[i<<1|1]);
  }
  Node query(const int &l, const int &r, const int &i = 1) {
    if (tr[i].l >= l && tr[i].r <= r) return tr[i];
    int mid = (tr[i].l+tr[i].r)>>1;
    if (r <= mid) return query(l, r, i<<1);
    if (l >  mid) return query(l, r, i<<1|1);
    return merge(merge(query(l, r, i<<1), query(l, r, i<<1|1)));
  }
};

template <typename T>
struct ShuPou {
  int dfn;
  int fa[N], d[N], num[N], son[N], id[N], tp[N];
  T init_val[N];
  SegmentTree ST;
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
  T query(int x, int y) {
    Node res;
    while (tp[x] != tp[y]) {
      if (d[tp[x]] >= d[tp[y]]) {
        res += ST.query(id[tp[x]], id[x]);
        x = fa[tp[x]];
      } else {
        y = fa[tp[y]];
      }
    }
    if (d[x] > d[y]) swap(x, y);
    return res+ST.query(id[x], id[y]);
  }
};

int n, q;
int a[N];
vector<int> e[N];
ShuPou<int> tree;

inline void solve() {
  cin >> n;
  for (int i = 1; i <= n; ++i) cin >> a[i];
  for (int i = 1, fa; i <= n; ++i) {
    cin >> fa;
    e[fa].emplace_back(i);
  }
  tree.build(e, a, n);
  cin >> q;
  for (int i = 1, u, v; i <= n; ++i) {
    cin >> u >> v;
    cout << tree.query(u, v) << endl;
  }
  for (int i = 1; i <= n; ++i) {
    vector<int>().swap(e[i]);
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