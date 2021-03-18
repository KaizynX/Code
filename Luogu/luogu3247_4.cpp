/*
 * @Author: Kaizyn
 * @Date: 2021-03-17 15:31:47
 * @LastEditTime: 2021-03-17 21:16:57
 */
#include <bits/stdc++.h>

#define DEBUG

using namespace std;

typedef long long ll;
const int INF = 0x3f3f3f3f;
const int N = 5e4+7;
const int M = 1e5+7;

struct Node {
  int u, v, a, b, id;
};

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
Node e[M];
vector<Node> qy[M];
DSU dsu;

signed main() {
  scanf("%d%d", &n, &m);
  for (int i = 1; i <= m; ++i) {
    scanf("%d%d%d%d", &e[i].u, &e[i].v, &e[i].a, &e[i].b);
  }
  sort(e+1, e+m+1, [](Node &nl, Node &nr) {
    return nl.a < nr.a;
  });
  scanf("%d", &q);
  // int sz = 1.5 * m / sqrt(q);
  int sz = sqrt(m*log(n))+1;
  int blocks = (m + sz - 1) / sz;
  for (int i = 1, u, v, a, b, j; i <= q; ++i) {
    scanf("%d%d%d%d", &u, &v, &a, &b);
    for (j = 1; j < blocks && e[sz*j].a <= a; ++j) {}
    qy[j].emplace_back(Node{u, v, a, b, i});
  }
  for (int i = 1, j; i <= blocks; ++i) {
    dsu.init(n);
    j = 1;
    sort(e+1, e+(i-1)*sz+1, [](Node &nl, Node &nr) {
      return nl.b < nr.b;
    });
    sort(qy[i].begin(), qy[i].end(), [](Node &nl, Node &nr) {
      return nl.b < nr.b;
    });
    #ifdef DEBUG
    puts("****************");
    for (int k = 1; k <= (i-1)*sz; ++k) {
      printf("%d:%d %d %d %d\n", k, e[k].u, e[k].v, e[k].a, e[k].b);
    }
    #endif
    for (auto &qq : qy[i]) {
      for ( ; j <= (i-1)*sz && e[j].b <= qq.b; ++j) {
        dsu.merge(e[j].u, e[j].v, e[j].a, e[j].b);
      }
      int opt = 0;
      for (int k = (i-1)*sz+1; k <= min(m, i*sz); ++k) {
        if (e[k].a <= qq.a && e[k].b <= qq.b) {
          dsu.merge(e[k].u, e[k].v, e[k].a, e[k].b);
          ++opt;
        }
      }
      int u = dsu[qq.u], v = dsu[qq.v];
      res[qq.id] = u == v && dsu.ma[u] == qq.a && dsu.mb[u] == qq.b;
      while (opt--) dsu.undo();
    }
  }
  for (int i = 1; i <= q; ++i) {
    puts(res[i] ? "Yes" : "No");
  }
  return 0;
}