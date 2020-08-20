/*
 * @Author: Kaizyn
 * @Date: 2020-08-13 13:00:19
 * @LastEditTime: 2020-08-13 13:55:11
 */
#pragma GCC optimize("Ofast,no-stack-protector")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,avx2,tune=native")
#include <bits/stdc++.h>

// #define DEBUG

using namespace std;

const double eps = 1e-7;
const double PI = acos(-1);
typedef pair<int, int> pii;
const int MOD = 998244353;
const int INF = 0x3f3f3f3f;
const int N = 2e3+7;

int n, m;
int l[N], r[N], minv[N], mminv[N];
int dp[N][N<<1];
vector<int> e[N];
vector<int> dis;

inline void init_val(const int &u) {
  minv[u] = mminv[u] = INF;
  for (int i = l[u]; i <= r[u]; ++i) {
    if (dp[u][i] < minv[u]) {
      minv[u] = dp[u][i];
    } else if (dp[u][i] < mminv[u]) {
      mminv[u] = dp[u][i];
    }
  }
}

inline int get_val(const int &v, const int &i) {
  if (i < l[v] || i > r[v]) {
    return minv[v]+1;
  } else if (l[v] == r[v]) { // l[v] == r[v] == i
    return dp[v][i];
  } else {
    return min(dp[v][i], (dp[v][i] == minv[v] ? mminv[v] : minv[v])+1);
  }
}

void dfs(const int &u, const int &fa) {
  // clear
  for (int i = l[u]; i <= r[u]; ++i) dp[u][i] = 0;

  for (const int &v : e[u]) if (v != fa) {
    dfs(v, u);
    for (int i = l[u]; i <= r[u]; ++i) {
      dp[u][i] += get_val(v, i);
    }
  }
  init_val(u);
}

inline void discrete() {
  // static vector<int> dis;
  dis.clear();
  dis.emplace_back(0);
  for (int i = 1; i <= n; ++i) {
    dis.emplace_back(l[i]);
    dis.emplace_back(r[i]);
  }
  sort(dis.begin(), dis.end());
  dis.erase(unique(dis.begin(), dis.end()), dis.end());
  m = dis.size();
  for (int i = 1; i <= n; ++i) {
    l[i] = lower_bound(dis.begin(), dis.end(), l[i])-dis.begin();
    r[i] = lower_bound(dis.begin(), dis.end(), r[i])-dis.begin();
  }
  // l[0] = r[0] = lower_bound(dis.begin(), dis.end(), 0)-dis.begin();
}

inline void solve() {
  cin >> n;
  for (int i = 1, u, v; i < n; ++i) {
    cin >> u >> v;
    e[u].emplace_back(v);
    e[v].emplace_back(u);
  }
  for (int i = 1; i <= n; ++i) {
    cin >> l[i] >> r[i];
  }
  discrete();
  dfs(1, 0);
  int zero = lower_bound(dis.begin(), dis.end(), 0)-dis.begin();
  int res = get_val(1, zero);
  cout << res << endl;
}

signed main() {
  int T = 1;
  cin >> T;
  for (int t = 1; t <= T; ++t) {
    solve();
    // clear
    for (int i = 1; i <= n; ++i) {
      e[i].clear();
    }
  }
  return 0;
}