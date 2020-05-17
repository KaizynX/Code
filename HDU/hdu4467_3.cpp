/*
 * @Author: Kaizyn
 * @Date: 2020-05-08 23:47:23
 * @LastEditTime: 2020-05-09 12:42:13
 */
#include <bits/stdc++.h>

// #define DEBUG

using namespace std;

const int N = 1e5+7;
typedef pair<int, long long> pil;

int n, m, q;
int col[N];
vector<pil> heavy[N];
map<int, long long> e[N];
long long hw[N][2], lw[N][2], res[2][2];

inline void update(const int &u) {
  int &c = col[u], v;
  long long w;
  hw[u][0] = hw[u][1] = 0;
  for (const pil &p : heavy[u]) {
    v = p.first; w = p.second;
    hw[u][col[v]] += w;
    lw[v][c] -= w;
    lw[v][c^1] += w;
  }
  res[c][0] -= lw[u][0]+hw[u][0];
  res[c][1] -= lw[u][1]+hw[u][1];
  c ^= 1;
  res[c][0] += lw[u][0]+hw[u][0];
  res[c][1] += lw[u][1]+hw[u][1];
}

inline void solve() {
  static char ask[10];

  for (int i = 1; i <= n; ++i) scanf("%d", col+i);
  for (int i = 1, u, v, w; i <= m; ++i) {
    scanf("%d %d %d", &u, &v, &w);
    e[u][v] += w;
    e[v][u] += w;
    res[col[u]][col[v]] += w;
  }
  for (int i = 1, v; i <= n; ++i) {
    for (const pil &p : e[i]) {
      v = p.first;
      if (e[i].size() < e[v].size() ||
          (e[i].size() == e[v].size() && i < v)) {
        heavy[i].emplace_back(p);
        // hw[i][col[v]] += p.second;
      } else {
        lw[i][col[v]] += p.second;
      }
    }
  }
  scanf("%d", &q);
  for (int i = 1, l, r; i <= q; ++i) {
    scanf("%s", ask);
    if (ask[0] == 'A') {
      scanf("%d %d", &l, &r);
      if (l == r) printf("%lld\n", res[l][r]);
      else printf("%lld\n", res[l][r]+res[r][l]);
    } else {
      scanf("%d", &l);
      update(l);
    }
  }

  memset(res, 0, sizeof res);
  for (int i = 1; i <= n; ++i) {
    hw[i][0] = hw[i][1] = 0;
    lw[i][0] = lw[i][1] = 0;
    e[i].clear();
    vector<pil>().swap(heavy[i]);
  }
}

signed main() {
  int T = 0;
  while (scanf("%d %d", &n, &m) == 2) {
    printf("Case %d:\n", ++T);
    solve();
  }
  return 0;
}