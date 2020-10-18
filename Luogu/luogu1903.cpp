/*
 * @Author: Kaizyn
 * @Date: 2020-10-09 20:06:30
 * @LastEditTime: 2020-10-09 20:29:43
 */
#include <bits/stdc++.h>

// #define DEBUG

using namespace std;

const double eps = 1e-7;
const double PI = acos(-1);
typedef pair<int, int> pii;
const int MOD = 998244353;
const int INF = 0x3f3f3f3f;
const int N = 133333+7;
const int T = 1e6+7;

struct Query {
  int id, l, r, t;
};

struct Modify {
  int p, bef, aft;
};

int n, m, block, tot;
int a[N], b[N], cnt[T], res[N];
Modify c[N];
Query q[N];

bool cmp(const Query &q1, const Query &q2) {
  return q1.l/block != q2.l/block ? q1.l < q2.l :
      q1.r/block != q2.r/block ? q1.r < q2.r : q1.t < q2.t;
}

void add(int x) {
  tot += ++cnt[x] == 1;
}

void del(int x) {
  tot -= --cnt[x] == 0;
}

signed main() {
  scanf("%d %d", &n, &m);
  block = pow(n, 2/3.0);
  for (int i = 1; i <= n; ++i) scanf("%d", a+i);
  memcpy(b+1, a+1, sizeof(int)*n);
  char op[2];
  int t1 = 0, t2 = 0;
  for (int i = 1, l, r; i <= m; ++i) {
    scanf("%s%d%d", op, &l, &r);
    if (op[0] == 'Q') {
      ++t1;
      q[t1] = {t1, l, r, t2};
    } else {
      ++t2;
      c[t2] = {l, b[l], r};
      b[l] = r;
    }
  }
  sort(q+1, q+t1+1, cmp);
  for (int i = 1, l = 1, r = 0, t = 0; i <= t1; ++i) {
    while (t < q[i].t) {
      ++t;
      if (c[t].p >= l && c[t].p <= r) del(c[t].bef), add(c[t].aft);
      a[c[t].p] = c[t].aft;
    }
    while (t > q[i].t) {
      if (c[t].p >= l && c[t].p <= r) add(c[t].bef), del(c[t].aft);
      a[c[t].p] = c[t].bef;
      --t;
    }
    while (r < q[i].r) add(a[++r]);
    while (l > q[i].l) add(a[--l]);
    while (r > q[i].r) del(a[r--]);
    while (l < q[i].l) del(a[l++]);
    res[q[i].id] = tot;
  }
  for (int i = 1; i <= t1; ++i) printf("%d%c\n", res[i], " \n"[i==t1]);
  return 0;
}