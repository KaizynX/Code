#include <bits/stdc++.h>
 
// #define DEBUG
 
using namespace std;
 
const double eps = 1e-7;
const double PI = acos(-1);
typedef pair<int, int> pii;
const int MOD = 998244353;
const int INF = 0x3f3f3f3f;
const int N = 1e5+7;
const int NN = (int)log2(N)+3;
 
struct Edge {
  int u, v, w, id;
  friend bool operator <(const Edge &e1, const Edge &e2) {
    return e1.w < e2.w;
  }
  friend istream& operator >>(istream &is, Edge &e) {
    return is >> e.u >> e.v >> e.w;
  }
};
 
struct DSU {
  int fa[N];
  void init(int sz) { for (int i = 0; i <= sz; ++i) fa[i] = i; }
  int get(int s) { return s == fa[s] ? s : fa[s] = get(fa[s]); }
  int& operator [] (int i) { return fa[get(i)]; }
  bool merge(int x, int y) { // merge x to y
    int fx = get(x), fy = get(y);
    if (fx == fy) return false;
    fa[fx] = fy; return true;
  }
};
 
int n, m;
vector<pii> e[N];
DSU dsu;
Edge edge[N];
long long sum;
long long res1[N];
int res2[N], val[N], num[N];
int f[N][NN], d[N], lg2[N];
long long w[N][NN];
 
int update(const int &x, const int &y) {
  return val[x] < val[y] ? y : x;
}
 
void build(const int &u = 1, const int &fa = 0) {
  num[u] = 1;
  d[u] = d[fa]+1;
  f[u][0] = fa;
  for (int i = 1; (1<<i) <= d[u]; ++i) {
    f[u][i] = f[f[u][i-1]][i-1];
    w[u][i] = update(w[u][i-1], w[f[u][i-1]][i-1]);
  }
  for (auto &v : e[u]) if (v.first != fa) {
    w[v.first][0] = v.first;
    val[v.first] = v.second;
    build(v.first, u);
    num[u] += num[v.first];
  }
}
 
int fuck(int x, int y) {
  int res = 0;
  if (d[x] < d[y]) swap(x, y);
  while (d[x] > d[y]) {
    res = update(res, w[x][lg2[d[x]-d[y]]]);
    x = f[x][lg2[d[x]-d[y]]];
  }
  if (x == y) return res;
  for (int i = lg2[d[x]]; i >= 0; --i)
    if(f[x][i] != f[y][i]) {
      res = update(res, w[x][i]);
      res = update(res, w[y][i]);
      x = f[x][i], y = f[y][i];
    }
  return update(res, update(w[x][0], w[y][0]));
}
 
signed main() {
  ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
  for (int i = 2; i < N; ++i) lg2[i] = lg2[i>>1]+1;
 
  cin >> n >> m;
  for (int i = 1; i <= m; ++i) {
    cin >> edge[i];
    edge[i].id = i;
  }
 
  sort(edge+1, edge+m+1);
  dsu.init(n);
  memset(res2, -1, sizeof res2);
  for (int i = 1, u, v, w, id; i <= m; ++i) {
    u = edge[i].u;
    v = edge[i].v;
    w = edge[i].w;
    id = edge[i].id;
    if (dsu.merge(u, v)) {
      sum += w;
      res2[id] = 0;
      e[u].emplace_back(v, w);
      e[v].emplace_back(u, w);
    }
  }
  build();
  for (int i = 1, u, v, w, id; i <= m; ++i) {
    u = edge[i].u;
    v = edge[i].v;
    w = edge[i].w;
    id = edge[i].id;
    if (res2[id] != -1) {
      res1[id] = sum;
    } else {
      int p = fuck(u, v);
      res1[id] = sum+w-val[p];
      res2[id] = num[p];
    }
  }
  for (int i = 1; i <= m; ++i) {
    cout << res1[i] << endl;
  }
  return 0;
}
