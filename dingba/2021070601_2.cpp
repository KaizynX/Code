/*
 * @Author: Kaizyn
 * @Date: 2021-07-07 14:09:21
 * @LastEditTime: 2021-07-07 14:42:52
 */
#include <bits/stdc++.h>

#define DEBUG

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

typedef long long ll;
typedef pair<int, ll> pil;
const int NN = (int)log2(N)+3;
int n, _dfn, cnt;
// cid 点所属环编号 ciid 点在环上编号
int f[N<<1][NN], d[N<<1], lg2[N<<1], dfn[N], cid[N], ciid[N];
long long w[N<<1][NN];
// cir[cid[x]][ciid[x]] x到换上深度最小点的距离
vector<long long> cir[N];
vector<pil> *e, ce[N<<1];

// 仙人掌
bool dfs1(int u) {
  dfn[u] = ++_dfn;
  for (const pil &edge : e[u]) {
    int v = edge.first;
    if (v == f[u][0]) continue;
    if (!dfn[v]) {
      f[v][0] = u;
      w[v][0] = edge.second;
      if (!dfs1(v)) return false;
    } else if (dfn[v] < dfn[u]) {
      if (cid[v]) return false;
      cid[v] = ++cnt;
      ciid[v] = 0;
      cir[cnt] = vector<ll>{0ll, edge.second};
      for (int x = u, id = 1; x != v; x = f[x][0], ++id) {
        cid[x] = cnt;
        ciid[x] = id;
        cir[cnt].emplace_back(cir[cnt].back()+w[x][0]);
      }
    }
  }
  return true;
}
// 建圆方树,存入 ce
void dfs2(int u) {
  if (cid[u]) {
    ll w = min(cir[cid[u]].back()-cir[cid[u]][ciid[u]], cir[cid[u]][ciid[u]]);
    ce[u].emplace_back(n+cid[u], w);
    ce[n+cid[u]].emplace_back(u, w);
  }
  for (const pil &edge : e[u]) {
    int v = edge.first;
    if (v == f[u][0]) continue;
    dfs2(v);
    if (cid[u] == cid[v]) continue;
    ce[u].emplace_back(v, edge.second);
    ce[v].emplace_back(u, edge.second);
  }
}
// 带权倍增LCA
void build_lca(int u) {
  for (int i = 1; (1<<i) <= d[u]; ++i) {
    f[u][i] = f[f[u][i-1]][i-1];
    w[u][i] = w[u][i-1]+w[f[u][i-1]][i-1];
  }
  for (const pil &edge : ce[u]) {
    int v = edge.first;
    if (v == f[u][0]) continue;
    d[v] = d[u]+1;
    f[v][0] = u;
    w[v][0] = edge.second;
    build_lca(v);
  }
}

bool build(int _n, vector<pil> *_e) {
  // 还没清空呢
  n = _n; e = _e;
  _dfn = cnt = 0;
  if (!dfs1(1)) return false;
  dfs2(1);
#ifdef DEBUG
  cout << "圆方树:**************\n";
  for (int i = 1; i <= n+cnt; ++i) {
    cout << i << ":";
    for (auto &p : e[i]) {
      cout << "(" << p.first << "," << p.second << ") ";
    }
    cout << endl;
  }
  cout << "********************\n";
#endif
  d[1] = 1;
  for (int i = 2; i < N<<1; ++i) lg2[i] = lg2[i>>1]+1;
  build_lca(1);
  return true;
}
// 环上两点距离
ll dis(int x, int y) {
  // assert(cid[x] == cid[y]);
  if (ciid[x] > ciid[y]) swap(x, y);
  ll res = cir[cid[x]][ciid[y]]-cir[cid[x]][ciid[x]];
  return min(cir[cid[x]].back()-res, res);
}

ll query(int x, int y) {
  ll res = 0;
  if (d[x] < d[y]) swap(x, y);
  while (d[x] > d[y]) {
    res += w[x][lg2[d[x]-d[y]]];
    x = f[x][lg2[d[x]-d[y]]];
  }
  if (x == y) return res;
  for (int i = lg2[d[x]]; i >= 0; --i) if(f[x][i] != f[y][i]) {
    res += w[x][i]+w[y][i];
    x = f[x][i], y = f[y][i];
  }
  if (f[x][0] < n) return res+w[x][0]+w[y][0];
  return res+dis(x, y);
}

} /* namespace Catus */

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