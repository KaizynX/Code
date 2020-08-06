/*
 * @Author: Kaizyn
 * @Date: 2020-07-19 14:40:01
 * @LastEditTime: 2020-07-19 14:42:40
 */ 
#include <bits/stdc++.h>

// #define DEBUG

using namespace std;

const double eps = 1e-7;
const double PI = acos(-1);
typedef pair<int, int> pii;
const int MOD = 998244353;
const int INF = 0x3f3f3f3f;
const int N = 1e3+7;

int dp[N][N];

inline void solve() {
  int a, b;
  cin >> a >> b;
  cout << dp[a][b] << endl;
}

signed main() {
  ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
  for (int i = 1; i <= 1000; ++i) {
    for (int j = 1; j <= 1000; ++j) {
      dp[i][j] = max(dp[i-1][j], dp[i][j-1])+(__gcd(i, j) == 1);
    }
  }
  cout.flush();
  int T = 1;
  cin >> T;
  for (int t = 1; t <= T; ++t) {
    solve();
  }
  return 0;
}