/*
 * @Author: Kaizyn
 * @Date: 2020-07-30 09:50:36
 * @LastEditTime: 2020-07-30 12:07:20
 */ 
#include <bits/stdc++.h>

#define DEBUG

using namespace std;

const double eps = 1e-7;
const double PI = acos(-1);
typedef pair<int, int> pii;
const int MOD = 998244353;
const int INF = 0x3f3f3f3f;
const int N = 2e5+7;

template <typename T, typename U = greater<T>>
struct SegmentTree {
  U cmp = U();
  int n;
  T tr[N<<2];
  SegmentTree(){}
  T mv(const T &x, const T &y) { return cmp(x, y) ? x : y;}
  void build(const int &_n, const T &k = 0) { n = _n; _build(1, n, k); }
  void modify(const int &x, const T &k) { _modify(x, k, 1, n); }
  T query(const int &l, const int &r) { return l > r ? 0 : _query(l, r, 1, n); }
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
    if (trl == x && trr == x) return tr[i] = k, void();
    int mid = (trl+trr)>>1;
    if (x <= mid) _modify(x, k, trl, mid, i<<1);
    else _modify(x, k, mid+1, trr, i<<1|1);
    push_up(i);
  }
  T _query(const int &l, const int &r, const int &trl, const int &trr, const int &i = 1) {
    if (trl >= l && trr <= r) return tr[i];
    int mid = (trl+trr)>>1;
    if (r <=  mid) return _query(l, r, trl, mid, i<<1);
    if (l >  mid) return _query(l, r, mid+1, trr, i<<1|1);
    return mv(_query(l, r, trl, mid, i<<1), _query(l, r, mid+1, trr, i<<1|1));
  }
};

int n;
vector<pii> a[2];
vector<int> dp[2];
SegmentTree<int> st[2];

inline void calc(const int &i) {
  int k = lower_bound(a[0].begin(), a[0].end(), pii{a[1][i].second+1, 0})-a[0].begin();
  dp[1][i] = max(st[1].query(i+1, a[1].size()), st[0].query(k+1, a[0].size()))+1;
  st[1].modify(i+1, dp[1][i]);
}

inline int solve() {
  cin >> n;
  for (int i = 1, l, r, t; i <= n; ++i) {
    cin >> l >> r >> t;
    a[--t].emplace_back(l, r);
  }
  for (int i = 0; i < 2; ++i) {
    sort(a[i].begin(), a[i].end());
    dp[i].resize(a[i].size());
    st[i].build(a[i].size());
  }
  if (a[0].empty()) swap(a[0], a[1]);
  if (a[1].empty()) return a[0].size();
  int j = a[1].size();
  for (int i = a[0].size()-1; i >= 0; --i) {
    int k = lower_bound(a[1].begin(), a[1].end(), pii{a[0][i].second+1, 0})-a[1].begin();
    while (k < j) calc(--j);
    dp[0][i] = max(st[0].query(i+1, a[0].size()), st[1].query(k+1, a[1].size()))+1;
    st[0].modify(i+1, dp[0][i]);
  }
  while (j > 0) calc(--j);
#ifdef DEBUG
  for (int i = 0; i < 2; ++i) {
    for (const auto &p : a[i]) printf("(%d,%d)", p.first, p.second);
    puts("");
    for (const auto &p : dp[i]) printf("%d ", p);
    puts("");
  }
#endif
  return max(st[0].query(1, a[0].size()), st[1].query(1, a[1].size()));
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