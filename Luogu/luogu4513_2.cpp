/*
 * @Author: Kaizyn
 * @Date: 2021-07-13 15:41:48
 * @LastEditTime: 2021-07-13 15:43:21
 */
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
const int N = 5e5+7;

// 区间最大连续子段和
struct SegmentTree {
  struct TreeNode {
    long long s, ls, rs, ms;
    void set(long long x) { s = ls = rs = ms = x; }
    friend TreeNode operator +(const TreeNode &lc, const TreeNode &rc) {
      return TreeNode {
          lc.s+rc.s,
          max(lc.ls, lc.s+rc.ls),
          max(rc.rs, lc.rs+rc.s),
          max({lc.ms, rc.ms, lc.rs+rc.ls})
      };
    }
  } tr[N<<2];
  int *a, n;
  void build(int a[], int n) {
    this->a = a;
    this->n = n;
    build(1, n, 1);
  }
  void build(int l, int r, int i) {
    if (l == r) return tr[i].set(a[l]);
    int mid = (l+r)>>1;
    build(l, mid, i<<1);
    build(mid+1, r, i<<1|1);
    tr[i] = tr[i<<1]+tr[i<<1|1];
  }
  void update(int x, long long v) { update(x, v, 1, n, 1); }
  void update(int x, long long v, int l, int r, int i) {
    if (l == r) return tr[i].set(v);
    int mid = (l+r)>>1;
    if (x <= mid) update(x, v, l, mid, i<<1);
    else update(x, v, mid+1, r, i<<1|1);
    tr[i] = tr[i<<1]+tr[i<<1|1];
  }
  long long query(int L, int R) { return query(L, R, 1, n, 1).ms; }
  TreeNode query(int L, int R, int l, int r, int i) {
    if (l >= L && r <= R) return tr[i];
    int mid = (l+r)>>1;
    if (R <= mid) return query(L, R, l, mid, i<<1);
    if (L >  mid) return query(L, R, mid+1, r, i<<1|1);
    return query(L, R, l, mid, i<<1)+query(L, R, mid+1, r, i<<1|1);
  }
};

int n, m;
int a[N];
SegmentTree tree;

inline void solve() {
  cin >> n >> m;
  for (int i = 1; i <= n; ++i) cin >> a[i];
  tree.build(a, n);
  for (int _ = m, k, x, y; _; --_) {
    cin >> k >> x >> y;
    if (k == 1) {
      if (x > y) swap(x, y);
      cout << tree.query(x, y) << '\n';
    } else {
      tree.update(x, y);
    }
  }
}

signed main() {
#ifdef ONLINE_JUDGE
  ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
#endif
  int T = 1;
  // cin >> T; // scanf("%d", &T);
  for (int t = 1; t <= T; ++t) {
    solve();
  }
  return 0;
}