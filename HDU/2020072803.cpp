/*
 * @Author: Kaizyn
 * @Date: 2020-07-28 13:37:46
 * @LastEditTime: 2020-07-29 16:00:13
 */ 
#pragma GCC optimize("Ofast,no-stack-protector")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,avx2,tune=native")
#include <bits/stdc++.h>

// #define DEBUG

using namespace std;

const double eps = 1e-7;
const double PI = acos(-1);
typedef pair<int, int> pii;
const int MOD = 998244353;
const int INF = 0x3f3f3f3f;
const int N = 1e5+7;
const int M = 20;

template <typename T> inline void read(T &x) {
  int c; T tag = 1;
  while(!isdigit((c=getchar()))) if(c == '-') tag = -1;
  x = c-'0';
  while(isdigit((c=getchar()))) x = (x<<1)+(x<<3) + c-'0';
  x *= tag;
}

template <typename T> void write(T x) {
  if(x < 0) x = -x, putchar('-');
  if (x > 9) write(x/10);
  putchar(x%10+'0');
}

template <typename T>
struct BinaryIndexedTree {
  int n;
  T tr[N];
  BinaryIndexedTree() { memset(tr, 0, sizeof tr); }
  void init(const int &_n) { n = _n; clear(); }
  void clear() { memset(tr+1, 0, sizeof(T)*n); }
  void add(const int &x, const T &v) { for (int i = x; i <= n; i += i&-i) tr[i] += v; }
  void add(const int &x, const int &y, const T &v) { add(x, v); add(y+1, -v); }
  T query(const int &x) { T res = 0; for (int i = x ; i; i -= i&-i) res += tr[i]; return res; }
  T query(const int &x, const int &y) { return query(y)-query(x-1); }
};

struct Operator {
  int x, v, k, t;
};

int n, q;
int col[N], val[N], s[2][M];
long long res[N];
vector<int> e[N];
vector<Operator> ope[N];

struct ShuPou {
  typedef int T;
  int dfn;
  int fa[N], d[N], num[N], son[N], id[N];
  BinaryIndexedTree<T> up[2][M], dw[2][M];
  void build(const int &rt = 1) {
    fa[rt] = dfn = 0;
    dfs1(rt);
    dfs2(rt);
    for (int i = 0; i < M; ++i) {
      up[0][i].n = n; up[1][i].n = n;
      dw[0][i].n = n; dw[1][i].n = n;
    }
  }
  void dfs1(const int &u = 1) {
    d[u] = d[fa[u]]+1;
    num[u] = 1;
    son[u] = 0;
    for (const int &v : e[u]) if (v != fa[u]) {
      fa[v] = u;
      dfs1(v);
      num[u] += num[v];
      if (num[v] > num[son[u]]) son[u] = v;
    }
  }
  void dfs2(const int &u = 1) {
    id[u] = ++dfn;
    if (son[u]) dfs2(son[u]);
    for (const int &v : e[u]) if (v != son[u] && v != fa[u])
      dfs2(v);
  }
  void add_up(const int &b, const int &i, const int &x, const T &k) {
    up[b][i].add(id[x], id[x]+num[x]-1, k);
  }
  void add_dw(const int &b, const int &i, const int &x, const T &k) {
    dw[b][i].add(id[x], k);
  }
  T query_up(const int &b, const int &i, const int &x) {
    return up[b][i].query(id[x]);
  }
  T query_dw(const int &b, const int &i, const int &x) {
    return dw[b][i].query(id[x], id[x]+num[x]-1);
  }
} tree;

inline void solve() {
  read(n);
  for (int i = 1; i <= n; ++i) read(col[i]);
  for (int i = 1; i <= n; ++i) read(val[i]);
  for (int i = 1, u, v; i < n; ++i) {
    read(u); read(v);
    e[u].emplace_back(v);
    e[v].emplace_back(u);
  }
  tree.build();
  for (int i = 1; i <= n; ++i) {
    ope[col[i]].emplace_back(Operator{i, val[i], 1, 0});
  }
  read(q);
  for (int i = 1, op, x, y; i <= q; ++i) {
    read(op); read(x); read(y);
    ope[col[x]].emplace_back(Operator{x, val[x], -1, i});
    op == 1 ? val[x] = y : col[x] = y;
    ope[col[x]].emplace_back(Operator{x, val[x], 1, i});
  }
  for (int i = 1; i <= n; ++i) {
    for (const auto &op : ope[i]) {
      int x = op.x, v = op.v, k = op.k, t = op.t;
      for (int j = 0, b, cnt; j < M; ++j) {
        b = v>>j&1;
        cnt = k*s[b^1][j];
        s[b][j] += k;
        cnt -= k*tree.query_up(b^1, j, x);
        cnt -= k*tree.query_dw(b^1, j, x);
        tree.add_up(b, j, x, k);
        tree.add_dw(b, j, x, k);
        res[t] += (1ll<<j)*cnt;
      }
    }
    // clear
    for (const auto &op : ope[i]) {
      int x = op.x,v = op.v, k = op.k;
      for (int j = 0, b; j < M; ++j) {
        b = v>>j&1;
        s[b][j] -= k;
        tree.add_up(b, j, x, -k);
        tree.add_dw(b, j, x, -k);
      }
    }
  }
  write(res[0]); putchar('\n');
  for (int i = 1; i <= q; ++i) {
    res[i] += res[i-1];
    write(res[i]); putchar('\n');
  }
  // clear
  for (int i = 0; i <= n; ++i) {
    res[i] = 0;
    e[i].clear();
    ope[i].clear();
  }
}

signed main() {
  int T = 1;
  read(T);
  for (int t = 1; t <= T; ++t) {
    solve();
  }
  return 0;
}