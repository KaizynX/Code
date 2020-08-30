/*
 * @Author: Kaizyn
 * @Date: 2020-08-28 15:40:15
 * @LastEditTime: 2020-08-28 16:29:50
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

int n, q;
int a[N], rev[20];

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
  void update(int x, int k, int d, int i = 1) {
    if (tr[i].l == tr[i].r) return tr[i].v = k, void();
    if (rev[d]) x = tr[i].r-(x-tr[i].l);
    int mid = (tr[i].l+tr[i].r)>>1;
    if (x <= mid) update(x, k, d-1, i<<1);
    else update(x, k, d-1, i<<1|1);
    push_up(i);
  }
  long long query(int l, int r, int d, int i = 1) {
    if (rev[d]) l = tr[i].r-(l-tr[i].l), r = tr[i].r-(r-tr[i].l);
    if (l > r) swap(l, r);
    if (tr[i].l >= l && tr[i].r <= r) return tr[i].v;
    int mid = (tr[i].l+tr[i].r)>>1;
    long long res = 0;
    if (l <= mid) res += query(l, min(mid, r), d-1, i<<1);
    if (r >  mid) res += query(max(l, mid+1), r, d-1, i<<1|1);
    return res;
  }
} seg;

signed main() {
  ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
  cin >> n >> q;
  int d = n;
  n = 1<<n;
  for (int i = 1; i <= n; ++i) cin >> a[i];
  seg.build(1, n);
  for (int i = 1, op, x, k, l, r, head = 0; i <= q; ++i) {
    cin >> op;
    if (op == 1) {
      cin >> x >> k;
      x += head;
      if (x > n) x -= n;
      seg.update(x, k, d);
    } else if (op == 2) {
      cin >> k;
      rev[k] ^= 1;
    } else if (op == 3) {
      cin >> k;
      head = (head+(1<<k))%n;
    } else if (op == 4) {
      cin >> l >> r;
      l += head;
      r += head;
      if (l > n) l -= n;
      if (r > n) r -= n;
      if (l <= r) cout << seg.query(l, r, d) << endl;
      else cout << seg.query(l, n, d)+seg.query(1, r, d) << endl;
    }
  }
  return 0;
}