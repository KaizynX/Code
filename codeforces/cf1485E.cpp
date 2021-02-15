/*
 * @Author: Kaizyn
 * @Date: 2021-02-13 21:52:12
 * @LastEditTime: 2021-02-13 22:15:53
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

int n, d;
int a[N], fa[N], min_val[N], max_val[N];
ll dp[N], min_dp[N], max_dp[N];
vector<int> e[N], p[N];

void dfs(int u, int dep) {
  d = max(d, dep);
  p[dep].emplace_back(u);
  min_val[dep] = min(min_val[dep], a[u]);
  max_val[dep] = max(max_val[dep], a[u]);
  for (int &v : e[u]) if (v != fa[u]) {
    fa[v] = u;
    dfs(v, dep+1);
  }
}

inline void solve() {
  d = 0;
  cin >> n;
  for (int i = 2, j; i <= n; ++i) {
    cin >> j;
    e[i].emplace_back(j);
    e[j].emplace_back(i);
  }
  for (int i = 2; i <= n; ++i) cin >> a[i];
  dfs(1, 0);
  ll res = 0;
  for (int dep = 1, val; dep <= n; ++dep) {
    for (int &i : p[dep]) {
      val = max(max_val[dep]-a[i], a[i]-min_val[dep]);
      dp[i] = val+max({dp[fa[i]],
          min_dp[dep-1]+a[fa[i]],
          max_dp[dep-1]-a[fa[i]]});
      min_dp[dep] = max(min_dp[dep], dp[i]-val-a[i]);
      max_dp[dep] = max(max_dp[dep], dp[i]-val+a[i]);
      res = max(res, dp[i]);
    }
  }
#ifdef DEBUG
  for (int i = 1; i <= n; ++i) cout << dp[i] << " \n"[i==n];
#endif
  cout << res << '\n';
}

signed main() {
#ifdef ONLINE_JUDGE
  ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
#endif
  int T = 1;
  cin >> T;
  for (int i = 0; i < N; ++i) {
    min_val[i] = INF;
    max_val[i] = -INF;
    min_dp[i] = -INF;
    max_dp[i] = -INF;
  }
  for (int t = 1; t <= T; ++t) {
    solve();
    for (int i = 1; i <= n; ++i) {
      e[i].clear();
    }
    for (int i = 1; i <= d; ++i) {
      p[i].clear();
      min_val[i] = INF;
      max_val[i] = -INF;
      min_dp[i] = -INF;
      max_dp[i] = -INF;
    }
  }
  return 0;
}