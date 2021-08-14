/*
 * @Author: Kaizyn
 * @Date: 2021-08-14 13:23:00
 * @LastEditTime: 2021-08-14 13:24:29
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
const int N = 1e5+7;

int n, q, l, r, res;
int t[N];
vector<int> e[N];

void dfs(int u, int fa = 0) {
  if (t[u] < l || t[u] > r) return;
  ++res;
  for (int v : e[u]) if (v != fa) dfs(v, u);
}

inline void solve() {
  cin >> n;
  // clear e
  for (int i = 1, u, v; i < n; ++i) {
    cin >> u >> v;
    e[u].emplace_back(v);
    e[v].emplace_back(u);
  }
  for (int i = 1; i <= n; ++i) cin >> t[i];
  cin >> q;
  for (int _ = q, x; _; --_) {
    cin >> x >> l >> r;
    res = 0;
    dfs(x);
    cout << res << '\n';
  }
}

signed main() {
#ifdef ONLINE_JUDGE
  ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
#endif
  int T = 1;
  // cin >> T; // scanf("%d", &T);
  for (int t = 1; t <= T; ++t) {
    solve();
  }
  return 0;
}