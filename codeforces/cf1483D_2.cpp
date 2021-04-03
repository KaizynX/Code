/*
 * @Author: Kaizyn
 * @Date: 2021-04-03 20:29:15
 * @LastEditTime: 2021-04-03 20:51:27
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
const int N = 6e2+7;
const int M = 18e4;

int n, m, q;
ll dist[N][N], lim[N][N];
int a[M], b[M], w[M], vis[M];

/* edge(a, b, w)
 * limit(v, u, l)
 * dist(v, a)+w+dist(u, b) <= l
 * l-dist(u, b) >= dist(v, a)+w
 * li-dist(ui, b) >= dist(v, a)+w
 */

inline void floyd() {
  for (int i = 1; i <= n; ++i) dist[i][i] = 0;
  for (int k = 1; k <= n; ++k)
  for (int i = 1; i <= n; ++i) if (i != k)
  for (int j = 1; j <= n; ++j) if (j != i && j != k) {
    dist[i][j] = min(dist[i][j], dist[i][k]+dist[k][j]);
  }
}

inline void solve() {
  memset(dist, 0x3f, sizeof dist);
  memset(lim, 0x9f, sizeof lim);
  cin >> n >> m;
  for (int i = 1; i <= m; ++i) {
    cin >> a[i] >> b[i] >> w[i];
    dist[a[i]][b[i]] = dist[b[i]][a[i]] = w[i];
  }
  floyd();
  cin >> q;
  for (int i = 1, u, v, l; i <= q; ++i) {
    cin >> u >> v >> l;
    for (int j = 1; j <= n; ++j) {
      lim[u][j] = max(lim[u][j], l-dist[v][j]);
      lim[v][j] = max(lim[v][j], l-dist[u][j]);
    }
  }
  for (int v = 1; v <= n; ++v) {
    for (int i = 1; i <= m; ++i) {
      if (lim[v][b[i]] >= dist[v][a[i]]+w[i]) {
        vis[i] = 1;
      }
      if (lim[v][a[i]] >= dist[v][b[i]]+w[i]) {
        vis[i] = 1;
      }
    }
  }
  int res = 0;
  for (int i = 1; i <= m; ++i) res += vis[i];
  cout << res << '\n';
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