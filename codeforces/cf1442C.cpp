/*
 * @Author: Kaizyn
 * @Date: 2020-11-02 23:24:56
 * @LastEditTime: 2020-11-03 00:03:01
 */
#include <bits/stdc++.h>

// #define DEBUG

using namespace std;

const double eps = 1e-7;
const double PI = acos(-1);
typedef pair<int, int> pii;
const int MOD = 998244353;
const int INF = 0x3f3f3f3f;
const int N = 2e5+7;
const int K = 20;

template <typename T, typename H>
inline T qpow(const T &a, const H &p, const int &mo = MOD) {
  long long res = 1, x = a;
  for (H i = p; i; i >>= 1, x = x*x%mo)
    if (i&1) res = res*x%mo;
  return static_cast<T>(res);
}

struct Node {
  int i, t, d;
  bool operator <(const Node &nex) const {
    return d > nex.d;
  }
};

int n, m;
vector<int> e[N], re[N];

inline int solve1() {
  static int dis[K][N];
  static priority_queue<Node> q;
  memset(dis, 0x3f, sizeof dis);
  dis[0][1] = 0;
  q.push(Node{1, 0, 0});
  int u, ut, ud, vd, vt;
  vector<int> *e1, *e2;
  while (q.size()) {
    u = q.top().i;
    ut = q.top().t;
    ud = q.top().d;
    q.pop();
    if (ut&1) e1 = re, e2 = e;
    else e1 = e, e2 = re;
    if (ud > dis[ut][u]) continue;
    for (int &v : e1[u]) {
      vd = ud+1;
      vt = ut;
      if (dis[vt][v] > vd) {
        dis[vt][v] = vd;
        q.push(Node{v, vt, vd});
      }
    }
    if (ut < K) for (int &v : e2[u]) {
      vd = ud+1+(1<<ut);
      vt = ut+1;
      if (dis[vt][v] > vd) {
        dis[vt][v] = vd;
        q.push(Node{v, vt, vd});
      }
    }
  }
  int res = INF;
  for (int i = 0; i < K; ++i) res = min(res, dis[i][n]);
  return res;
}

inline int solve2() {
  typedef pair<pii, int> piii;
  static pii dis[2][N];
  static priority_queue<piii, vector<piii>, greater<piii>> q;
  for (int i = 1; i <= n; ++i) dis[0][i] = dis[1][i] = pii{INF, INF};
  dis[0][1] = pii{0, 0};
  q.push({pii{0, 0}, 1});
  int u, ut, ud, vd, vt;
  vector<int> *e1, *e2;
  while (q.size()) {
    u = q.top().second;
    ut = q.top().first.first;
    ud = q.top().first.second;
    q.pop();
    if (pii{ut, ud} > dis[ut&1][u]) continue;
    if (ut&1) e1 = re, e2 = e;
    else e1 = e, e2 = re;
    for (int &v : e1[u]) {
      vt = ut;
      vd = ud+1;
      if (pii{vt, vd} < dis[vt&1][v]) {
        dis[vt&1][v] = pii{vt, vd};
        q.push(piii{pii{vt, vd}, v});
      }
    }
    for (int &v : e2[u]) {
      vt = ut+1;
      vd = ud+1;
      if (pii{vt, vd} < dis[vt&1][v]) {
        dis[vt&1][v] = pii{vt, vd};
        q.push(piii{pii{vt, vd}, v});
      }
    }
  }
  int res = dis[0][n] <= dis[1][n] ? 
      qpow(2, dis[0][n].first)+dis[0][n].second :
      qpow(2, dis[1][n].first)+dis[1][n].second ;
  return (res-1+MOD)%MOD;
}

inline void solve() {
  cin >> n >> m;
  for (int i = 1, u, v; i <= m; ++i) {
    cin >> u >> v;
    e[u].emplace_back(v);
    re[v].emplace_back(u);
  }
  int res = solve1();
  cout << (res == INF ? solve2() : res) << endl;
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