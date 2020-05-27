/*
 * @Author: Kaizyn
 * @Date: 2020-05-22 22:15:00
 * @LastEditTime: 2020-05-24 14:02:18
 */ 
#include <bits/stdc++.h>

using namespace std;

const int N = 1e3+7;
// const int NN = sqrt(N)+7;
const int NN = 5;

int n, m, q, t;
char str[N];
int a[N][N], pre_sum[N][N], dp[N][N][NN]; // dp[i][j][k] don't include a[i][j]

signed main() {
  while (scanf("%d %d %d", &n, &m, &q) == 3) {
    for(int i = 1; i <= n; ++i) {
      scanf("%s", str+1);
      for (int j = 1; j <= m; ++j) {
        a[i][j] = str[j] == 'X';
      }
    }
    // t = sqrt(n);
    t = 3;
    for (int i = 1; i <= n; ++i) {
      for (int j = 1; j <= m; ++j) {
        pre_sum[i][j] = pre_sum[i][j-1]+a[i][j];
        for (int k = 1; k <= t; ++k) {
          dp[i][j][k] = a[i][j];
          if (i-k <= 0) continue;
          if (j-k > 0) {
            dp[i][j][k] += dp[i-k][j-k][k]+pre_sum[i-k][j]-pre_sum[i-k][j-k];
          } else {
            dp[i][j][k] += pre_sum[i-k][j];
            if (i-2*k > 0) dp[i][j][k] += dp[i-2*k][j][k]+pre_sum[i-2*k][j-1];
          }
          if (j+k <= m) {
            dp[i][j][k] += dp[i-k][j+k][k]+pre_sum[i-k][j+k-1]-pre_sum[i-k][j];
          } else {
            dp[i][j][k] += pre_sum[i-k][m]-pre_sum[i-k][j];
            if (i-2*k > 0) dp[i][j][k] += dp[i-2*k][j][k]+pre_sum[i-2*k][m]-pre_sum[i-2*k][j];
          }
          if (i-2*k > 0) dp[i][j][k] -= dp[i-2*k][j][k];
        }
      }
    }
    for (int i = 1, x, y, d, res; i <= q; ++i) {
      scanf("%d %d %d", &x, &y, &d);
      if (d <= t) res = dp[x][y][d];
      else {
        res = 0;
        for (int j = x, l = y, r = y; j > 0; j -= d) {
          res += pre_sum[j][r]-pre_sum[j][l-1];
          l = max(1, l-d);
          r = min(m, r+d);
        }
      }
      printf("%d\n", res);
    }
  }
  return 0;
}