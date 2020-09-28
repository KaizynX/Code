/*
 * @Author: Kaizyn
 * @Date: 2020-09-27 23:03:40
 * @LastEditTime: 2020-09-27 23:21:33
 */
#include <bits/stdc++.h>

// #define DEBUG

using namespace std;

const double eps = 1e-7;
const double PI = acos(-1);
typedef pair<int, int> pii;
const int MOD = 998244353;
const int INF = 0x3f3f3f3f;
const int N = 3e5+7;

int n;
int a[N], res[N];
vector<int> p[N];

void update(int &x, int y) {
  if (x == -1 || x > y) x = y;
}

inline void solve() {
  cin >> n;
  memset(res+1, -1, sizeof(int)*n);
  for (int i = 1; i <= n; ++i) p[i].emplace_back(0);
  for (int i = 1; i <= n; ++i) {
    cin >> a[i];
    p[a[i]].emplace_back(i);
  }
  for (int i = 1; i <= n; ++i) p[i].emplace_back(n+1);
  for (int i = 1; i <= n; ++i) {
    int d = 0;
    for (int j = 1; j < (int)p[i].size(); ++j) {
      d = max(d, p[i][j]-p[i][j-1]);
    }
    update(res[d], i);
  }
  for (int i = 2; i <= n; ++i) {
    if (~res[i-1]) update(res[i], res[i-1]);
  }
  for (int i = 1; i <= n; ++i) {
    cout << res[i] << " \n"[i==n];
  }
}

signed main() {
  ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
  int T = 1;
  cin >> T;
  for (int t = 1; t <= T; ++t) {
    solve();
    for (int i = 1; i <= n; ++i) {
      p[i].clear();
    }
  }
  return 0;
}