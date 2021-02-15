/*
 * @Author: Kaizyn
 * @Date: 2021-02-13 14:51:11
 * @LastEditTime: 2021-02-13 15:18:36
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

ll x, y, z;

ll brute() {
  ll res = 0;
  for (ll b = 1; b <= y; ++b) {
    res += min(x/(b+1), b-1);
  }
  return res;
}

ll calc() {
  ll res = 0;
  for (ll b = z+1; b <= min(x, y); ++b) res += x/(b+1);
  /*
  for (ll b = z+2; b < sqrt(x); ++b) res += x/(b+1);
  // for (ll c = 1; c < sqrt(x); ++c) res += c*(x/c-x/(c+1));
  for (ll i = x, j = 1, l, r, k = sqrt(x); j <= k; ++j) { // i/[l, r] == j, b+1 [l, r]
    l = max(1ll, i/(j+1));
    while (l-1 >= 1 && i/(l-1) == j) --l;
    while (i/l > j) ++l;
    r = i/j;
    while (r+1 <= i && i/(r+1) == j) ++r;
    while (i/r < j) --r;
    l = max(l, k);
    r = min(r, x);
    res += (r-l+1)*j;
  }
  */
  return res;
}

inline void solve() {
  cin >> x >> y;
  ll l = 1, r = y;
  while (l < r) {
    ll mid = (l+r+1)/2;
    if (x >= mid*mid-1) l = mid;
    else r = mid-1;
  }
  z = min(y, l);
  y = min(x, y);
  ll res = z*(z-1)/2+calc();
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