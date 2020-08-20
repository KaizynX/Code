/*
 * @Author: Kaizyn
 * @Date: 2020-03-19 20:12:35
 * @LastEditTime: 2020-08-07 21:28:55
 */
#include <bits/stdc++.h>

// #define DEBUG

using namespace std;

const int N = 1e4+7;
const int M = 1e5+7;
const int MOD = 1e9+7;
const double eps = 1e-7;
const int INF = 0x3f3f3f3f;
typedef pair<int, int> pii;

template <typename T>
struct ISAP { // copy from oi-wiki
  struct Edge {
    int from, to;
    T cap, flow;
    Edge(int u, int v, T c, T f) : from(u), to(v), cap(c), flow(f) {}
    friend bool operator<(const Edge& a, const Edge& b) {
      return a.from < b.from || (a.from == b.from && a.to < b.to);
    }
  };
  int n, m, s, t;
  vector<Edge> edges;
  vector<int> G[N];
  bool vis[N];
  int d[N], cur[N], p[N], num[N];

  void add_edge(int from, int to, int cap) {
    edges.push_back(Edge(from, to, cap, 0));
    edges.push_back(Edge(to, from, 0, 0));
    m = edges.size();
    G[from].push_back(m - 2);
    G[to].push_back(m - 1);
  }

  bool BFS() {
    memset(vis, 0, sizeof(bool)*(n+3));
    queue<int> Q;
    Q.push(t);
    vis[t] = 1;
    d[t] = 0;
    while (!Q.empty()) {
      int x = Q.front();
      Q.pop();
      for (int i = 0; i < (int)G[x].size(); i++) {
        Edge& e = edges[G[x][i] ^ 1];
        if (!vis[e.from] && e.cap > e.flow) {
          vis[e.from] = 1;
          d[e.from] = d[x] + 1;
          Q.push(e.from);
        }
      }
    }
    return vis[s];
  }

  void init(int n) {
    this->n = n;
    for (int i = 1; i <= n; i++) G[i].clear();
    edges.clear();
  }

  T Augment() {
    int x = t;
    T flow = INF;
    while (x != s) {
      Edge& e = edges[p[x]];
      flow = min(flow, e.cap - e.flow);
      x = edges[p[x]].from;
    }
    x = t;
    while (x != s) {
      edges[p[x]].flow += flow;
      edges[p[x]^1].flow -= flow;
      x = edges[p[x]].from;
    }
    return flow;
  }

  T work(int s, int t) {
    this->s = s;
    this->t = t;
    T flow = 0;
    BFS();
    memset(num+1, 0, sizeof(int)*n);
    for (int i = 1; i <= n; i++) num[d[i]]++;
    int x = s;
    memset(cur+1, 0, sizeof(int)*n);
    while (d[s] < n) {
      if (x == t) {
        flow += Augment();
        x = s;
      }
      int ok = 0;
      for (int i = cur[x]; i < (int)G[x].size(); i++) {
        Edge& e = edges[G[x][i]];
        if (e.cap > e.flow && d[x] == d[e.to]+1) {
          ok = 1;
          p[e.to] = G[x][i];
          cur[x] = i;
          x = e.to;
          break;
        }
      }
      if (!ok) {
        int m = n-1;
        for (int i = 0; i < (int)G[x].size(); i++) {
          Edge& e = edges[G[x][i]];
          if (e.cap > e.flow) m = min(m, d[e.to]);
        }
        if (--num[d[x]] == 0) break;
        num[d[x] = m+1]++;
        cur[x] = 0;
        if (x != s) x = edges[p[x]].from;
      }
    }
    return flow;
  }
};

int n, m, s, t;
ISAP<long long> isap;

signed main() {
  ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
  cin >> n >> m >> s >> t;
  isap.init(n);
  for (int i = 1, u, v, w; i <= m; ++i) {
    cin >> u >> v >> w;
    isap.add_edge(u, v, w);
  }
  cout << isap.work(s, t) << endl;
  return 0;
}