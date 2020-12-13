#include <bits/stdc++.h>

using namespace std;

const int N = 2e2+7;
const int INF = 0x3f3f3f3f;

int n, m, k;
int a[N][N];
int b[N], vis[N];

signed main() {
  memset(a, -1, sizeof a);
  cin >> n >> m;
  for (int i = 1, u, v, w; i <= m; ++i) {
    cin >> u >> v >> w;
    a[u][v] = a[v][u] = w;
  }
  cin >> k;
  int cnt = 0, resi = -1, resd = INF;
  for (int i = 1, t; i <= k; ++i) {
    cin >> t;
    int flag = 0;
    for (int j = 1; j <= t; ++j) {
      cin >> b[j];
      if (++vis[b[j]] == 1) ++flag;
    }
    for (int j = 1; j <= t; ++j) --vis[b[j]];
    if (t != n || flag != n) continue;
    b[0] = b[t+1] = 0;
    int curd = 0;
    for (int j = 0; j <= t; ++j) {
      if (a[b[j]][b[j+1]] == -1) {
        curd = INF;
        break;
      }
      curd += a[b[j]][b[j+1]];
    }
    if (curd < INF) ++cnt;
    if (curd < resd) {
      resd = curd;
      resi = i;
    }
  }
  cout << cnt << endl << resi << " " << resd << endl;
  return 0;
}