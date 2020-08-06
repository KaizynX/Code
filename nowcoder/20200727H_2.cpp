/*
 * @Author: Kaizyn
 * @Date: 2020-07-27 11:58:57
 * @LastEditTime: 2020-07-27 20:49:53
 */ 
#include <bits/stdc++.h>

using namespace std;

const int MOD = 1e9+7;
const int N = 1e2+7;
const int M = 1e3;

int n;
int s[N];
long long dp[2][2][N][M<<1]; // [b == n][a == b][][a-b]
string str;

signed main() {
  ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
  cin >> str;
  n = str.size();
  for (int i = 1; i <= n; ++i) s[i] = str[i-1]-'0';
  dp[1][1][0][M] = 1;
  for (int i = 1, a, b; i <= n; ++i) {
    for (int j = M-900; j <= M+900; ++j) {
      dp[0][0][i-1][j] %= MOD;
      dp[0][1][i-1][j] %= MOD;
      dp[1][0][i-1][j] %= MOD;
      dp[1][1][i-1][j] %= MOD;
      for (b = 0; b <= 9; ++b) {
        for (a = 0; a <= 9; ++a) {
          dp[0][0][i][j+a-b] += dp[0][0][i-1][j];
          if (a == b) dp[0][1][i][j+a-b] += dp[0][1][i-1][j];
          if (a <  b) dp[0][0][i][j+a-b] += dp[0][1][i-1][j];
          if (b == s[i]) dp[1][0][i][j+a-b] += dp[1][0][i-1][j];
          if (b <  s[i]) dp[0][0][i][j+a-b] += dp[1][0][i-1][j];
          if (b == s[i] && a == b) dp[1][1][i][j+a-b] += dp[1][1][i-1][j];
          if (b == s[i] && a <  b) dp[1][0][i][j+a-b] += dp[1][1][i-1][j];
          if (b <  s[i] && a == b) dp[0][1][i][j+a-b] += dp[1][1][i-1][j];
          if (b <  s[i] && a <  b) dp[0][0][i][j+a-b] += dp[1][1][i-1][j];
        }
      }
    }
  }
  long long res = 0;
  for (int i = M+1; i <= M+900; ++i) {
    res += dp[0][0][n][i];
    res += dp[0][1][n][i];
    res += dp[1][0][n][i];
    res += dp[1][1][n][i];
    res %= MOD;
  }
  cout << res << endl;
  return 0;
}