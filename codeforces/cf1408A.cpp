/*
 * @Author: Kaizyn
 * @Date: 2020-09-30 22:32:28
 * @LastEditTime: 2020-09-30 22:38:49
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

int n;
int a[3][N], p[N];

inline void solve() {
  cin >> n;
  for (int i = 0; i < 3; ++i) {
    for (int j = 1; j <= n; ++j) {
      cin >> a[i][j];
    }
  }
  for (int i = 1, j = 0; i <= n; ++i) {
    p[i] = a[j][i];
    while (p[i] == p[i-1]) {
      j = (j+1)%3;
      p[i] = a[j][i];
    }
  }
  for (int i = 0; i < 3; ++i) {
    if (a[i][n] != p[1] && a[i][n] != p[n-1]) p[n] = a[i][n];
  }
  for (int i = 1; i <= n; ++i) cout << p[i] << " \n"[i==n];
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