/*
 * @Author: Kaizyn
 * @Date: 2021-07-27 18:48:30
 * @LastEditTime: 2021-07-27 19:00:30
 */
#include <bits/stdc++.h>

// #define DEBUG

using namespace std;

const double eps = 1e-7;
const double PI = acos(-1);
typedef pair<int, int> pii;
typedef long long ll;
const int MOD = 998244353; // 1e9+7;
const int INF = 0x3f3f3f3f;
// const ll INF = 1e18;
const int N = 2e5+7;

int n, m, S;
int dis[N];
vector<int> e[N];

void bfs(int S = 1) {
  static set<int> st[2];
  static queue<int> q;
  memset(dis+1, -1, sizeof(int)*n);
  dis[S] = 0;
  q.push(S);
  st[0].clear(); st[1].clear();
  for (int i = 1; i <= n; ++i) if (i != S) st[0].insert(i);
  while (q.size()) {
    int u = q.front();
    q.pop();
    for (int v : e[u]) if (st[0].count(v)) {
      st[0].erase(v);
      st[1].insert(v);
    }
    for (auto v : st[0]) if (dis[v] == -1) {
      dis[v] = dis[u]+1;
      q.push(v);
    }
    swap(st[0], st[1]);
    st[1].clear();
  }
}

inline void solve() {
  cin >> n >> m;
  for (int i = 1, u, v; i <= m; ++i) {
    cin >> u >> v;
    e[u].emplace_back(v);
    e[v].emplace_back(u);
  }
  cin >> S;
  bfs(S);
  for (int i = 1; i <= n; ++i) if (i != S) {
    cout << dis[i] << " \n"[i==n];
  }
}

signed main() {
#ifdef ONLINE_JUDGE
  ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
#endif
  int T = 1;
  cin >> T; // scanf("%d", &T);
  for (int t = 1; t <= T; ++t) {
    solve();
    for (int i = 1; i <= n; ++i) e[i].clear();
  }
  return 0;
}