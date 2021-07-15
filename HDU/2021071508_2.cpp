/*
 * @Author: Kaizyn
 * @Date: 2021-07-15 13:59:03
 * @LastEditTime: 2021-07-15 14:12:05
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
const int N = 50+7;
const int M = 15000+7;
const int T = 5e2+7;

int n, m, t, p;
// cost y day gain x
int id[M], x[M], y[M];
// dp[i][j] cost i day the most mark can gain
int dp[N][T], f[N][5][T];
string str;
map<string, int> mp;

inline void solve() {
  mp.clear();
  memset(dp, 0, sizeof dp);
  memset(f, -1, sizeof f);
  cin >> n;
  for (int i = 1; i <= n; ++i) {
    cin >> str;
    mp[str] = i;
  }
  cin >> m;
  for (int i = 1; i <= m; ++i) {
    cin >> str;
    id[i] = mp[str];
    cin >> x[i] >> y[i];
  }
  cin >> t >> p;
  for (int i = 1; i <= m; ++i) {
    for (int j = t; j >= y[i]; --j) {
      dp[id[i]][j] = max(dp[id[i]][j], min(100, dp[id[i]][j-y[i]]+x[i]));
    }
  }
  f[0][0][0] = 0;
  for (int i = 1; i <= n; ++i) {
    for (int l = 0; l <= p; ++l) {
      for (int j = 0; j <= t; ++j) {
        for (int k = j; k <= t; ++k) {
          if (f[i-1][l][k-j] == -1) continue;
          if (dp[i][j] >= 60) f[i][l][k] = max(f[i][l][k], f[i-1][l][k-j]+dp[i][j]);
          else f[i][l+1][k] = max(f[i][l+1][k], f[i-1][l][k-j]+dp[i][j]);
        }
      }
    }
  }
  int res = -1;
  for (int i = 0; i <= p; ++i) {
    res = max(res, f[n][i][t]);
  }
  cout << res << '\n';
}

signed main() {
#ifdef ONLINE_JUDGE
  ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
#endif
  int Test = 1;
  cin >> Test; // scanf("%d", &T);
  for (int t = 1; t <= Test; ++t) {
    solve();
  }
  return 0;
}