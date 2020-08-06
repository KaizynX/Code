/*
 * @Author: Kaizyn
 * @Date: 2020-08-05 15:57:58
 * @LastEditTime: 2020-08-05 20:01:08
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

struct VirtualTree {
  int dfn;
  int fa[N], d[N], num[N], son[N], id[N], tp[N];
  int stk[N], top;
  vector<int> *e, ve[N];
  template <typename E>
  void init(E *_e, const int &rt = 1) {
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
  void clear(const int &u) {
    for (const int &v : ve[u]) clear(v);
    ve[u].clear();
  }
  int build(int vset[], const int &k) { // return root
    sort(vset+1, vset+k+1, [&](const int &x, const int &y) {
      return id[x] < id[y];
    });
    top = 0;
    int x, z;
    for (int i = 1; i <= k; ++i) {
      if (top && (z = lca(vset[i], stk[top])) != stk[top]) {
        x = stk[top--];
        while (top && d[stk[top]] > d[z]) {
          ve[stk[top]].emplace_back(x);
          x = stk[top--];
        }
        ve[z].emplace_back(x);
        if (!top || stk[top] != z) stk[++top] = z;
      }
      stk[++top] = vset[i];
    }
    x = stk[top--];
    while (top) {
      ve[stk[top]].emplace_back(x);
      x = stk[top--];
    }
    return x;
  }
};

int n, q, k, res;
int vset[N], vis[N];
VirtualTree vtree;
vector<int> e[N], *ve = vtree.ve;

int dfs(const int &u) {
  // cout << u << endl;
  int son = 0;
  for (const int &v : ve[u]) {
    son += dfs(v);
  }
  ve[u].clear();
  if (vis[u]) {
    res += son;
    return 1;
  } else {
    if (son > 1) return ++res, 0;
    else return son;
  }
}

inline void solve() {
  cin >> n;
  for (int i = 1, u, v; i < n; ++i) {
    cin >> u >> v;
    e[u].emplace_back(v);
    e[v].emplace_back(u);
  }
  vtree.init(e);
  cin >> q;
  for (int i = 1, rt; i <= q; ++i) {
    cin >> k;
    for (int i = 1; i <= k; ++i) {
      cin >> vset[i];
      vis[vset[i]] = 1;
    }
    rt = 1;
    for (int i = 1; i <= k; ++i) {
      if (vis[vtree.fa[vset[i]]]) {
        rt = 0;
        break;
      }
    }
    if (!rt) {
      res = -1;
    } else {
      rt = vtree.build(vset, k);
      res = 0;
      dfs(rt);
    }
    cout << res << endl;
    for (int i = 1; i <= k; ++i) vis[vset[i]] = 0;
  }
}

signed main() {
  ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
  int T = 1;
  // cin >> T;
  for (int t = 1; t <= T; ++t) {
    solve();
  }
  return 0;
}
/*
30
1 2
1 3
1 4
2 5
2 6
2 7
4 8
4 9
6 10
6 11
11 30
11 23
30 24
30 25
25 26
25 27
27 29
27 28
23 20
23 22
20 21
20 19
3 12
3 13
13 14
13 15
15 16
15 17
15 18
2
6 17 25 20 5 9 13
10 2 4 3 14 16 18 22 29 30 19

3
6
*/
/*
4
1 2
2 3
1 4
1
3 1 3 4

-1
*/