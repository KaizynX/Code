/*
 * @Author: Kaizyn
 * @Date: 2021-11-24 16:10:09
 * @LastEditTime: 2021-11-24 16:25:47
 */
#include <bits/stdc++.h>

#define DEBUG

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
// const int INF = 0x3f3f3f3f;
const ll INF = 1e12;
const int N = 5e4+7;

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
    // cout << u << ' ' << v << ' ' << w << '\n';
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

int n;
int w[N], v[N], d[N];
vector<int> e[N];
queue<int> q;
ISAP<ll> flow;

inline void solve() {
  cin >> n;
  for (int i = 1; i <= n; ++i) cin >> w[i];
  for (int i = 1; i <= n; ++i) cin >> v[i];
  for (int i = 1, x, y; i < n; ++i) {
    cin >> x >> y;
    e[x].emplace_back(y);
    e[y].emplace_back(x);
  }
  int S = n*n+n+1, T = n*n+n+2;
  flow.init(T);
  ll ans = v[n]*n;
  for (int i = 1; i <= n; ++i) {
    flow.add_edge(n*n+i, T, w[i]);
    for (int j = 1, k; j <= n; ++j) {
      k = (i-1)*n+j;
      flow.add_edge(S, k, v[j]-v[j-1]);
      if (j > 1) flow.add_edge(k, k-1, INF);
      d[j] = 0;
    }
    d[i] = 1;
    q.push(i);
    while (q.size()) {
      int u = q.front();
      q.pop();
      flow.add_edge((i-1)*n+d[u], n*n+u, INF);
      for (int v : e[u]) if (!d[v]) {
        d[v] = d[u]+1;
        q.push(v);
      }
    }
  }
  ans -= flow.work(S, T);
  cout << ans << '\n';
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