/*
 * @Author: Kaizyn
 * @Date: 2020-09-26 14:17:23
 * @LastEditTime: 2020-09-26 14:44:19
 */
// copy from 2020 Multi-University Training Contest 1 1006
#include <bits/stdc++.h>

// #define DEBUG

using namespace std;

const double eps = 1e-7;
const double PI = acos(-1);
typedef pair<int, int> pii;
const int MOD = 998244353;
const int INF = 0x3f3f3f3f;
const int N = 1e5+7;

int n, m, q, sqr;
int a[N], tag[N], deg[N], eu[N], ev[N];
vector<int> hve[N], lte[N], cnt[N];
// unordered_set<int> st[N];
set<int> st[N];

inline void modify(int u, int x) {
  for (const int &v : hve[u]) { // modify heavy point
    if (a[u] <= deg[v] && --cnt[v][a[u]] == 0) st[v].insert(a[u]);
    if (x <= deg[v] && ++cnt[v][x] == 1) st[v].erase(x);
  }
  a[u] = x;
}

inline void solve() {
  scanf("%d %d", &n, &m);
  for (int i = 1; i <= n; ++i) scanf("%d", a+i);
  for (int i = 1; i <= m; ++i) {
    scanf("%d %d", eu+i, ev+i);
    ++deg[eu[i]];
    ++deg[ev[i]];
  }
  // sqr = sqrt(2*m);
  sqr = 1000;
  for (int i = 1; i <= n; ++i) {
    cnt[i].resize(deg[i]+1, 0);
    tag[i] = deg[i] >= sqr;
  }
  for (int i = 1; i <= m; ++i) {
    if (a[ev[i]] <= deg[eu[i]]) ++cnt[eu[i]][a[ev[i]]];
    if (a[eu[i]] <= deg[ev[i]]) ++cnt[ev[i]][a[eu[i]]];
  }
  for (int i = 1; i <= n; ++i) if (tag[i]) {
    for (int j = 0; j <= deg[i]; ++j) {
      if (cnt[i][j] == 0) st[i].insert(j);
    }
  }
  for (int i = 1; i <= m; ++i) {
    if (tag[eu[i]]) hve[ev[i]].emplace_back(eu[i]);
    else lte[ev[i]].emplace_back(eu[i]);
    if (tag[ev[i]]) hve[eu[i]].emplace_back(ev[i]);
    else lte[eu[i]].emplace_back(ev[i]);
  }
  scanf("%d", &q);
  for (int i = 1, op, u, x; i <= q; ++i) {
    scanf("%d %d", &op, &u);
    if (op == 1) {
      scanf("%d", &x);
      modify(u, x);
    } else {
      int res;
      if (!tag[u]) { // rebuild light point
        for (int j = 0; j <= deg[u]; ++j) cnt[u][j] = 0;
        for (const int &v : hve[u]) if (a[v] <= deg[u]) ++cnt[u][a[v]];
        for (const int &v : lte[u]) if (a[v] <= deg[u]) ++cnt[u][a[v]];
        for (int j = 0; j <= deg[u]; ++j) if (cnt[u][j] == 0) {
          res = j;
          break;
        }
      } else {
        res = *st[u].begin();
      }
      printf("%d\n", res);
      modify(u, res);
    }
  }
  // clear
  for (int i = 1; i <= n; ++i) {
    vector<int>().swap(hve[i]);
    vector<int>().swap(lte[i]);
    vector<int>().swap(cnt[i]);
    st[i].clear();
    deg[i] = 0;
  }
}

signed main() {
  // ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
  int T = 1;
  for (int t = 1; t <= T; ++t) {
    solve();
  }
  return 0;
}