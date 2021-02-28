/*
 * @Author: Kaizyn
 * @Date: 2021-02-24 14:20:38
 * @LastEditTime: 2021-02-24 15:51:16
 */
#include <bits/stdc++.h>

// #define DEBUG

using namespace std;

typedef pair<int, int> pii;
typedef long long ll;
const ll INF = 1e18;
const int N = 5e5+7;

int n, m;
int a[N];

struct SegmentTree {
#define rt tr[i]
#define ls tr[i<<1]
#define rs tr[i<<1|1]
  typedef long long T;
  struct Tag {
    T add, mx;
    Tag(T _add = 0, T _mx = 0) : add(_add), mx(_mx) {}
    Tag operator +(const Tag &t) const { // 合并tag
      return Tag(max(-INF, add+t.add), max(mx+t.add, t.mx));
    }
    Tag operator *(const Tag &t) const { // 取max
      return Tag(max(add, t.add), max(mx, t.mx));
    }
    Tag& operator +=(const Tag &t) { return *this = *this+t; }
  };
  struct TreeNode {
    int l, r;
    Tag his, cur;
  } tr[N<<2];
  void push_tag(int i, Tag k1, Tag k2) {
    rt.his = rt.his*(rt.cur+k1);
    rt.cur += k2;
  }
  void push_down(int i) {
    push_tag(i<<1  , rt.his, rt.cur);
    push_tag(i<<1|1, rt.his, rt.cur);
    rt.his = rt.cur = Tag();
  }
  void build(int l, int r, int i = 1) {
    rt.l = l; rt.r = r; rt.his = rt.cur = Tag();
    if (l == r) return rt.his = rt.cur = Tag(a[l]), void();
    int mid = (l+r)>>1;
    build(l, mid, i<<1); build(mid+1, r, i<<1|1);
  }
  T query_max(int l, int r, int i = 1) {
    if (rt.r < l || rt.l > r) return -INF;
    if (l <= rt.l && rt.r <= r) return max(rt.cur.add, rt.cur.mx);
    push_down(i);
    return max(query_max(l, r, i<<1), query_max(l, r, i<<1|1));
  }
  T query_hmax(int l, int r, int i = 1) {
    if (rt.r < l || rt.l > r) return -INF;
    if (l <= rt.l && rt.r <= r) return max(rt.his.add, rt.his.mx);
    push_down(i);
    return max(query_hmax(l, r, i<<1), query_hmax(l, r, i<<1|1));
  }
  void update_add(int l, int r, int v, int i = 1) {
    if (rt.r < l || rt.l > r) return;
    if (l <= rt.l && rt.r <= r) return push_tag(i, Tag(v), Tag(v));
    push_down(i);
    update_add(l, r, v, i<<1); update_add(l, r, v, i<<1|1);
  }
  void update_cov(int l, int r, int v, int i = 1) {
    if (rt.r < l || rt.l > r) return;
    if (l <= rt.l && rt.r <= r) return push_tag(i, Tag(-INF, v), Tag(-INF, v));
    push_down(i);
    update_cov(l, r, v, i<<1); update_cov(l, r, v, i<<1|1);
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
  for (int i = 1, op, l, r, x; i <= m; ++i) {
    scanf("%d", &op);
    if (op <= 3) scanf("%d%d%d", &l, &r, &x);
    else scanf("%d", &x);
    if (op == 1) {
      tree.update_add(l, r, x);
    } else if (op == 2) {
      tree.update_add(l, r, -x);
    } else if (op == 3) {
      tree.update_cov(l, r, x);
    } else if (op == 4) {
      printf("%lld\n", tree.query_max(x, x));
    } else {
      printf("%lld\n", tree.query_hmax(x, x));
    }
  }
  return 0;
}