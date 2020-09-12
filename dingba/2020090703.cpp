/*
 * @Author: Kaizyn
 * @Date: 2020-09-07 19:21:40
 * @LastEditTime: 2020-09-07 19:37:33
 */
#include <bits/stdc++.h>

#define DEBUG

using namespace std;

const double eps = 1e-7;
const double PI = acos(-1);
typedef pair<int, int> pii;
const int MOD = 998244353;
const int INF = 0x3f3f3f3f;
const int N = 2e3+7;

int n;
int a[N], l[N], r[N];
int buf1[N][N<<2], buf2[N][N<<2];
int *dp[N], *sum[N];

signed main() {
  ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
  for (int i = 0; i < N; ++i) {
    dp[i] = buf1[i]+(N<<1);
    sum[i] = buf2[i]+(N<<1);
  }

  cin >> n;
  for (int i = 1; i <= n; ++i) cin >> a[i];
  for (int i = 1; i <= n; ++i) cin >> l[i] >> r[i];
  for (int i = a[1]-r[1]; i <= a[1]-l[1]; ++i) sum[0][i] = 1;
  for (int i = 1; i <= n; ++i) {
    // l <= a-b <= r
    for (int j = a[i]-r[i]; j <= a[i]-l[i]; ++j) {
      // a[i]-b[i] != a[i-1]-b[i-1]
      int k = a[i-1]-a[i]+j;
      dp[i][j] = sum[i-1][j];
      if (k <= j) (dp[i][j] -= dp[i-1][k]) %= MOD;
      sum[i][j] = (sum[i][j-1]+dp[i][j])%MOD;
      #ifdef DEBUG
      printf("dp[%d][%d]=%d\n", i, j, dp[i][j]);
      #endif
    }
    for (int j = a[i]-l[i]+1; j <= a[i+1]-l[i+1]; ++j) {
      sum[i][j] = sum[i][j-1];
    }
  }
  cout << (sum[n][a[n]-l[n]]+MOD)%MOD << endl;
  return 0;
}