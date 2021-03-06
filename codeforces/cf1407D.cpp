/*
 * @Author: Kaizyn
 * @Date: 2020-09-08 22:34:08
 * @LastEditTime: 2020-09-08 23:32:05
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

template <typename T, typename U = greater<T>>
struct SegmentTree {
  U cmp = U();
  int n;
  T tr[N<<2], lazy[N<<2], init_val = cmp(0, 1) ? INF : -INF;
  SegmentTree(){}
  T mv(const T &x, const T &y) { return cmp(x, y) ? x : y;}
  void build(const int &_n, const T &k = 0) { n = _n; _build(1, n, k); }
  template <typename TT>
  void build(const TT a[], const int &_n) { n = _n; _build(a, 1, n); }
  void modify(const int &x, const T &k) { _modify(x, k, 1, n); }
  void add(const int &x, const T &k) { _add(x, x, k, 1, n); }
  void add(const int &l, const int &r, const T &k) { _add(l, r, k, 1, n); }
  T query(const int &x) { return _query(x, x, 1, n); }
  T query(const int &l, const int &r) { return _query(l, r, 1, n); }
private :
  void push_up(const int &i) { tr[i] = mv(tr[i<<1], tr[i<<1|1]); }
  void push_down(const int &i) {
    if (!lazy[i]) return;
    tr[i<<1] += lazy[i];
    tr[i<<1|1] += lazy[i];
    lazy[i<<1] += lazy[i];
    lazy[i<<1|1] += lazy[i];
    lazy[i] = 0;
  }
  void _build(const int &l, const int &r, const T &k = 0, const int &i = 1) {
    lazy[i] = 0;
    if (l == r) { tr[i] = k; return; }
    int mid = (l+r)>>1;
    _build(l, mid, k, i<<1);
    _build(mid+1, r, k, i<<1|1);
    push_up(i);
  }
  template <typename TT>
  void _build(const TT a[], const int &l, const int &r, const int &i = 1) {
    lazy[i] = 0;
    if (l == r) { tr[i] = a[l]; return; }
    int mid = (l+r)>>1;
    _build(a, l, mid, i<<1);
    _build(a, mid+1, r, i<<1|1);
    push_up(i);
  }
  void _modify(const int &x, const T &k, const int &trl, const int &trr, const int &i = 1) {
    if (trl == x && trr == x) return tr[i] = k, void();
    push_down(i);
    int mid = (trl+trr)>>1;
    if (x <= mid) _modify(x, k, trl, mid, i<<1);
    else _modify(x, k, mid+1, trr, i<<1|1);
    push_up(i);
  }
  void _add(const int &l, const int &r, const T &k, const int &trl, const int &trr, const int &i = 1) {
    if (trl >= l && trr <= r) {
      tr[i] += k;
      lazy[i] += k;
      return;
    }
    push_down(i);
    int mid = (trl+trr)>>1;
    if (l <= mid) _add(l, r, k, trl, mid, i<<1);
    if (r >  mid) _add(l, r, k, mid+1, trr, i<<1|1);
    push_up(i);
  }
  T _query(const int &l, const int &r, const int &trl, const int &trr, const int &i = 1) {
    if (trl >= l && trr <= r) return tr[i];
    push_down(i);
    int mid = (trl+trr)>>1;
    if (r <=  mid) return _query(l, r, trl, mid, i<<1);
    if (l >  mid) return _query(l, r, mid+1, trr, i<<1|1);
    return mv(_query(l, r, trl, mid, i<<1), _query(l, r, mid+1, trr, i<<1|1));
  }
};

int n;
int a[N], dp[N];
int qn[N], qx[N], tn, tx;
SegmentTree<int, less<int>> segn, segx;

signed main() {
  ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
  cin >> n;
  for (int i = 1; i <= n; ++i) cin >> a[i];

  segn.build(n);
  segx.build(n);
  dp[1] = 0;
  qn[++tn] = 1; segn.modify(1, dp[1]);
  qx[++tx] = 1; segx.modify(1, dp[1]);
  for (int i = 2, l, r, m; i <= n; ++i) {
    dp[i] = dp[i-1]+1;
    // max(hi, hj) < min(...)
    l = 1; r = tn;
    while (l < r) {
      m = (l+r+1)>>1;
      if (a[qn[m]] <= a[i]) l = m;
      else r = m-1;
    }
    dp[i] = min(dp[i], segn.query(l, tn)+1);
    while (tn && a[qn[tn]] >= a[i]) --tn;
    qn[++tn] = i;
    segn.modify(tn, dp[i]);
    // min(hi, hj) > max(...)
    l = 1; r = tx;
    while (l < r) {
      m = (l+r+1)>>1;
      if (a[qx[m]] >= a[i]) l = m;
      else r = m-1;
    }
    dp[i] = min(dp[i], segx.query(l, tx)+1);
    while (tx && a[qx[tx]] <= a[i]) --tx;
    qx[++tx] = i;
    segx.modify(tx, dp[i]);
    #ifdef DEBUG
    cout << "qn:"; for (int i = 1; i <= tn; ++i) cout << qn[i] << " \n"[i==tn];
    cout << "qx:"; for (int i = 1; i <= tx; ++i) cout << qx[i] << " \n"[i==tx];
    cout << "dp[" << i << "]=" << dp[i] << endl;
    #endif
  }
  cout << dp[n] << endl;
  return 0;
}