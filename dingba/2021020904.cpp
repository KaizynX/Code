/*
 * @Author: Kaizyn
 * @Date: 2021-02-09 19:11:52
 * @LastEditTime: 2021-02-09 19:20:26
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

int n, m, k;
ll fac[N];

inline void solve() {
  cin >> n >> m;
  ll sum = 0, res;
  fac[0] = 1;
  for (k = 1; ; ++k) {
    fac[k] = fac[k-1]*k;
    if (fac[k] >= 1e14) break;
  }
  for (int i = 1, x; i <= m; ++i) {
    cin >> x;
    sum += x;
    if (n <= k) sum = min(sum, fac[n]);
    res = 0;
    ll s = sum;
    for (int j = k; j; --j) {
      res += s/fac[j];
      s %= fac[j];
    }
    cout << res << '\n';
  }
}

signed main() {
#ifdef ONLINE_JUDGE
  ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
#endif
  int T = 1;
  // cin >> T;
  for (int t = 1; t <= T; ++t) {
    solve();
  }
  return 0;
}