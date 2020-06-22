/*
 * @Author: Kaizyn
 * @Date: 2020-06-22 16:16:44
 * @LastEditTime: 2020-06-22 21:18:33
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

int n, m;
int deg[N], dep[N];
vector<int> e[N], res;
queue<int> q;

inline void solve() {
  cin >> n >> m;
  for (int i = 1; i <= n; ++i) e[i].clear();
  for (int i = 1, u, v; i <= m; ++i) {
    cin >> u >> v;
    if (e[u].size() && e[u].back() == v) continue;
    e[u].emplace_back(v);
    ++deg[v];
  }
  for (int i = 1; i <= n; ++i) {
    if (deg[i] == 0) {
      q.push(i);
      dep[i] = 0;
    } else {
      dep[i] = -1;
    }
  }
  res.clear();
  while (q.size()) {
    int u = q.front();
    q.pop();
    if (dep[u] == 2) res.emplace_back(u);
    for (const int &v : e[u]) {
      if (--deg[v] == 0) q.push(v);
      dep[v] = max(dep[v], (dep[u]+1)%3);
    }
  }
  cout << res.size() << endl;
  for (const int &i : res) cout << i << " ";
  cout << endl;
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