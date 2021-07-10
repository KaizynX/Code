/*
 * @Author: Kaizyn
 * @Date: 2021-06-09 15:10:34
 * @LastEditTime: 2021-06-09 15:17:54
 */
#include <bits/stdc++.h>

// #define DEBUG

using namespace std;

const double eps = 1e-7;
const double PI = acos(-1);
typedef pair<int, int> pii;
typedef long long ll;
const int MOD = 998244353; // 1e9+7;
const int INF = 0x3f3f3f3f;
// const ll INF = 1e18;
const int N = 3e3+7;

template <typename T>
struct Dinic {
  struct EDGE {
    int v, nex;
    T w;
    EDGE(const int &_v, const int &_nex, const T &_w) : v(_v), nex(_nex), w(_w) {}
  };
  vector<EDGE> e;
  int n, s, t;
  int fir[N], dep[N], cur[N];
  Dinic() { e.reserve(N<<2); }
  T work(const int &_s, const int &_t) {
    s = _s; t = _t;
    T maxflow = 0, flow;
    while (bfs())
      while ((flow = dfs(s, INF)))
        maxflow += flow;
    return maxflow;
  }
  void init(const int &_n) {
    n = _n;
    e.clear();
    memset(fir, -1, sizeof(int)*(n+3));
  }
  void add_edge(const int &u, const int &v, const T &w) {
    e.emplace_back(v, fir[u], w); fir[u] = e.size()-1;
    e.emplace_back(u, fir[v], 0); fir[v] = e.size()-1;
  }
  bool bfs() {
    queue<int> q;
    memset(dep, 0, sizeof(int)*(n+3));
    q.push(s);
    dep[s] = 1;
    for (int i = 0; i <= n; ++i) cur[i] = fir[i];
    while (q.size()) {
      int u = q.front();
      q.pop();
      for (int i = fir[u], v; i != -1; i = e[i].nex) {
        v = e[i].v;
        if (dep[v] || !e[i].w) continue;
        dep[v] = dep[u]+1;
        if (v == t) return true;
        q.push(v);
      }
    }
    return false;
  }
  T dfs(const int &u, const T &flow) {
    if (!flow || u == t) return flow;
    T rest = flow, now;
    for (int &i = cur[u], v; i != -1; i = e[i].nex) {
      v = e[i].v;
      if (dep[v] != dep[u]+1 || !e[i].w) continue;
      now = dfs(v, min(rest, e[i].w));
      if (!now) {
        dep[v] = 0;
      } else {
        e[i].w -= now;
        e[i^1].w += now;
        rest -= now;
        if (rest == flow) break;
      }
    }
    return flow-rest;
  }
};

int n, m;
int hp[N], use[N];
Dinic<int> flow;

inline void solve() {
  cin >> n >> m;
  flow.init(n+m+n+m+2);
  int s = 2*(n+m)+1, t = s+1, sum = 0;
  // sword [1, n]
  // id [n+1, n+n+m]
  // monster [n*2+m+1, ]
  for (int i = 1; i <= n; ++i) {
    cin >> use[i];
    flow.add_edge(s, i, use[i]);
  }
  for (int i = 1; i <= m; ++i) {
    cin >> hp[i];
    sum += hp[i];
    flow.add_edge(n*2+m+i, t, hp[i]);
  }
  for (int i = 1, k; i <= n; ++i) {
    cin >> k;
    for (int j = 1, id; j <= k; ++j) {
      cin >> id;
      flow.add_edge(i, n+id, INF);
    }
  }
  for (int i = 1, id; i <= m; ++i) {
    cin >> id;
    flow.add_edge(n+id, n*2+m+i, INF);
  }
  int res = flow.work(s, t);
  if (res == sum) cout << "V4yne\n";
  else cout << res << '\n';
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