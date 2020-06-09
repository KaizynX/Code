/*
 * @Author: Kaizyn
 * @Date: 2020-06-04 19:18:16
 * @LastEditTime: 2020-06-05 21:59:46
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
  pair<T, int> mv[N<<2];
  SegmentTree(){}
  void build(const int &n) { sz = n; _build(1, n); }
  void add(int l, int r, const T &k, const int &z) {
    if (l > r) swap(l, r);
    _add(l, r, k, z, 1, sz);
  }
  pair<T, int> query(const int &x) { return _query(x, 1, sz); }
private :
  void push_down(const int &i) {
    if (!lazy[i]) return;
    tr[i<<1] += lazy[i];
    tr[i<<1|1] += lazy[i];
    lazy[i<<1] += lazy[i];
    lazy[i<<1|1] += lazy[i];
    lazy[i] = 0;
  }
  void _build(const int &l, const int &r, const int &i = 1) {
    lazy[i] = tr[i] = 0;
    mv[i] = make_pair(0, 0);
    if (l == r) return;
    int mid = (l+r)>>1;
    _build(l, mid, i<<1);
    _build(mid+1, r, i<<1|1);
  }
  void _add(const int &l, const int &r, const T &k, const int &z,
      const int &trl, const int &trr, const int &i = 1) {
    mv[i] = max(mv[i], make_pair(tr[i], z));
    if (trl >= l && trr <= r) {
      tr[i] += k;
      lazy[i] += k;
      mv[i] = max(mv[i], make_pair(tr[i], z));
      return;
    }
    push_down(i);
    int mid = (trl+trr)>>1;
    if (l <= mid) _add(l, r, k, z, trl, mid, i<<1);
    if (r >  mid) _add(l, r, k, z, mid+1, trr, i<<1|1);
  }
  pair<T, int> _query(const int &x, const int &trl, const int &trr, const int &i = 1) {
    if (trl == x && trr == x) return mv[i];
    // push_down(i);
    int mid = (trl+trr)>>1;
    pair<T, int> res = mv[i];
    if (x <= mid) res = max(res, _query(x, trl, mid, i<<1));
    else res = max(res, _query(x, mid+1, trr, i<<1|1));
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