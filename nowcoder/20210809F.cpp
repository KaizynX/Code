/*
 * @Author: Kaizyn
 * @Date: 2021-08-09 14:07:56
 * @LastEditTime: 2021-08-09 14:23:49
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
const int N = 5e2+3;
const int Q = 5e5+7;
using bt = bitset<500*500>;

int n, m, q;
vector<pii> qry[N*N];
int res[Q];
char a[N][N];
bt dp[2][N];

inline void solve() {
  scanf("%d%d", &n, &m);
  for (int i = 0; i < n; ++i) scanf("%s", a[i]);
  scanf("%d", &q);
  for (int i = 0, t, xl, xr, yl, yr; i < q; ++i) {
    scanf("%d%d%d%d%d", &t, &xl, &yl, &xr, &yr);
    --xl; --yl; --xr; --yr;
    if (t == 1 && yl != yr) continue;
    if (t == 2 && xl != xr) continue;
    qry[xl*m+yl].emplace_back(i, xr*m+yr);
  }
  for (int i = n-1; i >= 0; --i) {
    for (int j = m-1; j >= 0; --j) {
      if (a[i][j] == '1') {
        dp[i&1][j] = 0;
      } else {
        dp[i&1][j] = dp[i&1][j+1]|dp[~i&1][j];
        dp[i&1][j][i*m+j] = 1;
      }
      for (const auto &item : qry[i*m+j]) {
        res[item.first] = dp[i&1][j][item.second];
      }
    }
  }
  for (int i = 0; i < q; ++i) {
    puts(res[i] ? "yes" : "no");
  }
}

signed main() {
#ifdef ONLINE_JUDGE
  ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
#endif
  int T = 1;
  // cin >> T; // scanf("%d", &T);
  for (int t = 1; t <= T; ++t) {
    solve();
  }
  return 0;
}