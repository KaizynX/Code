/*
 * @Author: Kaizyn
 * @Date: 2020-07-09 17:56:52
 * @LastEditTime: 2020-07-09 18:06:34
 */ 
#include <bits/stdc++.h>

// #define DEBUG

using namespace std;

const double eps = 1e-7;
const double PI = acos(-1);
typedef pair<int, int> pii;
const int MOD = 998244353;
const int INF = 0x3f3f3f3f;
const int N = 407;

int n;
int a[N][N];

inline void solve() {
  double mid = 0;
  int x = 1, y = 1;
  for (int i = 1; i <= n; ++i) {
    for (int j = 1; j <= n; ++j) {
      scanf("%d", &a[i][j]);
      mid += a[i][j];
    }
  }
  mid /= n*n;
  for (int i = 1; i <= n; ++i) {
    for (int j = 1; j <= n; ++j) {
      if (abs(a[i][j]-mid) < abs(a[x][y]-mid)) {
        x = i;
        y = j;
      }
    }
  }
  printf("%.2f %d %d\n", mid, x, y);
}

signed main() {
  // ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
  while (scanf("%d", &n) == 1) solve();
  return 0;
}