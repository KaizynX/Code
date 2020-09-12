/*
 * @Author: Kaizyn
 * @Date: 2020-09-10 20:42:05
 * @LastEditTime: 2020-09-10 21:39:51
 */
#include <bits/stdc++.h>

// #define DEBUG

using namespace std;

const double eps = 1e-7;
const double PI = acos(-1);
typedef pair<int, int> pii;
const int MOD = 998244353;
const int INF = 0x3f3f3f3f;
const int N = 7e2+7;

int n;
char s[N];
int dp[N][N];

inline void solve() {
  scanf("%s", s+1);
  n = strlen(s+1);
  for (int len = 2; len <= n; ++len) {
    for (int l = 1, r = len; (r = l+len-1) <= n; ++l) {
      dp[l][r] = len;
      for (int k = l; k < r; ++k) {
        dp[l][r] = min(dp[l][r], dp[l][k]+dp[k+1][r]);
      }
      for (int i = 0; l+i < r-i; ++i) {
        if (s[l+i] != s[r-i]) break;
        dp[l][r] = min(dp[l][r], dp[l+i+1][r-i-1]+1);
        for (int k = l+i+1; k <= r-i-1; ++k) {
          dp[l][r] = min(dp[l][r], dp[l+i+1][k-1]+dp[k+1][r-i-1]+1);
        }
      }
    }
  }
  printf("%d\n", dp[1][n]);
}

signed main() {
  for (int i = 0; i < N; ++i) dp[i][i] = 1;
  int T = 1;
  scanf("%d", &T);
  for (int t = 1; t <= T; ++t) {
    solve();
  }
  return 0;
}