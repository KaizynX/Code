/*
 * @Author: Kaizyn
 * @Date: 2020-07-23 15:07:49
 * @LastEditTime: 2020-07-23 15:18:13
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

int n, m;
long long res;
int b[N], rk[N], vis[N];
vector<int> e[N];
queue<int> q;

void bfs(const int &s) {
  q.push(s);
  vis[s] = 1;
  while (q.size()) {
    int u = q.front();
    long long tot = 0;
    q.pop();
    for (const int &v : e[u]) {
      if (vis[v]) tot += b[v];
      else q.push(v), vis[v] = 1;
    }
    res += max(0ll, b[u]-tot);
  }
}

inline void solve() {
  cin >> n >> m;
  for (int i = 1; i <= n; ++i) {
    cin >> b[i];
    rk[i] = i;
  }
  for (int i = 1, u, v; i <= m; ++i) {
    cin >> u >> v;
    e[u].emplace_back(v);
    e[v].emplace_back(u);
  }
  sort(rk+1, rk+n+1, [](int x, int y) { return b[x] > b[y]; });
  res = 0;
  for (int i = 1; i <= n; ++i) {
    if (!vis[rk[i]]) {
      bfs(rk[i]);
    }
  }
  cout << res << endl;
  for (int i = 1; i <= n; ++i) {
    vector<int>().swap(e[i]);
    vis[i] = 0;
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