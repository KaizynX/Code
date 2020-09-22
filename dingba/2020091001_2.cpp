/*
 * @Author: Kaizyn
 * @Date: 2020-09-10 20:42:05
 * @LastEditTime: 2020-09-12 14:27:24
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
int dp[N][N], nex[N][N];

inline void solve() {
  scanf("%s", s+1);
  n = strlen(s+1);
  for (int i = 0; i < 256; ++i) nex[n+1][i] = n+1;
  for (int i = n; i; --i) {
    for (int j = 'a'; j <= 'z'; ++j) nex[i][j] = nex[i+1][j];
    for (int j = 'A'; j <= 'Z'; ++j) nex[i][j] = nex[i+1][j];
    nex[i][s[i]] = i;
  }
  for (int len = 2; len <= n; ++len) {
    // for (int l = 1, r = len; (r = l+len-1) <= n; ++l) {
    for (int r = n, l = n-len+1; l; l = (--r-len+1)) {
      dp[l][r] = dp[l+1][r]+1;
      if (s[l] == s[l+1]) dp[l][r] = min(dp[l][r], dp[l+2][r]+1);
      for (int i = nex[l+2][s[l]]; i <= r; i = nex[i+1][s[l]]) {
        dp[l][r] = min(dp[l][r], dp[l+1][i-1]+dp[i+1][r]);
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