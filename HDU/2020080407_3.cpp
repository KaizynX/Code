/*
 * @Author: Kaizyn
 * @Date: 2020-08-04 11:58:50
 * @LastEditTime: 2020-08-04 15:13:03
 */
// #pragma comment (linker, "/STACK:102400000,102400000")

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
ll fa_val[N], sum[N], dp[N<<1];
int head[N], nex[N<<1], v[N<<1], w[N<<1], tot;
vector<int> rk[N];

inline bool cmp(int x, int y) {
  return dp[x] > dp[y];
}

ll dfs1(int u) {
  rk[u].clear();
  for (int i = head[u]; i; i = nex[i]) {
    if (v[i] == fa[u]) continue;
    fa[v[i]] = u;
    dp[i] = dfs1(v[i])+w[i];
    rk[u].emplace_back(i);
  }
  sort(rk[u].begin(), rk[u].end(), cmp);
  sum[u] = 0;
  for (int i = 0; i < (int)rk[u].size() && i < k-1; ++i) {
    sum[u] += dp[rk[u][i]];
  }
  return sum[u];
}

void dfs2(int u) {
  sum[u] = 0;
  for (int i = head[u]; i; i = nex[i]) {
    if (v[i] == fa[u]) dp[i] = fa_val[u], rk[u].emplace_back(i);
    sum[u] += dp[i];
  }
  res = max(res, sum[u]);
  sum[u] = 0;
  sort(rk[u].begin(), rk[u].end(), cmp);
  for (int i = 0; i < (int)rk[u].size() && i < k-1; ++i) sum[u] += dp[rk[u][i]];
#define i rk[u][j]
  for (int j = 0; j < (int)rk[u].size() && j < k-1; ++j) {
    if (v[i] == fa[u]) continue;
    fa_val[v[i]] = sum[u]+w[i]-dp[i]+(k <= (int)rk[u].size() ? dp[rk[u][k-1]] : 0);
    dfs2(v[i]);
  }
  for (int j = k-1; j < (int)rk[u].size(); ++j) {
    if (v[i] == fa[u]) continue;
    fa_val[v[i]] = sum[u]+w[i];
    dfs2(v[i]);
  }
#undef i
}

inline void add_edge(int uu, int vv, int ww) {
  ++tot;
  v[tot] = vv;
  w[tot] = ww;
  dp[tot] = 0;
  nex[tot] = head[uu];
  head[uu] = tot;
}

inline ll solve() {
  cin >> n >> k;
  for (int i = 1, u, v, w; i < n; ++i) {
    cin >> u >> v >> w;
    add_edge(u, v, w);
    add_edge(v, u, w);
  }
  if (k == 0) return 0;
  res = 0;
  dfs1(1);
  #ifdef DEBUG
  for (int i = 1; i <= n; ++i) cout << sum[i] << " \n"[i==n];
  #endif
  dfs2(1);
  #ifdef DEBUG
  for (int i = 1; i <= n; ++i) cout << sum[i] << " \n"[i==n];
  for (int i = 1; i <= n; ++i) cout << fa_val[i] << " \n"[i==n];
  cout.flush();
  #endif
  // clear
  tot = 0;
  for (int i = 1; i <= n; ++i) {
    head[i] = 0;
    fa[i] = 0;
    fa_val[i] = 0;
    rk[i].clear();
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