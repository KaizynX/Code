/*
 * @Author: Kaizyn
 * @Date: 2021-02-13 15:18:55
 * @LastEditTime: 2021-02-13 15:24:54
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
// const int N = ;

ll x, y;

inline void solve() {
  cin >> x >> y;
  ll res = 0, z, l = 1, r = y;
  while (l < r) {
    ll mid = (l+r+1)/2;
    if (x >= mid*mid-1) l = mid;
    else r = mid-1;
  }
  z = min(y, l);
  res = z*(z-1)/2;
  // b+1 [z+2, y+1]
  for (ll i = x, j = 1, l, r, k = sqrt(x); j <= k; ++j) { // x/[l, r] == c, b+1 [l, r]
    l = max(1ll, i/(j+1));
    while (l-1 >= 1 && i/(l-1) == j) --l;
    while (i/l > j) ++l;
    r = i/j;
    while (r+1 <= i && i/(r+1) == j) ++r;
    while (i/r < j) --r;
    l = max(l, z+2);
    r = min(r, y+1);
    res += max(0ll, r-l+1)*j;
  }
  cout << res << '\n';
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
/*
1000000000 1000000000
*/