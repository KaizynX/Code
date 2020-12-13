/*
 * @Author: Kaizyn
 * @Date: 2020-12-04 22:11:44
 * @LastEditTime: 2020-12-04 22:14:48
 */
#include <bits/stdc++.h>

// #define DEBUG

using namespace std;

const double eps = 1e-7;
const double PI = acos(-1);
typedef pair<int, int> pii;
const int MOD = 998244353;
const int INF = 0x3f3f3f3f;
const int N = 2e5+7;

int n, res;
vector<int> e[N], d[N];

int dfs(int u, int fa) {
  for (int &v : e[u]) if (v != fa) {
    d[u].emplace_back(dfs(v, u));
  }
  sort(d[u].begin(), d[u].end());
  if (d[u].empty()) return 1;
  if (d[u].size() == 1) {
    res = max(res, d[u].front());
    return d[u].front()+1;
  }
  if (u == 1) {
    res = max({res, d[u][d[u].size()-2]+1, d[u].back()});
    return 0;
  } else {
    res = max({res, d[u].back()+1});
    return d[u].front()+1;
  }
}

inline void solve() {
  cin >> n;
  for (int i = 1, u, v; i < n; ++i) {
    cin >> u >> v;
    e[u].emplace_back(v);
    e[v].emplace_back(u);
  }
  res = 0;
  dfs(1, 0);
  cout << res << endl;
}

signed main() {
  ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
  int T = 1;
  cin >> T;
  for (int t = 1; t <= T; ++t) {
    solve();
    for (int i = 1; i <= n; ++i) {
      e[i] = vector<int>();
      d[i] = vector<int>();
    }
  }
  return 0;
}