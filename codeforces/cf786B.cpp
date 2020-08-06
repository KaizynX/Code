/*
 * @Author: Kaizyn
 * @Date: 2020-08-05 10:47:16
 * @LastEditTime: 2020-08-05 13:53:26
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

template <typename T>
struct SegmentTreeGarph {
  struct TreeNode {
    int l, r;
    int ls, rs;
  } tr[N<<2];
  vector<pair<int, T>> *e;
  int tot, root[2];
  // op [down, 0] [up, 1]
  template <typename E>
  void build(const int &n, E *_e) {
    tot = n;
    e = _e;
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
    e[op ? tr[i].ls : i].emplace_back(op ? i : tr[i].ls, 0);
    e[op ? tr[i].rs : i].emplace_back(op ? i : tr[i].rs, 0);
  }
  void insert(const int &o, const int &l, const int &r, const T &w,
      const int &op) {
    insert(o, l, r, w, op, root[op]);
  }
  void insert(const int &o, const int &l, const int &r, const T &w,
      const int &op, const int &i) {
    if (tr[i].l >= l && tr[i].r <= r) {
      e[op ? i : o].emplace_back(op ? o : i, w);
      return;
    }
    int mid = (tr[i].l+tr[i].r)>>1;
    if (l <= mid) insert(o, l, r, w, op, tr[i].ls);
    if (r >  mid) insert(o, l, r, w, op, tr[i].rs);
  }
};

int n, q, s;
long long dis[N<<2];
vector<pair<int, long long>> e[N<<2];
SegmentTreeGarph<long long> stg;

void dijkstra(const int &s) {
  priority_queue<pair<long long, int>> q;
  memset(dis+1, -1, sizeof(long long)*stg.tot);
  dis[s] = 0;
  q.push({0, s});
  while (q.size()) {
    int u = q.top().second;
    long long ud = -q.top().first;
    q.pop();
    if (ud > dis[u]) continue;
    for (const auto &p : e[u]) {
      int v = p.first;
      long long w = p.second;
      if (dis[v] == -1 || ud+w < dis[v]) {
        dis[v] = ud+w;
        q.push({-dis[v], v});
      }
    }
  }
}

inline void solve() {
  cin >> n >> q >> s;
  stg.build(n, e);
  for (int i = 1, op, v, u, w, l, r; i <= q; ++i) {
    cin >> op;
    if (op == 1) {
      cin >> v >> u >> w;
      e[v].emplace_back(u, w);
    } else {
      cin >> v >> l >> r >> w;
      stg.insert(v, l, r, w, op-2);
    }
  }
  dijkstra(s);
  for (int i = 1; i <= n; ++i) {
    cout << dis[i] << " \n"[i==n];
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