/*
 * @Author: Kaizyn
 * @Date: 2020-09-10 20:35:07
 * @LastEditTime: 2020-09-10 20:41:31
 */
#include <bits/stdc++.h>

// #define DEBUG

using namespace std;

const double eps = 1e-7;
const double PI = acos(-1);
typedef pair<int, int> pii;
const int MOD = 998244353;
const int INF = 0x3f3f3f3f;
const int N = 5e3+7;

struct HLD {
  int dfn;
  int fa[N], d[N], num[N], son[N], id[N], tp[N];
  vector<int> *e;
  template <typename E>
  void build(E *_e, const int &rt = 1) {
    e = _e;
    fa[rt] = dfn = 0;
    dfs1(rt);
    dfs2(rt);
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
    tp[u] = son[fa[u]] == u ? tp[fa[u]] : u;
    id[u] = ++dfn;
    if (son[u]) dfs2(son[u]);
    for (const int &v : e[u]) if (v != son[u] && v != fa[u])
      dfs2(v);
  }
  int lca(int x, int y) {
    while (tp[x] != tp[y]) {
      if (d[tp[x]] < d[tp[y]]) swap(x, y);
      x = fa[tp[x]];
    }
    return d[x] < d[y] ? x : y;
  }
};

int n, q;
int a[N];
vector<int> e[N];
HLD hld;

long long query(int u, int v, int l, int r) {
  int lca = hld.lca(u, v);
  long long res = a[lca] >= l && a[lca] <= r ? a[lca] : 0;
  while (u != lca) {
    if (a[u] >= l && a[u] <= r) res += a[u];
    u = hld.fa[u];
  }
  while (v != lca) {
    if (a[v] >= l && a[v] <= r) res += a[v];
    v = hld.fa[v];
  }
  return res;
}

signed main() {
  ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
  cin >> n >> q;
  for (int i = 1; i <= n; ++i) cin >> a[i];
  for (int i = 1, u, v; i < n; ++i) {
    cin >> u >> v;
    e[u].emplace_back(v);
    e[v].emplace_back(u);
  }
  hld.build(e);
  for (int i = 1, op, u, v, l, r; i <= q; ++i) {
    cin >> op >> u >> v;
    if (op == 1) {
      a[u] = v;
    } else {
      cin >> l >> r;
      cout << query(u, v, l, r) << endl;
    }
  }
  return 0;
}