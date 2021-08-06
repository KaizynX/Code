/*
 * @Author: Kaizyn
 * @Date: 2021-08-06 12:51:12
 * @LastEditTime: 2021-08-06 14:30:41
 */
#include <bits/stdc++.h>

// #define DEBUG

using namespace std;

const double eps = 1e-7;
const double PI = acos(-1);
typedef pair<int, int> pii;
typedef long long ll;
const int MOD = 998244353; // 1e9+7;
const int INF = 0x3f3f3f3f;
// const ll INF = 1e18;
#define log(x) (31-__builtin_clz(x))
const int N = 1e5+7;
const int LOGN = log(N)+2;

struct HLD {
  int fa[N], d[N], num[N], son[N], tp[N];
  vector<int> *e;
  void build(vector<int> *e, const int &rt = 1) {
    this->e = e;
    fa[rt] = 0;
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

namespace Tree {
typedef pair<int, int> T;
int tot;
int lc[N*LOGN], rc[N*LOGN];
T tr[N*LOGN]; // {cnt, -z}

T giao(const T &x, const T &y) {
  return max(x, y);
}

int new_node(T v = pii{0, 0}) {
  ++tot;
  lc[tot] = rc[tot] = 0;
  tr[tot] = v;
  return tot;
}

void push_up(int i) {
  if (!lc[i] || !rc[i]) tr[i] = tr[lc[i]+rc[i]];
  else tr[i] = giao(tr[lc[i]], tr[rc[i]]);
}

void add(int x, int v, int L, int R, int &i) {
  if (!i) i = new_node();
  if (L == R) {
    tr[i].first += v;
    tr[i].second = -x;
    return;
  }
  int mid = (L+R)>>1;
  if (x <= mid) add(x, v, L, mid, lc[i]);
  else add(x, v, mid+1, R, rc[i]);
  push_up(i);
}

int merge(int x, int y) {
  if (!x || !y) return x+y;
  int &z = x; // int z = new_node(); // 新建结点?
  lc[z] = merge(lc[x], lc[y]);
  rc[z] = merge(rc[x], rc[y]);
  if (!lc[z] && !rc[z]) tr[z].first = tr[x].first+tr[y].first;
  else push_up(z); // tr[z] = giao(x, y);
  // del(y); // del(x); // 保留结点?
  return z;
}
} // namespace tree

int n, m, Z;
int res[N];
vector<int> e[N], op[N];
HLD hld;

int dfs(int u = 1, int fa = 0) {
  int x = 0;
  for (int v : e[u]) if (v != fa) {
    x = Tree::merge(x, dfs(v, u));
  }
  for (int i : op[u]) {
    Tree::add(abs(i), i/abs(i), 1, Z, x);
  }
  // printf("u=%d(%d,%d)\n", u, Tree::tr[x].first, Tree::tr[x].second);
  res[u] = Tree::tr[x].first ? -Tree::tr[x].second : 0;
  return x;
}

signed main() {
#ifdef ONLINE_JUDGE
  ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
#endif
  cin >> n >> m;
  for (int i = 1, u, v; i < n; ++i) {
    cin >> u >> v;
    e[u].emplace_back(v);
    e[v].emplace_back(u);
  }
  hld.build(e);
  for (int i = 1, x, y, z; i <= m; ++i) {
    cin >> x >> y >> z;
    Z = max(z, Z);
    int lca = hld.lca(x, y);
    int fa = hld.fa[lca];
    op[x].emplace_back(z);
    op[y].emplace_back(z);
    op[lca].emplace_back(-z);
    op[fa].emplace_back(-z);
  }
  dfs();
  for (int i = 1; i <= n; ++i) {
    cout << res[i] << '\n';
  }
  return 0;
}