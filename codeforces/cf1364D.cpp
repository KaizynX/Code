/*
 * @Author: Kaizyn
 * @Date: 2020-06-13 23:01:41
 * @LastEditTime: 2020-06-14 00:27:42
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
const int M = 2e5+7;

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

int n, m, k;
int u[M], v[M], used[M];
vector<int> e[N], res;
DSU dsu;
LCA lca;

inline void print() {
  for (const int &x : res) cout << x << " ";
  cout << endl;
}

inline void solve() {
  cin >> n >> m >> k;
  dsu.init(n);
  for (int i = 1; i <= m; ++i) {
    cin >> u[i] >> v[i];
    if (dsu[u[i]] != dsu[v[i]]) {
      used[i] = 1;
      dsu.merge(u[i], v[i]);
      e[u[i]].emplace_back(v[i]);
      e[v[i]].emplace_back(u[i]);
    }
  }
  lca.build(e);
  if (n-1 == m) {
    cout << 1 << endl;
    int cnt[2] = {0, 0}, x;
    for (int i = 1; i <= n; ++i) {
      ++cnt[lca.d[i]&1];
    }
    x = cnt[0] < cnt[1];
    for (int i = 1; i <= n; ++i) {
      if (lca.d[i]%2 == x && (int)res.size() < (k+1)/2) {
        res.emplace_back(i);
      }
    }
    print();
    return;
  }
  for (int i = 1; i <= m; ++i) {
    if (used[i]) continue;
    int f = lca.get(u[i], v[i]);
    int len = lca.d[u[i]]+lca.d[v[i]]-2*lca.d[f]+1;
    if (len <= k) {
      cout << 2 << endl << len << endl;
      for (int x = u[i]; x != f; x = lca.f[x][0]) {
        res.emplace_back(x);
      }
      res.emplace_back(f);
      reverse(res.begin(), res.end());
      for (int x = v[i]; x != f; x = lca.f[x][0]) {
        res.emplace_back(x);
      }
      print();
      return;
    } else if (len/2 == (k+1)/2) { // not this way
      cout << 1 << endl;
      int cu = 0, cv = 1;
      for (int x = u[i]; x != f; x = lca.f[x][0], cu ^= 1) {
        if (cu) res.emplace_back(x);
      }
      for (int x = v[i]; x != f; x = lca.f[x][0], cv ^= 1) {
        if (cv) res.emplace_back(x);
      }
      if (cu == cv) res.emplace_back(f);
      print();
      return;
    }
  }
}

signed main() {
  ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
  int T = 1;
  // cin >> T;
  for (int t = 1; t <= T; ++t) {
    solve();
  }
  return 0;
}