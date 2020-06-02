/*
 * @Author: Kaizyn
 * @Date: 2020-06-01 08:30:28
 * @LastEditTime: 2020-06-01 20:23:47
 */ 
#include <bits/stdc++.h>

// #define DEBUG

using namespace std;

const double eps = 1e-7;
const double PI = acos(-1);
typedef pair<int, int> pii;
const int MOD = 998244353;
const int INF = 0x3f3f3f3f;
const int N = 3e3+7;

int n, s;
int a[N];
int dp[N][N];

inline void solve() {
  cin >> n >> s;
  for (int i = 1; i <= n; ++i) cin >> a[i];
  dp[0][0] = 1;
  for (int i = 1; i <= n; ++i) {
    for (int j = 0; j <= s; ++j) {
      dp[i][j] = dp[i-1][j]*2%MOD;
    }
    for (int j = s; j >= a[i]; --j) {
      (dp[i][j] += dp[i-1][j-a[i]]) %= MOD;
    }
  }
  cout << dp[n][s] << endl;
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