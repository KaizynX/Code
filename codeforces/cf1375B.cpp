/*
 * @Author: Kaizyn
 * @Date: 2020-08-29 14:27:23
 * @LastEditTime: 2020-08-29 14:40:15
 */
#include <bits/stdc++.h>

// #define DEBUG

using namespace std;

const double eps = 1e-7;
const double PI = acos(-1);
typedef pair<int, int> pii;
const int MOD = 998244353;
const int INF = 0x3f3f3f3f;
const int N = 3e2+7;

int n, m;
int a[N][N], b[N][N];

inline void solve() {
  cin >> n >> m;
  for (int i = 1; i <= n; ++i) {
    for (int j = 1; j <= m; ++j) {
      cin >> a[i][j];
    }
  }
  for (int i = 1; i <= n; ++i) {
    for (int j = 1; j <= m; ++j) {
      b[i][j] = 4;
      if (i == 1 || i == n) --b[i][j];
      if (j == 1 || j == m) --b[i][j];
      if (a[i][j] > b[i][j]) return cout << "NO" << endl, void();
    }
  }
  cout << "YES" << endl;
  for (int i = 1; i <= n; ++i) {
    for (int j = 1; j <= m; ++j) {
      cout << b[i][j] << " \n"[j==m];
    }
  }
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