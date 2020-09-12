/*
 * @Author: Kaizyn
 * @Date: 2020-09-10 19:25:10
 * @LastEditTime: 2020-09-10 19:34:38
 */
#include <bits/stdc++.h>

// #define DEBUG

using namespace std;

const double eps = 1e-7;
const double PI = acos(-1);
typedef pair<int, int> pii;
const int MOD = 998244353;
const int INF = 0x3f3f3f3f;
const int N = 1e2+7;

int n, m;
int a[N];
int dp[N*3];

signed main() {
  ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
  cin >> n >> m;
  for (int i = 1; i <= m; ++i) cin >> a[i];
  sort(a+1, a+m+1);
  reverse(a+1, a+m+1);
  for (int u = 1000; u; --u) {
    int tot = 0;
    for (int i = 1; i <= m && a[i] >= u; ++i) {
      tot += a[i]/u;
    }
    memset(dp, 0x3f, sizeof dp);
    dp[0] = 0;
    for (int i = 1; i <= m && a[i] >= u; ++i) {
      int t = a[i]/u;
      for (int j = 2*n; j >= t; --j) {
        dp[j] = min(dp[j], dp[j-t]+a[i]);
      }
    }
    int res = INF;
    for (int i = n; i <= 2*n; ++i) res = min(res, dp[i]);
    if (tot >= n) return cout << u << " " << res << endl, 0;
  }
  cout << "0 0\n";
  return 0;
}