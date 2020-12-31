/*
 * @Author: Kaizyn
 * @Date: 2020-12-30 22:33:21
 * @LastEditTime: 2020-12-30 23:04:43
 */
#include <bits/stdc++.h>

// #define DEBUG

using namespace std;

const double eps = 1e-7;
const double PI = acos(-1);
typedef pair<int, int> pii;
typedef long long ll;
const int MOD = 998244353;
const int INF = 0x3f3f3f3f;
// const ll INF = 1e18;
const int N = 1e5+7;

int n;
char c[N];
int a[N];
int dp[N][26];

inline int solve() {
  scanf("%s", c+1);
  n = strlen(c+1);
  for (int i = 1; i <= n; ++i) {
    a[i] = c[i]-'a';
  }
  for (int i = 0; i < 26; ++i) {
    dp[1][i] = a[1] != i;
    dp[2][i] = (a[2] != i)+(a[1] == i);
  }
  for (int i = 3; i <= n; ++i) {
    for (int j = 0; j < 26; ++j) {
      dp[i][j] = n;
      for (int k = 0; k < 26; ++k) if (k != j) {
        dp[i][j] = min(dp[i][j], dp[i-2][k]+(a[i-1] == j || a[i-1] == k));
      }
      dp[i][j] += a[i] != j;
    }
  }
  int res = n;
  for (int i = 0; i < 26; ++i) {
    res = min(res, dp[n][i]);
  }
  return res;
}

signed main() {
#ifdef ONLINE_JUDGE
  // ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
#endif
  int T = 1;
  // cin >> T;
  scanf("%d", &T);
  for (int t = 1; t <= T; ++t) {
    printf("%d\n", solve());
  }
  return 0;
}