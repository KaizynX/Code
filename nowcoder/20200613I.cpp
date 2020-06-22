/*
 * @Author: Kaizyn
 * @Date: 2020-06-13 16:35:13
 * @LastEditTime: 2020-06-13 16:51:41
 */ 
#include <bits/stdc++.h>

// #define DEBUG

using namespace std;

typedef pair<int, int> pii;
const int INF = 0x3f3f3f3f;
const int N = 1e5+7;

int n, m;
long long d[N];
vector<pii> e[N];
priority_queue<pair<long long, int>> q;

inline void solve() {
  cin >> n >> m;
  for (int i = 1, u, v, w; i < n; ++i) {
    cin >> u >> v >> w;
    w *= 2;
    e[u].emplace_back(v, w);
    e[v].emplace_back(u, w);
  }
  memset(d+1, -1, sizeof(long long)*n);
  for (int i = 1, x; i <= m; ++i) {
    cin >> x;
    d[x] = 0;
    q.push({0, x});
  }
  while (q.size()) {
    int u = q.top().second;
    long long dis = -q.top().first;
    q.pop();
    if (dis > d[u]) continue;
    for (const pii &edge : e[u]) {
      int v = edge.first;
      int w = edge.second;
      if (d[v] == -1 || d[v] > d[u]+w) {
        d[v] = d[u]+w;
        q.push({-d[v], v});
      }
    }
  }
  #ifdef DEBUG
  for (int i = 1; i <= n; ++i) {
    cout << d[i] << " \n"[i==n];
  }
  #endif
  long long res = 0;
  for (int u = 1; u <= n; ++u) {
    for (const pii &edge : e[u]) {
      int v = edge.first;
      int w = edge.second;
      res = max(res, (d[u]+d[v]+w)/2);
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