/*
 * @Author: Kaizyn
 * @Date: 2021-02-23 20:36:25
 * @LastEditTime: 2021-02-23 20:44:16
 */
#include <bits/stdc++.h>

// #define DEBUG

using namespace std;

const double eps = 1e-7;
const double PI = acos(-1);
typedef pair<int, int> pii;
typedef long long ll;
const int MOD = 998244353;
// const int INF = 0x3f3f3f3f;
const ll INF = 1e18;
const int N = 1e5+7;

struct SegmentTree {
#define rt tr[i]
#define ls tr[i<<1]
#define rs tr[i<<1|1]
  typedef long long T;
  struct TreeNode {
    int l, r;
    bool tag;
    T add, cov, mx, hadd, hcov, hmx;
  } tr[N<<2];
  void push_up(int i) {
    rt.mx = max(ls.mx, rs.mx);
    rt.hmx = max(ls.hmx, rs.hmx);
  }
  void plus(int i, T k, T hk) {
    rt.hmx = max(rt.hmx, rt.mx+hk);
    rt.mx += k;
    rt.tag ? rt.hcov = max(rt.hcov, rt.cov+hk), rt.cov += k
        : rt.hadd = max(rt.hadd, rt.add+hk), rt.add += k;
  }
  void cover(int i, T k, T hk) {
    rt.hmx = max(rt.hmx, hk);
    rt.mx = k;
    rt.hcov = max(rt.hcov, hk);
    rt.cov = k;
    rt.tag = 1;
  }
  void push_down(int i) {
    if (rt.add) {
      plus(i<<1  , rt.add, rt.hadd);
      plus(i<<1|1, rt.add, rt.hadd);
      rt.add = rt.hadd = 0;
    }
    if (rt.tag) {
      cover(i<<1  , rt.cov, rt.hcov);
      cover(i<<1|1, rt.cov, rt.hcov);
      rt.tag = 0; rt.hcov = -INF;
    }
  }
  void build(int l, int r, int i = 1) {
    rt.l = l; rt.r = r; rt.tag = false;
    rt.add = rt.hadd = 0;
    rt.hcov = -INF;
    if (l == r) return rt.hmx = rt.mx = 0, void();
    int mid = (l+r)>>1;
    build(l, mid, i<<1); build(mid+1, r, i<<1|1);
    push_up(i);
  }
  T query_max(int l, int r, int i = 1) {
    if (rt.r < l || rt.l > r) return -INF;
    if (l <= rt.l && rt.r <= r) return rt.mx;
    push_down(i);
    return max(query_max(l, r, i<<1), query_max(l, r, i<<1|1));
  }
  T query_hmax(int l, int r, int i = 1) {
    if (rt.r < l || rt.l > r) return -INF;
    if (l <= rt.l && rt.r <= r) return rt.hmx;
    push_down(i);
    return max(query_hmax(l, r, i<<1), query_hmax(l, r, i<<1|1));
  }
  void update_add(int l, int r, int v, int i = 1) {
    if (rt.r < l || rt.l > r) return;
    if (l <= rt.l && rt.r <= r) return plus(i, v, v);
    push_down(i);
    update_add(l, r, v, i<<1); update_add(l, r, v, i<<1|1);
    push_up(i);
  }
  void update_cov(int l, int r, int v, int i = 1) {
    if (rt.r < l || rt.l > r) return;
    if (l <= rt.l && rt.r <= r) return cover(i, v, v);
    push_down(i);
    update_cov(l, r, v, i<<1); update_cov(l, r, v, i<<1|1);
    push_up(i);
  }
#undef rt
#undef ls
#undef rs
};

struct Node {
  int l, r, id;
  bool operator <(const Node &b) const {
    return r < b.r;
  }
};

int n, q;
int a[N], buf[N<<1], *last = buf+N;
ll res[N];
Node b[N];
SegmentTree tree;

signed main() {
  scanf("%d", &n);
  for (int i = 1; i <= n; ++i) scanf("%d", a+i);
  scanf("%d", &q);
  for (int i = 1; i <= q; ++i) {
    scanf("%d%d", &b[i].l, &b[i].r);
    b[i].id = i;
  }
  sort(b+1, b+q+1);
  tree.build(1, n);
  for (int i = 1, j = 1; i <= q; ++i) {
    while (j <= b[i].r) {
      tree.update_add(last[a[j]]+1, j, a[j]);
      last[a[j]] = j;
      ++j;
    }
    res[b[i].id] = tree.query_hmax(b[i].l, b[i].r);
  }
  for (int i = 1; i <= q; ++i) {
    printf("%lld\n", res[i]);
  }
  return 0;
}