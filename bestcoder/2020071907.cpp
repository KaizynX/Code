/*
 * @Author: Kaizyn
 * @Date: 2020-07-19 16:11:32
 * @LastEditTime: 2020-07-19 16:23:38
 */ 
#include <bits/stdc++.h>

// #define DEBUG

using namespace std;

const double eps = 1e-7;
const double PI = acos(-1);
typedef pair<int, int> pii;
const int MOD = 998244353;
const int INF = 0x3f3f3f3f;
const int N = 1e3+7;
const int K = 6;

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

struct Node {
  int x, y, z;
};

int n, m, k;
int cnt[1<<K];
Node mos[K];
ISAP<int> isap;

inline int dis(const int &r1, const int &c1, const int &r2, const int &c2) {
  return abs(r1-r2)+abs(c1-c2);
}

inline bool check(const int &t) {
  memset(cnt, 0, sizeof(int)*(1<<k));
  for (int x = 1; x <= n; ++x) {
    for (int y = 1; y <= m; ++y) {
      int state = 0;
      for (int i = 0; i < k; ++i) {
        if (dis(x, y, mos[i].x, mos[i].y) > t) continue;
        state |= 1<<i;
      }
      if (!state) return false;
      ++cnt[state];
    }
  }
  int st = (1<<k)+k+1, ed = (1<<k)+k+2;
  isap.init((1<<k)+k+2);
  for (int i = 0; i < 1<<k; ++i) {
    isap.add_edge(i, ed, cnt[i]);
    for (int j = 0; j < k; ++j) {
      if ((i>>j)&1) isap.add_edge((1<<k)+j, i, INF);
    }
  }
  for (int i = 0; i < k; ++i) {
    isap.add_edge(st, (1<<k)+i, mos[i].z);
  }
  return isap.work(st, ed) == n*m;
}

inline void solve() {
  cin >> n >> m >> k;
  int sum = 0;
  for (int i = 0; i < k; ++i) {
    cin >> mos[i].x >> mos[i].y >> mos[i].z;
    sum += mos[i].z;
  }
  if (sum < n*m) return cout << -1 << endl, void();
  int l = 0, r = n+m-2;
  while (l < r) {
    int mid = (l+r)>>1;
    if (check(mid)) r = mid;
    else l = mid+1;
  }
  cout << (check(l) ? l : -1) << endl;
}

signed main() {
  ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
  int T = 1;
  cin >> T;
  for (int t = 1; t <= T; ++t) {
    solve();
  }
  return 0;
}