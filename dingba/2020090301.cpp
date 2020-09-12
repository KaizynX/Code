/*
 * @Author: Kaizyn
 * @Date: 2020-09-03 19:00:05
 * @LastEditTime: 2020-09-03 21:26:12
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

int n;
int dis[N][N], a[N][N];

signed main() {
  ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
  cin >> n;
  int res = 0;
  for (int i = 1; i <= n; ++i) {
    for (int j = 1; j <= n; ++j) {
      cin >> dis[i][j];
      a[i][j] = INF;
    }
  }
  for (int i = 1; i <= n; ++i) {
    for (int j = i+1; j <= n; ++j) {
      if (dis[i][j] == 1) {
        ++res;
        a[i][j] = a[j][i] = 1;
      }
    }
  }
  for (int k = 1; k <= n; ++k) {
    for (int i = 1; i <= n; ++i) {
      for (int j = 1; j <= n; ++j) {
        a[i][j] = min(a[i][j], a[i][k]+a[k][j]);
      }
    }
  }
  for (int i = 1; i <= n; ++i) {
    for (int j = i+1; j <= n; ++j) {
      assert(a[i][j] >= dis[i][j]);
    }
  }
  cout << res << endl;
  return 0;
}