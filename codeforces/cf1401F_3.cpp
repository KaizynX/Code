/*
 * @Author: Kaizyn
 * @Date: 2020-08-28 15:40:15
 * @LastEditTime: 2020-08-29 14:21:39
 */
#include <bits/stdc++.h>

// #define DEBUG

using namespace std;

const double eps = 1e-7;
const double PI = acos(-1);
typedef pair<int, int> pii;
const int MOD = 998244353;
const int INF = 0x3f3f3f3f;
const int N = (1<<18)+7;

int n, q, bit;
int a[N];

struct SegmentTree {
  struct TreeNode {
    int l, r;
    long long v;
  } tr[N<<2];
  void push_up(const int &i) {
    tr[i].v = tr[i<<1].v+tr[i<<1|1].v;
  }
  void build(int l, int r, int i = 1) {
    tr[i].l = l; tr[i].r = r;
    if (l == r) return tr[i].v = a[l], void();
    int mid = (l+r)>>1;
    build(l, mid, i<<1);
    build(mid+1, r, i<<1|1);
    push_up(i);
  }
  void update(int x, int k, int i = 1) {
    if (tr[i].l == tr[i].r) return tr[i].v = k, void();
    int mid = (tr[i].l+tr[i].r)>>1;
    if (x <= mid) update(x, k, i<<1);
    else update(x, k, i<<1|1);
    push_up(i);
  }
  long long query(int l, int r, int d, int i = 1) {
    if (tr[i].l >= l && tr[i].r <= r) return tr[i].v;
    int mid = (tr[i].l+tr[i].r)>>1;
    long long res = 0;
    if ((1<<d)&bit) {
      if (l <= mid) res += query(l^(1<<d), min(mid, r)^(1<<d), d-1, i<<1|1);
      if (r >  mid) res += query(max(l, mid+1)^(1<<d), r^(1<<d), d-1, i<<1);
    } else {
      if (l <= mid) res += query(l, min(mid, r), d-1, i<<1);
      if (r >  mid) res += query(max(l, mid+1), r, d-1, i<<1|1);
    }
    return res;
  }
} seg;

signed main() {
  ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
  cin >> n >> q;
  int d = n;
  n = 1<<n;
  for (int i = 0; i < n; ++i) cin >> a[i];
  seg.build(0, n-1);
  for (int i = 1, op, x, k, l, r; i <= q; ++i) {
    cin >> op;
    if (op == 1) {
      cin >> x >> k;
      seg.update((x-1)^bit, k);
    } else if (op == 2) {
      cin >> k;
      bit ^= (1<<k)-1;
    } else if (op == 3) {
      cin >> k;
      bit ^= 1<<k;
    } else if (op == 4) {
      cin >> l >> r;
      cout << seg.query(l-1, r-1, d-1) << endl;
    }
  }
  return 0;
}