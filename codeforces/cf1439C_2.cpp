/*
 * @Author: Kaizyn
 * @Date: 2020-11-30 19:08:50
 * @LastEditTime: 2020-11-30 19:30:51
 */
#include <bits/stdc++.h>
// #define DEBUG
using namespace std;
const int N = 2e5+7;

int n, q;
int a[N];

struct SegmentTree {
  struct TreeNode {
    int l, r, lv, rv, lazy;
    long long sum;
    int len() const { return r-l+1; }
  } tr[N<<2];
  void push_up(int i) {
    tr[i].lv = tr[i<<1].lv;
    tr[i].rv = tr[i<<1|1].rv;
    tr[i].sum = tr[i<<1].sum+tr[i<<1|1].sum;
  }
  void push_down(int i) {
    int &z = tr[i].lazy;
    if (!z) return;
    tr[i<<1].lazy = tr[i<<1|1].lazy = z;
    tr[i<<1].lv = tr[i<<1|1].lv = z;
    tr[i<<1].rv = tr[i<<1|1].rv = z;
    tr[i<<1].sum = 1ll*z*tr[i<<1].len();
    tr[i<<1|1].sum = 1ll*z*tr[i<<1|1].len();
    z = 0;
  }
  void build(int l = 1, int r = n, int i = 1) {
    tr[i].l = l; tr[i].r = r; tr[i].lazy = 0;
    if (l == r) {
      tr[i].sum = tr[i].lv = tr[i].rv = a[l];
      return;
    }
    int m = (l+r)>>1;
    build(l, m, i<<1);
    build(m+1, r, i<<1|1);
    push_up(i);
  }
  void update(int l, int r, int k, int i = 1) {
    if (l > r) return;
    if (tr[i].l >= l && tr[i].r <= r) {
      tr[i].lv = tr[i].rv = tr[i].lazy = k;
      tr[i].sum = 1ll*k*tr[i].len();
      return;
    }
    push_down(i);
    int m = (tr[i].l+tr[i].r)>>1;
    if (l <= m) update(l, r, k, i<<1);
    if (r >  m) update(l, r, k, i<<1|1);
    push_up(i);
  }
  long long sum(int l, int r, int i = 1) {
    if (l > r) return 0;
    if (tr[i].l >= l && tr[i].r <= r) return tr[i].sum;
    push_down(i);
    int m = (tr[i].l+tr[i].r)>>1;
    if (r <= m) return sum(l, r, i<<1);
    if (l >  m) return sum(l, r, i<<1|1);
    return sum(l, r, i<<1)+sum(l, r, i<<1|1);
  }
  int BS1(int y) {
    if (y < tr[1].rv) return n+1;
    int i = 1;
    while (tr[i].l != tr[i].r) {
      push_down(i);
      if (tr[i<<1].rv <= y) i = i<<1;
      else i = i<<1|1;
    }
    return tr[i].l;
  }
  int BS2(long long y) {
    int i = 1;
    while (tr[i].l != tr[i].r) {
      push_down(i);
      if (y >= tr[i<<1].sum) {
        y -= tr[i<<1].sum;
        i = i<<1|1;
      } else {
        i = i<<1;
      }
    }
    return tr[i].l-(y < tr[i].sum);
  }
} tree;

inline void solve() {
  cin >> n >> q;
  for (int i = 1; i <= n; ++i) cin >> a[i];
  tree.build();
  for (int _ = q, t, x, y; _; --_) {
    cin >> t >> x >> y;
    if (t == 1) {
      tree.update(tree.BS1(y), x, y);
    } else {
      int res = 0;
      while ((x = max(x, tree.BS1(y))) <= n) {
        int xx = tree.BS2(y+tree.sum(1, x-1));
        y -= tree.sum(x, xx);
        res += xx-x+1;
        x = xx+1;
      }
      cout << res << endl;
    }
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