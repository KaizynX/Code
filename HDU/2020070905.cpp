/*
 * @Author: Kaizyn
 * @Date: 2020-07-09 18:11:55
 * @LastEditTime: 2020-07-09 18:16:19
 */ 
#include <bits/stdc++.h>

// #define DEBUG

using namespace std;

const double eps = 1e-7;
const double PI = acos(-1);
typedef pair<int, int> pii;
const int MOD = 998244353;
const int INF = 0x3f3f3f3f;
const int N = 6e3+7;

int n;
int a[N], deg[N], dp[N][2];
vector<int> e[N];

void dfs(const int &u) {
  dp[u][0] = 0;
  dp[u][1] = a[u];
  for (const int &v : e[u]) {
    dfs(v);
    dp[u][0] += max(dp[v][0], dp[v][1]);
    dp[u][1] += dp[v][0];
  }
  dp[u][0] = max(dp[u][0], 0);
  dp[u][1] = max(dp[u][1], 0);
}

inline void solve() {
  for (int i = 1; i <= n; ++i) {
    cin >> a[i];
  }
  int u, v, rt = 0;
  while (cin >> u >> v && u|v) {
    e[v].emplace_back(u);
    ++deg[u];
  }
  for (int i = 1; i <= n; ++i) {
    if (deg[i] == 0) rt = i;
  }
  dfs(rt);
  cout << max(dp[rt][0], dp[rt][1]) << endl;
  for (int i = 1; i <= n; ++i) {
    deg[i] = 0;
    dp[i][0] = dp[i][1] = 0;
    vector<int>().swap(e[i]);
  }
}

signed main() {
  ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
  while (cin >> n) solve();
  return 0;
}