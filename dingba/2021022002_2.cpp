/*
 * @Author: Kaizyn
 * @Date: 2021-02-20 21:16:01
 * @LastEditTime: 2021-02-20 22:10:42
 */
#include <bits/stdc++.h>

#define DEBUG

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
int d[N];
ll dis[N];
vector<pii> e[N];

inline ll calc(int x, int y) {
  return abs(dis[x]-dis[y]);
}

inline ll query(int x, int y) {
  return min({calc(x, y), calc(x, y+n), calc(x+n, y), calc(x+n, y+n)});
}

inline void solve() {
  cin >> n >> m;
  for (int i = 1; i <= n; ++i) {
    cin >> d[i];
  }
  for (int i = 1; i <= n; ++i) {
    e[i+1].emplace_back(i, d[i]);
    e[i+1+n].emplace_back(i+n, d[i]);
  }
  for (int i = 1, u, v, w; i <= m; ++i) {
    cin >> u >> v >> w;
    if (u < v) swap(u, v);
    e[u].emplace_back(v, w);
    e[u+n].emplace_back(v+n, w);
  }
  memset(dis, 0x3f, sizeof dis);
  dis[1] = 0;
  for (int i = 1; i <= n*2; ++i) {
    for (auto &p : e[i]) {
      int j = p.first;
      int w = p.second;
      dis[i] = min(dis[i], dis[j]+w);
    }
  }
  #ifdef DEBUG
  for (int i = 1; i < 2*n; ++i) {
    cout << dis[i] << " \n"[i==2*n-1];
  }
  #endif
  cin >> q;
  for (int i = 1, x, y; i <= q; ++i) {
    cin >> x >> y;
    cout << query(x, y) << '\n';
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