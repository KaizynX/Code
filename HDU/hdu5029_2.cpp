/*
 * @Author: Kaizyn
 * @Date: 2020-06-04 19:18:16
 * @LastEditTime: 2020-06-05 23:16:19
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
  int n;
  struct TreeNode {
    int l, r, v, lazy;
    pair<T, int> mv;
  } tr[N<<2];
  void push_down(const int &i, const int &z) {
    tr[i<<1].v += tr[i].lazy;
    tr[i<<1|1].v += tr[i].lazy;
    tr[i<<1].lazy += tr[i].lazy;
    tr[i<<1|1].lazy += tr[i].lazy;
    tr[i<<1].mv = max(tr[i<<1].mv, {tr[i<<1].v, z});
    tr[i<<1|1].mv = max(tr[i<<1|1].mv, {tr[i<<1|1].v, z});
    tr[i].lazy = 0;
  }
  void build(const int &_n) { n = _n; build(1, n); }
  void build(const int &l, const int &r, const int &i = 1) {
    tr[i].l = l; tr[i].r = r;
    tr[i].v = tr[i].lazy = 0;
    tr[i].mv = {0, 0};
    if (l == r) return;
    int mid = (l+r)>>1;
    build(l, mid, i<<1);
    build(mid+1, r, i<<1|1);
  }
  void add(const int &l, const int &r, const int &k,
      const int &z, const int &i = 1) {
    if (l <= tr[i].l && r >= tr[i].r) {
      tr[i].v += k;
      tr[i].lazy += k;
      tr[i].mv = max(tr[i].mv, {tr[i].v, z});
      return;
    }
    push_down(i, z);
    int mid = (tr[i].l+tr[i].r)>>1;
    if (l <= mid) add(l, r, k, z, i<<1);
    if (r >  mid) add(l, r, k, z, i<<1|1);
  }
  pair<T, int> query(const int &x, const int &i = 1) {
    if (tr[i].l == x && tr[i].r == x) return tr[i].mv;
    int mid = (tr[i].l+tr[i].r)>>1;
    pair<T, int> res = tr[i].mv;
    if (x <= mid) res = max(res, query(x, i<<1));
    else res = max(res, query(x, i<<1|1));
    return res;
  }
};

template <typename T>
struct ShuPou {
  int dfn;
  int fa[N], d[N], num[N], son[N], id[N], tp[N];
  SegmentTree<T> ST;
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
  void add(int x, int y, const T &k, const int &z) {
    while (tp[x] != tp[y]) {
      if (d[tp[x]] < d[tp[y]]) swap(x, y);
      ST.add(id[tp[x]], id[x], k, -z);
      x = fa[tp[x]];
    }
    if (d[x] > d[y]) swap(x, y);
    ST.add(id[x], id[y], k, -z);
  }
  T query(const int &x) {
    return -ST.query(id[x]).second;
  }
};

int n, m;
int x[N], y[N];
vector<int> e[N], op[N];
ShuPou<int> tree;

inline void solve() {
  for (int i = 1, u, v; i < n; ++i) {
    cin >> u >> v;
    e[u].emplace_back(v);
    e[v].emplace_back(u);
  }
  for (int i = 1, z; i <= m; ++i) {
    cin >> x[i] >> y[i] >> z;
    op[z].emplace_back(i);
  }
  tree.build(e, n);
  for (int z = 1; z <= 100000; ++z) {
    for (const int &i : op[z]) {
      tree.add(x[i], y[i], 1, z);
    }
    for (const int &i : op[z]) {
      tree.add(x[i], y[i], -1, z);
    }
    vector<int>().swap(op[z]);
  }
  for (int i = 1; i <= n; ++i) {
    cout << tree.query(i) << endl;
    vector<int>().swap(e[i]);
  }
}

signed main() {
  ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
  while (cin >> n >> m && n|m) solve();
  return 0;
} 
/*
2 3
1 2
2 2 2
1 2 2
2 2 1
*/