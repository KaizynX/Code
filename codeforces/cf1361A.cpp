/*
 * @Author: Kaizyn
 * @Date: 2020-06-04 22:31:32
 * @LastEditTime: 2020-06-04 22:58:18
 */ 
#include <bits/stdc++.h>

// #define DEBUG

using namespace std;

const double eps = 1e-7;
const double PI = acos(-1);
typedef pair<int, int> pii;
const int MOD = 998244353;
const int INF = 0x3f3f3f3f;
const int N = 5e5+7;

int n, m;
vector<int> e[N];
vector<int> res;
int t[N], c[N], vis[N], inq[N];
queue<int> q;

inline void solve() {
  cin >> n >> m;
  for (int i = 1, u, v; i <= m; ++i) {
    cin >> u >> v;
    e[u].emplace_back(v);
    e[v].emplace_back(u);
  }
  for (int i = 1; i <= n; ++i) {
    cin >> t[i];
    if (t[i] == 1) {
      c[i] = 1;
      q.push(i);
      inq[i] = 1;
    }
  }
  while (q.size()) {
    int u = q.front();
    q.pop();
    if (c[u] != t[u]) return cout << -1 << endl, void();
    vis[u] = 1;
    res.emplace_back(u);
    for (const int &v : e[u]) if (!vis[v]) {
      c[v] = max(c[v], c[u]+1);
      if (!inq[v] && t[v] == t[u]+1) q.push(v), inq[v] = 1;
    }
  }
  for (int i = 1; i <= n; ++i) {
    if (c[i] != t[i]) return cout << -1 << endl, void();
  }
  for (int &i : res) cout << i << " ";
  cout << endl;
}

signed main() {
  ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
  int T = 1;
  // cin >> T;
  for (int t = 1; t <= T; ++t) {
    solve();
  }
  return 0;
}