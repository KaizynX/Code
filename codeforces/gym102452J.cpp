/*
 * @Author: Kaizyn
 * @Date: 2020-06-23 13:11:04
 * @LastEditTime: 2020-06-24 21:09:41
 */ 
#include <bits/stdc++.h>

// #define DEBUG

using namespace std;

const int MOD = 1e9+7;
const int N = 5e3+7;
const int M = 65;

int m;
int pw10[N];
int dp[2][N][M][M];
// dp[][第i位][前面数位的和][模 == f(x)-x]

long long calc(const char *num) {
  int len = strlen(num), dig = num[0]-'0';
  // init
  pw10[0] = 1;
  for (int i = 1; i < len; ++i) pw10[i] = pw10[i-1]*10%m;
  for (int i = 0; i < len; ++i) {
    for (int j = 0; j < m; ++j) {
      for (int k = 0; k < m; ++k) {
        dp[0][i][j][k] = dp[1][i][j][k] = 0;
      }
    }
  }
  // 首位(最高位)
  for (int i = 0; i < dig; ++i) {
    dp[0][0][i%m][(-i*pw10[len-1]%m+m)%m] += 1;
  }
  dp[1][0][dig%m][(-dig*pw10[len-1]%m+m)%m] += 1;
  for (int i = 1; i < len; ++i) {
    dig = num[i]-'0';
    for (int j = 0; j < m; ++j) {
      for (int k = 0; k < m; ++k) {
        // 当前位
        for (int d = 0; d < 10; ++d) {
          int &nex = dp[0][i][(j+d)%m][((k+j*d-d*pw10[len-i-1])%m+m)%m];
          (nex += dp[0][i-1][j][k]) %= MOD;
          if (d < dig) (nex += dp[1][i-1][j][k]) %= MOD;
        }
        (dp[1][i][(j+dig)%m][((k+j*dig-dig*pw10[len-i-1])%m+m)%m] += dp[1][i-1][j][k]) %= MOD;
      }
    }
  }
  long long res = 0;
  for (int i = 0; i < m; ++i) {
    (res += dp[0][len-1][i][0]+dp[1][len-1][i][0]) %= MOD;
  }
  return res;
}

inline int check(const char *num) {
  int p10 = 1, res = 0, sum = 0, dig;
  for (int i = strlen(num)-1; i >= 0; --i) {
    dig = num[i]-'0';
    (res += dig*sum-dig*p10) %= m;
    (p10 *= 10) %= m;
    (sum += dig) %= m;
  }
  return res == 0;
}

inline void solve() {
  static char L[N], R[N];
  scanf("%s%s%d", L, R, &m);
  printf("%lld\n", (0ll+calc(R)-calc(L)+check(L)+MOD)%MOD);
}

signed main() {
  pw10[0] = 1;
  int T = 1;
  scanf("%d", &T);
  for (int t = 1; t <= T; ++t) {
    solve();
  }
  return 0;
}