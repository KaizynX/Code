/*
 * @Author: Kaizyn
 * @Date: 2021-07-27 12:13:04
 * @LastEditTime: 2021-07-27 12:15:35
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
// const int N = ;

ll n, k;
map<ll, ll> dp;

ll f(ll x) {
  if (x <= k) return 1;
  if (dp.count(x)) return dp[x];
  return dp[x] = f(x/2)+f(x-x/2)+1;
}

inline void solve() {
  dp.clear();
  cin >> n >> k;
  cout << f(n) << '\n';
}

signed main() {
#ifdef ONLINE_JUDGE
  ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
#endif
  int T = 1;
  cin >> T; // scanf("%d", &T);
  for (int t = 1; t <= T; ++t) {
    solve();
  }
  return 0;
}