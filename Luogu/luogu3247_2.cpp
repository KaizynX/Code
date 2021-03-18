/*
 * @Author: Kaizyn
 * @Date: 2021-03-16 10:46:27
 * @LastEditTime: 2021-03-16 21:48:48
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
  int merge(int x, int y) { // merge x to y
    x = get(x); y = get(y);
    if (x == y) return 0;
    if (rk[x] < rk[y]) {
      stk.push({fa.begin()+x, fa[x]});
      fa[x] = y;
      return 1;
    } else {
      stk.push({fa.begin()+y, fa[y]});
      fa[y] = x;
      if (rk[x] == rk[y]) {
        stk.push({rk.begin()+x, rk[x]});
        ++rk[x];
        return 2;
      }
      return 1;
    }
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

int n, m, k;
int res[M];
Node e[M<<1];
vector<Node> vec;
DSU dsu;

signed main() {
  scanf("%d%d", &n, &m);
  for (int i = 1; i <= m; ++i) {
    scanf("%d%d%d%d", &e[i].u, &e[i].v, &e[i].a, &e[i].b);
  }
  scanf("%d", &k);
  for (int i = m+1; i <= m+k; ++i) {
    scanf("%d%d%d%d", &e[i].u, &e[i].v, &e[i].a, &e[i].b);
    e[i].id = i-m;
  }
  sort(e+1, e+m+k+1, [&](Node &nl, Node &nr) {
    return pii{nl.a, nl.b} < pii{nr.a, nr.b};
  });
  #ifdef DEBUG
  for (int i = 1; i <= m+k; ++i) {
    printf("%d:%d %d %d %d %d\n", i, e[i].u, e[i].v, e[i].a, e[i].b, e[i].id);
  }
  #endif
  int sqr = sqrt(m+k);
  for (int _ = sqr, l, r, mxa, mxb; _; _ += sqr) {
    l = _-sqr+1;
    r = min(_, m+k);
    dsu.init(n);
    vec.clear();
    mxa = mxb = 0;
    for (int i = l; i <= r; ++i) {
      if (e[i].id) e[i].id = -e[i].id;
      else vec.emplace_back(e[i]);
    }
    sort(e+1, e+r+1, [&](Node &nl, Node &nr) {
      if (pii{nl.b, nl.a} != pii{nr.b, nr.a}) return pii{nl.b, nl.a} < pii{nr.b, nr.a};
      return !nl.id;
    });
    #ifdef DEBUG
    for (int i = 1; i <= r; ++i) {
      printf("%d:%d %d %d %d %d\n", i, e[i].u, e[i].v, e[i].a, e[i].b, e[i].id);
    }
    #endif
    for (int i = 1, opt, tma, tmb; i <= r; ++i) {
      if (!e[i].id) {
        dsu.merge(e[i].u, e[i].v);
        mxa = max(mxa, e[i].a);
        mxb = max(mxb, e[i].b);
      } else if (e[i].id < 0) {
        tma = mxa;
        tmb = mxb;
        opt = 0;
        for (auto &ee : vec) {
          if (ee.a <= e[i].a && ee.b <= e[i].b) {
            opt += dsu.merge(ee.u, ee.v);
            tma = max(tma, ee.a);
            tmb = max(tmb, ee.b);
          }
        }
        res[-e[i].id] = tma == e[i].a && tmb == e[i].b && dsu[e[i].u] == dsu[e[i].v];
        while (opt--) dsu.undo();
      }
    }
    for (int i = 1; i <= r; ++i) if (e[i].id < 0) e[i].id = -e[i].id;
    if (r == m+k) break;
  }
  for (int i = 1; i <= k; ++i) {
    puts(res[i] ? "Yes" : "No");
  }
  return 0;
}