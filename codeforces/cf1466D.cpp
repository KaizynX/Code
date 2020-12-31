/*
 * @Author: Kaizyn
 * @Date: 2020-12-30 22:33:34
 * @LastEditTime: 2020-12-30 23:23:53
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
const int N = 1e5+7;

int n;
int w[N], deg[N], rk[N];

inline void solve() {
  cin >> n;
  ll res = 0;
  for (int i = 1; i <= n; ++i) {
    cin >> w[i];
    rk[i] = i;
    res += w[i];
    deg[i] = 0;
  }
  for (int i = 1, u, v; i < n; ++i) {
    cin >> u >> v;
    ++deg[u];
    ++deg[v];
  }
  sort(rk+1, rk+n+1, [](int x, int y) {
    return w[x] > w[y];
  });
  cout << res << " ";
  for (int _ = 1, i; _ <= n; ++_) {
    i = rk[_];
    while (deg[i] > 1) {
      --deg[i];
      cout << (res += w[i]) << " ";
    }
  }
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
  }
  return 0;
}