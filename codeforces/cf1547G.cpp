/*
 * @Author: Kaizyn
 * @Date: 2021-07-10 22:29:29
 * @LastEditTime: 2021-07-10 23:06:25
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
const int N = 4e5+7;

int n, m;
int deg[N], vis[N], res[N], dfn[N], _dfn, id[N];
vector<int> e[N], re[N];
pii a[N];

void dfs(int u) {
  if (dfn[u]) return;
  dfn[u] = ++_dfn;
  id[_dfn] = u;
  for (int v : e[u]) dfs(v);
}

inline void solve() {
  cin >> n >> m;
  for (int i = 1, u, v; i <= m; ++i) {
    cin >> u >> v;
    a[i] = pii{u, v};
    e[u].emplace_back(v);
  }
  dfs(1);
  for (int i = 1; i <= n; ++i) e[i].clear();
  for (int i = 1, u, v; i <= m; ++i) {
    u = a[i].first;
    v = a[i].second;
    if (!dfn[u] || !dfn[v]) continue;
    e[u].emplace_back(v);
    re[v].emplace_back(u);
    ++deg[v];
  }
  queue<int> q;
  for (int i = 1; i <= n; ++i) {
    if (deg[i] == 0) q.push(i);
  }
  while (q.size()) {
    int u = q.front();
    q.pop();
    vis[u] = 1;
    for (int &v : e[u]) {
      if (--deg[v] == 0) q.push(v);
    }
  }
  for (int i = 1; i <= n; ++i) {
    if (!dfn[i]) res[i] = 0;
    else res[i] = vis[i] ? 1 : -1;
  }
  for (int _ = 1, i; id[_]; ++_) {
    i = id[_];
    if (res[i] == -1) continue;
    res[i] = 0;
    for (int u : re[i]) {
      if (res[u] == -1) {
        res[i] = -1;
        break;
      } else {
        res[i] += res[u];
      }
    }
    res[i] = max(res[i], 1);
    res[i] = min(res[i], 2);
  }
  for (int i = 1; i <= n; ++i) {
    cout << res[i] << " \n"[i==n];
  }
}

signed main() {
#ifdef ONLINE_JUDGE
  ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
#endif
  int T = 1;
  cin >> T; // scanf("%d", &T);
  for (int t = 1; t <= T; ++t) {
    solve();
    _dfn = 0;
    for (int i = 1; i <= n; ++i) {
      dfn[i] = res[i] = vis[i] = deg[i] = id[i] = 0;
      e[i].clear();
      re[i].clear();
    }
  }
  return 0;
}
/*
4 4
2 3
3 4
4 2
2 1
*/