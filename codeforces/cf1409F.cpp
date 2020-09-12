/*
 * @Author: Kaizyn
 * @Date: 2020-09-05 16:11:00
 * @LastEditTime: 2020-09-05 16:24:11
 */
#include <bits/stdc++.h>

// #define DEBUG

using namespace std;

const double eps = 1e-7;
const double PI = acos(-1);
typedef pair<int, int> pii;
const int MOD = 998244353;
const int INF = 0x3f3f3f3f;
const int N = 2e2+7;

int n, K;
string s, t;
int dp[N][N][N];
// dp[i][j][k] at pos i, change j times, has k's t[0], max number 

void update(int &x, int y) { if (y > x) x = y; }

inline void solve() {
  cin >> n >> K >> s >> t;
  if (t[0] == t[1]) {
    int cnt = 0;
    for (const char &c : s) cnt += c == t[0];
    cnt = min(cnt+K, n);
    cout << cnt*(cnt-1)/2 << endl;
    return;
  }
  memset(dp, 0x9f, sizeof dp);
  dp[0][0][0] = 0;
  for (int i = 1; i <= n; ++i) {
    for (int j = 0; j <= K; ++j) {
      for (int k = 0; k <= i; ++k) {
        int &cur = dp[i][j][k];
        if (s[i-1] == t[0]) {
          if (k) update(cur, dp[i-1][j][k-1]);
        } else if (s[i-1] == t[1]) {
          update(cur, dp[i-1][j][k]+k);
        }
        // make no change
        update(cur, dp[i-1][j][k]);
        // change to t[0]
        if (j && k) update(cur, dp[i-1][j-1][k-1]);
        // change to t[1]
        if (j) update(cur, dp[i-1][j-1][k]+k);
      }
    }
  }
  int res = 0;
  for (int i = 0; i <= K; ++i) {
    for (int j = 0; j <= n; ++j) {
      update(res, dp[n][i][j]);
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