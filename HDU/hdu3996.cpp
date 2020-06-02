/*
 * @Author: Kaizyn
 * @Date: 2020-05-31 11:17:50
 * @LastEditTime: 2020-05-31 19:30:04
 */ 
#include <bits/stdc++.h>

// #define DEBUG

using namespace std;

const double eps = 1e-7;
const double PI = acos(-1);
typedef pair<int, int> pii;
const int MOD = 998244353;
const long long INF = 1e18;
const int LN = 1e2+7;
const int GN = 30;
const int N = 2507;

template <typename T>
struct ISAP {
  struct EDGE
  {
    int v, nex;
    T w;
    EDGE(const int &_v, const int &_nex, const T &_w) : v(_v), nex(_nex), w(_w) {}
  };
  vector<EDGE> e;
  int n, s, t;
  T maxflow;
  int fir[N], gap[N], dep[N];
  T work(const int &_s, const int &_t) {
    s = _s; t = _t;
    maxflow = 0;
    bfs();
    while (dep[s] < n) dfs(s, INF);
    return maxflow;
  }
  void init(const int &_n) {
    n = _n;
    e.clear();
    e.reserve(N<<2);
    memset(fir, -1, sizeof(int)*(n+3));
  }
  void add_edge(const int &u, const int &v, const T &w) {
    e.emplace_back(v, fir[u], w); fir[u] = e.size()-1;
    e.emplace_back(u, fir[v], 0); fir[v] = e.size()-1;
  }
  void bfs() {
    queue<int> q;
    memset(dep, -1, sizeof(int)*(n+3));
    memset(gap, 0, sizeof(int)*(n+3));
    dep[t] = 0;
    gap[0] = 1;
    q.push(t);
    while (q.size()) {
      int u = q.front();
      q.pop();
      for (int i = fir[u], v; i != -1; i = e[i].nex) {
        v = e[i].v;
        if (dep[v] != -1) continue;
        q.push(v);
        dep[v] = dep[u]+1;
        ++gap[dep[v]];
      }
    }
  }
  T dfs(const int &u, const T &flow) {
    if (u == t) {
      maxflow += flow;
      return flow;
    }
    T used = 0;
    for (int i = fir[u], v; i != -1; i = e[i].nex) {
      v = e[i].v;
      if (!e[i].w || dep[v]+1 != dep[u]) continue;
      T minf = dfs(v, min(e[i].w, flow-used));
      if (minf) {
        e[i].w -= minf;
        e[i^1].w += minf;
        used += minf;
      }
      if (used == flow) return used;
    }
    if (--gap[dep[u]] == 0) dep[s] = n+1;
    ++gap[++dep[u]];
    return used;
  }
};

struct Gold {
  long long cost, value;
  int related;
  int x[55], y[55];
};

int ln, n;
int gn[LN];
int id[LN][GN];
Gold g[LN*GN];
ISAP<long long> isap;

inline long long solve() {
  n = 0;
  cin >> ln;
  for (int i = 1; i <= ln; ++i) {
    cin >> gn[i];
    for (int j = 1; j <= gn[i]; ++j) {
      id[i][j] = ++n;
      cin >> g[n].cost >> g[n].value >> g[n].related;
      for (int k = 1; k <= g[n].related; ++k) {
        cin >> g[n].x[i] >> g[n].y[i];
      }
    }
  }
  isap.init(n+2);
  int st = n+1, ed = n+2;
  long long sum = 0;
  for (int i = 1; i <= ln; ++i) {
    for (int j = 1, k; j <= gn[i]; ++j) {
      k = id[i][j];
      sum += g[k].value;
      isap.add_edge(k, ed, g[k].cost);
      isap.add_edge(st, k, g[k].value);
      for (int l = 1; l <= g[k].related; ++l) {
        isap.add_edge(id[g[k].x[l]][g[k].y[l]], k, INF);
      }
    }
  }
  return sum-isap.work(st, ed);
}

signed main() {
  ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
  int T = 1;
  cin >> T;
  for (int t = 1; t <= T; ++t) {
    cout << "Case #" << t << ": " << solve() << endl;
    // printf("Case #%d: %lld\n", solve());
  }
  return 0;
}