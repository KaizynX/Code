/*
 * @Author: Kaizyn
 * @Date: 2021-02-07 14:25:14
 * @LastEditTime: 2021-02-07 14:30:50
 */
#include <bits/stdc++.h>

// #define DEBUG

using namespace std;

const double eps = 1e-7;
const double PI = acos(-1);
typedef pair<int, int> pii;
typedef long long ll;
const int MOD = 998244353;
const int INF = 0x3f3f3f3f;
// const ll INF = 1e18;
const int N = 2e5+7;

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

int n, q;
int a[N], l[N], r[N];
string s, f;
SegmentTree<int> tree;

inline bool solve() {
  cin >> n >> q >> s >> f;
  for (int i = 1; i <= n; ++i) a[i] = f[i-1]-'0';
  for (int i = 1; i <= q; ++i) cin >> l[i] >> r[i];
  tree.build(a, n);
  for (int i = q; i; --i) {
    int len = r[i]-l[i]+1, cnt = tree.query(l[i], r[i]);
    if (cnt < (len+1)/2) tree.update(l[i], r[i], 0);
    else if (len-cnt < (len+1)/2) tree.update(l[i], r[i], 1);
    else return false;
  }
  for (int i = 1; i <= n; ++i) {
    if (tree.query(i) != s[i-1]-'0') return false;
  }
  return true;
}

signed main() {
#ifdef ONLINE_JUDGE
  ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
#endif
  int T = 1;
  cin >> T;
  for (int t = 1; t <= T; ++t) {
    cout << (solve() ? "YES" : "NO") << '\n';
  }
  return 0;
}