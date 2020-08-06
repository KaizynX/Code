/*
 * @Author: Kaizyn
 * @Date: 2020-07-21 11:53:48
 * @LastEditTime: 2020-07-21 14:29:00
 */ 
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
vector<int> hve[N], lte[N];
unordered_map<int, int> cnt[N];
// unordered_set<int> st[N];
set<int> st[N];

inline void solve() {
  scanf("%d %d", &n, &m);
  for (int i = 1; i <= n; ++i) scanf("%d", a+i);
  for (int i = 1; i <= m; ++i) {
    scanf("%d %d", eu+i, ev+i);
    ++deg[eu[i]];
    ++deg[ev[i]];
    ++cnt[eu[i]][a[ev[i]]];
    ++cnt[ev[i]][a[eu[i]]];
  }
  sqr = sqrt(2*m);
  for (int i = 1; i <= n; ++i) {
    tag[i] = deg[i] >= sqr;
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
      for (const int &v : hve[u]) { // modify heavy point
        if (--cnt[v][a[u]] == 0 && a[u] <= deg[v]) st[v].insert(a[u]);
        if (++cnt[v][x] == 1 && x <= deg[v]) st[v].erase(x);
      }
      a[u] = x;
    } else {
      if (!tag[u]) { // rebuild light point
        st[u].clear();
        cnt[u].clear();
        for (const int &v : hve[u]) ++cnt[u][a[v]];
        for (const int &v : lte[u]) ++cnt[u][a[v]];
        for (int j = 0; j <= deg[u]; ++j) {
          if (!cnt[u].count(j)) st[u].insert(j);
        }
      }
      printf("%d\n", *st[u].begin());
    }
  }
  // clear
  for (int i = 1; i <= n; ++i) {
    vector<int>().swap(hve[i]);
    vector<int>().swap(lte[i]);
    cnt[i].clear();
    st[i].clear();
    deg[i] = 0;
  }
}

signed main() {
  // ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
  int T = 1;
  scanf("%d", &T);
  for (int t = 1; t <= T; ++t) {
    solve();
  }
  return 0;
}