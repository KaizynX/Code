/*
 * @Author: Kaizyn
 * @Date: 2020-09-06 23:10:58
 * @LastEditTime: 2020-09-06 23:52:31
 */
#include <bits/stdc++.h>

// #define DEBUG

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
    int minv, zero, lazy;
  } tr[N<<2];
  int a[N];
  void build(int l, int r, int i = 1) {
    tr[i].l = l; tr[i].r = r;
    tr[i].lazy = 0; tr[i].zero = 0; tr[i].minv = r;
    if (l == r) return a[l] = INF, void();
    int m = l+r>>1;
    build(l, m, i<<1);
    build(m+1, r, i<<1|1);
  }
  void push_up(int i) {
    tr[i].minv = a[tr[i<<1|1].minv] <= a[tr[i<<1].minv] ? tr[i<<1|1].minv : tr[i<<1].minv;
    tr[i].zero = max(tr[i<<1|1].zero, tr[i<<1].zero);
  }
  void push_down(int i) {
    if (!tr[i].lazy) return;
    int &z = tr[i].lazy;
    tr[i<<1].lazy += z;
    tr[i<<1|1].lazy += z;
    if (a[tr[i<<1].minv] <= tr[i<<1].lazy) tr[i<<1].zero = max(tr[i<<1].zero, tr[i<<1].minv);
    if (a[tr[i<<1|1].minv] <= tr[i<<1|1].lazy) tr[i<<1|1].zero = max(tr[i<<1|1].zero, tr[i<<1|1].minv);
    z = 0;
  }
  void add(int l, int r, int k, int i = 1) {
    if (tr[i].l >= l && tr[i].r <= r) {
      // tr[i].minv += k;
      tr[i].lazy += k;
      return;
    }
    push_down(i);
    int m = tr[i].l+tr[i].r>>1;
    if (l <= m) add(l, r, i<<1);
    if (r >  m) add(l, r, i<<1|1);
    push_up(i);
  }
  void modify(int x, int k = INF, int i = 1) {
    if (tr[i].l == tr[i].r) {
      a[x] = k;
      if (!k) tr[i].zero = i;
      return;
    }
    push_down(i);
    int m = tr[i].l+tr[i].r>>1;
    if (x <= m) modify(x, k, i<<1);
    else modify(x, k, i<<1|1);
    push_up(i);
  }
};

int n, q;
int a[N], b[N], c[N];
SegmentTree tree;

inline void solve() {
  cin >> n >> q;
  for (int i = 1; i <= n; ++i) {
    cin >> a[i];
    b[i] = i-a[i];
  }
  tree.build(1, n);
  for (int i = n, x; i; --i) {
    if (b[i] < 0) continue;
    tree.modify(i, b[i]);
    while ((x = tree.tr[0].zero)) {
      c[x] = i;
      tree.add(x, n, -1);
    }
  }
  for (int i = 1, x, y; i <= q; ++i) {
    cin >> x >> y;
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