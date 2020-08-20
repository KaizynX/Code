/*
 * @Author: Kaizyn
 * @Date: 2020-08-15 10:00:37
 * @LastEditTime: 2020-08-15 11:02:34
 */
#include <bits/stdc++.h>

// #define DEBUG

using namespace std;

#define lg2(x) (31-__builtin_clz(x))
typedef pair<int, int> pii;
const int INF = 0x3f3f3f3f;
const int N = 1e6+7;
const int NN = lg2(N)+3;

int n;
int dp[2][N][NN];
string s;

int get_next(const int &d, int p, int len) {
  for (int i = lg2(len); len; i = lg2(len)) {
    len ^= 1<<i;
    p = dp[d][p][i];
  }
  return p;
}

signed main() {
  ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
  cin >> n >> s;
  memset(dp, -1, sizeof dp);
  for (int i = n-1; i >= 0; --i) {
    for (int j = 0; j <= lg2(n-i); ++j) {
      dp[0][i][j] = dp[0][i+1][j];
      dp[1][i][j] = dp[1][i+1][j];
    }
    if (s[i-1] == '1' || s[i-1] == '?') {
      dp[1][i][0] = i;
      for (int j = 1; j <= lg2(n-i); ++j) {
        dp[1][i][j] = dp[1][dp[1][i][j-1]][j-1];
      }
    }
    if (s[i-1] == '0' || s[i-1] == '?') {
      dp[0][i][0] = i;
      for (int j = 1; j <= lg2(n-i); ++j) {
        dp[0][i][j] = dp[0][dp[0][i][j-1]][j-1];
      }
    }
  }
  for (int len = 1; len <= n; ++len) {
    int res = 0, i = 0, j = 0;
    while ((~(i = get_next(0, i, len))) || (~(j = get_next(1, j, len)))) {
      ++res;
      if (i == -1) i = j;
      else if (j == -1) j = i;
      else if (i < j) j = i;
      else if (i > j) i = j;
    }
    cout << res << endl;
  }
  return 0;
}