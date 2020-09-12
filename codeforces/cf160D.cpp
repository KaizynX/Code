/*
 * @Author: Kaizyn
 * @Date: 2020-09-03 15:49:54
 * @LastEditTime: 2020-09-04 22:43:55
 */
#include <bits/stdc++.h>

// #define DEBUG

using namespace std;

const int MOD = 998244353;
const int INF = 0x3f3f3f3f;
const int N = 1e5+7;

int n, m;
vector<int> a, use, res; // a[] edge id upon node i
vector<vector<int>> e, edges, dif_add, dif_del;

namespace ST { // ST表
#define log2(x) (31-__builtin_clz(x))
vector<vector<int>> rmq;
// rmq[i][j] ==> [i, i+2^j-1]
void build() {
  rmq = vector<vector<int>>(n, vector<int>(log2(n)+1));
  for (int i = n-1; i; --i) {
    rmq[i][0] = edges[a[i]][2];
    for (int j = 1; j <= log2(n-i); ++j)
      rmq[i][j] =  max(rmq[i][j-1], rmq[i+(1<<(j-1))][j-1]);
  }
}
int query(int l, int r) {
  if (l > r) return 0;
  int k = log2(r-l+1);
  return max(rmq[l][k], rmq[r-(1<<k)+1][k]);
}
#undef log2
} // namespace ST

namespace HLD { // 树剖
int dfn;
vector<int> fa, d, num, son, id, tp;
void dfs1(int u = 1) {
  num[u] = 1;
  son[u] = -1;
  for (int &i : e[u]) {
    int v = edges[i][0] == u ? edges[i][1] : edges[i][0];
    if (v == fa[u]) continue;
    fa[v] = u;
    d[v] = d[u]+1;
    dfs1(v);
    num[u] += num[v];
    if (son[u] == -1 || num[v] > num[son[u]]) son[u] = v;
  }
}
void dfs2(int u = 1) {
  if (~son[u]) id[son[u]] = ++dfn, tp[son[u]] = tp[u], dfs2(son[u]);
  for (int &i : e[u]) {
    int v = edges[i][0] == u ? edges[i][1] : edges[i][0];
    if (v == fa[u]) continue;
    if (v != son[u]) id[v] = ++dfn, tp[v] = v, dfs2(v);
    a[id[v]] = i;
  }
}
void build(const int &rt = 0) {
  fa = vector<int>(n);
  d = vector<int>(n);
  num = vector<int>(n);
  son = vector<int>(n, -1);
  id = vector<int>(n);
  tp = vector<int>(n);
  fa[rt] = -1;
  d[rt] = dfn = 0;
  dfs1(rt);
  dfs2(rt);
  ST::build();
#ifdef DEBUG
  cout << "HLD build\n";
  for (int i = 0; i < n; ++i) cout << HLD::id[i] << " ";
  cout << endl;
  for (int i = 0; i < n; ++i) cout << a[i] << " ";
  cout << endl;
#endif
}
int query(int i) {
  int u = edges[i][0], v = edges[i][1], w = edges[i][2];
  int mxv = 0;
  while (tp[u] != tp[v]) {
    if (d[tp[u]] < d[tp[v]]) swap(u, v);
    mxv = max(mxv, ST::query(id[tp[u]], id[u]));
    u = fa[tp[u]];
  }
  if (d[u] > d[v]) swap(u, v);
  if (id[u] != id[v]) mxv = max(mxv, ST::query(id[u]+1, id[v]));
  if (mxv != w) return -1;

  u = edges[i][0]; v = edges[i][1];
  while (tp[u] != tp[v]) {
    if (d[tp[u]] < d[tp[v]]) swap(u, v);
    if (ST::query(id[tp[u]], id[u]) == mxv) {
      dif_add[id[tp[u]]].emplace_back(mxv);
      dif_del[id[u]+1].emplace_back(mxv);
    }
    u = fa[tp[u]];
  }
  if (d[u] > d[v]) swap(u, v);
  if (id[u] != id[v] && ST::query(id[u]+1, id[v]) == mxv) {
    dif_add[id[u]+1].emplace_back(mxv);
    dif_del[id[v]+1].emplace_back(mxv);
  }
  return 1;
}
} // namespace HLD

void build_mst() { // 最小生成树
  vector<int> rk(m), fa(n);
  for (int i = 0; i < n; ++i) fa[i] = i;
  for (int i = 0; i < m; ++i) rk[i] = i;
  function<int(int)> find_fa = [&](int x) { // 并查集
    return fa[x] == x ? x : fa[x] = find_fa(fa[x]);
  };
  sort(rk.begin(), rk.end(), [&](int x, int y) {
    return edges[x][2] < edges[y][2];
  });
  for (int &i : rk) {
    int u = edges[i][0], v = edges[i][1];
    int f0 = find_fa(u), f1 = find_fa(v);
    if (f0 == f1) continue;
    fa[f0] = f1;
    use[i] = 1;
    e[u].emplace_back(i);
    e[v].emplace_back(i);
  }
}

signed main() {
  ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
  cin >> n >> m;
  a = vector<int>(n, -1);
  use = vector<int>(m, 0);
  e = vector<vector<int>>(n);
  res = vector<int>(m);
  dif_add = vector<vector<int>>(n);
  dif_del = vector<vector<int>>(n+1);
  edges = vector<vector<int>>(m, vector<int>(3));
  for (int i = 0; i < m; ++i) {
    cin >> edges[i][0] >> edges[i][1] >> edges[i][2];
    --edges[i][0]; --edges[i][1];
  }
  build_mst();
  HLD::build();
  for (int i = 0; i < m; ++i) if (!use[i]) res[i] = HLD::query(i);
  unordered_map<int, int> cur;
  for (int i = 1; i < n; ++i) {
    for (int &j : dif_del[i]) --cur[j];
    for (int &j : dif_add[i]) ++cur[j];
    res[a[i]] = cur[edges[a[i]][2]];
  }
  for (int i = 0; i < m; ++i) {
    if (res[i] == -1) cout << "none" << endl;
    if (res[i] == 0) cout << "any" << endl;
    if (res[i] > 0) cout << "at least one" << endl;
  }
  return 0;
}
/*
input
10 15
6 5 805980
1 6 805980
7 8 805980
4 9 805980
4 1 805980
3 6 805980
6 9 805980
8 10 805980
3 1 805980
1 8 805980
8 4 805980
2 8 805980
2 10 805980
2 7 805980
2 9 805980
output
any
at least one
at least one
at least one
at least one
at least one
at least one
at least one
at least one
at least one
at least one
at least one
at least one
at least one
at least one
*/