/*
 * @Author: Kaizyn
 * @Date: 2020-08-08 16:47:33
 * @LastEditTime: 2020-08-08 16:52:22
 */
#include <bits/stdc++.h>

using namespace std;

const int N = 2e5+7;
const int M = 4e6+7;

template <typename T>
struct PersistenceSegmentTree {
  static const int NN = N*(log2(N)+5);
  int rt[N], sum[NN], ls[NN], rs[NN], tot, n;
  void build(const int &n) {
    this->n = n;
    tot = 0;
    rt[0] = _build(1, n);
  }
  void update(const int &cur, const int &pre, const T &k) {
    rt[cur] = _update(rt[pre], 1, n, k);
  }
  T query(const int &l, const int &r, const int &k) {
    return _query(rt[l-1], rt[r], 1, n, k);
  }
private:
  int _build(const int &l, const int &r) {
    int cur = ++tot;
    sum[cur] = 0;
    if (l >= r) return cur;
    int mid = (l+r)>>1;
    ls[cur] = _build(l, mid);
    rs[cur] = _build(mid+1, r);
    return cur;
  }
  int _update(const int &pre, const int &l, const int &r, const int &k) {
    int cur = ++tot;
    ls[cur] = ls[pre]; rs[cur] = rs[pre]; sum[cur] = sum[pre]+1;
    if (l >= r) return cur;
    int mid = (l+r)>>1;
    if (k <= mid) ls[cur] = _update(ls[pre], l, mid, k);
    else rs[cur] = _update(rs[pre], mid+1, r, k);
    return cur;
  }
  int _query(const int &u, const int &v, const int &l, const int &r, const int &k) {
    if (l >= r) return l;
    int num = sum[ls[v]]-sum[ls[u]], mid = (l+r)>>1;
    if (num >= k) return _query(ls[u], ls[v], l, mid, k);
    else return _query(rs[u], rs[v], mid+1, r, k-num);
  }
};

int n, m, q;
int a[N], b[N];
PersistenceSegmentTree<int> PST;

int my_hash(int x) {
  return lower_bound(b+1, b+m+1, x)-b;
}

int main() {
  scanf("%d%d", &n, &q);
  for (int i = 1; i <= n; ++i) {
    scanf("%d", a+i);
    b[i] = a[i];
  }
  sort(b+1, b+n+1);
  m = unique(b+1, b+n+1)-b-1;
  PST.build(m);
  for (int i = 1; i <= n; ++i) {
    a[i] = my_hash(a[i]);
    PST.update(i, i-1, a[i]);
  }
  for (int i = 1, l, r, k; i <= q; ++i) {
    scanf("%d %d %d", &l, &r, &k);
    printf("%d\n", b[PST.query(l, r, k)]);
  }
  return 0;
}
