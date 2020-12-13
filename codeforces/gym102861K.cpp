/*
 * @Author: Kaizyn
 * @Date: 2020-12-10 20:38:27
 * @LastEditTime: 2020-12-10 22:31:14
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

int n, m;
int deg[N];
int a[N][N];

// -1 : no solution, 0 : multi , 1 : one
template <typename T>
int XorGauss(T a[N], const int &n) {
  for (int i = 1, j, k; i <= n; ++i) {
    for (k = i; !a[k][i] && k <= n; ++k) {}
    if (k <= n) swap(a[k], a[i]);
    for (j = 1; j <= n; ++j) if (i != j && a[j][i])
      for (k = i; k <= n+1; ++k) a[j][k] ^= a[i][k];
  }
  for (int i = 1; i <= n; ++i) if (!a[i][i] && a[i][n+1]) return -1;
  for (int i = 1; i <= n; ++i) if (!a[i][i]) return 0;
  return 1;
}

inline bool solve() {
  cin >> n >> m;
  for (int i = 1, u, v; i <= m; ++i) {
    cin >> u >> v;
    ++deg[u];
    ++deg[v];
    a[u][v] = a[v][u] = 1;
  }
  for (int i = 1; i <= n; ++i) {
    if (deg[i]&1) a[i][i] = 1;
    else a[i][n+1] = 1;
  }
  return ~XorGauss(a, n);
}

signed main() {
  ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
  int T = 1;
  // cin >> T;
  for (int t = 1; t <= T; ++t) {
    cout << (solve() ? "Y" : "N") << endl;
  }
  return 0;
}