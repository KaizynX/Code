/*
 * @Author: Kaizyn
 * @Date: 2021-03-26 21:20:19
 * @LastEditTime: 2021-03-26 21:24:22
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
const int N = 1e3+7;

int n, x, y; // CJ-x, JC-y
string s;
int dp[N][2]; // 0-C, 1-J

inline int solve() {
  cin >> x >> y >> s;
  n = s.size();
  dp[0][0] = s[0] == 'J' ? INF : 0;
  dp[0][1] = s[0] == 'C' ? INF : 0;
  for (int i = 1; i < n; ++i) {
    dp[i][0] = dp[i][1] = INF;
    if (s[i] != 'J') {
      dp[i][0] = min({dp[i][0], dp[i-1][0], dp[i-1][1]+y});
    }
    if (s[i] != 'C') {
      dp[i][1] = min({dp[i][1], dp[i-1][1], dp[i-1][0]+x});
    }
  }
  return min(dp[n-1][0], dp[n-1][1]);
}

signed main() {
#ifdef ONLINE_JUDGE
  ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
#endif
  int T = 1;
  cin >> T; // scanf("%d", &T);
  for (int t = 1; t <= T; ++t) {
    cout << "Case #" << t << ": " << solve() << '\n';
  }
  return 0;
}