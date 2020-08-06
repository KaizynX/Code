/*
 * @Author: Kaizyn
 * @Date: 2020-07-20 11:56:57
 * @LastEditTime: 2020-07-20 23:40:27
 */ 
#include <bits/stdc++.h>

// #define DEBUG

using namespace std;

const double eps = 1e-7;
const double PI = acos(-1);
typedef pair<int, int> pii;
const int MOD = 998244353;
const int INF = 0x3f3f3f3f;
const int N = 2e5+7;
const int NN = log2(N)+3;

int n, D;
int dep[N], fa[N][NN], lg2[N];
int st[N], ed[N], dfn, id[N];
vector<int> e[N];

struct SegmentTree {
  struct TreeNode {
    int l, r;
    int v, mv, pt;
  } tr[N<<4];
  int n;
  void build(const int &_n) { _build(1, n = _n); }
  int next() { return tr[1].pt; }
  void push_up(const int &i) {
    tr[i].pt = dep[tr[i<<1].pt] > dep[tr[i<<1|1].pt] ? tr[i<<1].pt : tr[i<<1|1].pt;
  }
  void push_down(const int &i) {
    if (tr[i].v == -1) return;
    tr[i<<1].v = tr[i<<1|1].v = tr[i].v;
    if (tr[i].v) tr[i<<1].pt = tr[i<<1|1].pt = 0;
    else tr[i<<1].pt = tr[i<<1].mv, tr[i<<1|1].pt = tr[i<<1|1].mv;
    tr[i].v = -1;
  }
  void _build(const int &l, const int &r, const int &i = 1) {
    tr[i].l = l; tr[i].r = r; tr[i].v = -1;
    if (l == r) {
      tr[i].v = 0;
      tr[i].pt = tr[i].mv = id[l];
      return;
    }
    int mid = (l+r)>>1;
    _build(l, mid, i<<1);
    _build(mid+1, r, i<<1|1);
    tr[i].mv = dep[tr[i<<1].mv] > dep[tr[i<<1|1].mv] ? tr[i<<1].mv : tr[i<<1|1].mv;
    push_up(i);
  }
  void update(const int &l, const int &r, const int &k, const int &i = 1) {
    if (tr[i].l >= l && tr[i].r <= r) {
      tr[i].v = k;
      if (k) tr[i].pt = 0;
      else tr[i].pt = tr[i].mv;
      return;
    }
    push_down(i);
    int mid = (tr[i].l+tr[i].r)>>1;
    if (l <= mid) update(l, r, k, i<<1);
    if (r >  mid) update(l, r, k, i<<1|1);
    push_up(i);
  }
} ST;

inline int getf(int u, int len) {
  if (len > dep[u]) return 1;
  for (int i = lg2[len]; i >= 0; --i) {
    if (1<<i <= len) u = fa[u][i], len -= 1<<i;
  }
  return u;
}

inline void init(const int &u = 1) {
  D = max(D, dep[u]);
  st[u] = ++dfn;
  id[dfn] = u;
  for (int i = 1; 1<<i <= dep[u]; ++i) {
    fa[u][i] = fa[fa[u][i-1]][i-1];
  }
  for (const int &v : e[u]) {
    dep[v] = dep[u]+1;
    init(v);
  }
  ed[u] = dfn;
}

inline void solve() {
  for (int i = 2; i <= n; ++i) {
    cin >> fa[i][0];
    e[fa[i][0]].emplace_back(i);
  }
  D = dfn = 0;
  dep[0] = -1;
  dep[1] = 0;
  init();
  ST.build(n);
  long long res = 0;
  for (int d = 1, u, k = n, nk; d <= D; ++d) {
    nk = 0;
    while ((u = ST.next())) {
      ++nk;
      u = getf(u, d);
      ST.update(st[u], ed[u], 1);
    }
    res += 1ll*(k-nk)*d;
    k = nk;
    ST.update(1, n, 0); // clear the tree
  }
  cout << res << endl;
  // clear
  for (int i = 1; i <= n; ++i) {
    vector<int>().swap(e[i]);
  }
}

signed main() {
  ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
  for (int i = 2; i < N; ++i) lg2[i] = lg2[i>>1]+1;
  while (cin >> n) solve();
  return 0;
}