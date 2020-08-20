/*
 * @Author: Kaizyn
 * @Date: 2020-08-12 22:31:58
 * @LastEditTime: 2020-08-14 13:10:09
 */
#include <bits/stdc++.h>

#define DEBUG

using namespace std;

typedef pair<int, int> pii;
const int N = 2e5+7;
const int K = 10;

#ifdef DEBUG
int cnt;
#endif
int n, m, k, res;
int indeg[N];
vector<pii> e[N];
vector<int> otdeg[K];
vector<int> ee[K][K];

void dfs(const int &d) {
  for (int c = 0; c < d; ++c) {
    int flag = 1;
    for (const int &i : ee[d][c]) {
      if (++indeg[i] > 1) flag = 0;
#ifdef DEBUG
      ++cnt;
#endif
    }
    if (flag) d == k ? void(++res) : dfs(d+1);
    for (const int &i : ee[d][c]) {
      --indeg[i];
#ifdef DEBUG
      ++cnt;
#endif
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
  for (int i = 1; i <= k; ++i) {
    for (const int &u : otdeg[i]) {
      for (int c = 0; c < i; ++c) {
        ee[i][c].emplace_back(e[u][c].second);
      }
    }
  }
  dfs(1);
  printf("%d\n", res);
#ifdef DEBUG
  fprintf(stderr, "%d\n", cnt);
#endif
  return 0;
}