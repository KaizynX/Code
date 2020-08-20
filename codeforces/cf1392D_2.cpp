/*
 * @Author: Kaizyn
 * @Date: 2020-08-16 22:50:12
 * @LastEditTime: 2020-08-16 23:34:28
 */
#include <bits/stdc++.h>

#define DEBUG

using namespace std;

const double eps = 1e-7;
const double PI = acos(-1);
typedef pair<int, int> pii;
const int MOD = 998244353;
const int INF = 0x3f3f3f3f;
const int N = 2e5+7;

int n;
string s;
int a[N<<1];
int dp[N<<1][2][2]; // dp[i][j][k] a[i]==j, a[i-1]==k

bool check(int x, int y, int z) {
  return !(x == y && y == z);
}

inline void solve() {
  cin >> n >> s;
  for (int i = 0; i < n; ++i) {
    a[i+n] = a[i] = s[i] == 'L';
  }
  int res = n;
  for (int a0 = 0; a0 < 2; ++a0)
  for (int a1 = 0; a1 < 2; ++a1) {
    int cur = n;
    memset(dp[1], 0x3f, sizeof dp[1]);
    dp[1][a1][a0] = (a0 != a[0])+(a[1] != a1);
    for (int i = 2; i < n; ++i)
    for (int j = 0; j < 2; ++j)
    for (int k = 0; k < 2; ++k) {
      if (j == k) dp[i][j][k] = (a[i] != j)+dp[i-1][k][k^1];
      else dp[i][j][k] = (a[i] != j)+min(dp[i-1][k][0], dp[i-1][k][1]);
      if (i == n-1 && check(j, k, a0) && check(j, a0, a1)) cur = min(cur, dp[i][j][k]);
    }
    res = min(res, cur);
  }
  cout << res << endl;
}

signed main() {
  ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
  int T = 1;
  cin >> T;
  for (int t = 1; t <= T; ++t) {
    solve();
  }
  return 0;
}