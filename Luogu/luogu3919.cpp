/*
 * @Author: Kaizyn
 * @Date: 2020-08-14 16:03:42
 * @LastEditTime: 2020-08-14 16:30:13
 */
#include <bits/stdc++.h>

// #define DEBUG

using namespace std;

const double eps = 1e-7;
const double PI = acos(-1);
typedef pair<int, int> pii;
const int MOD = 998244353;
const int INF = 0x3f3f3f3f;
const int N = 1e6+7;

int n, m;
int a[N];

template <typename T>
struct PersistanceArray {
  static const int NN = N*(log2(N)+3);
  int rt[N], ls[NN], rs[NN], val[NN], tot, n;
  void build(const int &n) {
    this->n = n;
    tot = 0;
    rt[0] = build(1, n);
  }
  int build(const int &l, const int &r) {
    int cur = ++tot; assert(tot < NN);
    if (l == r) return val[cur] = a[l], cur;
    int mid = (l+r)>>1;
    ls[cur] = build(l, mid);
    rs[cur] = build(mid+1, r);
    return cur;
  }
  void update(const int &cur, const int &pre, const int &x, const T &k) {
    rt[cur] = update(rt[pre], x, k, 1, n);
  }
  int update(const int &pre, const int &x, const T &k, const int &l, const int &r) {
    int cur = ++tot; assert(tot < NN);
    if (l == x && r == x) return val[cur] = k, cur;
    ls[cur] = ls[pre]; rs[cur] = rs[pre];
    int mid = (l+r)>>1;
    if (x <= mid) ls[cur] = update(ls[pre], x, k, l, mid);
    else rs[cur] = update(rs[pre], x, k, mid+1, r);
    return cur;
  }
  T query(const int &cur, const int &x) {
    return query(rt[cur], x, 1, n);
  }
  T query(const int &cur, const int &x, const int &l, const int &r) {
    if (l == x && r == x) return val[cur];
    int mid = (l+r)>>1;
    if (x <= mid) return query(ls[cur], x, l, mid);
    return query(rs[cur], x, mid+1, r);
  }
};
PersistanceArray<int> psa;

signed main() {
  scanf("%d %d", &n, &m);
  for (int i = 1; i <= n; ++i) scanf("%d", a+i);
  psa.build(n);
  for (int i = 1, op, v, loc, val; i <= m; ++i) {
    scanf("%d %d %d", &v, &op, &loc);
    if (op == 1) {
      scanf("%d", &val);
      psa.update(i, v, loc, val);
    } else {
      psa.rt[i] = psa.rt[v];
      printf("%d\n", psa.query(v, loc));
    }
  }
  return 0;
}