/*
 * @Author: Kaizyn
 * @Date: 2021-05-15 23:45:23
 * @LastEditTime: 2021-05-15 23:58:58
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
const int N = 1e6+7;

int n;
map<int, int> mp;
vector<int> fac[N];

inline void init() {
  for (int i = 2; i <= 1000'000; ++i) {
    for (int j = i; j <= 1000'000; j += i) {
      fac[j].emplace_back(i);
    }
  }
  mp[0] = 0;
  mp[1] = -INF;
  /*
  n = 1000;
  for (int i = 1; i <= n; ++i) {
    for (int j = 1; j <= n; ++j) {
      dp[i][j] = -INF;
    }
  }
  for (int i = 3; i <= n; ++i) dp[i][i] = 1;
  for (int i = 3; i <= n; ++i) {
    for (int j = 3; j <= n; ++j) {
      if (dp[i][j] >= 0) mp[{i, j}] = dp[i][j];
      for (int k = j+j; i+k <= n; k += j) {
        dp[i+k][k] = max(dp[i+k][k], dp[i][j]+1);
      }
    }
  }
  */
}

int dfs(int x) {
  if (mp.count(x)) return mp[x];
  int res = -INF;
  for (auto &i : fac[x]) {
    res = max(res, dfs(x/i-1)+1);
  }
  if (res >= 0) mp[x] = res;
  return res;
}

inline int solve() {
  cin >> n;
  int res = 0;
  for (int &i : fac[n]) if (i != 2) {
    res = max(res, dfs(n/i-1)+1);
  }
  return res;
}

signed main() {
#ifdef ONLINE_JUDGE
  ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
#endif
  init();
  int T = 1;
  cin >> T; // scanf("%d", &T);
  for (int t = 1; t <= T; ++t) {
    auto res = solve();
    cout << "Case #" << t << ": " << res << '\n';
  }
  return 0;
}