/*
 * @Author: Kaizyn
 * @Date: 2020-06-24 11:04:15
 * @LastEditTime: 2020-06-24 11:18:08
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
int w[N], s[N], vis[N];
vector<pii> e[N];
vector<int> res;
queue<int> q;

inline void solve() {
  cin >> n >> m;
  for (int i = 1; i <= n; ++i) cin >> w[i];
  for (int i = 1, x, y; i <= m; ++i) {
    cin >> x >> y;
    e[x].emplace_back(i, y);
    e[y].emplace_back(i, x);
    ++s[x]; ++s[y];
  }
  for (int i = 1; i <= n; ++i) {
    if (s[i] <= w[i]) q.push(i), s[i] = INF;
  }
  while (q.size()) {
    int u = q.front();
    q.pop();
    for (const pii &p : e[u]) {
      int i = p.first, v = p.second;
      if (!vis[i]) {
        res.emplace_back(i);
        vis[i] = 1;
      }
      if (--s[v] <= w[v]) {
        q.push(v);
        s[v] = INF;
      }
    }
  }
  if ((int)res.size() < m) return cout << "DEAD" << endl, void();
  cout << "ALIVE" << endl;
  reverse(res.begin(), res.end());
  for (const int &i : res) cout << i << " ";
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