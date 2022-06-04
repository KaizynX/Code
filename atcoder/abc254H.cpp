/*
 * @Author: Kaizyn
 * @Date: 2022-06-04 20:57:45
 * @LastEditTime: 2022-06-04 21:21:10
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

using ll = long long;
using uint = unsigned;
using pii = pair<int, int>;
const double eps = 1e-7;
const double PI = acos(-1);
const int MOD = 998244353; // 1e9+7;
template <typename T> static constexpr T inf = numeric_limits<T>::max() / 2;
const int INF = 0x3f3f3f3f;
const int N = 1e5 + 7;

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
    #ifdef DEBUG
    cerr << "add_edge(" << u << "," << v << "," << w << ")\n";
    #endif
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
map<int, int> cntb, cnta, mpa, mpb;
Dinic<int> flow;

inline void solve() {
  cin >> n;
  for (int i = 1, a; i <= n; ++i) {
    cin >> a;
    cnta[a]++;
  }
  for (int i = 1, b; i <= n; ++i) {
    cin >> b;
    cntb[b]++;
  }
  int na = cnta.size();
  int nb = cntb.size();
  int S = na + nb + 1, T = na + nb + 2;
  flow.init(na + nb + 2);
  int id = 0;
  for (auto &pr : cnta) {
    ++id;
    mpa[pr.first] = id;
    flow.add_edge(S, id, pr.second);
  }
  for (auto &pr : cntb) {
    ++id;
    mpb[pr.first] = id;
    flow.add_edge(id, T, pr.second);
  }
  for (auto &pr : cnta) {
    int a = pr.first;
    int ia = mpa[a];
    while (a <= 1000'000'000 / 2) {
      a *= 2;
      if (mpb.count(a)) flow.add_edge(ia, mpb[a], INF);
    }
    a = pr.first;
    while (true) {
      if (mpb.count(a)) flow.add_edge(ia, mpb[a], INF);
      if (!a) break;
      a /= 2;
    }
  }
  cout << flow.work(S, T) << '\n';
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