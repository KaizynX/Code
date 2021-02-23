/*
 * @Author: Kaizyn
 * @Date: 2021-02-20 22:10:14
 * @LastEditTime: 2021-02-20 22:22:11
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
const int N = 1e6+7;

int n, m, q;
int u[N], v[N], w[N];
ll dis[N], d[N];

inline ll calc(int x, int y) {
  if (x > y) swap(x, y);
  return min(dis[y]-dis[x], dis[x+n]-dis[y]);
}

inline void solve() {
  cin >> n >> m;
  for (int i = 1; i <= n; ++i) {
    cin >> d[i];
    dis[i+1] = dis[i]+d[i];
  }
  for (int i = 1; i <= n; ++i) {
    dis[n+i+1] = dis[n+i]+d[i];
  }
  for (int i = 1; i <= m; ++i) {
    cin >> u[i] >> v[i] >> w[i];
  }
  cin >> q;
  for (int i = 1, x, y; i <= q; ++i) {
    cin >> x >> y;
    ll res = calc(x, y);
    for (int j = 1; j <= m; ++j) {
      res = min({res, calc(x, u[j])+calc(y, v[j])+w[j], calc(x, v[j])+calc(y, u[j])+w[j]});
    }
    cout << res << '\n';
  }
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