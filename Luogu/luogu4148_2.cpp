/*
 * @Author: Kaizyn
 * @Date: 2021-02-25 15:41:18
 * @LastEditTime: 2021-02-25 16:56:52
 */
#include <bits/stdc++.h>

// #define DEBUG

using namespace std;

typedef long long ll;
const int INF = 0x3f3f3f3f;
const int N = 2e5+7;

struct Node {
  int x, y, v;
} s[N];
bool cmpx(int a, int b) { return s[a].x < s[b].x; }
bool cmpy(int a, int b) { return s[a].y < s[b].y; }
struct KDTree {
  double alpha = 0.725;
  int rt, cur, xl, yl, xr, yr; //rt根结点
  int d[N], siz[N], lc[N], rc[N]; //d=1竖着砍，sz子树大小
  int L[N], R[N], D[N], U[N]; //该子树的界线
  int sum[N]; //维护的二维区间信息（二维区间和）
  int g[N], gt;
  void pia(int x) { //将树还原成序列g
    if (!x) return;
    pia(lc[x]);
    g[++gt] = x;
    pia(rc[x]);
  }
  void push_up(int x) { //更新信息
    siz[x] = siz[lc[x]] + siz[rc[x]] + 1;
    sum[x] = sum[lc[x]] + sum[rc[x]] + s[x].v;
    L[x] = R[x] = s[x].x;
    D[x] = U[x] = s[x].y;
    if (lc[x]) {
      L[x] = min(L[x], L[lc[x]]);
      R[x] = max(R[x], R[lc[x]]);
      D[x] = min(D[x], D[lc[x]]);
      U[x] = max(U[x], U[lc[x]]);
    }
    if (rc[x]) {
      L[x] = min(L[x], L[rc[x]]);
      R[x] = max(R[x], R[rc[x]]);
      D[x] = min(D[x], D[rc[x]]);
      U[x] = max(U[x], U[rc[x]]);
    }
  }
  int build(int l, int r) { //以序列g[l..r]为模板重建树，返回根结点
    if (l > r) return 0;
    int mid = (l + r) >> 1;
    double ax = 0, ay = 0, sx = 0, sy = 0;
    for (int i = l; i <= r; i++) ax += s[g[i]].x, ay += s[g[i]].y;
    ax /= (r - l + 1);
    ay /= (r - l + 1);
    for (int i = l; i <= r; i++) {
      sx += (ax - s[g[i]].x) * (ax - s[g[i]].x);
      sy += (ay - s[g[i]].y) * (ay - s[g[i]].y);
    }
    if (sx > sy)
      nth_element(g + l, g + mid, g + r + 1, cmpx), d[g[mid]] = 1;
    else
      nth_element(g + l, g + mid, g + r + 1, cmpy), d[g[mid]] = 2;
    lc[g[mid]] = build(l, mid - 1);
    rc[g[mid]] = build(mid + 1, r);
    push_up(g[mid]);
    return g[mid];
  }
  void rebuild(int &x) {
    gt = 0;
    pia(x);
    x = build(1, gt);
  }
  bool bad(int x) {
    return alpha * siz[x] <= max(siz[lc[x]], siz[rc[x]]);
  }
  void insert(int x, int y, int v) { //在(x,y)处插入元素
    s[++cur] = {x, y, v};
    insert(rt, cur);
  }
  void insert(int &x, int v) {
    if (!x) return push_up(x = v);
    if (d[x]) insert(s[v].x <= s[x].x ? lc[x] : rc[x], v);
    else insert(s[v].y <= s[x].y ? lc[x] : rc[x], v);
    push_up(x);
    if (bad(x)) rebuild(x);
  }
  int query(int xl, int yl, int xr, int yr) { //查询[x1,x2]×[y1,y2]的区间和
    if (xl > xr) swap(xl, xr);
    if (yl > yr) swap(yl, yr);
    this->xl = xl; this->yl = yl; this->xr = xr; this->yr = yr;
    return query(rt);
  }
  int query(int x) {
    if (!x || xr < L[x] || xl > R[x] || yr < D[x] || yl > U[x]) return 0;
    if (xl <= L[x] && R[x] <= xr && yl <= D[x] && U[x] <= yr) return sum[x];
    int res = 0;
    if (xl <= s[x].x && s[x].x <= xr && yl <= s[x].y && s[x].y <= yr)
      res += s[x].v;
    return query(lc[x]) + query(rc[x]) + res;
  }
};

int n;
KDTree kdt;

signed main() {
  scanf("%d", &n);
  for (int op, a, b, c, d, ans = 0; ; ) {
    scanf("%d", &op);
    if (op == 3) break;
    if (op == 1) {
      scanf("%d%d%d", &a, &b, &c);
      kdt.insert(a^ans, b^ans, c^ans);
    } else {
      scanf("%d%d%d%d", &a, &b, &c, &d);
      printf("%d\n", ans = kdt.query(a^ans, b^ans, c^ans, d^ans));
    }
  }
  return 0;
}