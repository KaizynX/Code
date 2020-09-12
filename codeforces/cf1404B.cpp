/*
 * @Author: Kaizyn
 * @Date: 2020-09-06 22:29:10
 * @LastEditTime: 2020-09-06 23:07:33
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

int n, a, b, da, db;
int dis[N];
vector<int> e[N];
queue<int> q;

void bfs(int s) {
  memset(dis+1, -1, sizeof(int)*n);
  dis[s] = 0;
  q.push(s);
  while (q.size()) {
    int u = q.front();
    q.pop();
    for (const int &v : e[u]) {
      if (~dis[v]) continue;
      dis[v] = dis[u]+1;
      q.push(v);
    }
  }
}

inline bool solve() {
  cin >> n >> a >> b >> da >> db;
  for (int i = 1, u, v; i < n; ++i) {
    cin >> u >> v;
    e[u].emplace_back(v);
    e[v].emplace_back(u);
  }
  if (da*2+1 > db) return true;
  // db >= da*2+1
  bfs(a);
  if (dis[b] <= da) return true;
  for (int i = 1; i <= n; ++i) {
    if (dis[i] > dis[b]) b = i;
  }
  bfs(b);
  for (int i = 1; i <= n; ++i) {
    if (dis[i] >= 2*da+1) return false;
  }
  return true;
}

signed main() {
  ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
  int T = 1;
  cin >> T;
  for (int t = 1; t <= T; ++t) {
    cout << (solve() ? "Alice" : "Bob") << endl;
    for (int i = 1; i <= n; ++i) {
      e[i].clear();
    }
  }
  return 0;
}