/*
 * @Author: Kaizyn
 * @Date: 2020-08-30 23:22:52
 * @LastEditTime: 2020-08-31 00:12:02
 */
#include <bits/stdc++.h>

#define DEBUG

using namespace std;

const double eps = 1e-7;
const double PI = acos(-1);
typedef pair<int, int> pii;
const int MOD = 998244353;
const int INF = 0x3f3f3f3f;
const int N = 1e6+7;

int n;
long long r1, r2, r3, d;
int a[N];
long long b[N][4], dp[N][4];

inline void solve() {
  cin >> n >> r1 >> r2 >> r3 >> d;
  for (int i = 1; i <= n; ++i) cin >> a[i];

  for (int i = 1; i <= n; ++i) {
    b[i][1] = min(a[i]*r1+2*r1, a[i]*r1+r3)+d;
    b[i][1] = a[i]*r1+r3+d;
    b[i][2] = min(a[i]*r1+2*r1, r2+r1)+2*d;
    b[i][3] = b[i][2]+d;
  }
  memset(dp, 0x3f, sizeof dp);
  dp[1][1] = b[1][1]-d;
  dp[1][2] = b[1][2]-d;
  dp[2][1] = dp[1][1]+b[2][1];
  dp[2][2] = min(dp[1][1], dp[1][2])+b[2][2];
  dp[2][3] = dp[1][2]+b[2][3];
  for (int i = 3; i <= n; ++i) {
    for (int j = 1; j <= 3; ++j) {
      for (int k = 1; k <= 3; ++k) {
        if (abs(j-k) > 1) continue;
        for (int l = 1; l <= 3; ++l) {
          if (abs(k-l) > 1) continue;
          // [l, k, j]
          if (i != n && l == 1 && k == 2 && j == 1) continue;
          // if (i != n && l == 3 && k == 2 && j == 2) continue;
          dp[i][j] = min(dp[i][j], dp[i-2][l]+b[i-1][k]+b[i][j]);
        }
      }
    }
  }
  cout << min(dp[n][1], dp[n][2]) << endl;
  #ifdef DEBUG
  cout << "****\n";
  for (int i = 1; i <= n; ++i) {
    for (int j = 1; j <= 3; ++j) {
      cout << b[i][j] << " \n"[j==3];
    }
  }
  cout << "****\n";
  for (int i = 1; i <= n; ++i) {
    for (int j = 1; j <= 3; ++j) {
      cout << dp[i][j] << " \n"[j==3];
    }
  }
  #endif
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