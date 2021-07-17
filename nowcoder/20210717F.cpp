/*
 * @Author: Kaizyn
 * @Date: 2021-07-17 12:15:07
 * @LastEditTime: 2021-07-17 12:42:08
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
const int N = 20;

ll pw[N];
// dp[1] equal dp[0] <=
ll dp[2][N][27][3];

int add(int k, int l) {
  if (l == 0) {
    if (k%3 < 2) k += 1;
  } else if (l == 1) {
    if (k/3%3 < 2) k += 3;
  } else {
    if (k/9%3 < 2) k += 9;
  }
  return k;
}

ll f(ll x) {
  memset(dp, 0, sizeof dp);
  int i = 0;
  while (i < 18 && pw[i+1] <= x) ++i;
  for (; i >= 0; --i) {
    int b = x/pw[i]%10;
    for (int j = 0; j < 3; ++j) {
      for (int k = 0; k < 27; ++k) {
        for (int l = 0; l < 10; ++l) {
          if (l == b) {
            dp[1][i][add(k, l%3)][(j+b)%3] += dp[1][i+1][k][j];
            dp[0][i][add(k, l%3)][(j+b)%3] += dp[0][i+1][k][j];
          } else if (l < b) {
            dp[0][i][add(k, l%3)][(j+b)%3] += dp[1][i+1][k][j]+dp[0][i+1][k][j];
          } else {
            dp[0][i][add(k, l%3)][(j+b)%3] += dp[0][i+1][k][j];
          }
        }
      }
    }
  }
  ll res = 0;
  for (int j = 0; j < 3; ++j) {
    for (int k = 0; k < 27; ++k) {
      if (k%3 == 2 || k/3%3 == 2 || k/9%3 == 2) {
        res += dp[0][0][k][j]+dp[1][0][k][j];
      }
    }
  }
  return res;
}

inline void solve() {
  ll L, R;
  cin >> L >> R;
  ll ans = f(R)-f(L-1);
  cout << ans << '\n';
}

signed main() {
#ifdef ONLINE_JUDGE
  ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
#endif
  pw[0] = 1;
  for (int i = 1; i <= 18; ++i) pw[i] = pw[i-1]*10;
  int T = 1;
  cin >> T; // scanf("%d", &T);
  for (int t = 1; t <= T; ++t) {
    solve();
  }
  return 0;
}