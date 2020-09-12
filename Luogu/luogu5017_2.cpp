/*
 * @Author: Kaizyn
 * @Date: 2020-09-06 13:02:26
 * @LastEditTime: 2020-09-06 14:49:33
 */
#include <bits/stdc++.h>

// #define DEBUG

using namespace std;

const double eps = 1e-7;
const double PI = acos(-1);
typedef pair<int, int> pii;
const int MOD = 998244353;
// const int INF = 0x3f3f3f3f;
// const int INF = 2e9;
const long long INF = 1e18;
const int N = 5e2+7;
const int M = 1e2+7;
const int T = 4e6+M;

int n, m;
int a[N], t[T];
long long dp[T];
// dp[i] a car start at time i

signed main() {
  ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
  cin >> n >> m;
  for (int i = 1; i <= n; ++i) cin >> a[i];

  int st = 1e9, ed = 0;
  for (int i = 1; i <= n; ++i) {
    ++a[i];
    ++t[a[i]];
    st = min(st, a[i]);
    ed = max(ed, a[i]);
  }
  long long res = INF;
  for (int i = st, r = 0; i <= ed+m; ++i) {
    if (t[i]) r = i+m;
    if (i > r) {
      dp[i] = dp[i-m];
      continue;
    }
    dp[i] = INF;
    long long sum = 0, cnt = 0;
    for (long long j = i; j > i-m && j; --j) {
      sum += t[j]*j;
      cnt += t[j];
    }
    // last time is j, current time is i
    for (long long j = i-m; j > i-2*m && j; --j) {
      dp[i] = min(dp[i], dp[j]+cnt*i-sum);
      sum += t[j]*j;
      cnt += t[j];
    }
    if (i <= m) dp[i] = min(dp[i], cnt*i-sum);
    if (i >= ed) res = min(res, dp[i]);
  }
  cout << res << endl;
  return 0;
}