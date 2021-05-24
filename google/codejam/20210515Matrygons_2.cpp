/*
 * @Author: Kaizyn
 * @Date: 2021-05-15 23:40:21
 * @LastEditTime: 2021-05-15 23:42:50
 */
#include <bits/stdc++.h>

// #define DEBUG

using namespace std;

const double eps = 1e-7;
const double PI = acos(-1);
typedef pair<int, int> pii;
typedef long long ll;
const int MOD = 998244353; // 1e9+7;
const int INF = 0x3f3f3f3f;
// const ll INF = 1e18;
const int N = 1e6+7;

int n;
map<int, int> dp[N];

inline int solve() {
  cin >> n;
  for (int i = 0; i <= n; ++i) dp[i].clear();
  for (int i = 3; i <= n; ++i) dp[i][i] = 1;
  for (int i = 3; i <= n; ++i) {
    for (auto &p : dp[i]) {
      int j = p.first;
      int v = p.second;
      for (int k = j+j; i+k <= n; k += j) {
        dp[i+k][k] = max(dp[i+k][k], v+1);
      }
    }
  }
  int res = 0;
  for (auto &p : dp[n]) res = max(res, p.second);
  return res;
}

signed main() {
#ifdef ONLINE_JUDGE
  ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
#endif
  int T = 1;
  cin >> T; // scanf("%d", &T);
  for (int t = 1; t <= T; ++t) {
    auto res = solve();
    cout << "Case #" << t << ": " << res << '\n';
  }
  return 0;
}