/*
 * @Author: Kaizyn
 * @Date: 2020-12-13 13:44:35
 * @LastEditTime: 2020-12-13 18:32:51
 */
#include <bits/stdc++.h>

#define DEBUG

using namespace std;

const double eps = 1e-7;
const double PI = acos(-1);
typedef pair<int, int> pii;
const int MOD = 998244353;
const int INF = 0x3f3f3f3f;
const int N = 20;

int n, m;
int a[N], c[N], pre[N], deg[N];
int dp[N][1<<18];
pii path[N][1<<18];
vector<int> order, e[N];

void topo() {
  queue<int> q;
  for (int i = 0; i < n; ++i) {
    if (deg[i]) continue;
    q.push(i);
  }
  while (q.size()) {
    int u = q.front();
    q.pop();
    order.emplace_back(u);
    for (int &v : e[u]) {
      pre[v] |= pre[u]|(1<<u);
      if (--deg[v] == 0) q.push(v);
    }
  }
  reverse(order.begin(), order.end());
}

inline void solve() {
  cin >> n >> m;
  for (int i = 1, u, v, w; i <= m; ++i) {
    cin >> u >> v >> w;
    --u; --v;
    c[u] += w;
    c[v] -= w;
    e[v].emplace_back(u);
    ++deg[u];
  }
  topo();
#ifdef DEBUG
  cout << "********pre\n";
  for (int i = 0; i < n; ++i) cout << pre[i] << " \n"[i==n-1];
  for (int &i : order) cout << i << " ";
  cout << "\n*********(order" << endl;
#endif
  memset(dp, 0x3f, sizeof dp);
  dp[0][0] = 0;
  int res = 0;
  for (int v = 1; v <= n; ++v) {
    for (int &i : order) {
      for (int b = 0; b < 1<<n; ++b) if ((b>>i)&1) {
        if ((b&pre[i]) != pre[i]) continue;
        if (dp[v][b] > dp[v-1][b^(1<<i)]+c[i]*v) {
          dp[v][b] = dp[v-1][b^(1<<i)]+c[i]*v;
          path[v][b] = {v-1, i};
        }
        if (dp[v][b] > dp[v][b^(1<<i)]+c[i]*v) {
          dp[v][b] = dp[v][b^(1<<i)]+c[i]*v;
          path[v][b] = {v, i};
        }
      }
    }
    if (dp[v][(1<<n)-1] < dp[res][(1<<n)-1]) res = v;
  }
  for (int v = res, b = (1<<n)-1, i; b; v = path[v][b].first, b ^= 1<<i) {
    i = path[v][b].second;
    a[i] = v;
  }
  for (int i = 0; i < n; ++i) cout << a[i] << " \n"[i==n-1];
#ifdef DEBUG
  for (int v = 1; v <= n; ++v) {
    for (int b = 1; b < 1<<n; ++b) if (dp[v][b] < 1e9) {
      printf("[%d][%d] %d {%d,%d}\n", v, b, dp[v][b], path[v][b].first, path[v][b].second);
    }
  }
#endif
}

signed main() {
#ifndef DEBUG
  ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
#endif
  int T = 1;
  // cin >> T;
  for (int t = 1; t <= T; ++t) {
    solve();
  }
  return 0;
}
/*
3 3
1 2 1
2 3 1
1 3 6
*/