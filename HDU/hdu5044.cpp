/*
 * @Author: Kaizyn
 * @Date: 2020-06-01 22:19:28
 * @LastEditTime: 2020-06-01 23:30:45
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
  int f[N], d[N], num[N], son[N], rk[N], id[N], tp[N];
  SegmentTree<T> ST;
  template <typename EDGE>
  void build(const EDGE e[], const int &n, const int &rt = 1) {
    memset(son+1, 0, sizeof(int)*n);
    d[0] = num[0] = dfn = 0;
    dfs1(e, rt);
    dfs2(e, rt);
    ST.build(n, 0);
  }
  template <typename EDGE>
  void dfs1(const EDGE e[], const int &u = 1, const int &fa = 0) {
    f[u] = fa;
    d[u] = d[fa]+1;
    num[u] = 1;
    for (auto v : e[u]) if (v != fa) {
      dfs1(e, v, u);
      num[u] += num[v];
      if (num[v] > num[son[u]])
        son[u] = v;
    }
  }
  template <typename EDGE>
  void dfs2(const EDGE e[], const int &u = 1) {
    tp[u] = son[f[u]] == u ? tp[f[u]] : u;
    id[u] = ++dfn;
    rk[dfn] = u;
    if (!son[u]) return;
    dfs2(e, son[u]);
    for (auto v : e[u]) if (v != son[u] && v != f[u])
      dfs2(e, v);
  }
  void add_sons(const int &x, const T &k) { ST.add(id[x], id[x]+num[x]-1, k); }
  void add(int x, int y, const T &k, const int &tag = 0) {
    while (tp[x] != tp[y]) {
      if (d[tp[x]] < d[tp[y]]) swap(x, y);
      ST.add(id[tp[x]], id[x], k);
      x = f[tp[x]];
    }
    if (d[x] > d[y]) swap(x, y);
    ST.add(id[x], id[y], k);
    if (tag) ST.add(id[x], -k);
  }
  T query_sons(const int &x) { return ST.query(id[x], id[x]+num[x]-1); }
  T query(const int &x) { return ST.query(id[x]); }
  T query(int x, int y) {
    T res = 0;
    while (tp[x] != tp[y]) {
      if (d[tp[x]] < d[tp[y]]) swap(x, y);
      res += ST.query(id[tp[x]], id[x]);
      x = f[tp[x]];
    }
    if (d[x] > d[y]) swap(x, y);
    return res+ST.query(id[x], id[y]);
  }
};

int n, m;
long long res[N];
vector<int> e[N];
map<pair<int, int>, int> mp;
ShuPou<long long> point, edge;

inline void solve(const int &T) {
  mp.clear();
  // cin >> n >> m;
  scanf("%d %d", &n, &m);
  for (int i = 1, u, v; i < n; ++i) {
    // cin >> u >> v;
    scanf("%d %d", &u, &v);
    e[u].emplace_back(v);
    e[v].emplace_back(u);
    mp[{u, v}] = mp[{v, u}] = i;
  }
  point.build(e, n);
  edge.build(e, n);
  // static string op;
  static char op[10];
  for (int i = 1, u, v, k; i <= m; ++i) {
    // cin >> op >> u >> v >> k;
    scanf("%s%d%d%d", op, &u, &v, &k);
    // if (op.back() == '1') {
    if (op[3] == '1') {
      point.add(u, v, k);
    } else {
      edge.add(u, v, k, 1);
    }
  }
  // cout << "Case #" << T << ":\n";
  printf("Case #%d:\n", T);
  for (int i = 1; i <= n; ++i) {
    // cout << point.query(i) << " \n"[i==n];
    printf("%lld%c", point.query(i), " \n"[i==n]);
  }
  for (int i = 2; i <= n; ++i) {
    res[mp[{i, edge.f[i]}]] = edge.query(i);
  }
  for (int i = 1; i < n; ++i) {
    // cout << res[i] << " \n"[i==n-1];
    printf("%lld%c", res[i], " \n"[i==n-1]);
  }
  // cout.flush();
  for (int i = 1; i <= n; ++i) vector<int>().swap(e[i]);
}

signed main() {
  // ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
  int T = 1;
  // cin >> T;
  scanf("%d", &T);
  for (int t = 1; t <= T; ++t) {
    solve(t);
  }
  return 0;
}