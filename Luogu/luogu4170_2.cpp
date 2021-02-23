/*
 * @Author: Kaizyn
 * @Date: 2021-02-15 14:15:13
 * @LastEditTime: 2021-02-15 14:41:28
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
const int N = 50+7;

int n;
char s[N];
int dp[N][N];
vector<int> p[26];

inline void solve() {
  cin >> (s+1);
  n = strlen(s+1);
  for (int i = 1; i <= n; ++i) dp[i][i] = 1;
  for (int len = 2; len <= n; ++len) {
    for (int l = 1, r = len; r <= n; ++l, ++r) {
      dp[l][r] = n;
      for (int k = l; k < r; ++k) {
        dp[l][r] = min(dp[l][r], dp[l][k]+dp[k+1][r]);
      }
      for (int i = 0; i < 26; ++i) p[i].assign({l-1});
      for (int i = l; i <= r; ++i) p[s[i]-'A'].emplace_back(i);
      for (int i = 0; i < 26; ++i) {
        int tmp = 1; // print [l, r] to i
        p[i].emplace_back(r+1);
        for (int j = 1; j < (int)p[i].size(); ++j) {
          tmp += dp[p[i][j-1]+1][p[i][j]-1];
        }
        dp[l][r] = min(dp[l][r], tmp);
      }
    }
  }
  cout << dp[1][n] << '\n';
}

signed main() {
#ifdef ONLINE_JUDGE
  ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
#endif
  int T = 1;
  // cin >> T;
  for (int t = 1; t <= T; ++t) {
    solve();
  }
  return 0;
}