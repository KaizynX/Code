/*
 * @Author: Kaizyn
 * @Date: 2021-02-15 15:01:17
 * @LastEditTime: 2021-02-15 15:02:06
 */
#include <bits/stdc++.h>

// #define DEBUG

using namespace std;

const double eps = 1e-7;
const double PI = acos(-1);
typedef pair<int, int> pii;
typedef long long ll;
const int MOD = 998244353;
const int INF = 0x3f3f3f3f;
// const ll INF = 1e18;
const int N = 50+7;

int n;
char s[N];
int dp[N][N];

inline void solve() {
  cin >> (s+1);
  n = strlen(s+1);
  for (int i = 1; i <= n; ++i) dp[i][i] = 1;
  for (int len = 2; len <= n; ++len) {
    for (int l = 1, r = len; r <= n; ++l, ++r) {
      dp[l][r] = n;
      if (s[l] == s[r]) dp[l][r] = min(dp[l+1][r], dp[l][r-1]);
      for (int k = l; k < r; ++k) {
        dp[l][r] = min(dp[l][r], dp[l][k]+dp[k+1][r]);
      }
    }
  }
  cout << dp[1][n] << '\n';
}

signed main() {
#ifdef ONLINE_JUDGE
  ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
#endif
  int T = 1;
  // cin >> T;
  for (int t = 1; t <= T; ++t) {
    solve();
  }
  return 0;
}