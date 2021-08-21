/*
 * @Author: Kaizyn
 * @Date: 2021-08-21 13:34:44
 * @LastEditTime: 2021-08-21 13:45:22
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
const int N = 1e4+7;

template <typename T>
struct ZKW_SPFA {
  struct Edge {
    int v, nex;
    T w, c; // edge wight and cost
    Edge(const int &_v, const int &_nex, const T &_w, const T &_c)
    : v(_v), nex(_nex), w(_w), c(_c) {}
  };
  vector<Edge> e;
  int n, s, t;
  int fir[N], vis[N];
  T maxflow, mincost;
  T dis[N];
  ZKW_SPFA() { e.reserve(N<<4); }
  void init(const int &_n) {
    n = _n;
    maxflow = mincost = 0;
    e.clear();
    memset(fir, -1, sizeof(int)*(n+3));
  }
  void add_edge(const int &u, const int &v, const T &w = 1, const T &c = 0) {
    e.emplace_back(v, fir[u], w, c); fir[u] = e.size()-1;
    e.emplace_back(u, fir[v], 0, -c); fir[v] = e.size()-1;
  }
  pair<T, T> work(const int &_s, const int &_t) {
    s = _s; t = _t;
    while (spfa()) {
      vis[t] = 1;
      while (vis[t]) {
        memset(vis, 0, sizeof(int)*(n+3));
        maxflow += dfs(s, INF);
      }
    }
    return {maxflow, mincost};
  }
  private:
  bool spfa() {
    memset(dis, 0x3f, sizeof(T)*(n+3));
    memset(vis, 0, sizeof(int)*(n+3));
    deque<int> q;
    q.push_back(t);
    dis[t] = 0;
    vis[t] = 1;
    while (q.size()) {
      int u = q.front(); q.pop_front();
      for (int i = fir[u], v; ~i; i = e[i].nex) {
        v = e[i].v;
        if (!e[i^1].w || dis[v] <= dis[u]+e[i^1].c) continue;
        dis[v] = dis[u]+e[i^1].c;
        if (vis[v]) continue;
        vis[v] = 1;
        if (q.size() && dis[v] < dis[q.front()]) q.push_front(v);
        else q.push_back(v);
      }
      vis[u] = 0;
    }
    return dis[s] < INF;
  }
  T dfs(const int &u, const T &flow) {
    vis[u] = 1;
    if (u == t || flow <= 0) return flow;
    T res, used = 0;
    for (int i = fir[u], v; ~i; i = e[i].nex) {
      v = e[i].v;
      if (vis[v] || !e[i].w || dis[u] != dis[v]+e[i].c) continue;
      res = dfs(v, min(e[i].w, flow-used));
      if (!res) continue;
      mincost += e[i].c; // mincost += res*e[i].c;
      // mincost += res*e[i].c;
      e[i].w -= res;
      e[i^1].w += res;
      used += res;
      if (used == flow) break;
    }
    return used;
  }
};

int n, m;
int a[N], t[N];
ZKW_SPFA<int> flow;

inline void solve() {
  cin >> n >> m;
  int ans = 0;
  int S = n+1, T = n+2, SS = n+3;
  flow.init(n+3);
  flow.add_edge(SS, S, m, 0);
  flow.add_edge(S, T, m, 0); // useless nodes
  for (int i = 1; i <= n; ++i) {
    cin >> a[i];
    ans += a[i];
    flow.add_edge(i, T, a[i], 0);
  }
  for (int i = 1, j, k; i <= n; ++i) {
    cin >> t[i];
    for (j = 2, k = 1; j <= t[i]; ++j) {
      int vj = (a[i]+j-1)/j, vk = (a[i]+k-1)/k;
      if (vj != vk) {
        flow.add_edge(S, i, j-k, vj-vk);
        // flow.add_edge(S, i, j-k, vk-vj);
        k = j;
      }
    }
  }
  cout << ans+flow.work(S, T).second << '\n';
}

signed main() {
#ifdef ONLINE_JUDGE
  ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
#endif
  int T = 1;
  cin >> T; // scanf("%d", &T);
  for (int t = 1; t <= T; ++t) {
    solve();
  }
  return 0;
}