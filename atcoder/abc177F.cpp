/*
 * @Author: Kaizyn
 * @Date: 2020-08-29 19:57:44
 * @LastEditTime: 2020-08-29 21:35:02
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

struct SegmentTree {
  struct TreeNode {
    int l, r, v, lazy;
  } tr[N<<2];
  int n;
  void push_up(int i) {
    tr[i].v = min(tr[i<<1].v, tr[i<<1|1].v);
  }
  void push_down(int i) {
    if (tr[i].lazy == -INF) return;
    tr[i<<1].lazy = tr[i<<1|1].lazy = tr[i].lazy;
    tr[i<<1].v = tr[i<<1].l+tr[i].lazy;
    tr[i<<1|1].v = tr[i<<1|1].l+tr[i].lazy;
    tr[i].lazy = -INF;
  }
  void build(int n) {
    this->n = n;
    build(1, n, 1);
  }
  void build(int l, int r, int i = 1) {
    tr[i].l = l; tr[i].r = r; tr[i].lazy = -INF;
    if (l == r) return;
    int mid = (l+r)>>1;
    build(l, mid, i<<1);
    build(mid+1, r, i<<1|1);
  }
  void update(int l, int r, int k, int i = 1) {
    if (l <= tr[i].l && r >= tr[i].r) {
      tr[i].lazy = k;
      tr[i].v = tr[i].l+k;
      return;
    }
    push_down(i);
    int mid = (tr[i].l+tr[i].r)>>1;
    if (l <= mid) update(l, r, k, i<<1);
    if (r >  mid) update(l, r, k, i<<1|1);
    push_up(i);
  }
  int query(int l, int r, int i = 1) {
    if (l <= tr[i].l && r >= tr[i].r) return tr[i].v;
    push_down(i);
    int mid = (tr[i].l+tr[i].r)>>1;
    if (r <= mid) return query(l, r, i<<1);
    if (l >  mid) return query(l, r, i<<1|1);
    return min(query(l, r, i<<1), query(l, r, i<<1|1));
  }
};

int n, m;
SegmentTree seg;

signed main() {
  ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
  cin >> n >> m;
  seg.build(m);
  for (int i = 1, l, r; i <= n; ++i) {
    cin >> l >> r;
    int t = l > 1 ? seg.query(1, l-1) : INF;
    seg.update(l, r, t-l+1);
    int res = seg.query(1, n)+i;
    cout << (res >= INF ? -1 : res) << endl;
  }
  return 0;
}