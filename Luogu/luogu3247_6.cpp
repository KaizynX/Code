/*
 * @Author: Kaizyn
 * @Date: 2021-03-17 22:00:48
 * @LastEditTime: 2021-03-17 22:31:09
 */
#include <bits/stdc++.h>

// #define DEBUG

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
const int INF = 0x3f3f3f3f;
const int N = 1e5+7;

struct Node {
  int u, v, a, b, id;
};

bool cmpa(const Node &l, const Node &r) {
  return pii{l.a, l.b} < pii{r.a, r.b};
}

bool cmpb(const Node &l, const Node &r) {
  return pii{l.b, l.a} < pii{r.b, r.a};
}

struct DSU {
  vector<int> fa, rk, ma, mb;
  stack<Node> stk;
  void init(int n) {
    stk = stack<Node>();
    fa = rk = ma = mb = vector<int>(n+1, 0);
    iota(fa.begin(), fa.end(), 0);
  }
  int get(int s) { while (s != fa[s]) s = fa[s]; return s; }
  int& operator [](int i) { return fa[get(i)]; }
  void merge(int x, int y, int a, int b) {
    x = get(x); y = get(y);
    if (rk[x] > rk[y]) swap(x, y);
    stk.push(Node{x, y, ma[y], mb[y], rk[y]});
    if (x != y) {
      fa[x] = y;
      rk[y] += rk[x] == rk[y];
    }
    ma[y] = max({ma[y], ma[x], a});
    mb[y] = max({mb[y], mb[x], b});
  }
  void undo() {
    if (stk.empty()) return;
    int x = stk.top().u, y = stk.top().v;
    fa[x] = x;
    rk[y] = stk.top().id;
    ma[y] = stk.top().a;
    mb[y] = stk.top().b;
    stk.pop();
  }
};

int n, m, q;
int res[N];
Node a[N], b[N], c[N];
DSU dsu;

signed main() {
  scanf("%d%d", &n, &m);
  for (int i = 1; i <= m; ++i) {
    scanf("%d%d%d%d", &a[i].u, &a[i].v, &a[i].a, &a[i].b);
  }
  scanf("%d", &q);
  for (int i = 1; i <= q; ++i) {
    scanf("%d%d%d%d", &b[i].u, &b[i].v, &b[i].a, &b[i].b);
    b[i].id = i;
  }
  sort(a+1, a+m+1, cmpa);
  sort(b+1, b+q+1, cmpb);
  int sz = sqrt(m*log2(n));
  for (int i = 1, j, k, l, sum, cnt; i <= m; i += sz) {
    dsu.init(n);
    for (j = 1, sum = 0; j <= q; ++j) {
      if (a[i].a <= b[j].a && (i+sz > m || b[j].a < a[i+sz].a)) {
        c[++sum] = b[j];
      }
    }
    if (!sum) continue;
    sort(a+1, a+i, cmpb);
    for (j = k = 1; j <= sum; ++j) {
      for ( ; k < i && a[k].b <= c[j].b; ++k) {
        dsu.merge(a[k].u, a[k].v, a[k].a, a[k].b);
      }
      for (l = i, cnt = 0; l < i+sz && l <= m; ++l) {
        if (a[l].a <= c[j].a && a[l].b <= c[j].b) {
          dsu.merge(a[l].u, a[l].v, a[l].a, a[l].b);
          ++cnt;
        }
      }
      int u = dsu[c[j].u], v = dsu[c[j].v];
      res[c[j].id] = u == v && dsu.ma[u] == c[j].a && dsu.mb[u] == c[j].b;
      while (cnt--) dsu.undo();
    }
  }
  for (int i = 1; i <= q; ++i) {
    puts(res[i] ? "Yes" : "No");
  }
  return 0;
}