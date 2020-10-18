/*
 * @Author: Kaizyn
 * @Date: 2020-10-10 23:35:27
 * @LastEditTime: 2020-10-11 01:46:38
 */
#include <bits/stdc++.h>

// #define DEBUG

using namespace std;

const double eps = 1e-7;
const double PI = acos(-1);
typedef pair<int, int> pii;
const int MOD = 998244353;
const int INF = 0x3f3f3f3f;
const int N = 1e5+3;

int R, n;
int t[N], x[N], y[N], dp[N];

int dis(int i, int j) {
  return abs(x[i]-x[j])+abs(y[i]-y[j]);
}

signed main() {
  scanf("%d%d", &R, &n);
  t[0] = 0; x[0] = y[0] = 1;
  int res = 0, mx = -INF;
  for (int i = 1, last = 0; i <= n; ++i) {
    scanf("%d%d%d", t+i, x+i, y+i);
    while (last < i && t[i]-t[last] >= 2*(R-1)) {
      mx = max(mx, dp[last++]);
    }
    dp[i] = mx+1;
    for (int j = last; j < i; ++j) {
      if (t[i]-t[j] >= dis(i, j)) {
        dp[i] = max(dp[i], dp[j]+1);
      }
    }
    res = max(res, dp[i]);
  }
  #ifdef DEBUG
  for (int i = 1; i <= n; ++i)
    cout << dp[i] << " \n"[i==n];
  #endif
  printf("%d\n", res);
  return 0;
}