/*
 * @Author: Kaizyn
 * @Date: 2021-01-07 10:30:21
 * @LastEditTime: 2021-01-07 10:51:18
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
const int N = 1e3+7;

int n, m;
int dp[N];

inline void solve() {
  memset(dp+1, -1, sizeof(int)*(m));
  dp[0] = 0; // fuck
  for (int i = 1, a, b; i <= n; ++i) {
    cin >> a >> b;
    for (int j = m; j >= b; --j) {
      if (~dp[j-b]) dp[j] = max(dp[j], dp[j-b]+a);
    }
  }
  cout << dp[m] << endl;
}

signed main() {
#ifdef ONLINE_JUDGE
  ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
#endif
  while (cin >> m >> n) {
    if (m == -1 && n == -1) break;
    solve();
  }
  return 0;
}