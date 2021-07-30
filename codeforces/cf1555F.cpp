/*
 * @Author: Kaizyn
 * @Date: 2021-07-30 23:23:27
 * @LastEditTime: 2021-07-31 00:11:43
 */
#include <bits/stdc++.h>

// #define DEBUG

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
const double eps = 1e-7;
const double PI = acos(-1);
const int MOD = 998244353; // 1e9+7;
const int INF = 0x3f3f3f3f;
// const ll INF = 1e18;
const int N = 5e5+7;

struct DSU {
  vector<int> fa;
  void init(int n) { fa = vector<int>(n+1); iota(fa.begin(), fa.end(), 0); }
  int get(int s) { return s == fa[s] ? s : fa[s] = get(fa[s]); }
  int& operator [] (int i) { return fa[get(i)]; }
  bool merge(int x, int y) { // merge x to y
    x = get(x); y = get(y);
    return x == y ? false : (fa[x] = y, true);
  }
};

template <typename T>
struct SegmentTree {
  int sz;
  T tr[N<<2], lazy[N<<2];
  SegmentTree(){}
  void build(const int &n, const T &k = 0) { sz = n; _build(1, n, k); }
  template <typename TT>
  void build(const TT a[], const int &n) { sz = n; _build(a, 1, n); }
  void modify(const int &x, const T &k) { _modify(x, k, 1, sz); }
#ifdef DEBUG
  void add(const int &x, const T &k) { cout<<"add"<<x<<'\n';_add(x, x, k, 1, sz); }
  void add(int l, int r, const T &k) { cout<<"add"<<l<<' '<<r<<'\n';if (l > r) swap(l, r); _add(l, r, k, 1, sz); }
  T query(const int &x) { cout<<"query"<<x<<'\n';return _query(x, x, 1, sz); }
  T query(int l, int r) { cout<<"query"<<l<<' '<<r<<'\n';if (l > r) swap(l, r); return _query(l, r, 1, sz); }
#else
  void add(const int &x, const T &k) { _add(x, x, k, 1, sz); }
  void add(int l, int r, const T &k) { if (l > r) swap(l, r); _add(l, r, k, 1, sz); }
  T query(const int &x) { return _query(x, x, 1, sz); }
  T query(int l, int r) { if (l > r) swap(l, r); return _query(l, r, 1, sz); }
#endif
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
struct HLD {
  int dfn;
  int fa[N], d[N], num[N], son[N], id[N], tp[N];
  vector<pii> *e;
  SegmentTree<T> t_xor, t_sum;
  void build(vector<pii> e[], const int &n, const int &rt = 1) {
    this->e = e;
    fa[rt] = dfn = 0;
    dfs1(rt);
    dfs2(rt);
  }
  void dfs1(const int &u = 1) {
    // cout << u << '\n';
    d[u] = d[fa[u]]+1;
    num[u] = 1;
    son[u] = 0;
    for (auto p : e[u]) {
      int v = p.first;
      if (v == fa[u]) continue;
      fa[v] = u;
      dfs1(v);
      num[u] += num[v];
      if (num[v] > num[son[u]]) son[u] = v;
    }
  }
  void dfs2(const int &u = 1) {
    tp[u] = son[fa[u]] == u ? tp[fa[u]] : u;
    id[u] = ++dfn;
    if (son[u]) dfs2(son[u]);
    for (auto p : e[u]) {
      int v = p.first;
      int w = p.second;
      if (v == fa[u]) continue;
      if (v != son[u]) dfs2(v);
      t_xor.add(id[v], w);
    }
  }
  void add(int x, int y, const T &k, const int &is_edge = 1) {
    while (tp[x] != tp[y]) {
      if (d[tp[x]] < d[tp[y]]) swap(x, y);
      t_sum.add(id[tp[x]], id[x], k);
      x = fa[tp[x]];
    }
    if (d[x] > d[y]) swap(x, y);
    t_sum.add(id[x], id[y], k);
    if (is_edge) t_sum.add(id[x], -k);
  }
  T query(int x, int y, int is_edge = 1) {
    #ifdef DEBUG
    cout << "tree:query:" << x << ' ' << y << '\n';
    #endif
    T q_xor = 0, q_sum = 0;
    while (tp[x] != tp[y]) {
      if (d[tp[x]] < d[tp[y]]) swap(x, y);
      q_xor += t_xor.query(id[tp[x]], id[x]);
      q_sum += t_sum.query(id[tp[x]], id[x]);
      x = fa[tp[x]];
    }
    if (d[x] > d[y]) swap(x, y);
    q_xor += t_xor.query(id[x], id[y]);
    q_sum += t_sum.query(id[x], id[y]);
    if (is_edge) {
      q_xor -= t_xor.query(id[x]);
      q_sum -= t_sum.query(id[x]);
    }
    if (q_sum) return -1;
    return q_xor&1;
  }
};

int n, q;
int u[N], v[N], w[N], res[N];
vector<int> qset[N];
vector<pii> e[N];
DSU dsu;
HLD<int> tree;

void fuck(int i) {
  if (res[i] == -1) {
    int x = tree.query(u[i], v[i], 1);
    if (x == -1 || w[i] == x) res[i] = 0;
    else res[i] = 1, tree.add(u[i], v[i], 1, 1);
  }
}

signed main() {
#ifdef ONLINE_JUDGE
  ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
#endif
  cin >> n >> q;
  dsu.init(n);
  for (int i = 1; i <= q; ++i) {
    cin >> u[i] >> v[i] >> w[i];
    res[i] = -1;
    if (dsu.merge(u[i], v[i])) {
      res[i] = 1;
      e[u[i]].emplace_back(v[i], w[i]);
      e[v[i]].emplace_back(u[i], w[i]);
    }
  }
  for (int i = 1; i <= q; ++i) {
    assert(dsu[u[i]] == dsu[v[i]]);
    qset[dsu[u[i]]].emplace_back(i);
  }
  tree.t_xor.build(n, 0);
  tree.t_sum.build(n, 0);
  for (int i = 1; i <= n; ++i) if (qset[i].size()) {
    tree.build(e, n, i);
    for (int j : qset[i]) fuck(j);
  }
  for (int i = 1; i <= q; ++i) {
    cout << (res[i] ? "YES" : "NO") << '\n';
  }
  return 0;
}