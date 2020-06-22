/*
 * @Author: Kaizyn
 * @Date: 2020-06-13 13:03:33
 * @LastEditTime: 2020-06-13 13:07:19
 */ 
#include <bits/stdc++.h>

// #define DEBUG

using namespace std;

const double eps = 1e-7;
const double PI = acos(-1);
typedef pair<int, int> pii;
const int MOD = 998244353;
const int INF = 0x3f3f3f3f;
const int N = 1e6+7;

int n;
int a[N];
long long dp[N][5];

inline void solve() {
  cin >> n;
  memset(dp, 0x3f, sizeof dp);
  long long sum = 0;
  dp[0][0] = 0;
  for (int i = 1; i <= n; ++i) {
    cin >> a[i];
    sum += a[i];
    for (int j = 0; j < 5; ++j) {
      dp[i][j] = min(dp[i-1][j], dp[i-1][((j-a[i])%5+5)%5]+a[i]);
    }
  }
  cout << sum-dp[n][sum%5] << endl;
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