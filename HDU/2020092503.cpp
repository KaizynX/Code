/*
 * @Author: Kaizyn
 * @Date: 2020-09-25 17:55:22
 * @LastEditTime: 2020-09-25 19:50:34
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
const int M = 1e7+7;

template <typename T>
struct SegmentTree {
  int sz;
  int tag[N<<2];
  T tr[N<<2], lazy[N<<2];
  SegmentTree(){}
  void build(const int &n, const T &k = 0) { sz = n; _build(1, n, k); }
  template <typename TT>
  void build(const TT a[], const int &n) { sz = n; _build(a, 1, n); }
  void update(const int &x, const T &k) { _update(x, x, k, 1, sz); }
  void update(int l, int r, const T &k) { if (l > r) swap(l, r); _update(l, r, k, 1, sz); }
  T query(const int &x) { return _query(x, x, 1, sz); }
  T query(int l, int r) { if (l > r) swap(l, r); return _query(l, r, 1, sz); }
private :
  void push_up(const int &i) { tr[i] = tr[i<<1]+tr[i<<1|1]; }
  void push_down(const int &i, const int &len) {
    if (!tag[i]) return;
    tr[i<<1] = lazy[i]*(len-len/2);
    tr[i<<1|1] = lazy[i]*(len/2);
    lazy[i<<1] = lazy[i<<1|1] = lazy[i];
    tag[i<<1] = tag[i<<1|1] = 1;
    tag[i] = 0;
  }
  void _build(const int &l, const int &r, const T &k = 0, const int &i = 1) {
    lazy[i] = tag[i] = 0;
    if (l == r) { tr[i] = k; return; }
    int mid = (l+r)>>1;
    _build(l, mid, k, i<<1);
    _build(mid+1, r, k, i<<1|1);
    push_up(i);
  }
  template <typename TT>
  void _build(const TT a[], const int &l, const int &r, const int &i = 1) {
    lazy[i] = tag[i] = 0;
    if (l == r) { tr[i] = a[l]; return; }
    int mid = (l+r)>>1;
    _build(a, l, mid, i<<1);
    _build(a, mid+1, r, i<<1|1);
    push_up(i);
  }
  void _update(const int &l, const int &r, const T &k, const int &trl, const int &trr, const int &i = 1) {
    if (trl >= l && trr <= r) {
      tr[i] = k*(trr-trl+1);
      lazy[i] = k;
      tag[i] = 1;
      return;
    }
    push_down(i, trr-trl+1);
    int mid = (trl+trr)>>1;
    if (l <= mid) _update(l, r, k, trl, mid, i<<1);
    if (r >  mid) _update(l, r, k, mid+1, trr, i<<1|1);
    push_up(i);
  }
  T _query(const int &l, const int &r, const int &trl, const int &trr, const int &i = 1) {
    if (trl >= l && trr <= r) return tr[i];
    push_down(i, trr-trl+1);
    int mid = (trl+trr)>>1;
    T res = 0;
    if (l <= mid) res += _query(l, r, trl, mid, i<<1);
    if (r >  mid) res += _query(l, r, mid+1, trr, i<<1|1);
    return res;
  }
};

int n, d;
int a[N], last[M];

template <typename U = greater<int>>
struct Solver {
  U cmp = U();
  int h, t, st;
  pii q[N];
  long long sum;
  SegmentTree<long long> seg;
  void init(int st) {
    this->st = st;
    h = st; t = st-1;
    sum = 0;
  }
  void insert(int x, int p) {
    if (h > t) {
      q[++t] = {x, p};
      seg.update(p, x);
      return;
    }
    if (x < q[h].first) {
      int l = h, r = t; 
      while (l < r) {
        int m = (l+r+1)>>1;
        if (q[m].first == x || U(x, q[m].first)) l = m;
        else r = m-1;
      }
      int idx = q[l].second;
      sum += (idx-st+1)*x-seg.query(st, idx);
    }
    x = max(x, q[t].first);
    if (x == q[t].first) q[t].second = p;
    else q[++t] = {x, p};
    seg.update(p, x);
  }
};
Solver<greater<int>> max_solver;
Solver<less<int>> min_solver;

inline void solve() {
  scanf("%d %d", &n, &d);
  for (int i = 1; i <= n; ++i) scanf("%d", a+i);
  max_solver.seg.build(n);
  min_solver.seg.build(n);
  for (int st = 1, i; st < n; st = i) {
    for (i = st; i < n && a[i]%d == a[st]%d; ++i) {
      ;
    }
  }
}

signed main() {
  // ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
  int T = 1;
  // cin >> T;
  for (int t = 1; t <= T; ++t) {
    solve();
  }
  return 0;
}