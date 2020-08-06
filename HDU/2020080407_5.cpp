/*
 * @Author: Kaizyn
 * @Date: 2020-08-04 11:58:50
 * @LastEditTime: 2020-08-04 15:32:14
 */

#pragma GCC optimize("Ofast,no-stack-protector")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,avx2,tune=native")
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
ll fa_val[N], sum[N], dp[N<<1];
int head[N], nex[N<<1], v[N<<1], w[N<<1], tot;
vector<int> rk[N];
queue<int> q;

inline bool cmp(int x, int y) {
  return dp[x] > dp[y];
}

inline void add_edge(int uu, int vv, int ww) {
  ++tot;
  v[tot] = vv;
  w[tot] = ww;
  dp[tot] = 0;
  nex[tot] = head[uu];
  head[uu] = tot;
}

inline void clear() {
  tot = 0;
  for (int i = 1; i <= n; ++i) {
    head[i] = 0;
    fa[i] = 0;
    fa_val[i] = 0;
    sum[i] = 0;
  }
}

inline ll solve() {
  // cin >> n >> k;
  scanf("%d %d", &n, &k);
  for (int i = 1, u, v, w; i < n; ++i) {
    // cin >> u >> v >> w;
    scanf("%d %d %d", &u, &v, &w);
    add_edge(u, v, w);
    add_edge(v, u, w);
  }
  if (k == 0) return 0;
  int m = 0;
  q.push(1);
  while (q.size()) {
    int u = q.front();
    q.pop();
    id[++m] = u;
    for (int i = head[u]; i; i = nex[i]) {
      if (v[i] == fa[u]) continue;
      fa[v[i]] = u;
      q.push(v[i]);
    }
  }
  res = 0;
  // dfs1
  for (int _ = n, u; _; --_) {
    u = id[_];
    rk[u].clear();
    for (int i = head[u]; i; i = nex[i]) {
      if (v[i] == fa[u]) continue;
      fa[v[i]] = u;
      dp[i] = sum[v[i]]+w[i];
      rk[u].emplace_back(i);
    }
    // sort(rk[u].begin(), rk[u].end(), cmp);
    int sz = rk[u].size();
    nth_element(rk[u].begin(), rk[u].begin()+min(k-1, sz-1), rk[u].end(), cmp);
    sum[u] = 0;
    for (int i = 0; i < sz && i < k-1; ++i) {
      sum[u] += dp[rk[u][i]];
    }
  }
  // dfs2
  for (int _ = 1, u; _ <= n; ++_) {
    u = id[_];
    sum[u] = 0;
    for (int i = head[u]; i; i = nex[i]) {
      if (v[i] == fa[u]) dp[i] = fa_val[u], rk[u].emplace_back(i);
      sum[u] += dp[i];
    }
    res = max(res, sum[u]);
    sum[u] = 0;
    int sz = rk[u].size();
    // sort(rk[u].begin(), rk[u].end(), cmp);
    nth_element(rk[u].begin(), rk[u].begin()+min(k-1, sz-1), rk[u].end(), cmp);
    for (int i = 0; i < sz && i < k-1; ++i) sum[u] += dp[rk[u][i]];
  #define i rk[u][j]
    for (int j = 0; j < sz && j < k-1; ++j) {
      if (v[i] == fa[u]) continue;
      fa_val[v[i]] = sum[u]+w[i]-dp[i]+(k <= sz ? dp[rk[u][k-1]] : 0);
    }
    for (int j = k-1; j < sz; ++j) {
      if (v[i] == fa[u]) continue;
      fa_val[v[i]] = sum[u]+w[i];
    }
  #undef i
  }
  return res;
}

signed main() {
  // ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
  int T = 1;
  scanf("%d", &T);
  for (int t = 1; t <= T; ++t) {
    // cout << solve() << endl;
    printf("%lld\n", solve());
    clear();
  }
  return 0;
}