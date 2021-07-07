/*
 * @Author: Kaizyn
 * @Date: 2021-07-07 13:28:59
 * @LastEditTime: 2021-07-07 14:05:14
 */
#include <bits/stdc++.h>

// #define DEBUG

using namespace std;

const double eps = 1e-7;
const double PI = acos(-1);
typedef pair<int, int> pii;
typedef long long ll;
const int MOD = 998244353; // 1e9+7;
const int INF = 0x3f3f3f3f;
// const ll INF = 1e18;
const int N = 1e5+7;

template <typename T>
struct LCA {
  static const int NN = (int)log2(N)+3;
  int f[N][NN], d[N], lg2[N];
  T w[N][NN], init_val = 0;
  LCA() {
    for (int i = 2; i < N; ++i) lg2[i] = lg2[i>>1]+1;
    init();
  }
  // set sum or min or max, and don't forget to set init_val
  T update(const T &x, const T &y) { return x+y; }
  void init(const int &n = N-1) {
    fill(w[0], w[0]+(n+1)*NN, init_val);
  }
  template <typename TT>
  void build(const TT e[], const int &u = 1, const int &fa = 0) {
    d[u] = d[fa]+1;
    f[u][0] = fa;
    for (int i = 1; (1<<i) <= d[u]; ++i) {
      f[u][i] = f[f[u][i-1]][i-1];
      w[u][i] = update(w[u][i-1], w[f[u][i-1]][i-1]);
    }
    for (auto v : e[u]) if (v.first != fa) {
      w[v.first][0] = v.second;
      build(e, v.first, u);
    }
  }
  T get(int x, int y) {
    T res = init_val;
    if (d[x] < d[y]) swap(x, y);
    while (d[x] > d[y]) {
      res = update(res, w[x][lg2[d[x]-d[y]]]);
      x = f[x][lg2[d[x]-d[y]]];
    }
    if (x == y) return res;
    for (int i = lg2[d[x]]; i >= 0; --i)
      if(f[x][i] != f[y][i]) {
        res = update(res, w[x][i]);
        res = update(res, w[y][i]);
        x = f[x][i], y = f[y][i];
      }
    return update(res, update(w[x][0], w[y][0]));
  }
};

template <typename T>
struct Cactus {
  typedef pair<int, T> pr;
  int n, _dfn, cnt;
  vector<int> fa, faw, dfn, cid, ciid;
  vector<vector<long long>> cir;
  vector<pr> *e;
  vector<vector<pr>> ce;
  LCA<long long> lca;
  bool dfs(int u) {
    dfn[u] = ++_dfn;
    for (const pr &edge : e[u]) {
      int v = edge.first;
      if (v == fa[u]) continue;
      T w = edge.second;
      fa[v] = u;
      faw[v] = w;
      if (!dfn[v]) {
        if (!dfs(v)) return false;
      } else if (dfn[v] < dfn[u]) {
        if (cid[v]) return false;
        cid[v] = ++cnt;
        ciid[v] = 0;
        cir.emplace_back(vector<long long>(2, {0, w}));
        vector<long long> &sum = cir.back();
        int x = u;
        while (x != v) {
          // if (cid[x]) return false;
          cid[x] = cnt;
          ciid[x] = sum.size();
          sum.emplace_back(sum.back()+faw[x]);
          x = fa[x];
        }
      }
    }
    return true;
  }
  void dfs2(int u) {
    if (cid[u]) {
      long long w = min(cir[cid[u]-1].back()-cir[cid[u]-1][ciid[u]], cir[cid[u]-1][ciid[u]]);
      ce[u].emplace_back(n+cid[u], w);
      ce[n+cid[u]].emplace_back(v, w);
    }
    for (const pr &edge : e[u]) {
      int v = edge.first;
      if (v == fa[u]) continue;
      T w = edge.second;
      if (!cid[u] || !cid[v] || cid[u] != cid[v]) {
        ce[u].emplace_back(v, w);
        ce[v].emplace_back(w, w);
      }
    }
  }
  bool build(int n, vector<pr> *e) {
    this->n = n; this->e = e;
    _dfn = cnt = 0;
    fa.assign(n+1, 0);
    faw.assign(n+1, 0);
    dfn.assign(n+1, 0);
    cid.assign(n+1, 0);
    ciid.assign(n+1);
    if (!dfs(1)) return false;
    ce.assign(n+cnt+1);
    dfs2(1);
    return true;
  }
  long long query(int u, int v) {
    ;
  }
};

int n, m, q;
vector<pii> e[N];
Cactus<int> cactus;

inline void solve() {
  cin >> n >> m >> q;
  for (int i = 1, u, v, w; i <= m; ++i) {
    cin >> u >> v >> w;
    e[u].emplace_back(v, w);
    e[v].emplace_back(u, w);
  }
  cactus.build(n, e);
  for (int _ = q, u, v; _; --_) {
    cin >> u >> v;
    cout << cactus.query(u, v) << '\n';
  }
}

signed main() {
#ifdef ONLINE_JUDGE
  ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
#endif
  int T = 1;
  // cin >> T; // scanf("%d", &T);
  for (int t = 1; t <= T; ++t) {
    solve();
  }
  return 0;
}