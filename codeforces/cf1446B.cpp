/*
 * @Author: Kaizyn
 * @Date: 2020-11-15 22:25:29
 * @LastEditTime: 2020-11-16 00:10:18
 */
#include <bits/stdc++.h>

// #define DEBUG

using namespace std;

const double eps = 1e-7;
const double PI = acos(-1);
typedef pair<int, int> pii;
const int MOD = 998244353;
const int INF = 0x3f3f3f3f;
const int N = 5e3+7;

int n, m;
int dp[N][N];
string A, B;

inline void solve() {
  int res = 0;
  cin >> n >> m >> A >> B;
  for (int i = 1; i <= n; ++i) {
    for (int j = 1; j <= m; ++j) {
      if (A[i-1] == B[j-1]) {
        dp[i][j] = dp[i-1][j-1]+2;
      }
      dp[i][j] = max({0, dp[i][j], dp[i-1][j]-1, dp[i][j-1]-1});
      res = max(res, dp[i][j]);
    }
  }
  cout << res << endl;
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