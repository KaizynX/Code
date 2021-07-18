/*
 * @Author: Kaizyn
 * @Date: 2021-07-18 14:33:07
 * @LastEditTime: 2021-07-18 16:04:26
 */
// #pragma GCC optimize("Ofast,no-stack-protector")
// #pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,avx2,tune=native")
#include <bits/stdc++.h>

// #define DEBUG

using namespace std;

const double eps = 1e-7;
const double PI = acos(-1);
typedef pair<int, int> pii;
typedef long long ll;
const int MOD = 998244353; // 1e9+7;
const int INF = 0x3f3f3f3f;
// const ll INF = 1e18;
const int N = 2e5+7;
const int M = 11;

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

int n, m;
int a[N];
vector<int> p[N];
// dp[i][j] j'th part's end is on i's right
int dp[N][M];
SegmentTree<int, greater<int>> tree[M];

inline void solve() {
  // cin >> n >> m;
  // scanf("%d%d", &n, &m);
  for (int i = 1; i <= n; ++i) {
    // cin >> a[i];
    scanf("%d", a+i);
    p[i].assign(1, 0);
  }
  for (int i = 0; i <= m; ++i) tree[i].build(n+1, -INF);
  // memset(dp, 0x9f, sizeof dp);
  dp[0][0] = 0;
  tree[0].modify(0+1, 0);
  for (int i = 1, l, r; i <= n; ++i) {
    l = p[a[i]].back();
    r = i;
    for (int j = 0; j <= m; ++j) tree[j].add(l+1, r-1+1, 1);
    if (p[a[i]].size() >= 2u) {
      r = l;
      l = p[a[i]][p[a[i]].size()-2];
      for (int j = 0; j <= m; ++j) tree[j].add(l+1, r-1+1, -1);
    }
    p[a[i]].emplace_back(i);
    for (int j = 1; j <= m; ++j) {
      dp[i][j] = tree[j-1].query(0+1, i-1+1);
      tree[j].modify(i+1, dp[i][j]);
      #ifdef DEBUG
      printf("dp[%d][%d]=%d\n", i, j, dp[i][j]);
      #endif
    }
  }
  // cout << dp[n][m] << '\n';
  printf("%d\n", dp[n][m]);
}

signed main() {
#ifdef ONLINE_JUDGE
  ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
#endif
  // int T = 1;
  // scanf("%d", &T);
  // for (int t = 1; t <= T; ++t) {
    // solve();
  // }
  while (scanf("%d%d", &n, &m) == 2) solve();
  return 0;
}