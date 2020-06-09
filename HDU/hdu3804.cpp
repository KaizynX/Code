/*
 * @Author: Kaizyn
 * @Date: 2020-06-04 11:28:24
 * @LastEditTime: 2020-06-04 15:46:38
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

int n, q;
vector<pii> e[N];

template <typename T>
struct ShuPou {
  int dfn;
  int fa[N], d[N], num[N], son[N], rk[N], id[N], tp[N];
  set<T> st[N];
  template <typename Edge>
  void build(const Edge e[], const int &n, const int &rt = 1) {
    fa[rt] = dfn = 0;
    dfs1(e, rt);
    dfs2(e, rt);
  }
  template <typename Edge>
  void dfs1(const Edge e[], const int &u = 1) {
    d[u] = d[fa[u]]+1;
    num[u] = 1;
    son[u] = 0;
    for (auto &v : e[u]) if (v != fa[u]) {
      dfs1(e, v);
      if (num[v] > num[son[u]]) son[u] = v;
    }
  }
  template <typename Edge>
  void dfs2(const Edge e[], const int &u = 1) {
    tp[u] = son[fa[u]] == u ? tp[fa[u]] : u;
    id[u] = ++dfn;
    rk[dfn] = u;
    set<T>.swap(st[u]);
    if (son[u]) dfs2(e, son[u]);
    for (auto &v : e[u]) if (v != son[u] && v != fa[u])
      dfs2(e, v);
  }
  T query(int x) {
    T res = -1;
    while (tp[x] != 1) {
      x = fa[tp[x]];
    }
    return res;
  }
};

inline void solve() {
  cin >> n >> q;
  for (int i = 1, u, v, w; i <= n; ++i) {
    cin >> u >> v >> w;
    e[u].emplace_back(v, w);
    e[v].emplace_back(u, w);
  }
}

signed main() {
  ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
  int T = 1;
  cin >> T;
  for (int t = 1; t <= T; ++t) {
    solve();
  }
  return 0;
}