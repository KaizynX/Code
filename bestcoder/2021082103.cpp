/*
 * @Author: Kaizyn
 * @Date: 2021-08-21 21:24:40
 * @LastEditTime: 2021-08-21 21:33:00
 */
#include <bits/stdc++.h>

// #define DEBUG

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
const double eps = 1e-7;
const double PI = acos(-1);
const int MOD = 998244353; // 1e9+7;
const int INF = 0x3f3f3f3f;
// const ll INF = 1e18;
const int N = 2e5+7;

int n;
ll ans;
ll b[N], p[N];
vector<int> e[N];

ll dfs(int u, int fa) {
  ll sum = b[u]*p[u];
  for (int v : e[u]) if (v != fa) {
    ll w = dfs(v, u);
    ll tmp = min({sum, w, b[u]});
    sum -= tmp;
    ans -= tmp;
  }
  return min(sum, b[u]);
}

inline void solve() {
  cin >> n;
  for (int i = 1, u, v; i < n; ++i) {
    cin >> u >> v;
    e[u].emplace_back(v);
    e[v].emplace_back(u);
  }
  ans = 0;
  for (int i = 1; i <= n; ++i) {
    cin >> b[i] >> p[i];
    p[i] = min(p[i], (ll)e[i].size());
    ans += b[i];
  }
  dfs(1, 0);
  cout << ans << '\n';
}

signed main() {
#ifdef ONLINE_JUDGE
  ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
#endif
  int T = 1;
  cin >> T; // scanf("%d", &T);
  for (int t = 1; t <= T; ++t) {
    solve();
    for (int i = 1; i <= n; ++i) {
      e[i].clear();
    }
  }
  return 0;
}