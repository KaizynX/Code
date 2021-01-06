/*
 * @Author: Kaizyn
 * @Date: 2021-01-05 15:21:49
 * @LastEditTime: 2021-01-05 15:23:59
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
int dp[N][2], vis[N], d[N];
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
  for (int &v : e[u]) {
    dfs(v);
    if (d[u] < d[v]) {
      dp[u][0] = min(dp[u][0], dp[v][0]);
      dp[u][1] = min(dp[u][1], dp[v][1]);
    } else {
      dp[u][1] = min(dp[u][1], dp[v][0]);
    }
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
    dp[i][0] = dp[i][1] = d[i];
  }
  memset(vis+1, 0, sizeof(int)*n);
  for (int i = 1; i <= n; ++i) dfs(i);
  memset(vis+1, 0, sizeof(int)*n);
  for (int i = 1; i <= n; ++i) dfs(i);
  for (int i = 1; i <= n; ++i) {
    cout << min(dp[i][0], dp[i][1]) << " \n"[i==n];
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
    }
  }
  return 0;
}