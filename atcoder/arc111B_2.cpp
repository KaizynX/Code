/*
 * @Author: Kaizyn
 * @Date: 2021-01-10 15:06:01
 * @LastEditTime: 2021-01-10 15:13:02
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
const int N = 4e5+7;

int n;
int fa[N], p[N], e[N], vis[N];

int getf(int x) {
  return x == fa[x] ? x : fa[x] = getf(fa[x]);
}

inline void solve() {
  cin >> n;
  iota(fa, fa+N, 0);
  fill(p, p+N, 1);
  for (int i = 1, u, v; i <= n; ++i) {
    cin >> u >> v;
    vis[u] = vis[v] = 1;
    u = getf(u);
    v = getf(v);
    if (u != v) {
      e[u] += e[v];
      p[u] += p[v];
      fa[v] = u;
    }
    ++e[u];
  }
  int res = 0;
  for (int i = 1; i < N; ++i) if (vis[i] && getf(i) == i) {
    res += p[i]-(e[i] == p[i]-1);
  }
  cout << res << endl;
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