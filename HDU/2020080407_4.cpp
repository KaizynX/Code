/*
 * @Author: Kaizyn
 * @Date: 2020-08-04 11:58:50
 * @LastEditTime: 2020-08-04 15:10:37
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
const int N = 2e5+7;

int n, k;
int fa[N], id[N];
ll res;
ll fa_val[N], sum[N];
vector<pii> e[N];
vector<ll> dp[N];
vector<int> rk[N];
queue<int> q;

inline ll solve() {
  cin >> n >> k;
  for (int i = 1, u, v, w; i < n; ++i) {
    cin >> u >> v >> w;
    e[u].emplace_back(v, w);
    e[v].emplace_back(u, w);
  }
  if (k == 0) return 0;
  for (int i = 1; i <= n; ++i) {
    dp[i].resize(e[i].size(), 0);
    rk[i].resize(e[i].size());
  }
  int tot = 0;
  q.push(1);
  while (q.size()) {
    int u = q.front();
    q.pop();
    id[++tot] = u;
    for (int i = 0, v; i < (int)e[u].size(); ++i) {
      v = e[u][i].first;
      if (v == fa[u]) continue;
      fa[v] = u;
      q.push(v);
    }
  }
  res = 0;
  // dfs1
  for (int _ = n, u; _; --_) {
    u = id[_];
    for (int i = 0, v, w; i < (int)e[u].size(); ++i) {
      v = e[u][i].first;
      w = e[u][i].second;
      if (v == fa[u]) continue;
      dp[u][i] = sum[v]+w;
      rk[u][i] = i;
    }
    sort(rk[u].begin(), rk[u].end(), [&](int x, int y) {
      return dp[u][x] > dp[u][y];
    });
    sum[u] = 0;
    for (int i = 0; i < (int)e[u].size() && i < k-1; ++i) {
      sum[u] += dp[u][rk[u][i]];
    }
  }
  // dfs2
  for (int _ = 1, u; _ <= n; ++_) {
    u = id[_];
    sum[u] = 0;
    for (int i = 0, v; i < (int)e[u].size(); ++i) {
      v = e[u][i].first;
      if (v == fa[u]) dp[u][i] = fa_val[u];
      sum[u] += dp[u][i];
      rk[u][i] = i;
    }
    res = max(res, sum[u]);
    sum[u] = 0;
    sort(rk[u].begin(), rk[u].end(), [&](int x, int y) {
      return dp[u][x] > dp[u][y];
    });
    for (int i = 0; i < (int)e[u].size() && i < k-1; ++i) sum[u] += dp[u][rk[u][i]];
    for (int j = 0, i, v, w; j < (int)e[u].size() && j < k-1; ++j) {
      i = rk[u][j];
      v = e[u][i].first;
      w = e[u][i].second;
      if (v == fa[u]) continue;
      fa_val[v] = sum[u]+w-dp[u][i]+(k <= (int)e[u].size() ? dp[u][rk[u][k-1]] : 0);
    }
    for (int j = k-1, i, v, w; j < (int)e[u].size(); ++j) {
      i = rk[u][j];
      v = e[u][i].first;
      w = e[u][i].second;
      if (v == fa[u]) continue;
      fa_val[v] = sum[u]+w;
    }
  }
  // clear
  for (int i = 1; i <= n; ++i) {
    fa[i] = 0;
    fa_val[i] = 0;
    sum[i] = 0;
    vector<pii>().swap(e[i]);
    vector<ll>().swap(dp[i]);
    vector<int>().swap(rk[i]);
  }
  return res;
}

signed main() {
  ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
  int T = 1;
  cin >> T;
  for (int t = 1; t <= T; ++t) {
    cout << solve() << endl;
  }
  return 0;
}