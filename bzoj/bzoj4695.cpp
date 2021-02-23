/*
 * @Author: Kaizyn
 * @Date: 2021-02-22 17:23:38
 * @LastEditTime: 2021-02-22 19:59:35
 */
#include <bits/stdc++.h>

// #define DEBUG

using namespace std;

const int INF = 0x3f3f3f3f;
const int N = 5e5+7;

template <typename T> inline void read(T &x) {
  int c; T tag = 1;
  while(!isdigit((c=getchar()))) if(c == '-') tag = -1;
  x = c-'0';
  while(isdigit((c=getchar()))) x = (x<<1)+(x<<3) + c-'0';
  x *= tag;
}

template <typename T> void write(T x) {
  if(x < 0) x = -x, putchar('-');
  if(x > 9) write(x/10);
  putchar(x%10+'0');
}

struct Tree {
#define rt tr[i]
#define ls tr[i<<1]
#define rs tr[i<<1|1]
  typedef int T;
  struct TreeNode {
    int l, r;
    T mn1, mn2, mx1, mx2, cmn, cmx, tag1, tag2, tag3;
    long long sum;
  };
  vector<T> a;
  vector<TreeNode> tr;
  void push_up(int i) {
    rt.sum = ls.sum+rs.sum;
    if (ls.mn1 == rs.mn1) {
      rt.mn1 = ls.mn1;
      rt.cmn = ls.cmn+rs.cmn;
      rt.mn2 = min(ls.mn2, rs.mn2);
    } else if (ls.mn1 < rs.mn1) {
      rt.mn1 = ls.mn1;
      rt.cmn = ls.cmn;
      rt.mn2 = min(ls.mn2, rs.mn1);
    } else if (ls.mn1 > rs.mn1) {
      rt.mn1 = rs.mn1;
      rt.cmn = rs.cmn;
      rt.mn2 = min(ls.mn1, rs.mn2);
    }
    if (ls.mx1 == rs.mx1) {
      rt.mx1 = ls.mx1;
      rt.cmx = ls.cmx+rs.cmx;
      rt.mx2 = max(ls.mx2, rs.mx2);
    } else if (ls.mx1 > rs.mx1) {
      rt.mx1 = ls.mx1;
      rt.cmx = ls.cmx;
      rt.mx2 = max(ls.mx2, rs.mx1);
    } else if (ls.mx1 < rs.mx1) {
      rt.mx1 = rs.mx1;
      rt.cmx = rs.cmx;
      rt.mx2 = max(ls.mx1, rs.mx2);
    }
  }
  // 1 2 3 -> min, max, other
  void push_tag(int i, T add1, T add2, T add3) {
    if (rt.mn1 == rt.mx1) {
      add1 == add3 ? add1 = add2 : add2 = add1; // 不应被其他值的标记作用
      rt.sum += 1ll*rt.cmn*add1;
    } else {
      rt.sum += 1ll*rt.cmn*add1+1ll*rt.cmx*add2
          +(rt.r-rt.l+1ll-rt.cmn-rt.cmx)*add3;
    }
    if (rt.mn2 == rt.mx1) rt.mn2 += add2;
    else if (rt.mn2 != INF) rt.mn2 += add3;
    if (rt.mx2 == rt.mn1) rt.mx2 += add1;
    else if (rt.mx2 != -INF) rt.mx2 += add3;
    rt.mn1 += add1; rt.mx1 += add2;
    rt.tag1 += add1; rt.tag2 += add2; rt.tag3 += add3;
  }
  void push_down(int i) {
    T mn = min(ls.mn1, rs.mn1);
    T mx = max(ls.mx1, rs.mx1);
    push_tag(i<<1  , ls.mn1 == mn ? rt.tag1 : rt.tag3, ls.mx1 == mx ? rt.tag2 : rt.tag3, rt.tag3);
    push_tag(i<<1|1, rs.mn1 == mn ? rt.tag1 : rt.tag3, rs.mx1 == mx ? rt.tag2 : rt.tag3, rt.tag3);
    rt.tag1 = rt.tag2 = rt.tag3 = 0;
  }
   template <typename TT> void build(int n, TT arr[]) {
    a.resize(1);
    a.insert(a.end(), arr+1, arr+n+1);
    tr.resize(n*4+1);
    build(1, n, 1);
  }
  void build(int n, T val = 0) {
    a.resize(n+1, val);
    tr.resize(n*4+1);
    build(1, n, 1);
  }
  void build(int l, int r, int i) {
    rt.l = l; rt.r = r;
    rt.tag1 = rt.tag2 = rt.tag3 = 0;
    if (l == r) {
      rt.sum = rt.mn1 = rt.mx1 = a[l];
      rt.mn2 = INF; rt.mx2 = -INF;
      rt.cmn = rt.cmx = 1;
      return;
    }
    int mid = (l+r)>>1;
    build(l, mid, i<<1); build(mid+1, r, i<<1|1);
    push_up(i);
  }
  void update_add(int l, int r, T v, int i = 1) {
    if (rt.r < l || rt.l > r) return;
    if (rt.l >= l && rt.r <= r)
      return push_tag(i, v, v, v);
    push_down(i);
    update_add(l, r, v, i<<1); update_add(l, r, v, i<<1|1);
    push_up(i);
  }
  void update_max(int l, int r, T v, int i = 1) {
    if (rt.r < l || rt.l > r || rt.mn1 >= v) return;
    if (rt.l >= l && rt.r <= r && rt.mn2 > v)
      return push_tag(i, v-rt.mn1, 0, 0);
    push_down(i);
    update_max(l, r, v, i<<1); update_max(l, r, v, i<<1|1);
    push_up(i);
  }
  void update_min(int l, int r, T v, int i = 1) {
    if (rt.r < l || rt.l > r || rt.mx1 <= v) return;
    if (rt.l >= l && rt.r <= r && rt.mx2 < v)
      return push_tag(i, 0, v-rt.mx1, 0);
    push_down(i);
    update_min(l, r, v, i<<1); update_min(l, r, v, i<<1|1);
    push_up(i);
  }
  long long query_sum(int l, int r, int i = 1) {
    if (rt.r < l || rt.l > r) return 0;
    if (rt.l >= l && rt.r <= r) return rt.sum;
    push_down(i);
    return query_sum(l, r, i<<1)+query_sum(l, r, i<<1|1);
  }
  T query_max(int l, int r, int i = 1) {
    if (rt.r < l || rt.l > r) return -INF;
    if (rt.l >= l && rt.r <= r) return rt.mx1;
    push_down(i);
    return max(query_max(l, r, i<<1), query_max(l, r, i<<1|1));
  }
  T query_min(int l, int r, int i = 1) {
    if (rt.r < l || rt.l > r) return INF;
    if (rt.l >= l && rt.r <= r) return rt.mn1;
    push_down(i);
    return min(query_min(l, r, i<<1), query_min(l, r, i<<1|1));
  }
#undef rt
#undef ls
#undef rs
};

int n, m;
int a[N];
Tree tree;

signed main() {
  read(n);
  for (int i = 1; i <= n; ++i) read(a[i]);
  tree.build(n, a);
  read(m);
  for (int _ = m, op, l, r, x; _; --_) {
    read(op); read(l); read(r);
    if (op <= 3) read(x);
    if (op == 1) {
      tree.update_add(l, r, x);
    } else if (op == 2) {
      tree.update_max(l, r, x);
    } else if (op == 3) {
      tree.update_min(l, r, x);
    } else if (op == 4) {
      write(tree.query_sum(l, r));
    } else if (op == 5) {
      write(tree.query_max(l, r));
    } else {
      write(tree.query_min(l, r));
    }
    if (op > 3) putchar('\n');
  }
  return 0;
}