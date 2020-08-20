/*
 * @Author: Kaizyn
 * @Date: 2020-08-10 12:51:47
 * @LastEditTime: 2020-08-10 13:21:47
 */
#include <bits/stdc++.h>

// #define DEBUG

using namespace std;

const double eps = 1e-7;
const double PI = acos(-1);
typedef pair<int, int> pii;
const int MOD = 998244353;
const int INF = 0x3f3f3f3f;
const int N = 5e2+7;

template <typename T>
struct ZKW_SPFA {
  struct Edge {
    int v, nex;
    T w, c; // edge wight and cost
    Edge(const int &_v, const int &_nex, const T &_w, const T &_c) \
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
      mincost += res*e[i].c;
      e[i].w -= res;
      e[i^1].w += res;
      used += res;
      if (used == flow) break;
    }
    return used;
  }
};

int n, rt[2];
int cost[N][N];
int num[2][N];
vector<int> e[2][N];
ZKW_SPFA<int> flow[N];

void dfs(const int &id, const int &u) {
  num[id][u] = 1;
  for (const int &v : e[id][u]) {
    dfs(id, v);
    num[id][u] += num[id][v];
  }
}

int get_cost(int u0, int u1) {
  if (~cost[u0][u1]) return cost[u0][u1];
  if (e[0][u0].size() != e[1][u1].size() ||
      num[0][u0] != num[1][u1]) return cost[u0][u1] = n+1;
  // if (num[0][u0] == 1 && num[1][u1] == 1) return cost[u0][u1] = u0 != u1;
  int sz = e[0][u0].size(), st = sz*2+1, ed = sz*2+2;
  flow[u0].init(sz*2+2);
  for (int i = 0, v0; i < sz; ++i) {
    v0 = e[0][u0][i];
    for (int j = 0, v1; j < sz; ++j) {
      v1 = e[1][u1][j];
      int c = get_cost(v0, v1);
      if (c > n) continue;
      flow[u0].add_edge(i+1, sz+j+1, 1, c);
    }
  }
  for (int i = 1; i <= sz; ++i) {
    flow[u0].add_edge(st, i, 1, 0);
    flow[u0].add_edge(sz+i, ed, 1, 0);
  }
  pii res = flow[u0].work(st, ed);
  res.second += u0 != u1;
  return cost[u0][u1] = (res.first >= sz ? res.second : n+1);
}

inline void solve() {
  cin >> n;
  for (int t = 0; t < 2; ++t) {
    for (int i = 1, p; i <= n; ++i) {
      cin >> p;
      if (p) e[t][p].emplace_back(i);
      else rt[t] = i;
    }
    dfs(t, rt[t]);
  }
  memset(cost, -1, sizeof cost);
  cout << get_cost(rt[0], rt[1]) << endl;
}

signed main() {
  ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
  int T = 1;
  // cin >> T;
  for (int t = 1; t <= T; ++t) {
    solve();
  }
  return 0;
}