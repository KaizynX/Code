/*
 * @Author: Kaizyn
 * @Date: 2020-08-05 20:57:30
 * @LastEditTime: 2020-08-05 23:46:15
 */
#include <bits/stdc++.h>

// #define DEBUG

using namespace std;

const double eps = 1e-7;
const double PI = acos(-1);
typedef pair<int, int> pii;
const int MOD = 998244353;
const int INF = 0x3f3f3f3f;
const int N = 2e4+7;
const int NN = (int)log2(N)+3;

template <typename T>
struct ISAP {
  struct EDGE {
    int v, nex;
    T w;
    EDGE(const int &_v, const int &_nex, const T &_w) : v(_v), nex(_nex), w(_w) {}
  };
  vector<EDGE> e;
  int n, s, t;
  T maxflow;
  int fir[N<<2], gap[N<<2], dep[N<<2];
  T work(const int &_s, const int &_t) {
    s = _s; t = _t;
    maxflow = 0;
    bfs();
    while (dep[s] < n) dfs(s, INF);
    return maxflow;
  }
  void init(const int &_n) {
    n = _n;
    e.clear();
    e.reserve(N<<2);
    memset(fir, -1, sizeof(int)*(n+3));
  }
  void add_edge(const int &u, const int &v, const T &w) {
    e.emplace_back(v, fir[u], w); fir[u] = e.size()-1;
    e.emplace_back(u, fir[v], 0); fir[v] = e.size()-1;
  }
  void bfs() {
    queue<int> q;
    memset(dep, -1, sizeof(int)*(n+3));
    memset(gap, 0, sizeof(int)*(n+3));
    dep[t] = 0;
    gap[0] = 1;
    q.push(t);
    while (q.size()) {
      int u = q.front();
      q.pop();
      for (int i = fir[u], v; i != -1; i = e[i].nex) {
        v = e[i].v;
        if (dep[v] != -1) continue;
        q.push(v);
        dep[v] = dep[u]+1;
        ++gap[dep[v]];
      }
    }
  }
  T dfs(const int &u, const T &flow) {
    if (u == t) return maxflow += flow, flow;
    T used = 0;
    for (int i = fir[u], v; i != -1; i = e[i].nex) {
      v = e[i].v;
      if (!e[i].w || dep[v]+1 != dep[u]) continue;
      T minf = dfs(v, min(e[i].w, flow-used));
      if (minf) {
        e[i].w -= minf;
        e[i^1].w += minf;
        used += minf;
      }
      if (used == flow) return used;
    }
    if (--gap[dep[u]] == 0) dep[s] = n+1;
    ++gap[++dep[u]];
    return used;
  }
};

int n, dfn;
int c[N], id[N], vfa[N];
vector<int> e[N], ve[N], col[N];
int f[N][NN], d[N], lg2[N];
ISAP<int> isap;

// LCA begin
void tree_init(const int &u = 1) {
  id[u] = ++dfn;
  for (int i = 1; (1<<i) <= d[u]; ++i)
    f[u][i] = f[f[u][i-1]][i-1];
  for (auto v : e[u]) {
    f[v][0] = u;
    d[v] = d[u]+1;
    tree_init(v);
  }
}

int lca(int x, int y) {
  if (d[x] < d[y]) swap(x, y);
  while (d[x] > d[y])
    x = f[x][lg2[d[x]-d[y]]];
  if (x == y) return x;
  for (int i = lg2[d[x]]; i >= 0; --i)
    if(f[x][i] != f[y][i])
      x = f[x][i], y = f[y][i];
  return f[x][0];
}

int y_son(int x, int y) { // x is son of y, return y'son who is x's father
  if (d[x] < d[y]) swap(x, y);
  for (int dis = d[x]-d[y]-1, i = lg2[dis]; i >= 0; --i) {
    if (1<<i <= dis) {
      x = f[x][i];
      dis -= 1<<i;
    }
  }
  return x;
}
// LCA end

// VirtualTree begin
void virtual_tree_clear(const int &u = 1) {
  for (const int &v : ve[u]) virtual_tree_clear(v);
  ve[u].clear();
}

// build a VirtualTree return the root
int virtual_tree_build(vector<int> &vset) {
  // id ==> dfn rank, d ==> depth
  static int stk[N], top;
  sort(vset.begin(), vset.end(), [&](const int &x, const int &y) {
    return id[x] < id[y];
  });
  top = 0;
  int x, z;
  for (const int &v : vset) {
    if (top && (z = lca(v, stk[top])) != stk[top]) {
      x = stk[top--];
      while (top && d[stk[top]] > d[z]) {
        ve[stk[top]].emplace_back(x);
        vfa[x] = stk[top];
        x = stk[top--];
      }
      ve[z].emplace_back(x);
      vfa[x] = z;
      if (!top || stk[top] != z) stk[++top] = z;
    }
    stk[++top] = v;
  }
  x = stk[top--];
  while (top) {
    ve[stk[top]].emplace_back(x);
    vfa[x] = stk[top];
    x = stk[top--];
  }
  // if (x != 1) ve[1].emplace_back(x), vfa[x] = 1;
  return x;
}
// VirtualTree end

// SegmentTreeGraph begin
struct SegmentTreeGarph {
  struct TreeNode {
    int l, r;
    int ls, rs;
    int len() const { return r-l+1; }
  } tr[N<<2];
  int tot, root[2];
  // op [down, 0] [up, 1]
  void build(const int &n) {
    tot = n;
    for (int i = 1; i <= n; ++i) tr[i].l = tr[i].r = i;
    // build(1, n, root[0], 0);
    build(1, n, root[1], 1);
  }
  void build(const int &l, const int &r, int &i, const int &op) {
    if (l == r) return i = l, void();
    i = ++tot;
    tr[i].l = l; tr[i].r = r;
    int mid = (l+r)>>1;
    build(l, mid, tr[i].ls, op);
    build(mid+1, r, tr[i].rs, op);
    isap.add_edge(op ? tr[i].ls : i, op ? i : tr[i].ls, INF);
    isap.add_edge(op ? tr[i].rs : i, op ? i : tr[i].rs, INF);
  }
  void insert(const int &o, int l, int r, const int &op) {
    if (l > r) swap(l, r);
    insert(o, l, r, op, root[op]);
  }
  void insert(const int &o, const int &l, const int &r,
      const int &op, const int &i) {
    if (tr[i].l >= l && tr[i].r <= r) {
      isap.add_edge(op ? i : o, op ? 0 : i, tr[i].len());
      return;
    }
    int mid = (tr[i].l+tr[i].r)>>1;
    if (l <= mid) insert(o, l, r, op, tr[i].ls);
    if (r >  mid) insert(o, l, r, op, tr[i].rs);
  }
} stg;
// SegmentTreeGraph end

// (k*d) ==> 2*n+(k*d)
int C, MID;
int build_stg(const int &u = 1) {
  int sum = 1;
  for (const int &v : ve[u]) {
    sum += build_stg(v);
  }
  if (vfa[u] && sum*C <= MID) {
    int v = y_son(u, vfa[u]);
    stg.insert(2*n+sum*C, id[v], id[u], 1);
  }
  return sum;
}

bool check() {
  isap.init(n*3+2);
  stg.build(n);
  for (int i = 1, rt, num; i <= n; ++i) if (col[i].size()) {
    C = i;
    rt = virtual_tree_build(col[i]);
    num = build_stg(rt);
    if (rt != 1 && num <= MID) stg.insert(2*n+num, id[1], id[rt], 1);
    virtual_tree_clear(rt);
  }
  assert(stg.tot < n*2);
  int st = n*3+1, ed = n*3+2;
  for (int i = 1; i <= n; ++i) {
    isap.add_edge(st, i, 1);
    isap.add_edge(i, 2*n, 1);
    isap.add_edge(2*n+i, ed, 1);
  }
  isap.add_edge(2*n, ed, 1);
  return isap.work(st, ed) >= MID+1;
}

signed main() {
  ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(NULL);
  for (int i = 2; i < N; ++i) lg2[i] = lg2[i>>1]+1;

  cin >> n;
  for (int i = 2, p; i <= n; ++i) {
    cin >> p;
    e[p].emplace_back(i);
  }
  for (int i = 1; i <= n; ++i) {
    cin >> c[i];
    col[c[i]].emplace_back(i);
  }

  tree_init();
  int l = 0, r = n;
  // global variable MID
  while (l < r) {
    MID = (l+r+1)>>1;
    if (check()) l = MID;
    else r = MID-1;
  }
  cout << l+1 << endl;
  return 0;
}