/*
 * @Author: Kaizyn
 * @Date: 2021-01-05 15:56:42
 * @LastEditTime: 2021-01-05 16:29:35
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
const int N = 2e5+7;

int n, m;
map<int, int> mp;
int a[N], b[N], dp[N][4];

inline bool solve() {
  mp.clear();
  cin >> m >> n;
  for (int i = 1, r, c; i <= n; ++i) {
    cin >> r >> c;
    mp[c] |= 1<<(r-1);
  }
  n = 0;
  for (auto &p : mp) {
    ++n;
    a[n] = p.first;
    b[n] = p.second;
  }
  a[0] = 0; b[0] = 3;
  dp[0][3] = 1;
  int tmp[4];
  for (int i = 1; i <= n; ++i) {
    if ((a[i]-a[i-1])&1) swap(dp[i-1][1], dp[i-1][2]);
    tmp[0] = tmp[3] = dp[i-1][0]|dp[i-1][3];
    tmp[1] = dp[i-1][1];
    tmp[2] = dp[i-1][2];
    memset(dp[i], 0, sizeof dp[i]);
    for (int j = 0; j < 4; ++j) {
      if ((j&b[i]) == 0) dp[i][j|b[i]] |= tmp[j];
    }
    #ifdef DEBUG
    for (int j = 0; j < 4; ++j) cout << tmp[j] << " \n"[j==3];
    for (int j = 0; j < 4; ++j) cout << dp[i][j] << " \n"[j==3];
    #endif
  }
  return dp[n][0]|dp[n][3];
}

signed main() {
#ifdef ONLINE_JUDGE
  ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
#endif
  int T = 1;
  cin >> T;
  for (int t = 1; t <= T; ++t) {
    cout << (solve() ? "YES" : "NO") << endl;
  }
  return 0;
}