/*
 * @Author: Kaizyn
 * @Date: 2020-08-04 11:58:50
 * @LastEditTime: 2020-08-04 16:18:18
 */

// #pragma comment (linker, "/STACK:204800000,204800000")

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
int fa[N];
ll res;
ll fa_val[N], sum[N];
vector<pii> e[N];
vector<ll> dp[N];
vector<int> rk[N];

#define v e[u][i].first
#define w e[u][i].second
ll dfs1(int u) {
  for (int i = 0; i < (int)e[u].size(); ++i) {
    if (v == fa[u]) continue;
    fa[v] = u;
    dp[u][i] = dfs1(v)+w;
    rk[u][i] = i;
  }
  sort(rk[u].begin(), rk[u].end(), [&](int x, int y) {
    return dp[u][x] > dp[u][y];
  });
  sum[u] = 0;
  for (int i = 0; i < (int)e[u].size() && i < k-1; ++i) {
    sum[u] += dp[u][rk[u][i]];
  }
  return sum[u];
}

void dfs2(int u) {
  sum[u] = 0;
  for (int i = 0; i < (int)e[u].size(); ++i) {
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
#define i rk[u][j]
  for (int j = 0; j < (int)e[u].size() && j < k-1; ++j) {
    if (v == fa[u]) continue;
    fa_val[v] = sum[u]+w-dp[u][i]+(k <= (int)e[u].size() ? dp[u][rk[u][k-1]] : 0);
    dfs2(v);
  }
  for (int j = k-1; j < (int)e[u].size(); ++j) {
    if (v == fa[u]) continue;
    fa_val[v] = sum[u]+w;
    dfs2(v);
  }
}
#undef i
#undef v
#undef w

void clear() {
  for (int i = 1; i <= n; ++i) {
    fa[i] = 0;
    fa_val[i] = 0;
    sum[i] = 0;
    vector<pii>().swap(e[i]);
    vector<ll>().swap(dp[i]);
    vector<int>().swap(rk[i]);
  }
}

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
  res = 0;
  dfs1(1);
  dfs2(1);
  return res;
}

signed main() {
  ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
  int T = 1;
  cin >> T;
  for (int t = 1; t <= T; ++t) {
    cout << solve() << endl;
    clear();
  }
  return 0;
}