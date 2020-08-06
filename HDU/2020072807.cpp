/*
 * @Author: Kaizyn
 * @Date: 2020-07-28 14:12:32
 * @LastEditTime: 2020-07-28 14:22:18
 */ 
#include <bits/stdc++.h>

// #define DEBUG

using namespace std;

const double eps = 1e-7;
const double PI = acos(-1);
typedef pair<int, int> pii;
const int MOD = 998244353;
const int INF = 0x3f3f3f3f;
const int N = 55;

int n, k, res;
int a[N][N];

void fuck(int t) {
  vector<int> dis(n+1, INF), pre(n+1);
  priority_queue<pii> q;
  dis[1] = 0;
  q.push({0, 1});
  while (q.size()) {
    int u = q.top().second;
    int ud = -q.top().first;
    q.pop();
    if (ud > dis[u]) continue;
    if (u == n) break;
    for (int v = 1; v <= n; ++v) if (u != v) {
      if (ud+a[u][v] < dis[v]) {
        dis[v] = ud+a[u][v];
        pre[v] = u;
        q.push({-dis[v], v});
      }
    }
  }
  if (t == k) return res = max(res, dis[n]), void();
  for (int v = n, u, w; u != 1; v = u) {
    u = pre[v];
    w = a[u][v];
    a[u][v] = a[v][u] = INF;
    fuck(t+1);
    a[u][v] = a[v][u] = w;
  }
}

inline void solve() {
  cin >> n >> k;
  for (int i = 1, u, v, w; i <= n*(n-1)/2; ++i) {
    cin >> u >> v >> w;
    a[u][v] = a[v][u] = w;
  }
  res = 0;
  fuck(0);
  cout << res << endl;
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