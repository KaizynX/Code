/*
 * @Author: Kaizyn
 * @Date: 2020-08-14 16:32:11
 * @LastEditTime: 2020-08-15 12:52:41
 */
#include <bits/stdc++.h>

// #define DEBUG

using namespace std;

const double eps = 1e-7;
const double PI = acos(-1);
typedef pair<int, int> pii;
const int MOD = 998244353;
const int INF = 0x3f3f3f3f;
const int N = 2e5+7;

struct PersistantUnionSet {
  static const int NN = N*(log2(N)+3);
  int rt[N], ls[NN], rs[NN], fa[NN], dep[NN], n, tot;
  void build(const int &n) {
    this->n = n;
    tot = 0;
    rt[0] = build(1, n);
  }
  int build(const int &l, const int &r) {
    int cur = ++tot; assert(tot < NN);
    if (l == r) return fa[cur] = l, dep[cur] = 0, cur;
    int mid = (l+r)>>1;
    ls[cur] = build(l, mid);
    rs[cur] = build(mid+1, r);
    return cur;
  }
  bool query(const int &cur, const int &x, const int &y) {
    return fa[getf(rt[cur], x)] == fa[getf(rt[cur], y)];
  }
  // return the id of fa[], dep[]
  int query(const int &cur, const int &x, const int &l, const int &r) {
    if (l == r) return cur;
    int mid = (l+r)>>1;
    if (x <= mid) return query(ls[cur], x, l, mid);
    else return query(rs[cur], x, mid+1, r);
  }
  // return the id of fa[], dep[]
  int getf(const int &cur, int x) {
    int fi;
    while (fa[(fi = query(cur, x, 1, n))] != x) x = fa[fi];
    return fi;
  }
  void merge(const int &cur, const int &pre, const int &x, const int &y) {
    rt[cur] = rt[pre];
    int fx = getf(rt[cur], x), fy = getf(rt[cur], y);
    if (fa[fx] == fa[fy]) return;
    if (dep[fx] > dep[fy]) swap(fx, fy);
    rt[cur] = update(rt[pre], fa[fx], fa[fy], 1, n);
    if (dep[fx] == dep[fy]) add(rt[cur], fa[fy], 1, n);
  }
  // update fa, merge x to y
  int update(const int &pre, const int &x, const int &y, const int &l, const int &r) {
    int cur = ++tot; assert(tot < NN);
    if (l == r) return fa[cur] = y, dep[cur] = dep[pre], cur;
    ls[cur] = ls[pre]; rs[cur] = rs[pre];
    int mid = (l+r)>>1;
    if (x <= mid) ls[cur] = update(ls[pre], x, y, l, mid);
    else rs[cur] = update(rs[pre], x, y, mid+1, r);
    return cur;
  }
  // add dep
  void add(const int &cur, const int &x, const int &l, const int &r) {
    if (l == r) return ++dep[cur], void();
    int mid = (l+r)>>1;
    if (x <= mid) add(ls[cur], x, l, mid);
    else add(rs[cur], x, mid+1, r);
  }
};

int n, m;
PersistantUnionSet pus;

signed main() {
  // freopen("P3402_2.in", "r", stdin);
  // freopen("my.out", "w", stdout);
  scanf("%d %d", &n, &m);
  pus.build(n);
  for (int i = 1, opt, a, b, k; i <= m; ++i) {
    scanf("%d", &opt);
    if (opt == 1) {
      scanf("%d %d", &a, &b);
      pus.merge(i, i-1, a, b);
    } else if (opt == 2) {
      scanf("%d", &k);
      pus.rt[i] = pus.rt[k];
    } else if (opt == 3) {
      pus.rt[i] = pus.rt[i-1];
      scanf("%d %d", &a, &b);
      printf("%d\n", pus.query(i, a, b));
    }
  }
  return 0;
}