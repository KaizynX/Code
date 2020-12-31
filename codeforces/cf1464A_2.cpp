/*
 * @Author: Kaizyn
 * @Date: 2020-12-21 14:16:17
 * @LastEditTime: 2020-12-21 14:32:42
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
const int N = 1e5+7;

int n, m;
int x[N], y[N], vis[N*2];
vector<int> e[N*2];

void add(int x, int y) {
  e[x].emplace_back(y);
  e[y].emplace_back(x);
}

int dfs(int x, int last) {
  if (vis[x]) return 1;
  vis[x] = 1;
  int flag = 0;
  for (int &y : e[x]) {
    if (y == last) continue;
    flag |= dfs(y, x);
  }
  return flag;
}

inline void solve() {
  cin >> n >> m;
  for (int i = 1; i <= m+n; ++i) {
    vis[i] = 0;
    e[i] = vector<int>();
  }
  int res = 0;
  for (int i = 1; i <= m; ++i) {
    cin >> x[i] >> y[i];
    if (x[i] == y[i]) continue;
    ++res;
    add(i, x[i]+m);
    add(i, y[i]+m);
  }
  for (int i = 1; i <= m; ++i) {
    if (vis[i]) continue;
    res += dfs(i, 0);
  }
  cout << res << endl;
}

signed main() {
#ifndef DEBUG
  ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
#endif
  int T = 1;
  cin >> T;
  for (int t = 1; t <= T; ++t) {
    solve();
  }
  return 0;
}