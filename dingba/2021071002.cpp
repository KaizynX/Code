/*
 * @Author: Kaizyn
 * @Date: 2021-07-10 13:30:45
 * @LastEditTime: 2021-07-10 13:35:29
 */
#include <bits/stdc++.h>

// #define DEBUG

using namespace std;

const double eps = 1e-7;
const double PI = acos(-1);
typedef pair<int, int> pii;
typedef long long ll;
const int MOD = 998244353; // 1e9+7;
const int INF = 0x3f3f3f3f;
// const ll INF = 1e18;
const int N = 1e2+7;

int n, k;
int x[N], y[N];
ll res[N], dis[N];

inline void solve() {
  cin >> n >> k;
  for (int i = 1; i <= n; ++i) {
    cin >> x[i] >> y[i];
  }
  memset(res, 0x3f, sizeof res);
  for (int i = 1; i <= n; ++i) {
    for (int j = 1; j <= n; ++j) {
      dis[j] = abs(x[i]-x[j])+abs(y[i]-y[j]);
    }
    sort(dis+1, dis+n+1);
    for (int j = 1; j <= k; ++j) {
      dis[j] += dis[j-1];
      res[j] = min(res[j], dis[j]);
    }
  }
  for (int i = 1; i <= k; ++i) {
    cout << res[i] << '\n';
  }
}

signed main() {
#ifdef ONLINE_JUDGE
  ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
#endif
  int T = 1;
  // cin >> T; // scanf("%d", &T);
  for (int t = 1; t <= T; ++t) {
    solve();
  }
  return 0;
}