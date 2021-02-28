/*
 * @Author: Kaizyn
 * @Date: 2021-02-24 19:10:45
 * @LastEditTime: 2021-02-24 19:39:43
 */
#include <bits/stdc++.h>

// #define DEBUG

using namespace std;

typedef long long ll;
const int MOD = 998244353;
// const int INF = 0x3f3f3f3f;
const int INF = INT_MAX;
const int N = 5e5+7;

int n, m;
int a[N];

struct SegmentTree {
#define rt tr[i]
#define ls tr[i<<1]
#define rs tr[i<<1|1]
  typedef int T;
  struct TreeNode {
    int l, r;
    T mn, hmn, se, tag1, htag1, tag2, htag2;
  } tr[N<<2];
  void push_up(int i) {
    rt.hmn = min(ls.hmn, rs.hmn);
    if (ls.mn == rs.mn) {
      rt.mn = ls.mn;
      rt.se = min(ls.se, rs.se);
    } else if (ls.mn < rs.mn) {
      rt.mn = ls.mn;
      rt.se = min(ls.se, rs.mn);
    } else if (ls.mn > rs.mn) {
      rt.mn = rs.mn;
      rt.se = min(ls.mn, rs.se);
    }
  }
  void push_tag(int i, T add1, T hadd1, T add2, T hadd2) {
    rt.hmn = min(rt.hmn, rt.mn+hadd1);
    rt.htag1 = min(rt.htag1, rt.tag1+hadd1);
    rt.mn += add1; rt.tag1 += add1;
    rt.htag2 = min(rt.htag2, rt.tag2+hadd2);
    if (rt.se != INF) rt.se += add2;
    rt.tag2 += add2;
  }
  void push_down(int i) {
    T mn = min(ls.mn, rs.mn);
    push_tag(i<<1  , ls.mn == mn ? rt.tag1 : rt.tag2,
        ls.mn == mn ? rt.htag1 : rt.htag2, rt.tag2, rt.htag2);
    push_tag(i<<1|1, rs.mn == mn ? rt.tag1 : rt.tag2,
        rs.mn == mn ? rt.htag1 : rt.htag2, rt.tag2, rt.htag2);
    rt.tag1 = rt.htag1 = rt.tag2 = rt.htag2 = 0;
  }
  void build(int l, int r, int i = 1) {
    rt.l = l; rt.r = r;
    rt.tag1 = rt.htag1 = rt.tag2 = rt.htag2 = 0;
    if (l == r) {
      rt.hmn = rt.mn = a[l];
      rt.se = INF;
      return;
    }
    int mid = (l+r)>>1;
    build(l, mid, i<<1); build(mid+1, r, i<<1|1);
    push_up(i);
  }
  void update_add(int l, int r, T v, int i = 1) {
    if (rt.r < l || rt.l > r) return;
    if (l <= rt.l && rt.r <= r) return push_tag(i, v, v, v, v);
    push_down(i);
    update_add(l, r, v, i<<1); update_add(l, r, v, i<<1|1);
    push_up(i);
  }
  void update_max(int l, int r, T v, int i = 1) {
    if (rt.r < l || rt.l > r || v <= rt.mn) return;
    if (l <= rt.l && rt.r <= r && v < rt.se)
      return push_tag(i, v-rt.mn, v-rt.mn, 0, 0);
    push_down(i);
    update_max(l, r, v, i<<1); update_max(l, r, v, i<<1|1);
    push_up(i);
  }
  T query_min(int l, int r, int i = 1) {
    if (rt.r < l || rt.l > r) return INF;
    if (l <= rt.l && rt.r <= r) return rt.mn;
    push_down(i);
    return min(query_min(l, r, i<<1), query_min(l, r, i<<1|1));
  }
  T query_hmin(int l, int r, int i = 1) {
    if (rt.r < l || rt.l > r) return INF;
    if (l <= rt.l && rt.r <= r) return rt.hmn;
    push_down(i);
    return min(query_hmin(l, r, i<<1), query_hmin(l, r, i<<1|1));
  }
#undef rt
#undef ls
#undef rs
};

SegmentTree tree;

signed main() {
  scanf("%d%d", &n, &m);
  for (int i = 1; i <= n; ++i) scanf("%d", a+i);
  tree.build(1, n);
  for (int _ = m, op, l, r, x; _; --_) {
    scanf("%d%d%d", &op, &l, &r);
    if (op == 1) {
      scanf("%d", &x);
      tree.update_add(l, r, x);
    } else if (op == 2) {
      scanf("%d", &x);
      tree.update_max(l, r, x);
    } else if (op == 3) {
      printf("%d\n", tree.query_min(l, r));
    } else {
      printf("%d\n", tree.query_hmin(l, r));
    }
  }
  return 0;
}