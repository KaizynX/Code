/*
 * @Author: Kaizyn
 * @Date: 2021-08-17 14:44:00
 * @LastEditTime: 2021-08-17 15:07:08
 */
#pragma GCC optimize("Ofast,no-stack-protector")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,avx2,tune=native")
#include <bits/stdc++.h>

// #define DEBUG

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
const double eps = 1e-7;
const double PI = acos(-1);
const int MOD = 998244353; // 1e9+7;
const int INF = 0x3f3f3f3f;
// const ll INF = 1e18;
const int N = 2e3+7;
const int M = 51*51*51*51+7;

int n;
int a[5][N], sz[5], _sz[5];
int dp[5][M];

int mp(int i1, int i2, int i3, int i4) {
  return i1+i2*sz[1]+i3*sz[2]+i4*sz[3];
}

inline void solve() {
  cin >> n;
  memset(sz, 0, sizeof sz);
  for (int i = 1, d, id; i <= n; ++i) {
    cin >> d >> id;
    a[id][++sz[id]] = d;
  }
  sz[0] = 1;
  for (int i = 1; i <= 4; ++i) {
    sort(a[i]+1, a[i]+sz[i]+1);
    _sz[i] = sz[i];
    sz[i] = (sz[i]+1)*sz[i-1];
  }
  memset(dp, 0x3f, sizeof dp);
  memset(dp[0], 0, sizeof dp[0]);
  for (int i1 = 0; i1 <= _sz[1]; ++i1)
  for (int i2 = 0; i2 <= _sz[2]; ++i2)
  for (int i3 = 0; i3 <= _sz[3]; ++i3)
  for (int i4 = 0; i4 <= _sz[4]; ++i4) {
    int u = mp(i1, i2, i3, i4);
    if (i1) dp[0][u] = max(dp[0][u], dp[1][mp(i1-1, i2, i3, i4)]+a[1][i1]);
    if (i2) dp[0][u] = max(dp[0][u], dp[2][mp(i1, i2-1, i3, i4)]+a[2][i2]);
    if (i3) dp[0][u] = max(dp[0][u], dp[3][mp(i1, i2, i3-1, i4)]+a[3][i3]);
    if (i4) dp[0][u] = max(dp[0][u], dp[4][mp(i1, i2, i3, i4-1)]+a[4][i4]);
    for (int i = 1; i <= 4; ++i) {
      dp[i][u] = min(dp[i][u], dp[i-1][mp(max(i1-1, 0), i2, i3, i4)]);
      dp[i][u] = min(dp[i][u], dp[i-1][mp(i1, max(i2-1, 0), i3, i4)]);
      dp[i][u] = min(dp[i][u], dp[i-1][mp(i1, i2, max(i3-1, 0), i4)]);
      dp[i][u] = min(dp[i][u], dp[i-1][mp(i1, i2, i3, max(i4-1, 0))]);
    }
    #ifdef DEBUG
    for (int i = 0; i <= 4; ++i)
    printf("dp[%d][%d][%d][%d][%d]=%d\n", i, i1, i2, i3, i4, dp[i][u]);
    #endif
  }
  cout << dp[0][mp(_sz[1], _sz[2], _sz[3], _sz[4])] << '\n';
}

signed main() {
#ifdef ONLINE_JUDGE
  ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
#endif
  int T = 1;
  cin >> T; // scanf("%d", &T);
  for (int t = 1; t <= T; ++t) {
    solve();
  }
  return 0;
}