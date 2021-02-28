/*
 * @Author: Kaizyn
 * @Date: 2021-02-26 16:58:40
 * @LastEditTime: 2021-02-26 17:13:41
 */
#include <bits/stdc++.h>

// #define DEBUG

using namespace std;

const double eps = 1e-7;
const double PI = acos(-1);
typedef pair<int, int> pii;
typedef long long ll;
const int MOD = 998244353;
const int INF = 0x3f3f3f3f;
// const ll INF = 1e18;
const int N = 1e5+7;

int n, k, p, q;
int d[N];
vector<pii> e[N];

void dfs(int u, int fa = 0) {
  for (auto &p : e[u]) {
    int v = p.first;
    if (v == fa) continue;
    d[v] = d[u]+1;
    dfs(v, u);
  }
}

bool dfs2(int u, int fa = 0) { // 标记最长链
  bool flag = u == q;
  for (auto &p : e[u]) {
    int v = p.first;
    if (v == fa) continue;
    flag |= dfs2(v, u);
  }
  d[u] = flag;
  return flag;
}

void dfs3(int u, int fa = 0) { // 到最长链距离
  for (auto &p : e[u]) {
    int v = p.first;
    if (v == fa) continue;
    if (!d[v]) d[v] = d[u]+1;
    dfs3(v, u);
  }
}

inline void solve() {
  cin >> n >> k;
  for (int i = 1, u, v, w; i < n; ++i) {
    cin >> u >> v >> w;
    e[u].emplace_back(v, w);
    e[v].emplace_back(u, w);
  }
  if (k == 1) return cout << 1 << '\n', void();

  memset(d+1, 0, sizeof(int)*n);
  d[1] = 1;
  dfs(1);
  p = 0;
  for (int i = 1; i <= n; ++i) if (d[p] < d[i]) p = i;

  memset(d+1, 0, sizeof(int)*n);
  d[p] = 1;
  dfs(p);
  q = 0;
  for (int i = 1; i <= n; ++i) if (d[q] < d[i]) q = i;

  if (k == 2) return cout << d[q] << '\n', void();
  int res = d[q], mx = 0;
  memset(d+1, 0, sizeof(int)*n);
  dfs2(p);
  dfs3(p);
  for (int i = 1; i <= n; ++i) mx = max(mx, d[i]);
  cout << res+mx-1 << '\n';
}

signed main() {
#ifdef ONLINE_JUDGE
  ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
#endif
  int T = 1;
  cin >> T;
  for (int t = 1; t <= T; ++t) {
    solve();
    for (int i = 1; i <= n; ++i) e[i].clear();
  }
  return 0;
}