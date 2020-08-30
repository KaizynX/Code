/*
 * @Author: Kaizyn
 * @Date: 2020-08-29 19:57:44
 * @LastEditTime: 2020-08-29 21:36:17
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

template <typename T, typename U = greater<T>>
struct SegmentTree {
  SegmentTree(){}
  void build(const int &_n, const T &k = 0) { n = _n; _build(1, n, k); }
  void modify(const int &x, const T &k) { _modify(x, x, k); }
  void modify(const int &l, const int &r, const T &k) { _modify(l, r, k); }
  void add(const int &x, const T &k) { _add(x, k); }
  T query(const int &x) { return _query(x, x); }
  T query(const int &l, const int &r) { return _query(l, r); }
// private:
  struct TreeNode
  {
    int l, r;
    T v, lazy, vv;
  } tr[N<<2];
  int n;
  T init_val = cmp(0, 1) ? INF : -INF;
  U cmp = U();
  T mv(const T &x, const T &y) { return cmp(x, y) ? x : y;}
  void update(const int &i, const T &k) { 
    tr[i].v = mv(tr[i].v, k); tr[i].lazy = mv(tr[i].lazy, k);
  }
  void push_up(const int &i) {
    tr[i].v = mv(tr[i<<1].v, tr[i<<1|1].v);
    tr[i].vv = min(tr[i<<1].vv, tr[i<<1|1].vv);
  }
  void push_down(const int &i) {
    if (tr[i].lazy == init_val) return;
    // update(i<<1, tr[i].lazy);
    // update(i<<1|1, tr[i].lazy);
    tr[i<<1].lazy = tr[i].lazy;
    tr[i<<1|1].lazy = tr[i].lazy;
    tr[i<<1].v = tr[i].lazy;
    tr[i<<1].vv = tr[i<<1].l-tr[i].lazy;
    tr[i<<1|1].vv = tr[i<<1|1].l-tr[i].lazy;
    tr[i].lazy = init_val;
  }
  void _build(const int &l, const int &r, const T &k = 0, const int &i = 1) {
    tr[i].lazy = init_val;
    tr[i].l = l; tr[i].r = r;
    if (l == r) { tr[i].v = l; return; }
    int mid = (l+r)>>1;
    _build(l, mid, k, i<<1);
    _build(mid+1, r, k, i<<1|1);
    push_up(i);
  }
  void _modify(const int &l, const int &r, const T &k, const int &i = 1) {
    if (tr[i].l  >= l && tr[i].r <= r) {
      // update(i, k);
      tr[i].v = k;
      tr[i].lazy = k;
      tr[i].vv = tr[i].l-k;
      return;
    }
    push_down(i);
    int mid = (tr[i].l+tr[i].r)>>1;
    if (l <= mid) _modify(l, r, k, i<<1);
    if (r >  mid) _modify(l, r, k, i<<1|1);
    push_up(i);
  }
  void _add(const int &x, const T &k, const int &i = 1) {
    if (tr[i].l == x && tr[i].r == x) { tr[i].v += k; return; }
    push_down(i);
    int mid = (tr[i].l+tr[i].r)>>1;
    if (x <= mid) _add(x, k, i<<1);
    else _add(x, k, i<<1|1);
    push_up(i);
  }
  T _query(const int &l, const int &r, const int &i = 1) {
    if (tr[i].l  >= l && tr[i].r <= r) return tr[i].v;
    push_down(i);
    int mid = (tr[i].l+tr[i].r)>>1;
    T res = init_val;
    if (l <= mid) res = mv(res, _query(l, r, i<<1));
    if (r >  mid) res = mv(res, _query(l, r, i<<1|1));
    return res;
  }
  T _query2(const int &l, const int &r, const int &i = 1) {
    if (tr[i].l  >= l && tr[i].r <= r) return tr[i].vv;
    push_down(i);
    int mid = (tr[i].l+tr[i].r)>>1;
    if (r <= mid) return _query2(l, r, i<<1);
    if (l >  mid) return _query2(l, r, i<<1|1);
    return min(_query2(l, r, i<<1), _query2(l, r, i<<1|1));
  }
};

int n, m;
SegmentTree<int, greater<int>> seg;

signed main() {
  ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
  cin >> n >> m;
  seg.build(m);
  for (int i = 1, l, r, st = 1; i <= n; ++i) {
    cin >> l >> r;
    if (l <= st) {
      st = max(st, r+1);
    } else {
      int t = seg.query(st, l-1);
      seg.modify(l, r, t);
    }
    int res = st <= n ? seg._query2(st, n)+i : -1;
    cout << res << endl;
  }
  return 0;
}