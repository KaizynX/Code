/*
 * @Author: Kaizyn
 * @Date: 2020-10-26 19:43:43
 * @LastEditTime: 2020-10-26 22:33:29
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

template <typename T, typename U = greater<T>>
struct SegmentTree {
  SegmentTree(){}
  void build(const int &_n) { n = _n; _build(1, n); }
  void modify(const int &x, const T &k) { _modify(x, x, k); }
  void modify(const int &l, const int &r, const T &k) { _modify(l, r, k); }
  void add(const int &x, const T &k) { _add(x, k); }
  T query(const int &x) { return _query(x, x); }
  T query(const int &l, const int &r) { return _query(l, r); }
private:
  struct TreeNode
  {
    int l, r;
    T v, lazy;
  } tr[N<<2];
  int n;
  T init_val = cmp(0, 1) ? INF : -INF;
  U cmp = U();
  T mv(const T &x, const T &y) { return cmp(x, y) ? x : y;}
  void update(const int &i, const T &k) { tr[i].v = mv(tr[i].v, k); tr[i].lazy = mv(tr[i].lazy, k); }
  void push_up(const int &i) { tr[i].v = mv(tr[i<<1].v, tr[i<<1|1].v); }
  void push_down(const int &i) {
    if (tr[i].lazy == init_val) return;
    update(i<<1, tr[i].lazy);
    update(i<<1|1, tr[i].lazy);
    tr[i].lazy = init_val;
  }
  void _build(const int &l, const int &r, const int &i = 1) {
    tr[i].lazy = init_val;
    tr[i].l = l; tr[i].r = r;
    if (l == r) { tr[i].v = l; return; }
    int mid = (l+r)>>1;
    _build(l, mid, i<<1);
    _build(mid+1, r, i<<1|1);
    push_up(i);
  }
  void _modify(const int &l, const int &r, const T &k, const int &i = 1) {
    if (tr[i].l  >= l && tr[i].r <= r) { update(i, k); return; }
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
};

int n;
int a[N];
vector<int> p[N];
SegmentTree<int, greater<int>> tree; 

inline int solve() {
  cin >> n;
  for (int i = 1; i <= n+1; ++i) p[i].emplace_back(0);
  for (int i = 1; i <= n; ++i) {
    cin >> a[i];
    p[a[i]].emplace_back(i);
  }
  tree.build(n);
  for (int i = 1; i <= n+1; ++i) {
    int flag = 0;
    for (int j = 1; j < (int)p[i].size(); ++j) {
      if (p[i][j-1]+1 != p[i][j])
        // flag |= tree.query(p[i][j-1]+1, p[i][j]-1) <= p[i][j]-1;
        flag |= tree.query(p[i][j-1]+1) <= p[i][j]-1;
      tree.modify(p[i][j-1]+1, p[i][j], p[i][j]);
    }
    if (p[i].back() < n) {
      // flag |= tree.query(p[i].back()+1, n) <= n;
      flag |= tree.query(p[i].back()) <= n;
      tree.modify(p[i].back()+1, n, INF);
    }
    // if (i == 1) flag = (int)p[i].size() != n+1;
    if (!flag) return i;
  }
  return n+2;
}

signed main() {
  ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
  int T = 1;
  // cin >> T;
  for (int t = 1; t <= T; ++t) {
    cout << solve() << endl;
  }
  return 0;
}