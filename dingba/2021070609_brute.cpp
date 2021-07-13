/*
 * @Author: Kaizyn
 * @Date: 2021-07-13 22:50:41
 * @LastEditTime: 2021-07-13 22:52:11
 */
#include <bits/stdc++.h>

// #define DEBUG

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
const double eps = 1e-7;
const double PI = acos(-1);
const int MOD = 998244353; // 1e9+7;
const int INF = 0x3f3f3f3f;
// const ll INF = 1e18;
const int N = 2e5+7;

int n, m;
ll t[N], f[N];

inline void solve() {
  cin >> n >> m;
  for (int i = 1; i <= n; ++i) cin >> t[i];
  for (int _ = m, d; _; --_) {
    cin >> d;
    ll res = 0;
    for (int i = 1; i <= n; ++i) {
      f[i] = max(f[i-1]+d, t[i]);
      res += f[i]-t[i];
    }
    cout << res << '\n';
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