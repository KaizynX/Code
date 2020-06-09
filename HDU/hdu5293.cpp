/*
 * @Author: Kaizyn
 * @Date: 2020-06-08 21:12:27
 * @LastEditTime: 2020-06-08 23:36:11
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

struct DSU {
  int fa[N];
  void init(int sz) { for (int i = 0; i <= sz; ++i) fa[i] = i; }
  int get(int s) { return s == fa[s] ? s : fa[s] = get(fa[s]); }
  int& operator [] (int i) { return fa[get(i)]; }
  bool merge(int x, int y) { // merge x to y
    int fx = get(x), fy = get(y);
    if (fx == fy) return false;
    fa[fx] = fy; return true;
  }
};

struct LCA {
  static const int NN = (int)log2(N)+3;
  int f[N][NN], d[N], lg2[N];
  LCA() { for (int i = 2; i < N; ++i) lg2[i] = lg2[i>>1]+1; }
  template <typename TT>
  void build(const TT e[], const int &u = 1, const int &fa = 0) {
    d[u] = d[fa]+1;
    f[u][0] = fa;
    for (int i = 1; (1<<i) <= d[u]; ++i)
      f[u][i] = f[f[u][i-1]][i-1];
    for (auto v : e[u]) if (v != fa)
      build(e, v, u);
  }
  int get(int x, int y) {
    if (d[x] < d[y]) swap(x, y);
    while (d[x] > d[y])
      x = f[x][lg2[d[x]-d[y]]];
    if (x == y) return x;
    for (int i = lg2[d[x]]; i >= 0; --i)
      if(f[x][i] != f[y][i])
        x = f[x][i], y = f[y][i];
    return f[x][0];
  }
};

struct Edge {
  int u, v, w;
};

int n, m;
int dp[2][N];
LCA lca;
DSU dsu;
vector<int> e[N];
vector<Edge> chains[N];

void dfs(const int &u, const int &fa) {
  dp[0][u] = dp[1][u] = 0;
  for (const int &v : e[u]) if (v != fa) {
    dfs(v, u);
    dp[0][u] += max(dp[0][v], dp[1][v]);
  }
  for (const Edge &chain : chains[u]) {
    int val = dp[0][u]+chain.w;
    if (chain.u != u) {
      // val += dp[0][chain.u]-max(dp[0][dsu[chain.u]], dp[1][dsu[chain.u]]);
      val += dp[0][dsu[chain.u]]-max(dp[0][dsu[chain.u]], dp[1][dsu[chain.u]]);
    }
    if (chain.v != u) {
      // val += dp[0][chain.v]-max(dp[0][dsu[chain.v]], dp[1][dsu[chain.v]]);
      val += dp[0][dsu[chain.v]]-max(dp[0][dsu[chain.v]], dp[1][dsu[chain.v]]);
    }
    dp[1][u] = max(dp[1][u], val);
  }
  for (const int &v : e[u]) if (v != fa) {
    dsu.merge(v, u);
  }
}

inline void solve() {
  cin >> n >> m;
  for (int i = 1, u, v; i < n; ++i) {
    cin >> u >> v;
    e[u].emplace_back(v);
    e[v].emplace_back(u);
  }
  lca.build(e);
  dsu.init(n);
  for (int i = 1, u, v, w; i <= m; ++i) {
    cin >> u >> v >> w;
    chains[lca.get(u, v)].emplace_back(Edge{u, v, w});
  }
  dfs(1, 0);
  cout << max(dp[0][1], dp[1][1]) << endl;
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