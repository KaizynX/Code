/*
 * @Author: Kaizyn
 * @Date: 2020-09-30 22:32:52
 * @LastEditTime: 2020-09-30 23:29:38
 */
#include <bits/stdc++.h>

#define DEBUG

using namespace std;

const double eps = 1e-7;
const double PI = acos(-1);
typedef pair<int, int> pii;
const int MOD = 998244353;
const int INF = 0x3f3f3f3f;
const int N = 2e3+7;

struct Node {
  int x, y;
};

int n, m;
int a[N], b[N], c[N], d[N], my[N];
Node e[N];

inline void solve() {
  cin >> n >> m;
  for (int i = 1; i <= n; ++i) cin >> a[i] >> b[i];
  for (int i = 1; i <= m; ++i) cin >> c[i] >> d[i];
  for (int i = 1; i <= n; ++i) {
    for (int j = 1; j <= m; ++j) {
      e[i].x = max(e[i].x, c[j]-a[i]+1);
      e[i].y = max(e[i].y, d[j]-b[i]+1);
    }
  }
  #ifdef DEBUG
  for (int i = 1; i <= n; ++i) {
    cout << e[i].x << " " << e[i].y << endl;
  }
  #endif
  sort(e+1, e+n+1, [](Node &n1, Node &n2) {
    return n1.x < n2.x;
  });
  for (int i = n; i; --i) {
    my[i] = max(my[i+1], e[i].y);
  }
  int res = my[1];
  for (int i = 1; i <= n; ++i) {
    res = min(res, e[i].x+my[i+1]);
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