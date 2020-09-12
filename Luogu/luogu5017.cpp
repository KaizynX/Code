/*
 * @Author: Kaizyn
 * @Date: 2020-09-06 13:02:26
 * @LastEditTime: 2020-09-06 13:32:08
 */
#include <bits/stdc++.h>

// #define DEBUG

using namespace std;

const double eps = 1e-7;
const double PI = acos(-1);
typedef pair<int, int> pii;
const int MOD = 998244353;
const int INF = 0x3f3f3f3f;
const int N = 5e2+7;
const int M = 1e2+7;

int n, m;
int a[N], dp[N];
// dp[i] a car start at time a[i]

signed main() {
  ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
  cin >> n >> m;
  for (int i = 1; i <= n; ++i) cin >> a[i];
  sort(a+1, a+n+1);
  memset(dp, 0x3f, sizeof dp);
  dp[0] = 0;
  for (int i = 1; i <= n; ++i) {
    int sumt = a[i];
    // last car start is time a[j]
    for (int j = i-1; j; --j) {
      if (a[i]-a[j] >= m) dp[i] = min(dp[i], dp[j]+(i-j)*a[i]-sumt);
      sumt += a[j];
    }
    dp[i] = min(dp[i], dp[0]+i*a[i]-sumt);
  }
  cout << dp[n] << endl;
  return 0;
}