/*
 * @Author: Kaizyn
 * @Date: 2021-02-11 13:32:45
 * @LastEditTime: 2021-02-11 13:57:43
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
const int N = 5e2+1;

int n, x;
int a[N], dp[2][N][N];
// dp[i][j][k] when a[i] = j, x = k

template <typename T>
void update(T &x, const T &y) {
  if (x == -1 || y < x) x = y;
}

inline void solve() {
  cin >> n >> x;
  for (int i = 1; i <= n; ++i) cin >> a[i];
  memset(dp, -1, sizeof dp);
  dp[0][0][x] = 0;
  for (int i = 1; i <= n; ++i) {
    memset(dp[i&1], -1, sizeof dp[0]);
    // keep a[i]
    for (int j = 0; j < N; ++j) {
      for (int k = 0; k <= a[i]; ++k) { // a[i] >= a[i-1]
        if (~dp[~i&1][k][j]) update(dp[i&1][a[i]][j], dp[~i&1][k][j]);
      }
    }
    // swap(a[i], x)
    for (int j = 0; j < a[i]; ++j) { // a[i] > x
      for (int k = 0; k <= j; ++k) { // a[i] >= a[i-1]
        if (~dp[~i&1][k][j]) update(dp[i&1][j][a[i]], dp[~i&1][k][j]+1);
      }
    }
  }
  int res = -1;
  for (int j = 0; j < N; ++j) {
    for (int k = 0; k < N; ++k) {
      if (~dp[n&1][j][k]) update(res, dp[n&1][j][k]);
    }
  }
  cout << res << '\n';
}

signed main() {
#ifdef ONLINE_JUDGE
  ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
#endif
  int T = 1;
  cin >> T;
  for (int t = 1; t <= T; ++t) {
    solve();
  }
  return 0;
}