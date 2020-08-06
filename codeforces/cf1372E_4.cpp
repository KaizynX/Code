/*
 * @Author: Kaizyn
 * @Date: 2020-07-12 10:01:32
 * @LastEditTime: 2020-07-12 10:19:24
 */ 
#include <bits/stdc++.h>

// #define DEBUG

using namespace std;

const double eps = 1e-7;
const double PI = acos(-1);
typedef pair<int, int> pii;
const int MOD = 998244353;
const int INF = 0x3f3f3f3f;
const int N = 1e2+7;

int n, m;
int L[N][N], R[N][N];
int dp[N][N];

inline void solve() {
  cin >> n >> m;
  for (int i = 1, k, l, r; i <= n; ++i) {
    cin >> k;
    while (k--) {
      cin >> l >> r;
      for (int j = l; j <= r; ++j) {
        L[i][j] = l;
        R[i][j] = r;
      }
    }
  }
  for (int len = 1; len <= m; ++len) {
    for (int l = 1, r; (r = l+len-1) <= m; ++l) {
      for (int k = l; k <= r; ++k) {
        int cnt = 0;
        for (int i = 1; i <= n; ++i) {
          if (L[i][k] >= l && R[i][k] <= r) ++cnt;
        }
        dp[l][r] = max(dp[l][r], dp[l][k-1]+cnt*cnt+dp[k+1][r]);
      }
    }
  }
  cout << dp[1][m] << endl;
}

signed main() {
  ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
  int T = 1;
  // cin >> T;
  for (int t = 1; t <= T; ++t) {
    solve();
  }
  return 0;
}
/*
7 8
1
1 8
2
1 5
6 8
4
1 1
2 2
3 4
5 8
4
1 3
4 4
5 5
6 8
2
1 7
8 8
2
1 6
7 8
3
1 1
2 2
3 8

94
*/