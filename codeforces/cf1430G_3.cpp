/*
 * @Author: Kaizyn
 * @Date: 2020-12-13 18:36:08
 * @LastEditTime: 2020-12-13 23:07:05
 */
#include <bits/stdc++.h>

#define DEBUG

using namespace std;

const double eps = 1e-7;
const double PI = acos(-1);
typedef pair<int, int> pii;
const int MOD = 998244353;
const int INF = 0x3f3f3f3f;
const int N = 18;

int n, m;
int a[N], c[N], need[N], deg[N];
int dp[N+1][N][1<<N];
int path[N+1][N][1<<N];
vector<int> order, e[N];

void topo() {
  queue<int> q;
  for (int i = 0; i < n; ++i) if (!deg[i]) {
    q.push(i);
  }
  while (q.size()) {
    int u = q.front();
    q.pop();
    order.emplace_back(u);
    for (int &v : e[u]) {
      need[v] |= need[u]|(1<<u);
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
  memset(dp, 0x3f, sizeof dp);
  memset(path, -1, sizeof path);
  dp[0][n-1][0] = 0;
  for (int v = 1; v <= n; ++v) {
    for (int i = 0, o; i < n; ++i) {
      o = order[i];
      int *cur = dp[v][i], *pre = i ? dp[v][i-1] : dp[v-1][n-1];
      for (int b = 0; b < 1<<n; ++b) {
        if (cur[b] > pre[b]) {
          cur[b] = pre[b];
          path[v][i][b] = -1;
        }
        if (((b>>o)&1) && (b&need[o]) == need[o] &&
            cur[b] > pre[b^(1<<o)]+c[o]*v) {
          cur[b] = pre[b^(1<<o)]+c[o]*v;
          path[v][i][b] = o;
        }
      }
    }
  }
#ifdef DEBUG
  for (int v = 1; v <= n; ++v) {
    for (int i = 0; i < n; ++i) {
      for (int b = 0; b < 1<<n; ++b) {
        if (dp[v][i][b] < 1e9) {
          printf("[%d,%d,%d] %d %d\n", v, i, b, dp[v][i][b], path[v][i][b]);
        }
      }
    }
  }
#endif
  for (int v = n, b = (1<<n)-1, i; v && b; --v) {
    for (i = n-1; i >= 0 && b; --i) {
      if (~path[v][i][b]) {
        a[path[v][i][b]] = v;
        b ^= 1<<path[v][i][b];
      }
    }
  }
  for (int i = 0; i < n; ++i) cout << a[i] << " \n"[i==n-1];
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