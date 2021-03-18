/*
 * @Author: Kaizyn
 * @Date: 2021-03-16 21:57:02
 * @LastEditTime: 2021-03-17 15:16:13
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
  vector<int> fa, rk;
  stack<pair<vector<int>::iterator, int>> stk;
  void init(int n) {
    stk = stack<pair<vector<int>::iterator, int>>();
    fa = rk = vector<int>(n+1, 0);
    iota(fa.begin(), fa.end(), 0);
  }
  int get(int s) { return s == fa[s] ? s : get(fa[s]); }
  int operator [](int i) { return get(i); }
  int merge(int x, int y) {
    x = get(x); y = get(y);
    if (x == y) return 0;
    if (rk[x] > rk[y]) swap(x, y);
    stk.push({fa.begin()+x, fa[x]});
    fa[x] = y;
    return rk[x] == rk[y] ? stk.push({rk.begin()+y, rk[y]++}), 2 : 1;
  }
  bool undo() {
    if (stk.empty()) return false;
    *stk.top().first = stk.top().second;
    stk.pop();
    return true;
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
  for (int l = 1, r = sqr, mxa, mxb; l <= m+q; l += sqr, r = min(l+sqr, m+q)) {
    dsu.init(n);
    mxa = mxb = 0;
    sort(e+1, e+l, [&](Node &nl, Node &nr) {
      return pii{nl.b, nl.a} < pii{nr.b, nr.a};
    });
    sort(e+l, e+r+1, [&](Node &nl, Node &nr) {
      return pii{nl.b, nl.a} < pii{nr.b, nr.a};
    });
    for (int i = l, j = 1, opt, tma, tmb; i <= r; ++i) if (e[i].id) {
      while (j < l && e[j].b <= e[i].b) {
        if (!e[j].id) {
          dsu.merge(e[j].u, e[j].v);
          mxa = max(mxa, e[j].a);
          mxb = max(mxb, e[j].b);
        }
        ++j;
      }
      tma = mxa;
      tmb = mxb;
      opt = 0;
      for (int k = l; k <= r; ++k) {
        if (!e[k].id &&  e[k].a <= e[i].a && e[k].b <= e[i].b) {
          opt += dsu.merge(e[k].u, e[k].v);
          tma = max(tma, e[k].a);
          tmb = max(tmb, e[k].b);
        }
      }
      res[e[i].id] = tma == e[i].a && tmb == e[i].b && dsu[e[i].u] == dsu[e[i].v];
      while (opt--) dsu.undo();
    }
    if (r == m+q) break;
  }
  for (int i = 1; i <= q; ++i) {
    puts(res[i] ? "Yes" : "No");
  }
  return 0;
}