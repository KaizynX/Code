/*
 * @Author: Kaizyn
 * @Date: 2021-12-01 17:28:50
 * @LastEditTime: 2021-12-01 17:55:57
 */
#include <bits/stdc++.h>

// #define DEBUG

using namespace std;
namespace hjt {
template<typename A,typename B>
std::ostream &operator<<(std::ostream &o,const std::pair<A,B> &x){
  return o<<'('<<x.first<<','<<x.second<<')';
}
#define repeat(i,a,b) for(int i=(a),_=(b);i<_;i++)
#define repeat_back(i,a,b) for(int i=(b)-1,_=(a);i>=_;i--)
#define qwq [&]{cerr<<"qwq"<<endl;}()
#define orz(x) [&]{cerr<<#x": "<<x<<endl;}()
#define orzarr(a,n) [&]{cerr<<#a": "; repeat(__,0,n)cerr<<(a)[__]<<" "; cerr<<endl;}()
#define orzeach(a) [&]{cerr<<#a": "; for(auto __:a)cerr<<__<<" "; cerr<<endl;}()
#define pause [&]{system("pause");}()
} using namespace hjt;

typedef long long ll;
typedef pair<int, int> pii;
const double eps = 1e-7;
const double PI = acos(-1);
const int MOD = 998244353; // 1e9+7;
const int INF = 0x3f3f3f3f;
// const ll INF = 1e18;
const int N = 1e4+7;
const int M = 1e2+7;
const int dir[] = {0,-1,0,1,0};

template <typename T = int> struct DSU {
  vector<int> fa;
  vector<T> w1, w2;
  void init(int n, T v = 1) {
    fa = vector<int>(n+1);
    iota(fa.begin(), fa.end(), 0);
    w1 = vector<T>(n+1, v);
    w2 = vector<T>(n+1, v);
  }
  int get(int s) { return s == fa[s] ? s : fa[s] = get(fa[s]); }
  int& operator [] (int i) { return fa[get(i)]; }
  bool merge(int x, int y) { // merge x to y
    x = get(x); y = get(y);
    return x == y ? false : (w1[y] += w1[x], w2[y] += w2[x], fa[x] = y, true);
  }
};


template <typename T>
struct ISAP {
  struct EDGE {
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
  void clear() {
    for (int i = 0; i < (int)e.size(); i += 2) {
      e[i].w += e[i^1].w;
      e[i^1].w = 0;
    }
  }
  void modify_edge(const int &u, const int &v, const T &w) {
    for (int i = fir[u]; ~i; i = e[i].nex) if (e[i].v == v) {
      e[i].w = w;
      e[i^1].w = 0;
      break;
    }
  }
  void add_edge(const int &u, const int &v, const T &w) {
    #ifdef DEBUG
    printf("flow:add_edge(u=%d, v=%d, w=%d)\n", u, v, w);
    #endif
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
    if (u == t) return maxflow += flow, flow;
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

int n, m;
char a[M][M], b[M][M];
DSU<int> dsu;
vector<int> e[N];
ISAP<int> flow;

int magic(int x, int y) {
  return x*m+y;
}

inline void solve() {
  scanf("%d%d", &n, &m);
  dsu.init(n*m);
  int ans = 0;
  for (int i = 0; i < n; ++i) {
    scanf("%s", a[i]);
  }
  for (int i = 0; i < n; ++i) {
    scanf("%s", b[i]);
    for (int j = 0; j < m; ++j) {
      dsu.w1[i*m+j] = a[i][j] == b[i][j];
      ans += a[i][j] == b[i][j];
    }
  }
  for (int i = 0; i < n; ++i) {
    for (int j = 0; j < m; ++j) {
      for (int d = 0; d < 4; ++d) {
        int ni = i+dir[d];
        int nj = j+dir[d+1];
        if (ni < 0 || ni >= n || nj < 0 || nj >= m) continue;
        if (a[ni][nj] == a[i][j]) dsu.merge(magic(ni, nj), magic(i, j));
      }
    }
  }
  for (int i = 0; i < n; ++i) {
    for (int j = 0; j < m; ++j) {
      for (int d = 0; d < 4; ++d) {
        int ni = i+dir[d];
        int nj = j+dir[d+1];
        if (ni < 0 || ni >= n || nj < 0 || nj >= m) continue;
        int v = dsu[magic(i, j)], u = dsu[magic(ni, nj)];
        if (v != u) {
          e[v].emplace_back(u);
          e[u].emplace_back(v);
        }
      }
    }
  }
  // w1 为不同个数, w2为总个数
  int S = n*m+1, T = n*m+2;
  flow.init(n*m+2);
  for (int i = 0, x, y; i < n*m; ++i) if (e[i].size()) {
    sort(e[i].begin(), e[i].end());
    e[i].erase(unique(e[i].begin(), e[i].end()), e[i].end());
    x = i/m; y = i%m;
    #ifdef DEBUG
    cout << x << ' ' << y << ":";
    orzeach(e[i]);
    #endif
    int w = max(0, dsu.w2[i]-2*dsu.w1[i]);
    ans += w;
    if (a[x][y] == '0') {
      flow.add_edge(S, i, w);
      for (int j : e[i]) flow.add_edge(i, j, INF);
    } else {
      flow.add_edge(i, T, w);
    }
  }
  ans -= flow.work(S, T);
  printf("%d\n", n*m-ans);
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