/*
 * @Author: Kaizyn
 * @Date: 2020-09-07 19:21:40
 * @LastEditTime: 2020-09-07 19:26:40
 */
#include <bits/stdc++.h>

// #define DEBUG

using namespace std;

const double eps = 1e-7;
const double PI = acos(-1);
typedef pair<int, int> pii;
const int MOD = 998244353;
const int INF = 0x3f3f3f3f;
const int N = 2e3+7;

int n;
int a[N], l[N], r[N];
int sum[N], dp[N][N];

signed main() {
  ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
  cin >> n;
  for (int i = 1; i <= n; ++i) {
    cin >> a[i];
  }
  for (int i = 1; i <= n; ++i) {
    cin >> l[i] >> r[i];
  }
  sum[0] = 1;
  for (int i = 1; i <= n; ++i) {
    for (int j = l[i]; j <= r[i]; ++j) {
      dp[i][j] = (sum[i-1]-dp[i-1][j]+MOD)%MOD;
      (sum[i] += dp[i][j]) %= MOD;
    }
  }
  cout << sum[n] << endl;
  return 0;
}