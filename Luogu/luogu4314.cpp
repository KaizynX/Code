/*
 * @Author: Kaizyn
 * @Date: 2021-02-23 16:50:03
 * @LastEditTime: 2021-02-23 19:36:05
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
const int N = 1e5+7;

int n, m;
int a[N];

struct SegmentTree {
#define rt tr[i]
#define ls tr[i<<1]
#define rs tr[i<<1|1]
  struct TreeNode {
    int l, r;
    bool tag;
    int add, cov, mx, hadd, hcov, hmx;
  } tr[N<<2];
  void push_up(int i) {
    rt.mx = max(ls.mx, rs.mx);
    rt.hmx = max(ls.hmx, rs.hmx);
  }
  void plus(int i, int k, int hk) {
    rt.hmx = max(rt.hmx, rt.mx+hk);
    rt.mx += k;
    rt.tag ? rt.hcov = max(rt.hcov, rt.cov+hk), rt.cov += k
        : rt.hadd = max(rt.hadd, rt.add+hk), rt.add += k;
  }
  void cover(int i, int k, int hk) {
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
    if (l == r) return rt.hmx = rt.mx = a[l], void();
    int mid = (l+r)>>1;
    build(l, mid, i<<1); build(mid+1, r, i<<1|1);
    push_up(i);
  }
  int query_max(int l, int r, int i = 1) {
    if (rt.r < l || rt.l > r) return -INF;
    if (l <= rt.l && rt.r <= r) return rt.mx;
    push_down(i);
    return max(query_max(l, r, i<<1), query_max(l, r, i<<1|1));
  }
  int query_hmax(int l, int r, int i = 1) {
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

SegmentTree tree;

signed main() {
  scanf("%d", &n);
  for (int i = 1; i <= n; ++i) scanf("%d", a+i);
  tree.build(1, n);
  scanf("%d", &m);
  char op[2];
  for (int _ = m, x, y, z; _; --_) {
    scanf("%s%d%d", op, &x, &y);
    if (op[0] == 'Q') {
      printf("%d\n", tree.query_max(x, y));
    } else if (op[0] == 'A') {
      printf("%d\n", tree.query_hmax(x, y));
    } else if (op[0] == 'P') {
      scanf("%d", &z);
      tree.update_add(x, y, z);
    } else if (op[0] == 'C') {
      scanf("%d", &z);
      tree.update_cov(x, y, z);
    }
  }
  return 0;
}