/*
 * @Author: Kaizyn
 * @Date: 2020-07-19 13:55:51
 * @LastEditTime: 2020-07-19 14:14:38
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
const int M = 1e4+7;

int n, m;
int dp[M+100];

inline void update(int &x, const int &y) {
  if (x == -1 || y < x) x = y;
}

inline void solve() {
  cin >> n >> m;
  /*
  memset(dp, -1, sizeof(int)*(m+101));
  dp[0] = 0;
  for (int i = 1, x, y; i <= n; ++i) {
    cin >> x >> y;
    for (int j = x; j <= m+100; ++j) {
      if (dp[j-x] != -1) update(dp[j], dp[j-x]+y);
    }
  }
  int res = -1;
  for (int i = m; i <= m+100; ++i) {
    if (dp[i] != -1) update(res, dp[i]);
  }
  cout << res << endl;
  */
 int res = INF;
 for (int i = 1, x, y; i <= n; ++i) {
   cin >> x >> y;
   res = min(res, (m+x-1)/x*y);
 }
 cout << res << endl;
}

signed main() {
  ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
  int T = 1;
  cin >> T;
  for (int t = 1; t <= T; ++t) {
    solve();
  }
  return 0;
}