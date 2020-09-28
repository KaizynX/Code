/*
 * @Author: Kaizyn
 * @Date: 2020-09-24 23:25:22
 * @LastEditTime: 2020-09-24 23:47:10
 */
#include <bits/stdc++.h>

// #define DEBUG

using namespace std;

const int N = 3e5+7;
const long long INF = 1e18;
const int ope[] = {-1, 1};

struct SegmentTree {
  struct Node {
    long long t[4];
    void init(long long k = 0) {
      t[0] = -k; t[3] = k;
      t[1] = t[2] = -INF;
    }
    friend Node merge(const Node &nl, const Node &nr) {
      Node nt;
      for (int i = 0, l, r; i < 4; ++i) {
        l = i&2;
        r = i&1;
        nt.t[i] = max({nl.t[i], nr.t[i],
          nl.t[l+0]+nr.t[2+r], nl.t[l+1]+nr.t[0+r]});
      }
      return nt;
    }
    long long maxv() {
      return max({t[0], t[1], t[2], t[3]});
    }
  };
  struct TreeNode {
    int l, r;
    Node v;
  } tr[N<<2];
  int *a, n;
  void push_up(int i) {
    tr[i].v = merge(tr[i<<1].v, tr[i<<1|1].v);
  }
  void build(int *a, int n) {
    this->a = a;
    this->n = n;
    build(1, n, 1);
  }
  void build(int l, int r, int i) {
    tr[i].l = l; tr[i].r = r;
    if (l == r) return tr[i].v.init(a[l]);
    int m = (l+r)>>1;
    build(l, m, i<<1);
    build(m+1, r, i<<1|1);
    push_up(i);
  }
  void update(int x, int k, int i = 1) {
    if (tr[i].l == tr[i].r) return tr[i].v.init(k);
    int m = (tr[i].l+tr[i].r)>>1;
    if (x <= m) update(x, k, i<<1);
    else update(x, k, i<<1|1);
    push_up(i);
  }
  long long query() {
    return tr[1].v.maxv();
  }
};

int n, q;
int a[N];
SegmentTree seg;

inline void solve() {
  scanf("%d %d", &n, &q);
  for (int i = 1; i <= n; ++i) scanf("%d", a+i);
  seg.build(a, n);
  printf("%lld\n", seg.query());
  for (int i = 1, l, r; i <= q; ++i) {
    scanf("%d %d", &l, &r);
    swap(a[l], a[r]);
    seg.update(l, a[l]);
    seg.update(r, a[r]);
    printf("%lld\n", seg.query());
  }
}

signed main() {
  int T = 1;
  scanf("%d", &T);
  for (int t = 1; t <= T; ++t) {
    solve();
  }
  return 0;
}