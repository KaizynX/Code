/*
 * @Author: Kaizyn
 * @Date: 2021-01-05 22:30:37
 * @LastEditTime: 2021-01-05 22:31:57
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
const int N = 2e5+7;

int n, m;
int dp[N], vis[N], d[N];
vector<int> e[N];

void bfs() {
  queue<int> q;
  memset(d+1, -1, sizeof(int)*n);
  q.push(1);
  d[1] = 0;
  while (q.size()) {
    int u = q.front();
    q.pop();
    for (int &v : e[u]) {
      if (~d[v]) continue;
      d[v] = d[u]+1;
      q.push(v);
    }
  }
}

void dfs(int u) {
  if (vis[u]) return;
  vis[u] = 1;
  dp[u] = d[u];
  for (int &v : e[u]) {
    dp[u] = min(dp[u], d[v]);
  }
  for (int &v : e[u]) {
    dfs(v);
    if (d[u] < d[v]) dp[u] = min(dp[u], dp[v]);
  }
}

inline void solve() {
  cin >> n >> m;
  for (int i = 1, u, v; i <= m; ++i) {
    cin >> u >> v;
    e[u].emplace_back(v);
  }
  bfs();
  for (int i = 1; i <= n; ++i) {
    dfs(i);
    cout << dp[i] << " \n"[i==n];
  }
}

signed main() {
#ifdef ONLINE_JUDGE
  ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
#endif
  int T = 1;
  cin >> T;
  for (int t = 1; t <= T; ++t) {
    solve();
    for (int i = 1; i <= n; ++i) {
      e[i] = vector<int>();
      vis[i] = 0;
    }
  }
  return 0;
}