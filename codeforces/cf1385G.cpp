/*
 * @Author: Kaizyn
 * @Date: 2020-07-17 22:48:35
 * @LastEditTime: 2020-07-17 23:01:02
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

int n;
int a[2][N], res[N];
queue<int> q;
vector<int> p[2][N];

inline void erase(const int &i, const int &v, const int &k) {
  for (auto it = p[i][v].begin(); it != p[i][v].end(); ++it) {
    if (*it == k) {
      p[i][v].erase(it);
      break;
    }
  }
}

inline void solve() {
  cin >> n;
  for (int i = 0; i < 2; ++i) {
    for (int j = 1; j <= n; ++j) {
      cin >> a[i][j];
      p[i][a[i][j]].emplace_back(j);
    }
  }
  for (int i = 1; i <= n; ++i) {
    if (p[0][i].size()+p[1][i].size() != 2) {
      return cout << -1 << endl, void();
    }
    res[i] = 0;
  }
  for (int i = 1; i <= n; ++i) {
    if (p[0][i].size() == 2) q.push(p[0][i].front());
    if (p[1][i].size() == 2) q.push(p[1][i].front());
    while (q.size()) {
      int u = q.front();
      q.pop();
      res[u] ^= 1;
      erase(0, a[0][u], u);
      erase(1, a[1][u], u);
      swap(a[0][u], a[1][u]);
      p[0][a[0][u]].emplace_back(u);
      p[1][a[1][u]].emplace_back(u);
      if (p[0][a[0][u]].size() == 2) q.push(p[0][a[0][u]].front());
    }
  }
  int cnt = 0;
  for (int i = 1; i <= n; ++i) cnt += res[i];
  cout << cnt << endl;
  for (int i = 1; i <= n; ++i) if (res[i]) cout << i << " ";
  cout << endl;

  for (int i = 0; i < 2; ++i) {
    for (int j = 1; j <= n; ++j) {
      p[i][j].clear();
    }
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