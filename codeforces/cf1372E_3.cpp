/*
 * @Author: Kaizyn
 * @Date: 2020-07-12 10:01:32
 * @LastEditTime: 2020-07-12 10:14:22
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
int L[N][N][N], R[N][N][N];
int dp[N][N];

inline int calc(const int &l, const int &r, const int &k) {
  int cnt = 0;
  for (int i = 1; i <= n; ++i) {
    if (L[i][l][r] <= k && R[i][l][r] >= k) ++cnt;
  }
  return cnt*cnt;
}

inline void solve() {
  cin >> n >> m;
  memset(L, 0x3f, sizeof L);
  for (int row = 1, k, l, r; row <= n; ++row) {
    cin >> k;
    while (k--) {
      cin >> l >> r;
      for (int i = 1; i <= m; ++i) {
        for (int j = i; j <= m; ++j) {
          if (l >= i) L[row][i][j] = min(L[row][i][j], l);
          if (r <= j) R[row][i][j] = max(R[row][i][j], r);
        }
      }
    }
  }
  for (int i = 1; i <= m; ++i) {
    for (int j = i; j <= m; ++j) {
      for (int k = i; k <= j; ++k) {
        dp[i][j] = max(dp[i][j], dp[i][k-1]+calc(i, j, k)+dp[k+1][j]);
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