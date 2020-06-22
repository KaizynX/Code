/*
 * @Author: Kaizyn
 * @Date: 2020-06-10 11:25:55
 * @LastEditTime: 2020-06-10 19:53:29
 */ 
#include <bits/stdc++.h>

#define DEBUG

using namespace std;

const double eps = 1e-7;
const double PI = acos(-1);
typedef pair<int, int> pii;
const int MOD = 998244353;
const int INF = 0x3f3f3f3f;
const int N = 1e5+7;

struct Node {
  int len = 0, lv, rv;
  int lcs, rcs, mcs;
  void init(const int &val) {
    len = 1;
    lv = rv = val;
    lcs = rcs = mcs = 1;
  }
  void reverse() {
    swap(lv, rv);
    swap(lcs, rcs);
  }
  // 0 for increase 1 for decrease
  friend Node merge(const Node &ls, const Node &rs, const int &k) {
    if (ls.len == 0) return rs;
    if (rs.len == 0) return ls;
    Node rt;
    rt.len = ls.len+rs.len;
    rt.lv = ls.lv;
    rt.rv = rs.rv;
    rt.lcs = ls.lcs;
    rt.rcs = rs.rcs;
    rt.mcs = max(ls.mcs, rs.mcs);
    if ((k == 0 && ls.rv < rs.lv) || (k == 1 && ls.rv > rs.lv)) {
      if (ls.lcs == ls.len) rt.lcs += rs.lcs;
      if (rs.rcs == rs.len) rt.rcs += ls.rcs;
      rt.mcs = max(rt.mcs, ls.rcs+rs.lcs);
      // rt.mcs = max({rt.mcs, ls.rcs+rs.lcs, rt.lcs, rt.rcs});
    }
    return rt;
  }
  #ifdef DEBUG
  void print() {
    cout << "(" << len << " " << lv << " " << rv << ") ("
        << lcs << " " << rcs << " " << mcs << ")" << endl;
  }
  #endif
};

struct SegmentTree {
  struct TreeNode {
    int l, r;
    Node cs[2];
    void init(const int &val) {
      cs[0].init(val);
      cs[1].init(val);
    }
  } tr[N<<2];
  void push_up(const int &i) {
    tr[i].cs[0] = merge(tr[i<<1].cs[0], tr[i<<1|1].cs[0], 0);
    tr[i].cs[1] = merge(tr[i<<1].cs[1], tr[i<<1|1].cs[1], 1);
  }
  template <typename TT>
  void build(const TT a[], const int &l, const int &r, const int &i = 1) {
    tr[i].l = l; tr[i].r = r;
    if (l == r) return tr[i].init(a[l]);
    int mid = (l+r)>>1;
    build(a, l, mid, i<<1);
    build(a, mid+1, r, i<<1|1);
    push_up(i);
  }
  Node query(const int &l, const int &r, const int &k, const int &i = 1) {
    if (tr[i].l >= l && tr[i].r <= r) return tr[i].cs[k];
    int mid = (tr[i].l+tr[i].r)>>1;
    if (r <= mid) return query(l, r, k, i<<1);
    if (l >  mid) return query(l, r, k, i<<1|1);
    return merge(query(l, r, k, i<<1), query(l, r, k, i<<1|1), k);
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
    ST.build(init_val, 1, n);
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
    Node cis, cds;
    while (tp[x] != tp[y]) {
      if (d[tp[x]] > d[tp[y]]) {
        cds = merge(ST.query(id[tp[x]], id[x], 1), cds, 1);
        x = fa[tp[x]];
      } else {
        cis = merge(ST.query(id[tp[y]], id[y], 0), cis, 0);
        y = fa[tp[y]];
      }
    }
    if (d[x] < d[y]) {
      cis = merge(ST.query(id[x], id[y], 0), cis, 0);
    } else {
      cds = merge(ST.query(id[y], id[x], 1), cds, 1);
    }
    cds.reverse();
    return merge(cds, cis, 0).mcs;
  }
};

int n, q;
int a[N];
vector<int> e[N];
ShuPou<int> tree;

inline void solve() {
  cin >> n;
  for (int i = 1; i <= n; ++i) cin >> a[i];
  for (int i = 2, fa; i <= n; ++i) {
    cin >> fa;
    e[fa].emplace_back(i);
  }
  tree.build(e, a, n);
  cin >> q;
  for (int i = 1, u, v; i <= q; ++i) {
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
    cout << "Case #" << t << ":\n";
    solve();
    if (t < T) cout << endl;
  }
  return 0;
}