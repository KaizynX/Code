/*
 * @Author: Kaizyn
 * @Date: 2020-05-22 22:15:00
 * @LastEditTime: 2020-05-22 23:25:01
 */ 
#include <bits/stdc++.h>

using namespace std;

const int N = 1e3+7;

int n, m, q;
char str[N];
int pre_sum[N][N];

signed main() {
  while (scanf("%d %d %d", &n, &m, &q) == 3) {
    for(int i = 1; i <= n; ++i) {
      scanf("%s", str+1);
      for (int j = 1; j <= m; ++j) {
        pre_sum[i][j] = pre_sum[i][j-1]+(str[j] == 'X');
      }
    }
    for (int i = 1, x, y, d, res; i <= q; ++i) {
      scanf("%d %d %d", &x, &y, &d);
      res = 0;
      for (int j = x, l = y, r = y; j > 0; j -= d) {
        res += pre_sum[j][r]-pre_sum[j][l-1];
        l = max(1, l-d);
        r = min(m, r+d);
      }
      printf("%d\n", res);
    }
  }
  return 0;
}