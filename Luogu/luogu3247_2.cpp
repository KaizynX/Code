/*
 * @Author: Kaizyn
 * @Date: 2021-03-16 10:46:27
 * @LastEditTime: 2021-03-16 11:20:22
 */
#include <bits/stdc++.h>

// #define DEBUG

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
  stack<pair<int, int>> stk;
  void init(int n) {
    stk.clear();
    fa = rk = vector<int>(n+1, 0);
    iota(fa.begin(), fa.end(), 0);
  }
  int get(int s) { return s == fa[s] ? s : get(fa[s]); }
  int operator [](int i) { return get(i); }
  int merge(int x, int y) { // merge x to y
    x = get(x); y = get(y);
    if (x == y) return 0;
    if (rk[x] < rk[y]) {
      stk.push({fa+x, fa[x]});
      fa[x] = y;
      return 1;
    } else {
      stk.push({fa+y, fa[y]});
      fa[y] = x;
      if (rk[x] == rk[y]) {
        stk.push({rk+x, rk[x]});
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
set<pii> vis;
Node e[M<<1];
DSU dsu;

signed main() {
  scanf("%d%d", &n, &m);
  for (int i = 1, u, v, a, b; i <= m; ++i) {
    scanf("%d%d%d%d", &e[i].u, &e[i].v, &e[i].a, &e[i].b);
    vis.insert({e[i].a, e[i].b});
  }
  scanf("%d", &k);
  for (int i = m+1, u, v, a, b; i <= m+k; ++i) {
    scanf("%d%d%d%d", &e[i].u, &e[i].v, &e[i].a, &e[i].b);
    e[i].id = i-m;
  }
  sort(e+1, e+m+k+1, [&](Node &nl, Node &nr) {
    return nl.a < nr.a;
  });
  int sqr = sqrt(m+k);
  for (int _ = sqr, l, r; _ <= m+k; _ += sqr) {
    l = _-sqr+1;
    r = min(_, m+k);
    for (int i = l; i <= r; ++i) e[i].id = -e[i].id;
    sort(e+1, e+r+1, [&](Node &nl, Node &nr) {
      return nl.b < nr.b;
    });
    dsu.init(n);
    for (int i = 1; i <= r; ++i) {
      ;
    }
    for (int i = 1; i <= r; ++i) if (e[i].id < 0) e[i].id = -e[i].id;
  }
  for (int i = 1; i <= k; ++i) {
    puts(res[i] ? "Yes" : "No");
  }
  return 0;
}