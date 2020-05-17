/*
 * @Author: Kaizyn
 * @Date: 2020-05-12 20:33:19
 * @LastEditTime: 2020-05-12 22:56:07
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
struct SegmentTree
{
    U cmp = U();
    int n;
    T tr[N<<2], init_val = cmp(0, 1) ? INF : -INF;
    SegmentTree(){}
    T mv(const T &x, const T &y) { return cmp(x, y) ? x : y;}
    void build(const int &_n, const T &k = 0) { n = _n; _build(1, n, k); }
    void modify(const int &x, const T &k) { _modify(x, k, 1, n); }
    T query(const int &x) { return _query(x, x, 1, n); }
    T query(const int &l, const int &r) { return _query(l, r, 1, n); }
private :
    void push_up(const int &i) { tr[i] = mv(tr[i<<1], tr[i<<1|1]); }
    void _build(const int &l, const int &r, const T &k = 0, const int &i = 1) {
        if (l == r) { tr[i] = k; return; }
        int mid = (l+r)>>1;
        _build(l, mid, k, i<<1);
        _build(mid+1, r, k, i<<1|1);
        push_up(i);
    }
    void _modify(const int &x, const T &k, const int &trl, const int &trr, const int &i = 1) {
        if (trl == x && trr == x) {
            tr[i] = k;
            return;
        }
        int mid = (trl+trr)>>1;
        if (x <= mid) _modify(x, k, trl, mid, i<<1);
        else _modify(x, k, mid+1, trr, i<<1|1);
        push_up(i);
    }
    T _query(const int &l, const int &r, const int &trl, const int &trr, const int &i = 1) {
        if (trl >= l && trr <= r) return tr[i];
        int mid = (trl+trr)>>1;
        T res = init_val;
        if (l <= mid) res = mv(res, _query(l, r, trl, mid, i<<1));
        if (r >  mid) res = mv(res, _query(l, r, mid+1, trr, i<<1|1));
        return res;
    }
};

struct Node {
  int id, l, r;
  friend bool operator < (const Node &lhs, const Node &rhs) {
    return lhs.l == rhs.l ? lhs.r < rhs.r : lhs.l < rhs.l;
  }
};

int n, k;
int a[N], cntl[N], cntr[N], pos[N];
int b_l[N];
Node b[N];
SegmentTree<int> ST[2];

inline void solve() {
  cin >> n >> k;
  for (int i = 1; i <= n; ++i) cin >> a[i];
  if (n == 1) return void(cout << (a[1] == k ? "yes" : "no") << endl);
  for (int i = 1; i <= n; ++i) {
    cntl[i] = cntl[i-1]+(a[i] < k);
    cntr[i] = cntr[i-1]+(a[i] > k);
  }
  #ifdef DEBUG
  for (int i = 1; i <= n; ++i) cout << cntl[i] << " \n"[i==n];
  for (int i = 1; i <= n; ++i) cout << cntr[i] << " \n"[i==n];
  #endif
  for (int i = 0; i <= n; ++i) b[i+1] = {i, 2*cntl[i]-i, 2*cntr[i]-i};
  sort(b+1, b+n+2);
  for (int i = 1; i <= n+1; ++i) {
    pos[b[i].id] = i;
    b_l[i] = b[i].l;
  }
  ST[0].build(n+1, -INF);
  ST[1].build(n+1, -INF);
  for (int i = 2, p; i <= n; ++i) {
    ST[i&1].modify(pos[i-2], 2*cntr[i-2]-(i-2));
    // odd
    p = lower_bound(b_l+1, b_l+n+2, 2*cntl[i]-i+1)-b_l;
    if (p <= n+1 && ST[~i&1].query(p, n+1) >= 2*cntr[i]-i+1)
      return void(cout << "yes" << endl);
    // even
    p = lower_bound(b_l+1, b_l+n+2, 2*cntl[i]-i+2)-b_l;
    if (p <= n+1 && ST[i&1].query(p, n+1) >= 2*cntr[i]-i)
      return void(cout << "yes" << endl);
  }
  /*
  for (int i = 2; i <= n; ++i) {
    for (int j = 0; j <= i-2; ++j) {
      if (cntl[i]-cntl[j] <= (i-j-1)/2 &&
          cntr[i]-cntr[j] <= (i-j)/2)
        return void(cout << "yes" << endl);
    }
  }
  */
  cout << "no" << endl;
}

signed main() {
  ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
  int T = 1;
  cin >> T;
  for (int t = 1; t <= T; ++t) {
    solve();
  }
  return 0;
}