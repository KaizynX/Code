/*
 * @Author: Kaizyn
 * @Date: 2021-02-19 13:32:31
 * @LastEditTime: 2021-02-19 13:39:54
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
const int M = 51;

struct Node {
  int u, w;
  ll d;
  bool operator <(const Node &b) const {
    return d > b.d;
  }
};

int n, m;
vector<pii> e[N];
ll dis[N][M], res[N];
priority_queue<Node> q;

inline void solve() {
  cin >> n >> m;
  for (int i = 1, u, v, w; i <= m; ++i) {
    cin >> u >> v >> w;
    e[u].emplace_back(v, w);
    e[v].emplace_back(u, w);
  }
  memset(dis, -1, sizeof dis);
  dis[1][0] = 0;
  q.push(Node{1, 0, 0});
  while (q.size()) {
    int u = q.top().u;
    int uw = q.top().w;
    ll ud = q.top().d;
    q.pop();
    if (ud > dis[u][uw]) continue;
    for (auto &edge : e[u]) {
      int v = edge.first;
      int vw = edge.second;
      if (uw) {
        if (dis[v][0] == -1 || ud+(uw+vw)*(uw+vw) < dis[v][0]) {
          dis[v][0] = ud+(uw+vw)*(uw+vw);
          q.push(Node{v, 0, dis[v][0]});
        }
      } else {
        if (dis[v][vw] == -1 || ud < dis[v][vw]) {
          dis[v][vw] = ud;
          q.push(Node{v, vw, ud});
        }
      }
    }
  }
  for (int i = 1; i <= n; ++i) {
    cout << dis[i][0] << " \n"[i==n];
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