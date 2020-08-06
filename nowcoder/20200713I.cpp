/*
 * @Author: Kaizyn
 * @Date: 2020-07-13 16:25:16
 * @LastEditTime: 2020-07-13 16:55:13
 */ 
#include <bits/stdc++.h>

// #define DEBUG

using namespace std;

const double eps = 1e-7;
const double PI = acos(-1);
typedef pair<int, int> pii;
const int MOD = 998244353;
const int INF = 0x3f3f3f3f;
const int N = 5e2+7;

int n, m;
int road[N][N][2]; // 0 down 1 left
long long dp[N][N];

template <typename T>
inline void update(T &x, const T &y) {
  if (x == -1 || y < x) x = y;
}

inline void solve() {
  memset(road, -1, sizeof road);
  memset(dp, -1, sizeof dp);

  for (int i = 1, l, r, c; i <= m; ++i) {
    char dir;
    cin >> l >> r >> dir >> c;
    if (dir == 'L') {
      road[l][r][0] = c;
    } else {
      road[l][r-1][1] = c;
    }
  }
  for (int i = 1; i <= n; ++i) dp[i][n] = 0;
  for (int r = n; r; --r) {
    for (int l = r; l; --l) {
      if (dp[l][r] == -1) continue;
      if (road[l][r][0] != -1) {
        update(dp[l][r-1], dp[l][r]+road[l][r][0]);
      } else if (road[l][r][1] != -1) {
        update(dp[l-1][r], dp[l][r]+road[l][r][1]);
      }
    }
  }
  #ifdef DEBUG
  for (int r = n; r >= 0; --r) {
    for (int l = 0; l <= n; ++l) {
      cout << dp[l][r] << " \n"[l==n];
    }
  }
  #endif
  long long res = -1;
  for (int i = 0; i <= n; ++i) {
    if (dp[0][i] != -1) update(res, dp[0][i]);
  }
  cout << res << endl;
}

signed main() {
  ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
  while (cin >> n >> m) solve();
  return 0;
}