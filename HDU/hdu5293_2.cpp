/*
 * @Author: Kaizyn
 * @Date: 2020-06-08 21:12:27
 * @LastEditTime: 2020-06-09 10:39:02
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

template <typename T>
struct BinaryIndexedTree {
  int n;
  T tr[N];
  BinaryIndexedTree() { memset(tr, 0, sizeof tr); }
  void init(const int &_n) { n = _n; clear(); }
  void clear() { for (int i = 1; i <= n; ++i) tr[i] = 0; }
  void add(const int &x, const T &v) { for (int i = x ; i <= n; i += i&-i) tr[i] += v; }
  void add(const int &x, const int &y, const T &v) { add(x, v); add(y+1, -v); }
  T query(const int &x) { T res = 0; for (int i = x ; i; i -= i&-i) res += tr[i]; return res; }
  T query(const int &x, const int &y) { return query(y)-query(x-1); }
};

template <typename T>
struct ShuPou {
  int dfn;
  int fa[N], d[N], num[N], son[N], id[N], tp[N];
  BinaryIndexedTree<T> BIT;
  template <typename Edge>
  void build(const Edge e[], const int &n, const int &rt = 1) {
    fa[rt] = dfn = 0;
    dfs1(e, rt);
    dfs2(e, rt);
    BIT.init(n);
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
  void update(const int &x, const T &k) { BIT.add(id[x], k); }
  T lca(int x, int y) {
    while (tp[x] != tp[y]) {
      if (d[tp[x]] < d[tp[y]]) y = fa[tp[y]];
      else x = fa[tp[x]];
    }
    return d[x] > d[y] ? y : x;
  }
  T query(int x, int y) {
    T res = 0;
    while (tp[x] != tp[y]) {
      if (d[tp[x]] < d[tp[y]]) swap(x, y);
      res += BIT.query(id[tp[x]], id[x]);
      x = fa[tp[x]];
    }
    if (d[x] > d[y]) swap(x, y);
    return res+BIT.query(id[x], id[y])-BIT.query(id[x], id[x]);
  }
  #ifdef DEBUG
  void print(const int &n) {
    for (int i = 1; i <= n; ++i) {
      cout << id[i] << " \n"[i==n];
    }
  }
  #endif
};

struct Edge {
  int u, v, w;
};

int n, m;
int dp[N], sum[N];
ShuPou<int> tree;
vector<int> e[N];
vector<Edge> chains[N];

void dfs(const int &u, const int &fa) {
  sum[u] = 0;
  for (const int &v : e[u]) if (v != fa) {
    dfs(v, u);
    sum[u] += dp[v];
  }
  dp[u] = sum[u];
  for (const Edge &chain : chains[u]) {
    dp[u] = max(dp[u], sum[u]+tree.query(chain.u, chain.v)+chain.w);
  }
  tree.update(u, sum[u]-dp[u]);
}

inline void solve() {
  cin >> n >> m;
  for (int i = 1, u, v; i < n; ++i) {
    cin >> u >> v;
    e[u].emplace_back(v);
    e[v].emplace_back(u);
  }
  tree.build(e, n);
  for (int i = 1, u, v, w; i <= m; ++i) {
    cin >> u >> v >> w;
    chains[tree.lca(u, v)].emplace_back(Edge{u, v, w});
  }
  dfs(1, 0);
  cout << dp[1] << endl;
  #ifdef DEBUG
  tree.print(n);
  for (int i = 1; i <= n; ++i) {
    cout << sum[i] << " " << dp[i] << endl;
  }
  #endif
  for (int i = 1; i <= n; ++i) {
    vector<int>().swap(e[i]);
    vector<Edge>().swap(chains[i]);
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