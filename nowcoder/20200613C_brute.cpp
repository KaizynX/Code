/*
 * @Author: Kaizyn
 * @Date: 2020-06-13 17:45:29
 * @LastEditTime: 2020-06-13 17:49:08
 */ 
#include <bits/stdc++.h>

// #define DEBUG

using namespace std;

const double eps = 1e-7;
const double PI = acos(-1);
typedef pair<int, int> pii;
const int MOD = 998244353;
const int INF = 0x3f3f3f3f;
const int N = 4e4+7;

int n, m;
int deg[N], a[N];
bitset<N> b[N];
vector<int> e[N];
queue<int> q;

inline void solve() {
  cin >> n >> m;
  for (int i = 1, u, v; i <= m; ++i) {
    cin >> u >> v;
    e[u].emplace_back(v);
    ++deg[v];
  }
  int res = 0;
  q.push(1);
  while (q.size()) {
    int u = q.front();
    q.pop();
    if (u == 1 || b[u].count()&1) b[u][u] = 1, ++res;
    for (const int &v : e[u]) {
      b[v] |= b[u];
      if (--deg[v] == 0) q.push(v);
    }
  }
  cout << res << endl;
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