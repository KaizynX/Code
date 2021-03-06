/*
 * @Author: Kaizyn
 * @Date: 2020-11-27 08:43:01
 * @LastEditTime: 2020-11-30 16:37:58
 */
#include <bits/stdc++.h>

// #define DEBUG
// #define int long long

using namespace std;

const double eps = 1e-7;
const double PI = acos(-1);
typedef pair<int, int> pii;
const int MOD = 998244353;
const int INF = 0x3f3f3f3f;
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
  int first_less_or_equal(int k) {
    if (k < tr[1].rv) return n+1;
    int i = 1;
    while (tr[i].l != tr[i].r) {
      push_down(i);
      if (tr[i<<1].rv <= k) i = i<<1;
      else i = i<<1|1;
    }
    return tr[i].l;
  }
  int minus_sum(int &x, int &y) {
    int i = 1, cnt = 1;
    while (tr[i].l != tr[i].r) {
      push_down(i);
      int m = (tr[i].l+tr[i].r)>>1;
      if (x <= m) i = i<<1;
      else i = i<<1|1;
    }
    assert(tr[i].l == x);
    y -= tr[i].lv;
    while (i > 1) {
      if (i%2 == 0) { // && i < id[n]
        if (y >= tr[i|1].sum) {
          y -= tr[i|1].sum;
          cnt += tr[i|1].len();
        } else {
          break;
        }
      }
      i >>= 1;
    }
    if (i == 1) return x = n+1, cnt;
    i = i|1;
    while (tr[i].l != tr[i].r) {
      if (y >= tr[i<<1].sum) {
        y -= tr[i<<1].sum;
        cnt += tr[i<<1].len();
        i = i<<1|1;
      } else {
        i = i<<1;
      }
    }
    return x = tr[i].l, cnt;
  }
} tree;

inline void solve() {
  cin >> n >> q;
  for (int i = 1; i <= n; ++i) cin >> a[i];
  tree.build();
  for (int _ = q, t, x, y; _; --_) {
    cin >> t >> x >> y;
    if (t == 1) {
      tree.update(tree.first_less_or_equal(y), x, y);
    } else {
      int res = 0;
      while ((x = max(x, tree.first_less_or_equal(y))) <= n) {
        res += tree.minus_sum(x, y);
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