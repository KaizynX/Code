/*
 * @Author: Kaizyn
 * @Date: 2020-08-09 14:29:58
 * @LastEditTime: 2020-08-09 16:34:47
 */
#include <bits/stdc++.h>

#define DEBUG

using namespace std;

const double eps = 1e-7;
const double PI = acos(-1);
typedef pair<int, int> pii;
const int MOD = 998244353;
const int INF = 0x3f3f3f3f;
const int N = 25000+7;

int n, m;
int rev[N*2];
pii t[N*2];
vector<int> e[N*2*3];

struct SegmentTreeGarph {
  struct TreeNode {
    int l, r;
    int ls, rs;
  } tr[N*2*3];
  int tot, root[2];
  // op [down, 0] [up, 1]
  void build(const int &n) {
    tot = n;
    for (int i = 1; i <= n; ++i) tr[i].l = tr[i].r = i;
    build(1, n, root[0], 0);
    build(1, n, root[1], 1);
  }
  void build(const int &l, const int &r, int &i, const int &op) {
    if (l == r) return i = l, void();
    i = ++tot;
    tr[i].l = l; tr[i].r = r;
    int mid = (l+r)>>1;
    build(l, mid, tr[i].ls, op);
    build(mid+1, r, tr[i].rs, op);
    e[op ? tr[i].ls : i].emplace_back(op ? i : tr[i].ls);
    e[op ? tr[i].rs : i].emplace_back(op ? i : tr[i].rs);
  }
  void insert(const int &o, const int &l, const int &r,
      const int &op) {
    if (l > r) return;
    if (l == r) e[op ? l : o].emplace_back(op ? o : l);
    else insert(o, l, r, op, root[op]);
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
  int dfn[N*2*3], low[N*2*3], stk[N*2*3], scc[N*2*3];
  void init() {
    top = 0;
    memset(dfn+1, 0, sizeof(int)*m);
    memset(low+1, 0, sizeof(int)*m);
  }
  // if u then v
  void add_edge(const int &u, const int &v) {
    e[u].emplace_back(v);
  }
  inline bool work() {
    init();
    for (int i = 1; i <= 2*n; ++i)
      if (!dfn[i]) tarjan(i);
    for (int i = 1; i <= 2*n; ++i) {
      if (scc[i] == scc[rev[i]]) return false;
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
    if (t[i].second > mid) e[i].emplace_back(rev[i]);
  }
  bool res = sat.work();
  for (int i = 1; i <= 2*n; ++i) {
    if (t[i].second > mid) e[i].pop_back();
  }
  return res;
}

inline void build_graph() {
  stg.build(2*n);
  m = stg.tot;
  for (int i = 1, l, r; i <= 2*n; ++i) {
    l = lower_bound(t+1, t+2*n+1, pii{t[i].first, 0})-t;
    r = lower_bound(t+1, t+2*n+1, pii{t[i].second+1, 0})-t-1;
    // 0 : o -> [l, r]
    // 1 : [l, r] -> o
    stg.insert(i, l, i-1, 0);
    stg.insert(i, i+1, r, 0);
    stg.insert(rev[i], l, i-1, 1);
    stg.insert(rev[i], i+1, r, 1);
  }
}

inline void get_rev() {
  static int tmp[N], rk[N*2];
  for (int i = 1; i <= n; ++i) {
    tmp[i] = 0;
    rk[i*2-1] = i*2-1;
    rk[i*2] = i*2;
  }
  sort(rk+1, rk+2*n+1, [](int x, int y) { return t[x] < t[y]; });
  for (int i = 1, j; i <= 2*n; ++i) {
    j = (rk[i]+1)/2;
    if (tmp[j]) {
      rev[tmp[j]] = i;
      rev[i] = tmp[j];
    } else {
      tmp[j] = i;
    }
  }
}

inline void solve() {
  int l = 0, r = 0, mid;
  cin >> n;
  for (int i = 1, a, at, b, bt; i <= n; ++i) {
    cin >> a >> at >> b >> bt;
    t[i*2-1] = {a, a+at};
    t[i*2] = {b, b+bt};
    l = max(l, min(a+at, b+bt));
    r = max(r, max(a+at, b+bt));
  }
  get_rev();
  sort(t+1, t+2*n+1);
  build_graph();
#ifdef DEBUG
  for (int i = 1; i <= 2*n; ++i) {
    printf("%d:(%d,%d)->%d\n", i, t[i].first, t[i].second, rev[i]);
  }
#endif
  while (l < r) {
    mid = (l+r)>>1;
    if (check(mid)) r = mid;
    else l = mid+1;
  }
  cout << (check(l) ? l : -1) << endl;
  // clear
  for (int i = 1; i <= m; ++i) {
    vector<int>().swap(e[i]);
  }
}

signed main() {
  ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
  int T = 1;
  cin >> T;
  while (T--) solve();
  return 0;
}