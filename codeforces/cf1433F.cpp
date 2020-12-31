/*
 * @Author: Kaizyn
 * @Date: 2020-12-24 15:19:03
 * @LastEditTime: 2020-12-24 15:29:19
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
const int N = 70+7;

int n, m, k;
int dp[N][N][N];
// dp[i][j][l] on i'th row choose j's %k == l

template <typename T>
void update(T &x, const T &y) {
  if (y > x) x = y;
}

inline void solve() {
  cin >> n >> m >> k;
  memset(dp, 0x9f, sizeof dp);
  dp[0][0][0] = 0;
  for (int i = 1, a; i <= n; ++i) {
    memcpy(dp[i][0], dp[i-1][m], sizeof(int)*k);
    for (int j = 0; j <= m/2; ++j) {
      for (int l = 0; l < k; ++l) {
        update(dp[i][0][l], dp[i-1][j][l]);
      }
    }
    for (int j = 1; j <= m; ++j) {
      cin >> a;
      for (int c = min(j, m/2); c; --c) {
        for (int l = 0; l < k; ++l) {
          update(dp[i][c][(l+a)%k], dp[i][c-1][l]+a);
        }
      }
    }
  }
  int res = 0;
  for (int i = 0; i <= m/2; ++i) {
    update(res, dp[n][i][0]);
  }
  cout << res << endl;
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