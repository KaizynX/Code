/*
 * @Author: Kaizyn
 * @Date: 2021-08-12 14:27:04
 * @LastEditTime: 2021-08-12 16:28:01
 */
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
const int N = 5e2+7;
const int B = 20;

int X;
ll l, r;
ll pw[B];
// dp[0|1:cur<y|cur==y][exist presum==0][exist presum==][leading zero][presum%X]
ll dp[B][2][2][2][2][N];

ll f(ll y) {
  ll res = 0;
  for (int sufsum = 0; sufsum < X; ++sufsum) {
    memset(dp, 0, sizeof dp); // attention!!!
    dp[19][1][0][sufsum == 0][1][0] = 1;
    // dp[19][1][0][0][1][0] = 1;
    for (int b = 18, by; b >= 0; --b) {
      by = y/pw[b]%10;
      for (int i1 : {0, 1}) for (int i2 : {0, 1}) for (int i3 : {0, 1}) for (int i4 : {0, 1})
      for (int presum = 0; presum < X; ++presum)
      for (int num = 0, cur; num <= (i1 ? by : 9); ++num) if (num != 7) {
        cur = (presum*10+num)%X;
        int ii4 = i4 && num == 0;
        dp[b][i1 && num == by][i2 || (!ii4 && cur == 0)][i3 || (b && pw[b]%X*cur%X == sufsum)][ii4][cur]
        // dp[b][i1 && num == by][i2 || (!ii4 && cur == 0)][i3 || pw[b+1]%X*presum%X == sufsum][ii4][cur]
            += dp[b+1][i1][i2][i3][i4][presum];
#ifdef DEBUG
        if (sufsum == 2) {
        printf("dp[%d][%d][%d][%d][%d][%d]=%lld+=",
        b,i1 && num == by,i2 || (!ii4 && cur == 0),i3 || cur == sufsum,ii4,cur,
        dp[b][i1 && num == by][i2 || (!ii4 && cur == 0)][i3 || cur == sufsum][ii4][cur]);
        printf("dp[%d][%d][%d][%d][%d][%d]=%lld,", b+1, i1, i2, i3, i4, sufsum, dp[b+1][i1][i2][i3][i4][presum]);
        printf("num=%d,cur=%d,by=%d\n", num, cur, by);
        }
/*
        if (i1 == 1 && i2 == 0 && i3 == 1 && i4 == 0 && sufsum == 2) {
        printf("dp[%d][%d][%d][%d][%d][%d]=%lld+=",
        b,i1 && num == by,i2 || (!i4 && cur == 0),i3 || cur == sufsum,i4 && num == 0,cur,
        dp[b][i1 && num == by][i2 || (!i4 && cur == 0)][i3 || cur == sufsum][i4 && num == 0][cur]);
        printf("dp[%d][%d][%d][%d][%d][%d]=%lld\n", b+1, i1, i2, i3, i4, sufsum, dp[b+1][i1][i2][i3][i4][presum]);
        }
        */
#endif
      }
#ifdef DEBUG
      /*
      if (sufsum == 2) {
        printf("dp[1][0][1][0][2]=%lld\n", dp[b][1][0][1][0][2]);
        printf("dp[1][0][1][1][2]=%lld\n", dp[b][1][0][1][1][2]);
      }
      */
#endif
    }
    for (int i1 : {0, 1}) for (int i2 : {0, 1}) for (int i3 : {0, 1}) {
      if (i2 || i3) {
        res += dp[0][i1][i2][i3][0][sufsum];
#ifdef DEBUG
        // printf("dp[%d][%d][%d][%d]=%lld\n", i1, i2, i3, sufsum, dp[0][i1][i2][i3][0][sufsum]);
#endif
      }
    }
  }
#ifdef DEBUG
  printf("f(%lld)=%lld\n", y, res);
#endif
  return res;
}

inline void solve() {
  cin >> l >> r >> X;
  cout << f(r)-f(l-1) << '\n';
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