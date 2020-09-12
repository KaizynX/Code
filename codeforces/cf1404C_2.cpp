/*
 * @Author: Kaizyn
 * @Date: 2020-09-06 23:10:58
 * @LastEditTime: 2020-09-07 00:51:44
 */
#include <bits/stdc++.h>

#define DEBUG

using namespace std;

const double eps = 1e-7;
const double PI = acos(-1);
typedef pair<int, int> pii;
const int MOD = 998244353;
const int INF = 0x3f3f3f3f;
const int N = 3e5+7;

struct SegmentTree {
  struct TreeNode {
    int l, r;
    int minv, lazy, pos, zero;
  } tr[N<<2];
  void build(int l, int r, int i = 1) {
    tr[i].l = l; tr[i].r = r;
    tr[i].lazy = 0;
    tr[i].zero = 0;
    tr[i].minv = INF;
    tr[i].pos = r;
    if (l == r) return;
    int m = (l+r)>>1;
    build(l, m, i<<1);
    build(m+1, r, i<<1|1);
    push_up(i);
  }
  void push_up(int i) {
    if (tr[i<<1|1].minv <= tr[i<<1].minv) {
      tr[i].minv = tr[i<<1|1].minv;
      tr[i].pos = tr[i<<1|1].pos;
    } else {
      tr[i].minv = tr[i<<1].minv;
      tr[i].pos = tr[i<<1].pos;
    }
    tr[i].zero = max(tr[i<<1].zero, tr[i<<1|1].zero);
  }
  void push_down(int i) {
    if (!tr[i].lazy) return;
    int &z = tr[i].lazy;
    tr[i<<1].lazy += z;
    tr[i<<1|1].lazy += z;
    tr[i<<1].minv += z;
    tr[i<<1|1].minv += z;
    if (tr[i<<1].minv == 0) tr[i<<1].zero = tr[i<<1].pos;
    if (tr[i<<1|1].minv == 0) tr[i<<1|1].zero = tr[i<<1|1].pos;
    z = 0;
  }
  void add(int l, int r, int k, int i = 1) {
    if (tr[i].l >= l && tr[i].r <= r) {
      tr[i].minv += k;
      tr[i].lazy += k;
      if (tr[i].minv == 0) tr[i].zero = tr[i].pos;
      return;
    }
    push_down(i);
    int m = (tr[i].l+tr[i].r)>>1;
    if (l <= m) add(l, r, k, i<<1);
    if (r >  m) add(l, r, k, i<<1|1);
    push_up(i);
  }
  void modify(int x, int k = INF, int i = 1) {
    if (tr[i].l == tr[i].r) {
      tr[i].minv = k;
      if (!k) tr[i].zero = x;
      else tr[i].zero = 0;
      return;
    }
    push_down(i);
    int m = (tr[i].l+tr[i].r)>>1;
    if (x <= m) modify(x, k, i<<1);
    else modify(x, k, i<<1|1);
    push_up(i);
  }
};

template <typename T>
struct PersistantSegmentTree {
  static const int NN = N*(log2(N)+5);
  int rt[N], sum[NN], ls[NN], rs[NN], tot, n;
  void build(const int &n) {
    this->n = n;
    tot = 0;
    rt[0] = _build(1, n);
  }
  void update(const int &cur, const int &pre, const T &k) {
    rt[cur] = _update(rt[pre], 1, n, k);
  }
  T query(const int &l, const int &r, const int &k) {
    return _query(rt[l-1], rt[r], 1, n, k);
  }
private:
  int _build(const int &l, const int &r) {
    int cur = ++tot;
    sum[cur] = 0;
    if (l >= r) return cur;
    int mid = (l+r)>>1;
    ls[cur] = _build(l, mid);
    rs[cur] = _build(mid+1, r);
    return cur;
  }
  int _update(const int &pre, const int &l, const int &r, const int &k) {
    int cur = ++tot;
    ls[cur] = ls[pre]; rs[cur] = rs[pre]; sum[cur] = sum[pre]+1;
    if (l >= r) return cur;
    int mid = (l+r)>>1;
    if (k <= mid) ls[cur] = _update(ls[pre], l, mid, k);
    else rs[cur] = _update(rs[pre], mid+1, r, k);
    return cur;
  }
  // return >= k
  int _query(const int &u, const int &v, const int &l, const int &r, const int &k) {
    if (l == r) return sum[v]-sum[u];
    int mid = (l+r)>>1;
    if (k <= mid) return sum[rs[v]]-sum[rs[u]]+_query(ls[u], ls[v], l, mid, k);
    else return _query(rs[u], rs[v], mid+1, r, k);
  }
};

int n, q;
int a[N], b[N], c[N];
SegmentTree tree;
PersistantSegmentTree<int> pst;

inline void solve() {
  cin >> n >> q;
  for (int i = 1; i <= n; ++i) {
    cin >> a[i];
    b[i] = i-a[i];
  }
  #ifdef DEBUG
  for (int i = 1; i <= n; ++i) cout << b[i] << " \n"[i==n];
  cout.flush();
  #endif
  tree.build(1, n);
  for (int i = n, x; i; --i) {
    if (b[i] < 0) continue;
    tree.modify(i, b[i]);
    while ((x = tree.tr[1].zero)) {
      c[x] = i;
      tree.modify(x, INF);
      tree.add(x, n, -1);
    }
  }
  #ifdef DEBUG
  for (int i = 1; i <= n; ++i) cout << c[i] << " \n"[i==n];
  cout.flush();
  #endif
  pst.build(n);
  for (int i = 1; i <= n; ++i) {
    if (!c[i]) pst.rt[i] = pst.rt[i-1];
    else pst.update(i, i-1, c[i]);
  }
  for (int i = 1, x, y; i <= q; ++i) {
    cin >> x >> y;
    ++x;
    y = n-y;
    if (x > y) cout << 0 << endl;
    else cout << pst.query(x, y, x) << endl;
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