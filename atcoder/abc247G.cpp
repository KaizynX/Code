/*
 * @Author: Kaizyn
 * @Date: 2022-04-10 20:51:30
 * @LastEditTime: 2022-04-10 20:56:29
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
template <typename T> static constexpr T inf = numeric_limits<T>::max() / 2;
const int N = 3e4 + 7;

template <typename T>
struct MCMF {
  struct Edge {
    int v, nex;
    T w, c; // edge wight and cost
    Edge(const int &_v, const int &_nex, const T &_w, const T &_c) \
    : v(_v), nex(_nex), w(_w), c(_c) {}
  };
  vector<Edge> e;
  int n, s, t;
  int fir[N], vis[N], pre[N];
  T incf[N], dis[N];
  void init(const int &_n) {
    n = _n;
    e.clear();
    e.reserve(N<<4);
    memset(fir, -1, sizeof(int)*(n+3));
  }
  void add_edge(const int &u, const int &v, const T &w, const T &c) {
    e.emplace_back(v, fir[u], w, c); fir[u] = e.size()-1;
    e.emplace_back(u, fir[v], 0, -c); fir[v] = e.size()-1;
  }
  vector<T> work(const int &_s, const int &_t) {
    s = _s; t = _t;
    vector<T> ans;
    T maxflow = 0, mincost = 0;
    while (spfa()) {
      for (int u = t, id; u != s; u = e[id^1].v) {
        id = pre[u];
        e[id].w -= incf[t];
        e[id^1].w += incf[t];
        mincost += incf[t]*e[id].c;
      }
      maxflow += incf[t];
      ans.emplace_back(-mincost);
    }
    // return {maxflow, mincost};
    assert((int)ans.size() == maxflow);
    return ans;
  }
  bool spfa() {
    queue<int> q;
    memset(dis, 0x3f, sizeof(T)*(n+3));
    memset(vis, 0, sizeof(int)*(n+3));
    q.push(s);
    dis[s] = 0;
    incf[s] = inf<T>;
    incf[t] = 0;
    while (q.size()) {
      int u = q.front();
      q.pop();
      vis[u] = 0;
      for (int i = fir[u], v; i != -1; i = e[i].nex) {
        v = e[i].v;
        if (!e[i].w || dis[v] <= dis[u]+e[i].c) continue;
        dis[v] = dis[u]+e[i].c;
        incf[v] = min(incf[u], e[i].w);
        pre[v] = i;
        if (vis[v]) continue;
        q.push(v);
        vis[v] = 1;
      }
    }
    return incf[t];
  }
};

int n;
int a[N], b[N], c[N];
MCMF<ll> flow;
constexpr int A = 150;

inline void solve() {
  cin >> n;
  int S = 2 * A + 1, T = 2 * A + 2;
  flow.init(T);
  for (int i = 1; i <= A; ++i) {
    flow.add_edge(S, i, 1, 0);
    flow.add_edge(A + i, T, 1, 0);
  }
  for (int i = 1; i <= n; ++i) {
    cin >> a[i] >> b[i] >> c[i];
    flow.add_edge(a[i], A + b[i], 1, -c[i]);
  }
  auto ans = flow.work(S, T);
  cout << ans.size() << '\n';
  for (ll i : ans) cout << i << '\n';
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