/*
 * @Author: Kaizyn
 * @Date: 2021-02-10 13:41:45
 * @LastEditTime: 2021-02-10 15:06:52
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
const int N = 2e5+7;

struct Node {
  ll dis;
  int state, id;
  bool operator <(const Node &b) const {
    return dis > b.dis;
  }
};

int n, m;
vector<pii> e[N];
priority_queue<Node> q;
ll d[4][N];
// 0 none
// 1 +min
// 2 -max
// 3 -max+min

void update(ll dis, int state, int id) {
  if (dis < d[state][id]) {
    d[state][id] = dis;
    q.push(Node{dis, state, id});
  }
}

inline void solve() {
  cin >> n >> m;
  for (int i = 1, u, v, w; i <= m; ++i) {
    cin >> u >> v >> w;
    e[u].emplace_back(v, w);
    e[v].emplace_back(u, w);
  }
  memset(d, 0x3f, sizeof d);
  d[0][1] = 0;
  q.push(Node{0, 0, 1});
  while (q.size()) {
    ll ud = q.top().dis;
    int us = q.top().state;
    int u = q.top().id;
    q.pop();
    if (ud > d[us][u]) continue;
    for (auto &p : e[u]) {
      int v = p.first;
      int w = p.second;
      update(ud+w, us, v);
      if (~us&1) update(ud+w+w, us|1, v);
      if (~us&2) update(ud, us|2, v);
      if (!us) update(ud+w, 3, v);
    }
  }
  for (int i = 2; i <= n; ++i) {
    cout << d[3][i] << " \n"[i==n];
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