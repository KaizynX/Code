/*
 * @Author: Kaizyn
 * @Date: 2020-12-14 13:49:42
 * @LastEditTime: 2020-12-14 14:53:54
 */
#include <bits/stdc++.h>

// #define DEBUG

using namespace std;

const double eps = 1e-7;
const double PI = acos(-1);
typedef pair<int, int> pii;
const int MOD = 998244353;
const int INF = 0x3f3f3f3f;
const int N = 3e3+7;

int n;
int a[N], dp[N][2];
// dp[i][0] 从i出发到n无法到达最小删除数
// dp[i][1] 从i出发到n只有一条最小删除数

inline void solve() {
  cin >> n;
  for (int i = 1; i <= n; ++i) cin >> a[i];
  dp[n][0] = INF;
  dp[n][1] = 0;
  for (int i = n-1; i; --i) {
    int sum = 0, mn = INF;
    dp[i][1] = INF;
    for (int j = i+1; j <= i+a[i]; ++j) {
      sum += dp[j][0];
      mn = min(mn, -dp[j][0]+dp[j][1]);
      dp[i][1] = min(dp[i][1], sum+mn+1);
    }
    dp[i][1] = min(dp[i][1], sum+mn);
    dp[i][0] = min(1, sum);
  }
#ifdef DEBUG
  puts("*************");
  for (int i = 1; i <= n; ++i) {
    printf("dp[%d] %d %d\n", i, dp[i][0], dp[i][1]);
  }
  puts("*************");
#endif
  cout << dp[1][1] << endl;
}

signed main() {
#ifndef DEBUG
  ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
#endif
  int T = 1;
  cin >> T;
  for (int t = 1; t <= T; ++t) {
    solve();
  }
  return 0;
}
/*
1
4
3 1 1 0
*/