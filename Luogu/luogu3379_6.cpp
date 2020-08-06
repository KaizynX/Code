/*
 * @Author: Kaizyn
 * @Date: 2020-08-05 16:18:00
 * @LastEditTime: 2020-08-05 16:23:44
 */
#include <bits/stdc++.h>

using namespace std;

const int N = 5e5+7;

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
    if (d[x] > d[y]) swap(x, y);
    return x;
  }
};

int n, m, root;
vector<int> e[N];
HLD hld;

int main() {
  scanf("%d%d%d", &n, &m, &root);
  for(int i = 1, u, v; i < n; ++i) {
    scanf("%d%d", &u, &v);
    e[u].emplace_back(v);
    e[v].emplace_back(u);
  }
  hld.build(e, root);
  for(int i = 0, u, v; i < m; ++i) {
    scanf("%d%d", &u, &v);
    printf("%d\n", hld.lca(u, v));
  }
  return 0;
}