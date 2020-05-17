/*
 * @Author: Kaizyn
 * @Date: 2020-05-10 20:58:30
 * @LastEditTime: 2020-05-10 21:07:39
 */
#include <bits/stdc++.h>

// #define DEBUG

using namespace std;

const double eps = 1e-7;
const double PI = acos(-1);
typedef pair<int, int> pii;
const int MOD = 998244353;
const int INF = 0x3f3f3f3f;
const int N = 20;

int n, m, x, res = INF;
int c[N];
int a[N][N], sum[N];

void dfs(const int &u, const int cost) {
  if (u > n) {
    for (int i = 1; i <= m; ++i) {
      if (sum[i] < x) return;
    }
    res = min(res, cost);
    return;
  }
  dfs(u+1, cost);
  for (int i = 1; i <= m; ++i) {
    sum[i] += a[u][i];
  }
  dfs(u+1, cost+c[u]);
  for (int i = 1; i <= m; ++i) {
    sum[i] -= a[u][i];
  }
}

inline void solve() {
  cin >> n >> m >> x;
  for (int i = 1; i <= n; ++i) {
    cin >> c[i];
    for (int j = 1; j <= m; ++j) {
      cin >> a[i][j];
      sum[j] += a[i][j];
    }
  }
  for (int i = 1; i <= m; ++i) {
    if (sum[i] < x) return void(cout << -1 << endl);
    sum[i] = 0;
  }
  dfs(1, 0);
  cout << res << endl;
}

signed main() {
  ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
  int T = 1;
  // cin >> T;
  for (int t = 1; t <= T; ++t) {
    solve();
  }
  return 0;
}