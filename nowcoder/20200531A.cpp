/*
 * @Author: Kaizyn
 * @Date: 2020-05-31 14:48:35
 * @LastEditTime: 2020-05-31 15:33:23
 */ 
#include <bits/stdc++.h>

// #define DEBUG

using namespace std;

const double eps = 1e-7;
const double PI = acos(-1);
typedef pair<int, int> pii;
const int MOD = 998244353;
const int INF = 0x3f3f3f3f;
const int N = 1e6+7;

int n, res;
int c[N];
vector<pii> e[N];
vector<int> dp[N];
multiset<int> st[N];

int dfs1(const int &u) {
  // multiset<int>().swap(st[u]);
  for (int i = 0; i < (int)e[u].size(); ++i) {
    int v = e[u][i].first, w = e[u][i].second;
    dp[u][i] = dfs1(v)+w;
    st[u].insert(dp[u][i]);
    if (st[u].size() > 2) st[u].erase(st[u].begin());
  }
  if (!st[u].size()) return c[u];
  else return max(*(--st[u].end()), c[u]);
}

void dfs2(const int &u, const int &val) {
  multiset<int>().swap(st[u]);
  if (u != 1) st[u].insert(val);
  for (auto &v : dp[u]) {
    st[u].insert(v);
    if (st[u].size() > 2) st[u].erase(st[u].begin());
  }
  for (int i = 0; i < (int)e[u].size(); ++i) {
    int v = e[u][i].first, w = e[u][i].second;
    int nexv = *(--st[u].end());
    if (dp[u][i] == nexv) {
      if(st[u].size() == 1) nexv = c[u];
      else nexv = *st[u].begin();
    }
    nexv = max(nexv, c[u]);
    dfs2(v, nexv+w);
  }
  res = max(res, c[u]+*(--st[u].end()));
}

inline void solve() {
  cin >> n;
  for (int i = 2, a, b; i <= n; ++i) {
    cin >> a >> b;
    e[a].emplace_back(i, b);
  }
  for (int i = 1; i <= n; ++i) {
    cin >> c[i];
    vector<int>(e[i].size(), 0).swap(dp[i]);
  }
  res = -INF;
  dfs1(1);
  dfs2(1, 0);
  cout << res << endl;
  for (int i = 1; i <= n; ++i) {
    vector<pii>().swap(e[i]);
    multiset<int>().swap(st[i]);
  }
}

signed main() {
  ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
  int T = 1;
  cin >> T;
  for (int t = 1; t <= T; ++t) {
    solve();
  }
  return 0;
}