/*
 * @Author: Kaizyn
 * @Date: 2020-09-03 15:49:54
 * @LastEditTime: 2020-09-04 21:56:50
 */
#include <bits/stdc++.h>

// #define DEBUG

using namespace std;

const int MOD = 998244353;
const int INF = 0x3f3f3f3f;
const int N = 1e5+7;
const int M = 2e5+7;

int n, m;
vector<int> a, use, res; // a[] edge id upon node i
vector<vector<int>> e, edges;
vector<set<int>> pos;

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
    pos[edges[i][2]].insert(id[v]);
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
#ifdef DEBUG
  cout << "HLD build\n";
  for (int i = 0; i < n; ++i) cout << HLD::id[i] << " ";
  cout << endl;
  for (int i = 0; i < n; ++i) cout << a[i] << " ";
  cout << endl;
#endif
  ST::build();
}
void query(int i) {
  int u = edges[i][0], v = edges[i][1], w = edges[i][2];
  int mxv = 0;
  while (tp[u] != tp[v]) {
    if (d[tp[u]] < d[tp[v]]) swap(u, v);
    mxv = max(mxv, ST::query(id[tp[u]], id[u]));
    u = fa[tp[u]];
  }
  if (d[u] > d[v]) swap(u, v);
  if (id[u] != id[v]) mxv = max(mxv, ST::query(id[u]+1, id[v]));
  res[i] = -1;
  if (mxv != w) return;

  res[i] = 1;
  u = edges[i][0];
  v = edges[i][1];
  while (tp[u] != tp[v]) {
    if (d[tp[u]] < d[tp[v]]) swap(u, v);
    if (ST::query(id[tp[u]], id[u]) == mxv) {
      while (pos[mxv].size()) {
        set<int>::iterator it = pos[mxv].lower_bound(id[tp[u]]);
        if (it == pos[mxv].end() || *it > id[u]) break;
        res[a[*it]] = 1;
        pos[mxv].erase(it);
      }
    }
    u = fa[tp[u]];
  }
  if (d[u] > d[v]) swap(u, v);
  if (id[u] != id[v] && ST::query(id[u]+1, id[v]) == mxv) {
    while (pos[mxv].size()) {
      set<int>::iterator it = pos[mxv].lower_bound(id[u]+1);
      if (it == pos[mxv].end() || *it > id[v]) break;
      res[a[*it]] = 1;
      pos[mxv].erase(it);
    }
  }
}
} // namespace HLD

void discrete() {
  vector<int> dis(m);
  for (int i = 0; i < m; ++i) dis[i] = edges[i][2];
  sort(dis.begin(), dis.end());
  dis.erase(unique(dis.begin(), dis.end()), dis.end());
  pos = vector<set<int>>(dis.size());
  for (int i = 0; i < m; ++i)
    edges[i][2] = lower_bound(dis.begin(), dis.end(), edges[i][2])-dis.begin();
}

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
#ifdef DEBUG
  cout << "build_mst\n";
  for (int i = 0; i < m; ++i) cout << use[i] << " ";
  cout << endl;
#endif
}

signed main() {
  ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
  cin >> n >> m;
  a = vector<int>(n, -1);
  use = vector<int>(m, 0);
  e = vector<vector<int>>(n);
  res = vector<int>(m, 0);
  edges = vector<vector<int>>(m, vector<int>(3));
  for (int i = 0; i < m; ++i) {
    cin >> edges[i][0] >> edges[i][1] >> edges[i][2];
    --edges[i][0]; --edges[i][1];
  }
  discrete();
  build_mst();
  HLD::build();
  for (int i = 0; i < m; ++i) if (!use[i]) HLD::query(i);
  // for (set<int> &st : pos) for (const int &i : st) res[a[i]] = 0;
  for (int i = 0; i < m; ++i) {
    if (res[i] == -1) cout << "none" << endl;
    if (res[i] == 0) cout << "any" << endl;
    if (res[i] == 1) cout << "at least one" << endl;
  }
  return 0;
}