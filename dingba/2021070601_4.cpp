/*
 * @Author: Kaizyn
 * @Date: 2021-07-07 16:38:20
 * @LastEditTime: 2021-07-07 17:46:19
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

namespace Cactus {

#define log(x) (31-__builtin_clz(x))
typedef long long ll;
typedef pair<int, ll> pil;
const int NN = (int)log2(N)+3;
int n, _dfn, cnt;
int f[N<<1][NN], dep[N<<1], dfn[N], from[N];
// od 为仙人掌上距离, dis 为圆方树上距离, cir 为环上边权和
ll od[N], dis[N<<1], cir[N];
vector<pil> *e, ce[N<<1];

bool dfs(int u) {
  dfn[u] = ++_dfn;
  for (const pil &edge : e[u]) {
    int v = edge.first;
    if (v == f[u][0]) continue;
    ll w = edge.second;
    if (!dfn[v]) {
      f[v][0] = u;
      dep[v] = dep[u]+1;
      od[v] = od[u]+w;
      if (!dfs(v)) return false;
      if (!from[v]) ce[u].emplace_back(v, w);
    } else if (dfn[v] < dfn[u]) {
      cir[++cnt] = od[u]-od[v]+w;
      ce[v].emplace_back(n+cnt, 0);
      for (int x = u; x != v; x = f[x][0]) {
        if (from[x]) return false;
        from[x] = cnt;
        ll ww = od[x]-od[v];
        ce[n+cnt].emplace_back(x, min(ww, cir[cnt]-ww));
      }
    }
  }
  return true;
}

// 带权倍增LCA
void build_lca(int u) {
  for (int i = 1; (1<<i) <= dep[u]; ++i)
    f[u][i] = f[f[u][i-1]][i-1];
  for (const pil &edge : ce[u]) {
    int v = edge.first;
    dep[v] = dep[u]+1;
    dis[v] = dis[u]+edge.second;
    f[v][0] = u;
    build_lca(v);
  }
}

bool build(int _n, vector<pil> *_e) {
  // 还没清空呢
  n = _n; e = _e;
  _dfn = cnt = 0;
  if (!dfs(1)) return false;
#ifdef DEBUG
  cout << "圆方树:**************\n";
  for (int i = 1; i <= n+cnt; ++i) {
    cout << i << ":";
    for (auto &p : ce[i]) {
      cout << "(" << p.first << "," << p.second << ") ";
    }
    cout << endl;
  }
  cout << "********************\n";
#endif
  dep[1] = 1;
  build_lca(1);
  return true;
}

ll query(int u, int v) {
  if (dep[u] < dep[v]) swap(u, v);
  int x = u, y = v;
  while (dep[x] > dep[y]) x = f[x][log(dep[x]-dep[y])];
  if (x == y) return dis[u]-dis[v];
  for (int i = log(dep[x]); i >= 0; --i)
    if(f[x][i] != f[y][i]) x = f[x][i], y = f[y][i];
  if (f[x][0] <= n) return dis[u]+dis[v]-2*dis[f[x][0]];
  ll d = abs(od[x]-od[y]);
  return dis[u]-dis[x]+dis[v]-dis[y]+min(d, cir[f[x][0]-n]-d);
}

} /* namespace Cactus */

int n, m, q;
vector<pair<int, ll>> e[N];

inline void solve() {
  cin >> n >> m >> q;
  for (int i = 1, u, v, w; i <= m; ++i) {
    cin >> u >> v >> w;
    e[u].emplace_back(v, w);
    e[v].emplace_back(u, w);
  }
  Cactus::build(n, e);
  for (int _ = q, u, v; _; --_) {
    cin >> u >> v;
    cout << Cactus::query(u, v) << '\n';
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