/*
 * @Author: Kaizyn
 * @Date: 2021-02-25 18:33:45
 * @LastEditTime: 2021-02-25 18:38:12
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
const int N = 1e5+7;

int n, m;
int f[N];
ll res, ave;
ll dp[N];
vector<pii> e[N];

void dfs(int u, int fa) {
  dp[u] = f[u];
  for (auto &p : e[u]) {
    int v = p.first;
    int w = p.second;
    if (v == fa) continue;
    dfs(v, u);
    res += 1ll*abs(ave-dp[v])*w;
    dp[u] += dp[v]-ave;
  }
}

inline void solve() {
  cin >> n;
  for (int i = 1; i <= n; ++i) {
    cin >> f[i];
    ave += f[i];
  }
  ave /= n;
  for (int i = 1, u, v, w; i < n; ++i) {
    cin >> u >> v >> w;
    e[u].emplace_back(v, w);
    e[v].emplace_back(u, w);
  }
  dfs(1, 0);
  cout << res << '\n';
}

signed main() {
#ifdef ONLINE_JUDGE
  ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
#endif
  int T = 1;
  // cin >> T;
  for (int t = 1; t <= T; ++t) {
    solve();
  }
  return 0;
}