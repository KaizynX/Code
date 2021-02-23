/*
 * @Author: Kaizyn
 * @Date: 2021-02-16 19:10:12
 * @LastEditTime: 2021-02-16 22:32:22
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
const int B = 7;

int n;
int t[N], b[N], dp[N][1<<8][16];

template <typename T>
inline void update(T &x, const T &y) {
  if (x == -1 || y < x) x = y;
}

inline bool check(int i, int j) {
  for (int k = 0, l = 0; k < 8 && k <= i; ++k) {
    if ((j>>k)&1) {
      l = max(l, i-k);
    } else {
      if (l > i-k+b[i-k]) return false;
    }
  }
  return true;
}

inline void solve() {
  static const int b7 = 0b1111111;
  memset(dp, -1, sizeof dp);
  cin >> n;
  for (int i = 1; i <= n; ++i) cin >> t[i] >> b[i];
  dp[0][(1<<8)-1][0] = 0;
  for (int i = 1; i <= n; ++i) {
    for (int j = 1<<7; j < 1<<8; ++j) {
      for (int k = 0; k < 15; ++k) {
        int &last = dp[i-1][j][k];
        if (last == -1 || i-1-k < 0) continue;
        update(dp[i][(j&b7)<<1][k+1], last);
        if (check(i, (j&b7)<<1|1)) {
          update(dp[i][(j&b7)<<1|1][0], last+(i-1-k == 0 ? 0 : t[i-1-k]^t[i]));
        }
      }
    }
    for (int _ = 0, j; _ < 1<<7; ++_) {
      j = _<<1|1;
      if (!check(i, j)) continue;
      for (int k = 0; k < 8; ++k) if ((j>>k)&1) {
        int jj = j^(1<<k);
        for (int kk = 0; kk < 15; ++kk) if ((jj>>kk)&1) {
          int &last = dp[i][jj][kk];
          if (last == -1) continue;
          update(dp[i][j][k], last+(t[i-k]^t[i-kk]));
          // cout << i << ' ' << j << ' ' << k << ' ' << dp[i][j][k] << '\n';
        }
      }
    }
  }
  int res = -1;
  for (int k = 0; k < 15; ++k) {
    // cout << n << ' ' << (1<<8)-1 << ' ' << k << ' ' << dp[n][(1<<8)-1][k] << '\n';
    if (~dp[n][(1<<8)-1][k]) update(res, dp[n][(1<<8)-1][k]);
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