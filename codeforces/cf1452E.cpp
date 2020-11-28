/*
 * @Author: Kaizyn
 * @Date: 2020-11-25 23:25:39
 * @LastEditTime: 2020-11-25 23:33:22
 */
#include <bits/stdc++.h>

// #define DEBUG

using namespace std;

const double eps = 1e-7;
const double PI = acos(-1);
typedef pair<int, int> pii;
const int MOD = 998244353;
const int INF = 0x3f3f3f3f;
const int N = 2e3+7;

struct Node {
  int l, r;
};

int n, m, k;
int mx[N];
Node a[N];

inline void solve() {
  cin >> n >> m >> k;
  for (int i = 1; i <= m; ++i) cin >> a[i].l >> a[i].r;
  sort(a+1, a+m+1, [](Node &x, Node &y) {
    return x.l+x.r < y.l+y.r;
  });
  for (int i = 1; i+k-1 <= n; ++i) {
    int cur = 0;
    for (int j = m; j; --j) {
      cur += max(0, min(i+k-1, a[j].r)-max(i, a[j].l)+1);
      mx[j] = max(mx[j], cur);
    }
  }
  int res = mx[1];
  for (int i = 1; i+k-1 <= n; ++i) {
    int cur = 0;
    for (int j = 1; j <= m; ++j) {
      cur += max(0, min(i+k-1, a[j].r)-max(i, a[j].l)+1);
      res = max(res, cur+mx[j+1]);
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