/*
 * @Author: Kaizyn
 * @Date: 2020-12-20 22:48:37
 * @LastEditTime: 2020-12-21 14:16:06
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
int x[N], y[N], vis[N];
int cx[N], cy[N];
vector<int> e[N];

void add(int x, int y) {
  if (!x || !y) return;
  e[x].emplace_back(y);
  e[y].emplace_back(x);
}

bool dfs(int x, int last) {
  if (vis[x]) return true;
  vis[x] = 1;
  for (int &y : e[x]) if (y != last) return dfs(y, x);
  return false;
}

inline void solve() {
  cin >> n >> m;
  for (int i = 1; i <= n; ++i) {
    cx[i] = cy[i] = 0;
  }
  int res = 0;
  for (int i = 1; i <= m; ++i) {
    e[i] = vector<int>();
    cin >> x[i] >> y[i];
    add(cy[x[i]], i);
    add(cx[y[i]], i);
    cx[x[i]] = i;
    cy[y[i]] = i;
    res += x[i] != y[i];
    vis[i] = x[i] == y[i];
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