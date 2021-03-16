/*
 * @Author: Kaizyn
 * @Date: 2021-03-12 23:03:50
 * @LastEditTime: 2021-03-15 23:11:48
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
  vector<int> fa;
  void init(int n) { fa = vector<int>(n+1); iota(fa.begin(), fa.end(), 0); }
  int get(int s) { return s == fa[s] ? s : fa[s] = get(fa[s]); }
  int& operator [] (int i) { return fa[get(i)]; }
  bool merge(int x, int y) { // merge x to y
    x = get(x); y = get(y);
    return x == y ? false : fa[x] = y, true;
  }
};

struct Node {
  int u, v, id;
};

int n, m, k;
int res[M];
vector<pii> e[30][30];
vector<Node> q[30][30];
DSU dsu;

signed main() {
  scanf("%d%d", &n, &m);
  for (int i = 1, u, v, a, b; i <= m; ++i) {
    scanf("%d%d%d%d", &u, &v, &a, &b);
    e[a][b].emplace_back(pii{u, v});
  }
  scanf("%d", &k);
  for (int i = 1, u, v, a, b; i <= k; ++i) {
    scanf("%d%d%d%d", &u, &v, &a, &b);
    q[a][b].emplace_back(Node{u, v, i});
  }
  for (int i = 0; i < 30; ++i) {
    dsu.init(n);
    for (int j = 0; j < 20; ++j) {
      int flag = 0;
      for (int l = 0; l <= i; ++l) {
        for (auto p : e[l][j]) dsu.merge(p.first, p.second);
        flag |= e[l][j].size();
      }
      for (auto nd : q[i][j]) {
        res[nd.id] = flag && dsu[nd.u] == dsu[nd.v];
      }
    }
  }
  for (int i = 1; i <= k; ++i) {
    puts(res[i] ? "Yes" : "No");
  }
  return 0;
}