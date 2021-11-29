/*
 * @Author: Kaizyn
 * @Date: 2021-11-24 15:31:54
 * @LastEditTime: 2021-11-24 15:37:56
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
struct Dinic {
  struct EDGE {
    int v, nex;
    T w;
    EDGE(const int &_v, const int &_nex, const T &_w) : v(_v), nex(_nex), w(_w) {}
  };
  deque<EDGE> e;
  int n, s, t;
  int fir[N], dep[N], cur[N];
  // Dinic() { e.reserve(N<<2); }
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

int n;
int w[N], v[N], d[N];
vector<int> e[N];
queue<int> q;
Dinic<ll> flow;

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
      // if (j > 1) flow.add_edge(k, k-1, INF);
      d[j] = 0;
    }
    d[i] = 1;
    q.push(i);
    while (q.size()) {
      int u = q.front();
      q.pop();
      // flow.add_edge((i-1)*n+d[i], n*n+u, INF);
      for (int v : e[u]) if (!d[v]) {
        d[v] = d[u]+1;
        q.push(v);
      }
    }
    for (int j = 1; j <= n; ++j) {
      for (int k = 1; k <= n; ++k) {
        if (d[k] <= j) flow.add_edge((i-1)*n+j, n*n+k, INF);
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