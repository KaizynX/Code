/*
 * @Author: Kaizyn
 * @Date: 2021-03-12 23:03:50
 * @LastEditTime: 2021-03-13 11:14:39
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
  void init(int n) { fa = rk = vector<int>(n+1, 0); iota(fa.begin(), fa.end(), 0); }
  int get(int s) { return s == fa[s] ? s : get(fa[s]); }
  int operator [](int i) { return get(i); }
  bool merge(int x, int y) {
    x = get(x); y = get(y);
    if (x == y) return false;
    if (rk[x] < rk[y]) fa[x] = y;
    else fa[y] = x, rk[x] += rk[x] == rk[y];
    return true;
  }
};

int n, m, k;
pii e[30][30], q[30][30];

signed main() {
  scanf("%d%d", &n, &m);
  for (int i = 1, u, v, a, b; i <= m; ++i) {
    scanf("%d%d%d%d", &u, &v, &a, &b);
    e[a][b].emplace_back(u, v);
  }
  scanf("%d", &k);
  for (int i = 1, u, v, a, b; i <= k; ++i) {
    scanf("%d%d%d%d", &u, &v, &a, &b);
    q[a][b].emplace_back(u, v);
  }
  for (int i = 0; i < 30; ++i) {
    for (int j = 0; j < 20; ++j) {
      ;
    }
  }
  return 0;
}