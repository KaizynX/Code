/*
 * @Author: Kaizyn
 * @Date: 2020-05-26 22:28:05
 * @LastEditTime: 2020-05-26 23:08:07
 */ 
#include <bits/stdc++.h>

// #define DEBUG

using namespace std;

const double eps = 1e-7;
const double PI = acos(-1);
typedef pair<int, int> pii;
const int MOD = 998244353;
const int INF = 0x3f3f3f3f;
const int N = 1e2;

int u1, u2, v1, v2;
// int dp[N][N];

inline void solve() {
  cin >> u1 >> v1 >> u2 >> v2;
  int du = u2-u1+1,
      dv = v2-v1+1;
  cout << (du-1ll)*(dv-1ll)+1 << endl;
}

signed main() {
  ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
  /*
  dp[0][1] = 1;
  for (int i = 1; i <= 10; ++i) {
    for (int j = 1; j <= 10; ++j) {
      dp[i][j] = dp[i-1][j]+dp[i][j-1];
      cout << dp[i][j] << " \n"[j==10];
    }
  }
  */
  int T = 1;
  cin >> T;
  for (int t = 1; t <= T; ++t) {
    solve();
  }
  return 0;
}