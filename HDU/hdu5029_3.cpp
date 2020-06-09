/*
 * @Author: Kaizyn
 * @Date: 2020-06-04 19:18:16
 * @LastEditTime: 2020-06-08 08:52:02
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
const int Z = 1e5;

int n, m;
int res[N];
vector<int> e[N], add[N], del[N];

struct ShuPou {
  int dfn;
  int fa[N], d[N], num[N], son[N], id[N], tp[N];
  int val[N];
  set<pii> st;
  void build(const int &rt = 1) {
    fa[rt] = dfn = 0;
    dfs1(rt);
    dfs2(rt);
    // ST.build(n);
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
  void update(int x, int y, const int &z) {
    while (tp[x] != tp[y]) {
      if (d[tp[x]] < d[tp[y]]) swap(x, y);
      add[id[tp[x]]].emplace_back(z);
      del[id[x]+1].emplace_back(z);
      x = fa[tp[x]];
    }
    if (d[x] > d[y]) swap(x, y);
    add[id[x]].emplace_back(z);
    del[id[y]+1].emplace_back(z);
  }
  void query(const int &z = Z) {
    set<pii>().swap(st);
    for (int i = 0; i <= z; ++i) {
      st.insert({val[i] = 0, -i});
    }
    for (int i = 1; i <= n; ++i) {
      for (const int &j : add[i]) {
        st.erase(st.find({val[j], -j}));
        st.insert({++val[j], -j});
      }
      for (const int &j : del[i]) {
        st.erase(st.find({val[j], -j}));
        st.insert({--val[j], -j});
      }
      res[i] = -(--st.end())->second;
    }
    for (int i = 1; i <= n; ++i) {
      cout << res[id[i]] << endl;
    }
  }
} tree;

inline void solve() {
  for (int i = 1, u, v; i < n; ++i) {
    cin >> u >> v;
    e[u].emplace_back(v);
    e[v].emplace_back(u);
  }
  tree.build();
  int zz = 0;
  for (int i = 1, x, y, z; i <= m; ++i) {
    cin >> x >> y >> z;
    tree.update(x, y, z);
    zz = max(zz, z);
  }
  tree.query(zz);
  for (int i = 1; i <= n+1; ++i) {
    vector<int>().swap(e[i]);
    vector<int>().swap(add[i]);
    vector<int>().swap(del[i]);
  }
}

signed main() {
  ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
  while (cin >> n >> m && n|m) solve();
  return 0;
} 