/*
 * @Author: Kaizyn
 * @Date: 2021-01-08 09:15:55
 * @LastEditTime: 2021-01-09 15:16:32
 */
#include <bits/stdc++.h>

// #define DEBUG

using namespace std;

const double eps = 1e-7;
const double PI = acos(-1);
typedef pair<int, int> pii;
typedef long long ll;
const int MOD = 998244353;
const int INF = 0x3f3f3f3f;
// const ll INF = 1e18;
const int N = 3e5+7;

int n, m;
int vis[N];
vector<int> e[N];
queue<int> q;

inline void solve() {
  cin >> n >> m;
  for (int i = 1, u, v; i <= m; ++i) {
    cin >> u >> v;
    e[u].emplace_back(v);
    e[v].emplace_back(u);
  }
  vis[1] = 1;
  q.push(1);
  while (q.size()) {
    int u = q.front();
    q.pop();
    for (int &v : e[u]) {
      if (!vis[v]) {
        q.push(v);
        vis[v] = -vis[u];
      }
      if (vis[u] == 1) vis[v] = -1;
    }
  }
  vector<int> res;
  for (int i = 1; i <= n; ++i) {
    if (!vis[i]) {
      cout << "NO" << endl;
      return;
    } else if (vis[i] == 1) {
      res.emplace_back(i);
    }
  }
  cout << "YES" << endl;
  cout << res.size() << endl;
  for (int &i : res) cout <<i << " ";
  cout << endl;
}

signed main() {
#ifdef ONLINE_JUDGE
  ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
#endif
  int T = 1;
  cin >> T;
  for (int t = 1; t <= T; ++t) {
    solve();
    for (int i = 1; i <= n; ++i) {
      e[i] = vector<int>();
      vis[i] = 0;
    }
  }
  return 0;
}