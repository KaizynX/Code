/*
 * @Author: Kaizyn
 * @Date: 2021-03-17 17:01:47
 * @LastEditTime: 2021-03-17 17:03:40
 */
#include <bits/stdc++.h>

#define DEBUG

using namespace std;

const double eps = 1e-7;
const double PI = acos(-1);
typedef pair<int, int> pii;
typedef long long ll;
const int MOD = 998244353; // 1e9+7;
const int INF = 0x3f3f3f3f;
// const ll INF = 1e18;
const int N = 5e4+7;
const int M = 1e5+7;

struct DSU {
  vector<int> fa, rk, ma, mb;
  stack<pair<vector<int>::iterator, int>> stk;
  void init(int n) {
    stk = stack<pair<vector<int>::iterator, int>>();
    fa = rk = ma = mb = vector<int>(n+1, 0);
    iota(fa.begin(), fa.end(), 0);
  }
  int get(int s) { while (s != fa[s]) s = fa[s]; return s; }
  int& operator [](int i) { return fa[get(i)]; }
  int merge(int x, int y, int a, int b) {
    x = get(x); y = get(y);
    if (rk[x] > rk[y]) swap(x, y);
    int sz = stk.size();
    if (x != y) {
      stk.push({fa.begin()+x, fa[x]});
      fa[x] = y;
      if (rk[x] == rk[y]) {
        stk.push({rk.begin()+y, rk[y]});
        ++rk[y];
      }
    }
    if (max(ma[x], a) > ma[y]) {
      stk.push({ma.begin()+y, ma[y]});
      ma[y] = max(ma[x], a);
    }
    if (max(mb[x], b) > mb[y]) {
      stk.push({mb.begin()+y, mb[y]});
      mb[y] = max(mb[x], b);
    }
    return stk.size()-sz;
  }
  void undo() {
    *stk.top().first = stk.top().second;
    stk.pop();
  }
};

struct Node {
  int u, v, a, b, id;
};

int n, m, q;
int res[M];
Node e[M<<1];
DSU dsu;

signed main() {
  scanf("%d%d", &n, &m);
  for (int i = 1; i <= m; ++i) {
    scanf("%d%d%d%d", &e[i].u, &e[i].v, &e[i].a, &e[i].b);
  }
  scanf("%d", &q);
  for (int i = m+1; i <= m+q; ++i) {
    scanf("%d%d%d%d", &e[i].u, &e[i].v, &e[i].a, &e[i].b);
    e[i].id = i-m;
  }
  /*
  sort(e+1, e+m+q+1, [&](Node &nl, Node &nr) {
    if (pii{nl.a, nl.b} != pii{nr.a, nr.b}) return pii{nl.a, nl.b} < pii{nr.a, nr.b};
    return nl.id < nr.id;
  });
  */
  stable_sort(e+1, e+m+q+1, [](Node nl, Node nr) {
    return nl.a < nr.a;
  });
  int sqr = sqrt(m+q);
  for (int l = 1, r = sqr; l <= m+q; l += sqr, r = min(l+sqr, m+q)) {
    dsu.init(n);
    sort(e+1, e+l, [&](Node &nl, Node &nr) {
      return pii{nl.b, nl.a} < pii{nr.b, nr.a};
    });
    sort(e+l, e+r+1, [&](Node &nl, Node &nr) {
      return pii{nl.b, nl.a} < pii{nr.b, nr.a};
    });
    for (int i = l, j = 1, opt; i <= r; ++i) if (e[i].id) {
      while (j < l && e[j].b <= e[i].b) {
        if (!e[j].id) {
          dsu.merge(e[j].u, e[j].v, e[j].a, e[j].b);
        }
        ++j;
      }
      opt = 0;
      for (int k = l; k <= r; ++k) {
        if (!e[k].id &&  e[k].a <= e[i].a && e[k].b <= e[i].b) {
          opt += dsu.merge(e[k].u, e[k].v, e[k].a, e[k].b);
        }
      }
      int u = dsu[e[i].u], v = dsu[e[i].v];
      res[e[i].id] = dsu.ma[u] == e[i].a && dsu.mb[u] == e[i].b && u == v;
      while (opt--) dsu.undo();
    }
    if (r == m+q) break;
  }
  for (int i = 1; i <= q; ++i) {
    puts(res[i] ? "Yes" : "No");
  }
  return 0;
}