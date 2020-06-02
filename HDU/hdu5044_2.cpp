/*
 * @Author: Kaizyn
 * @Date: 2020-06-01 22:19:28
 * @LastEditTime: 2020-06-02 13:07:57
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

struct LCA {
  static const int NN = (int)log2(N)+3;
  int f[N][NN], d[N], lg2[N];
  LCA() { for (int i = 2; i < N; ++i) lg2[i] = lg2[i>>1]+1; }
  template <typename TT>
  void build(const TT e[], const int &rt = 1) {
    static queue<int> q;
    q.push(rt);
    while (q.size()) {
      int u = q.front();
      q.pop();
      d[u] = d[f[u][0]]+1;
      for (int i = 1; (1<<i) <= d[u]; ++i)
        f[u][i] = f[f[u][i-1]][i-1];
      for (const int &v : e[u]) if (v != f[u][0]) {
        f[v][0] = u;
        q.push(v);
      }
    }
  }
  int get(int x, int y) {
    if (d[x] < d[y]) swap(x, y);
    while (d[x] > d[y])
      x = f[x][lg2[d[x]-d[y]]];
    if (x == y) return x;
    for (int i = lg2[d[x]]; i >= 0; --i)
      if(f[x][i] != f[y][i])
        x = f[x][i], y = f[y][i];
    return f[x][0];
  }
} lca;

template <typename T>
struct ChaFen {
  T val[N];
  void clear(const int &n, const T &k = 0) { fill(val, val+n+1, k); }
  void update_point(const int &x, const int &y, const T &k) {
    int _lca = lca.get(x, y);
    val[x] += k; val[y] += k;
    val[_lca] -= k; val[lca.f[_lca][0]] -= k;
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
    res[mp[{i, lca.f[i][0]}]] = edge[i];
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