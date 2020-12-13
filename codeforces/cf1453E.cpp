/*
 * @Author: Kaizyn
 * @Date: 2020-12-04 21:52:50
 * @LastEditTime: 2020-12-04 21:58:58
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
vector<int> e[N];

int dfs(int u, int fa) {
  int maxd = 0, mind = INF, cnt = 0;
  for (int &v : e[u]) if (v != fa) {
    ++cnt;
    int d = dfs(v, u);
    maxd = max(maxd, d);
    mind = min(mind, d);
  }
  if (!cnt) return 1;
  if (cnt == 1) {
    res = max(res, mind);
    return mind+1;
  }
  if (u == 1) {
    res = max({res, mind+1, maxd});
    return 0;
  } else {
    res = max({res, maxd+1});
    return mind+1;
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
    for (int i = 1; i <= n; ++i) e[i] = vector<int>();
  }
  return 0;
}