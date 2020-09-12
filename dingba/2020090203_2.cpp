/*
 * @Author: Kaizyn
 * @Date: 2020-09-02 20:29:22
 * @LastEditTime: 2020-09-03 14:23:11
 */
#include <bits/stdc++.h>

// #define DEBUG

using namespace std;

const int N = 1e5+7;
const int M = 9600;

template <typename T> inline int miu(T x) {
  int t = 0;
  for (T i = 2; i*i <= x; ++i) if (x%i == 0) {
    ++t;
    x /= i;
    if (x%i == 0) return 0;
  }
  if (x > 1) ++t;
  return t&1 ? -1 : 1;
}

int n, q;
int a[N], mp[N];

struct Euler {
  int tot = 0;
  int prime[N];
  bool check[N];
  bool& operator [] (const int i) { return check[i]; }
  void init(int sz) {
    tot = 0;
    for (int i = 1; i <= sz; ++i) check[i] = true, mp[i] = -1;
    check[1] = false;
    for (int i = 2, j; i <= sz; ++i) {
      if (check[i]) mp[i] = tot, prime[++tot] = i;
      for (j = 1; j <= tot && i*prime[j] <= sz; ++j) {
        check[i*prime[j]] = false;
        if (i%prime[j] == 0) break;
      }
    }
  }
} E;

struct SegmentTree {
  struct TreeNode {
    int l, r, tag;
    long long sum;
    bitset<M> bit;
  } tr[N<<2];
  void fuck(int id) {
    long long x = tr[id].sum;
    tr[id].bit.reset();
    for (int i = 2; i*i <= x; ++i) if (x%i == 0) {
      x /= i;
      if (x%i == 0) {
        tr[id].tag = 1;
        return;
      }
      tr[id].bit.set(mp[i]);
    }
    if (x > 1) tr[id].bit.set(mp[x]);
    tr[id].tag = 0;
  }
  void push_up(int i) {
    tr[i].sum = tr[i<<1].sum+tr[i<<1|1].sum;
    if (tr[i<<1].tag || tr[i<<1|1].tag || (tr[i<<1].bit&tr[i<<1|1].bit).any()) {
      tr[i].tag = 1;
    } else {
      tr[i].tag = 0;
      tr[i].bit = tr[i<<1].bit|tr[i<<1|1].bit;
    }
  }
  void build(int l, int r, int i = 1) {
    tr[i].l = l; tr[i].r = r;
    if (l == r) {
      tr[i].sum = a[l];
      fuck(i);
      return;
    }
    int m = (l+r)>>1;
    build(l, m, i<<1);
    build(m+1, r, i<<1|1);
    push_up(i);
  }
  void update(int x, int k, int i = 1) {
    if (tr[i].l == tr[i].r) {
      tr[i].sum = k;
      fuck(i);
      return;
    }
    int m = (tr[i].l+tr[i].r)>>1;
    if (x <= m) update(x, k, i<<1);
    else update(x, k, i<<1|1);
    push_up(i);
  }
  long long query1(int l, int r, int i = 1) {
    if (tr[i].l >= l && tr[i].r <= r) return tr[i].sum;
    int m = (tr[i].l+tr[i].r)>>1;
    long long res = 0;
    if (l <= m) res += query1(l, r, i<<1);
    if (r >  m) res += query1(l, r, i<<1|1);
    return res;
  }
  int query2(int l, int r, int i = 1) {
    if (tr[i].l >= l && tr[i].r <= r) {
      if (tr[i].tag || (tr[0].bit&tr[i].bit).any()) return 1;
      tr[0].bit |= tr[i].bit;
      return 0;
    }
    int m = (tr[i].l+tr[i].r)>>1;
    if (l <= m && query2(l, r, i<<1)) return 1;
    if (r >  m && query2(l, r, i<<1|1)) return 1;
    return 0;
  }
} seg;

signed main() {
  E.init(100000);
  scanf("%d %d", &n, &q);
  for (int i = 1; i <= n; ++i) scanf("%d", a+i);
  seg.build(1, n);
  for (int i = 1, op, l, r; i <= q; ++i) {
    scanf("%d %d %d", &op, &l, &r);
    if (op == 1) {
      seg.update(l, r);
    } else if (op == 2) {
      printf("%d\n", miu(seg.query1(l, r)));
    } else if (op == 3) {
      seg.tr[0].bit.reset();
      if (seg.query2(l, r)) puts("0");
      else printf("%d\n", seg.tr[0].bit.count()&1 ? -1 : 1);
    }
  }
  return 0;
}