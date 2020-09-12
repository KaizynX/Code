/*
 * @Author: Kaizyn
 * @Date: 2020-09-07 19:38:35
 * @LastEditTime: 2020-09-07 19:50:27
 */
#include <bits/stdc++.h>

// #define DEBUG

using namespace std;

const double eps = 1e-7;
const double PI = acos(-1);
typedef pair<int, int> pii;
const int MOD = 998244353;
const int INF = 0x3f3f3f3f;
const int N = 1e5+7;

struct Node {
  int u, v, w;
  friend bool operator <(const Node &lhs, const Node &rhs) {
    return lhs.w < rhs.w;
  }
};

int n, m;
int dp[N], tmp[N];
Node e[N];

signed main() {
  ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
  cin >> n >> m;
  for (int i = 1; i <= m; ++i) {
    cin >> e[i].u >> e[i].v >> e[i].w;
  }
  sort(e+1, e+m+1);
  for (int i = 1, j; i <= m; i = j) {
    j = i+1;
    while (j <= m && e[j].w == e[i].w) ++j;
    for (int k = i; k < j; ++k) {
      tmp[e[k].u] = dp[e[k].u];
      tmp[e[k].v] = dp[e[k].v];
    }
    for (int k = i; k < j; ++k) {
      dp[e[k].u] = max(dp[e[k].u], tmp[e[k].v]+1);
      dp[e[k].v] = max(dp[e[k].v], tmp[e[k].u]+1);
    }
  }
  int res = 0;
  for (int i = 1; i <= n; ++i) res = max(res, dp[i]);
  cout << res << endl;
  return 0;
}