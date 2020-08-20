/*
 * @Author: Kaizyn
 * @Date: 2020-08-09 14:29:58
 * @LastEditTime: 2020-08-09 17:31:59
 */
#include <bits/stdc++.h>

// #define DEBUG

using namespace std;

const int N = 25000+7;
const int M = N*2*5;

int n, m;
vector<int> e[M];

struct Node {
  int l, r, id;
  friend bool operator <(const Node &lhs, const Node &rhs) {
    return lhs.l == rhs.l ? lhs.r < rhs.r : lhs.l < rhs.l;
  }
} t[N*2];

inline int rev(const int &x) {
  return x&1 ? x+1 : x-1;
}

struct SegmentTreeGarph {
  struct TreeNode {
    int l, r;
    int ls, rs;
  } tr[M];
  int tot, root[2];
  // op [down, 0] [up, 1]
  void build(const int &n) {
    tot = n;
    build(1, n, root[0], 0);
    build(1, n, root[1], 1);
  }
  void build(const int &l, const int &r, int &i, const int &op) {
    i = ++tot;
    tr[i].l = l; tr[i].r = r;
    if (l == r) {
      if (!op) e[i].emplace_back(rev(t[l].id));
      else e[t[l].id].emplace_back(i);
      return;
    }
    int mid = (l+r)>>1;
    build(l, mid, tr[i].ls, op);
    build(mid+1, r, tr[i].rs, op);
    e[op ? tr[i].ls : i].emplace_back(op ? i : tr[i].ls);
    e[op ? tr[i].rs : i].emplace_back(op ? i : tr[i].rs);
  }
  void insert(const int &o, const int &l, const int &r,
      const int &op) {
    if (l > r) return;
    insert(o, l, r, op, root[op]);
  }
  void insert(const int &o, const int &l, const int &r,
      const int &op, const int &i) {
    if (tr[i].l >= l && tr[i].r <= r) {
      e[op ? i : o].emplace_back(op ? o : i);
      return;
    }
    int mid = (tr[i].l+tr[i].r)>>1;
    if (l <= mid) insert(o, l, r, op, tr[i].ls);
    if (r >  mid) insert(o, l, r, op, tr[i].rs);
  }
} stg;

struct TWO_SAT {
  int top, _dfn, _scc;
  int dfn[M], low[M], stk[M], scc[M];
  void init() {
    top = 0;
    memset(dfn+1, 0, sizeof(int)*m);
    memset(low+1, 0, sizeof(int)*m);
    memset(scc+1, 0, sizeof(int)*m);
  }
  inline bool work() {
    init();
    for (int i = 1; i <= 2*n; ++i)
      if (!dfn[i]) tarjan(i);
    for (int i = 1; i <= n; ++i) {
      if (scc[i*2-1] == scc[i*2]) return false;
    }
    return true;
  }
  void tarjan(const int &u) {
    dfn[u] = low[u] = ++_dfn;
    stk[++top] = u;
    for (int &v : e[u]) {
      if (!dfn[v]) {
        tarjan(v);
        low[u] = min(low[u], low[v]);
      } else if (!scc[v]) {
        low[u] = min(low[u], dfn[v]);
      }
    }
    if (dfn[u] == low[u]) {
      ++_scc;
      do {
        scc[stk[top]] = _scc;
      } while (stk[top--] != u);
    }
  }
} sat;

inline bool check(const int &mid) {
  for (int i = 1; i <= 2*n; ++i) {
    if (t[i].r > mid) e[t[i].id].emplace_back(rev(t[i].id));
  }
  bool res = sat.work();
  for (int i = 1; i <= 2*n; ++i) {
    if (t[i].r > mid) e[t[i].id].pop_back();
  }
  return res;
}

inline void build_graph() {
  static int arr[N*2];
  for (int i = 1; i <= m; ++i) e[i].clear(); // clear
  stg.build(2*n);
  m = stg.tot;
  for (int i = 1; i <= 2*n; ++i) arr[i] = t[i].l;
  for (int i = 1, l, r; i <= 2*n; ++i) {
    l = lower_bound(arr+1, arr+2*n+1, t[i].l)-arr;
    r = upper_bound(arr+1, arr+2*n+1, t[i].r)-arr-1;
    // 0 : o -> [l, r]
    // 1 : [l, r] -> o
    stg.insert(t[i].id, l, i-1, 0);
    stg.insert(t[i].id, i+1, r, 0);
    stg.insert(rev(t[i].id), l, i-1, 1);
    stg.insert(rev(t[i].id), i+1, r, 1);
  }
}

inline void solve() {
  static int c[N<<1];
  cin >> n;
  for (int i = 1, a, at, b, bt; i <= n; ++i) {
    cin >> a >> at >> b >> bt;
    t[i*2-1] = {a, a+at, i*2-1};
    t[i*2] = {b, b+bt, i*2};
    c[i*2-1] = a+at;
    c[i*2] = b+bt;
  }
  sort(t+1, t+2*n+1);
  build_graph();
  sort(c+1, c+2*n+1);
  int l = n, r = 2*n, mid;
  while (l < r) {
    mid = (l+r)>>1;
    if (check(c[mid])) r = mid;
    else l = mid+1;
  }
  cout << (check(c[l]) ? c[l] : -1) << endl;
}

signed main() {
  ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
  int T = 1;
  cin >> T;
  while (T--) solve();
  return 0;
}