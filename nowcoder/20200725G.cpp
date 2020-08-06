/*
 * @Author: Kaizyn
 * @Date: 2020-07-25 11:58:03
 * @LastEditTime: 2020-07-25 14:16:25
 */ 
#include <bits/stdc++.h>

// #define DEBUG

using namespace std;

const double eps = 1e-7;
const double PI = acos(-1);
typedef pair<int, int> pii;
const int MOD = 998244353;
const int INF = 0x3f3f3f3f;
const int N = 2e4+7;

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

int n;
int c[N], cnt[N];
vector<int> e[N], d[N];
ISAP<int> isap;

void dfs(const int &u) {
  ++cnt[c[u]];
  for (const int &v : e[u]) dfs(v);
}

bool check(const int &m) { // [0, m]
  int st = n+m+2, ed = n+m+3;
  isap.init(ed);
  for (int i = 1; i <= n; ++i) {
    isap.add_edge(st, i, 1);
    for (const int &j : d[i]) {
      if (j > m) break;
      isap.add_edge(i, n+j+1, 1);
    }
  }
  for (int j = 0; j <= m; ++j) {
    isap.add_edge(n+j+1, ed, 1);
  }
  return isap.work(st, ed) >= m+1;
}

inline void solve() {
  cin >> n;
  for (int i = 2, p; i <= n; ++i) {
    cin >> p;
    e[p].emplace_back(i);
  }
  for (int i = 1; i <= n; ++i) cin >> c[i];
  vector<int> vec;
  for (int i = 1; i <= n; ++i) {
    memset(cnt+1, 0, sizeof(int)*n);
    dfs(i);
    vec.clear();
    for (int j = 0; j <= n; ++j) {
      if (j*cnt[j] < n) vec.emplace_back(j*cnt[j]);
    }
    sort(vec.begin(), vec.end());
    vec.erase(unique(vec.begin(), vec.end()), vec.end());
    d[i].assign(vec.begin(), vec.end());
  }
  int l = 0, r = n, mid;
  while (l < r) {
    mid = (l+r+1)>>1;
    if (check(mid)) l = mid;
    else r = mid-1;
  }
  cout << l+1 << endl;
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