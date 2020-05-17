/*
 * @Author: Kaizyn
 * @Date: 2020-05-10 14:42:24
 * @LastEditTime: 2020-05-10 14:55:51
 */
#include <bits/stdc++.h>

// #define DEBUG

using namespace std;

const double eps = 1e-7;
const double PI = acos(-1);
typedef pair<int, int> pii;
const int MOD = 998244353;
const long long INF = 1e18;
const int N = 1e3+7;

int n, s;
int p[N], t[N];
long long dp[N][N][2];

inline void solve() {
  cin >> n;
  for (int i = 1; i <= n; ++i) {
    cin >> p[i];
  }
  for (int i = 1; i <= n; ++i) {
    cin >> t[i];
    if (t[i] == 0) s = i;
  }
  /*
  if (s == 1) {
    long long cur = 0;
    for (int i = 2; i <= n; ++i) {
      cur += p[i]-p[i-1];
      if (cur > t[i]) return void(cout << -1 << endl);
    }
    return void(cout << cur << endl);
  } else if (s == n) {
    long long cur = 0;
    for (int i = n-1; i; --i) {
      cur += p[i+1]-p[i];
      if (cur > t[i]) return void(cout << -1 << endl);
    }
    return void(cout << cur << endl);
  }
  */
  memset(dp, 0x3f, sizeof dp);
  dp[s][s][0] = dp[s][s][1] = 0;
  for (int i = 1; i <= n-1; ++i) {
    for (int j = 0, l, r; j <= i; ++j) {
      l = s-j;
      r = s+(i-j);
      if (l < 1 || r > n) continue;
      dp[l][r][0] = min(
          dp[l+1][r][0]+p[l+1]-p[l],
          dp[l+1][r][1]+p[r]-p[l]
      );
      dp[l][r][1] = min(
          dp[l][r-1][0]+p[r]-p[l],
          dp[l][r-1][1]+p[r]-p[r-1]
      );
      if (dp[l][r][0] > t[l]) dp[l][r][0] = INF;
      if (dp[l][r][1] > t[r]) dp[l][r][1] = INF;
    }
  }
  long long res = min(dp[1][n][0], dp[1][n][1]);
  cout << (res >= INF ? -1 : res) << endl;
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