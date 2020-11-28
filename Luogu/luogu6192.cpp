/*
 * @Author: Kaizyn
 * @Date: 2020-10-29 19:14:45
 * @LastEditTime: 2020-10-29 20:37:34
 */
#include <bits/stdc++.h>

// #define DEBUG

using namespace std;

const double eps = 1e-7;
const double PI = acos(-1);
typedef pair<int, int> pii;
const int MOD = 998244353;
const int INF = 0x3f3f3f3f;
const int N = 1e2+7;
const int M = 5e2+7;
const int K = 10;

int n, m, k;
int p[K];
int vis[N], dp[N][1<<K];
vector<pair<int, int>> e[N]; // e[u] = {w, v}
priority_queue<pair<int, int>> q;

void dijkstra(int s) {
  while (q.size()) {
    int ud = -q.top().first;
    int u = q.top().second;
    q.pop();
    if (~dp[u][s] && ud > dp[u][s]) continue;
    for (int i = 0, v, w; i < (int)e[u].size(); ++i) {
      w = e[u][i].first;
      v = e[u][i].second;
      if (~dp[v][s] && dp[v][s] <= dp[u][s]+w) continue;
      dp[v][s] = dp[u][s]+w;
      q.push({-dp[v][s], v});
    }
  }
}

int steiner_tree() { // p[] is key point
  memset(dp, -1, sizeof dp);
  for (int i = 0; i < k; ++i) dp[p[i]][1<<i] = 0;
  for (int s = 1; s < 1<<k; ++s) {
    for (int i = 1; i <= n; ++i) {
      for (int t = s, val; t; t = t&(t-1)) if (~dp[i][t]) {
        val = dp[i][s^t]+dp[i][t];
        dp[i][s] = ~dp[i][s] ? min(dp[i][s], val) : val;
      }
      if (~dp[i][s]) q.push({-dp[i][s], i});
    }
    dijkstra(s);
  }
  return dp[p[0]][(1<<k)-1];
}

signed main() {
  ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
  cin >> n >> m >> k;
  for (int i = 1, u, v, w; i <= n; ++i) {
    cin >> u >> v >> w;
    e[u].emplace_back(w, v);
    e[v].emplace_back(w, u);
  }
  for (int i = 0; i < k; ++i) {
    cin >> p[i];
  }
  cout << steiner_tree() << endl;
  return 0;
}