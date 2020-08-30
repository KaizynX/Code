/*
 * @Author: Kaizyn
 * @Date: 2020-08-23 16:07:19
 * @LastEditTime: 2020-08-23 16:22:22
 */
#include <bits/stdc++.h>

// #define DEBUG

using namespace std;

const double eps = 1e-7;
const double PI = acos(-1);
typedef pair<int, int> pii;
const int MOD = 998244353;
const int INF = 0x3f3f3f3f;
const int N = 1e2+7;

typedef long long ll;
ll dp[52][52][52][4];
void solve() {
    int n, m, k;
    for (int i = 1; i <= 50; ++i) {
      n = m = k = i;
    // while (cin >> n >> m >> k) {
        memset(dp, 0, sizeof(dp));
        dp[n][m][k][3] = 1;
        for (int i = n; i >= 0; i--) {
            for (int j = m; j >= 0; j--) {
                for (int p = k; p >= 0; p--) {
                    for (int l = 0; l <= 3; l++) {
                        if (l == 3) {
                            if (i > 0) dp[i-1][j][p][0] += dp[i][j][p][l];
                            if (j > 0) dp[i][j-1][p][1] += dp[i][j][p][l];
                            if (p > 0) dp[i][j][p-1][2] += dp[i][j][p][l];
                        }
                        if (l == 0) {
                            if (j > 0) dp[i][j-1][p][1] += dp[i][j][p][l];
                            if (p > 0) dp[i][j][p-1][2] += dp[i][j][p][l];
                        }
                        if (l == 1) {
                            if (i > 0) dp[i-1][j][p][0] += dp[i][j][p][l];
                            if (p > 0) dp[i][j][p-1][2] += dp[i][j][p][l];
                        }
                        if (l == 2) {
                            if (i > 0) dp[i-1][j][p][0] += dp[i][j][p][l];
                            if (j > 0) dp[i][j-1][p][1] += dp[i][j][p][l];
                        }
                    }
                }
            }
        }
        ll sum = 0;
        for (int l = 0; l <= 3; l++) {
            sum += dp[0][0][0][l];
        }
        cout << i << ":";
        cout << sum << endl;
    }
}

signed main() {
  ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
  int T = 1;
  // cin >> T;
  for (int t = 1; t <= T; ++t) {
    solve();
  }
  return 0;
}