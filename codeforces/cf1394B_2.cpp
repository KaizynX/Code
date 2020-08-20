/*
 * @Author: Kaizyn
 * @Date: 2020-08-12 22:31:58
 * @LastEditTime: 2020-08-14 13:00:58
 */
#include <bits/stdc++.h>

// #define DEBUG

using namespace std;

typedef pair<int, int> pii;
const int N = 2e5+7;
const int K = 10;

int n, m, k, res;
int indeg[N];
vector<pii> e[N];
vector<int> otdeg[K];

void dfs(const int &d) {
  for (int c = 0; c < d; ++c) {
    int flag = 1;
    for (const int &u : otdeg[d]) {
      int v = e[u][c].second;
      if (++indeg[v] > 1) flag = 0;
    }
    if (flag) d == k ? void(++res) : dfs(d+1);
    for (const int &u : otdeg[d]) {
      int v = e[u][c].second;
      --indeg[v];
    }
  }
}

signed main() {
  scanf("%d %d %d", &n, &m, &k);
  for (int i = 1, u, v, w; i <= m; ++i) {
    scanf("%d %d %d", &u, &v, &w);
    e[u].emplace_back(w, v);
  }
  for (int i = 1; i <= n; ++i) {
    sort(e[i].begin(), e[i].end());
    assert((int)e[i].size() <= k);
    otdeg[e[i].size()].emplace_back(i);
  }
  dfs(1);
  printf("%d\n", res);
  return 0;
}