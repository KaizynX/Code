/*
 * @Author: Kaizyn
 * @Date: 2020-06-01 22:19:28
 * @LastEditTime: 2020-06-08 18:05:29
 */ 
#include <bits/stdc++.h>

// #define DEBUG

using namespace std;

const double eps = 1e-7;
const double PI = acos(-1);
typedef pair<int, int> pii;
const int MOD = 998244353;
const int INF = 0x3f3f3f3f;
const int N = 1e5+7;

struct ShuPou {
  int dfn;
  int fa[N], d[N], num[N], son[N], id[N], tp[N];
  template <typename Edge>
  void build(const Edge e[], const int &rt = 1) {
    fa[rt] = dfn = 0;
    dfs1(e, rt);
    dfs2(e, rt);
  }
  template <typename Edge>
  void dfs1(const Edge e[], const int &u = 1) {
    d[u] = d[fa[u]]+1;
    num[u] = 1;
    son[u] = 0;
    for (const int &v : e[u]) if (v != fa[u]) {
      fa[v] = u;
      dfs1(e, v);
      num[u] += num[v];
      if (num[v] > num[son[u]]) son[u] = v;
    }
  }
  template <typename Edge>
  void dfs2(const Edge e[], const int &u = 1) {
    tp[u] = son[fa[u]] == u ? tp[fa[u]] : u;
    id[u] = ++dfn;
    if (son[u]) dfs2(e, son[u]);
    for (const int &v : e[u]) if (v != son[u] && v != fa[u])
      dfs2(e, v);
  }
  int get(int x, int y) {
    while (tp[x] != tp[y]) {
      if (d[tp[x]] < d[tp[y]]) y = fa[tp[y]];
      else x = fa[tp[x]];
    }
    return d[x] > d[y] ? y : x;
  }
} lca;

template <typename T>
struct ChaFen {
  T val[N];
  void clear(const int &n, const T &k = 0) { fill(val, val+n+1, k); }
  void update_point(const int &x, const int &y, const T &k) {
    int _lca = lca.get(x, y);
    val[x] += k; val[y] += k;
    val[_lca] -= k; val[lca.fa[_lca]] -= k;
  }
  void update_edge(const int &x, const int &y, const T &k) {
    int _lca = lca.get(x, y);
    val[x] += k; val[y] += k; val[_lca] -= 2*k;
  }
  template <typename TT>
  void dfs(const TT e[], const int &u = 1, const int &fa = 0) {
    for (const int &v : e[u]) if (v != fa) {
      dfs(e, v, u);
      val[u] += val[v];
    }
  }
  T query(const int &x) { return val[x]; }
  T& operator [](const int &x) { return val[x]; }
};

int n, m;
long long res[N];
vector<int> e[N];
map<pair<int, int>, int> mp;
ChaFen<long long> point, edge;

inline int readop() {
  while (getchar() != 'A');
  getchar(); getchar();
  return getchar();
}

template <typename T> inline void read(T &x) {
  static int c;
  static T tag = 1;
  while(!isdigit((c=getchar()))) if(c == '-') tag = -1;
  x = c-'0';
  while(isdigit((c=getchar()))) x = (x<<1)+(x<<3) + c-'0';
  x *= tag;
}

template <typename T> void write(T x) {
  if(x < 0) x = -x, putchar('-');
  if(x > 9) write(x/10);
  putchar(x%10+'0');
}

inline void solve(const int &T) {
  mp.clear();
  read(n); read(m);
  // scanf("%d %d", &n, &m);
  for (int i = 1, u, v; i < n; ++i) {
    // scanf("%d %d", &u, &v);
    read(u); read(v);
    e[u].emplace_back(v);
    e[v].emplace_back(u);
    mp[{u, v}] = mp[{v, u}] = i;
  }
  lca.build(e);
  point.clear(n);
  edge.clear(n);
  // static char op[10];
  for (int i = 1, u, v, k, op; i <= m; ++i) {
    // scanf("%s%d%d%d", op, &u, &v, &k);
    op = readop(); read(u); read(v); read(k);
    if (op == '1') {
      point.update_point(u, v, k);
    } else {
      edge.update_edge(u, v, k);
    }
  }
  point.dfs(e);
  edge.dfs(e);
  printf("Case #%d:\n", T);
  for (int i = 1; i <= n; ++i) {
    write(point[i]); putchar(" \n"[i==n]);
    // printf("%lld%c", point[i], " \n"[i==n]);
  }
  for (int i = 2; i <= n; ++i) {
    res[mp[{i, lca.fa[i]}]] = edge[i];
  }
  for (int i = 1; i < n; ++i) {
    write(res[i]); putchar(" \n"[i==n-1]);
    // printf("%lld%c", res[i], " \n"[i==n-1]);
  }
  for (int i = 1; i <= n; ++i) vector<int>().swap(e[i]);
}

signed main() {
  int T = 1;
  // scanf("%d", &T);
  read(T);
  for (int t = 1; t <= T; ++t) {
    solve(t);
  }
  return 0;
}