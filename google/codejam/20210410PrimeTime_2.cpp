/*
 * @Author: Kaizyn
 * @Date: 2021-04-10 09:43:33
 * @LastEditTime: 2021-04-10 09:44:49
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

int n;
ll sum;
ll p[N], t[N];

inline bool check(ll x) {
  ll tmp = 0, y = x;
  for (int i = 1, k; i <= n; ++i) {
    k = 0;
    while (y%p[i] == 0) y /= p[i], ++k;
    if (k > t[i]) return false;
    tmp += k*p[i];
  }
  if (y > 1) return false;
  return x == sum-tmp;
}

inline ll solve() {
  cin >> n;
  sum = 0;
  for (int i = 1; i <= n; ++i) {
    cin >> p[i] >> t[i];
    sum += p[i]*t[i];
  }
  for (ll r = sum; r > max(0ll, sum-10000); --r) {
    if (check(r)) return r;
  }
  return 0;
}

signed main() {
#ifdef ONLINE_JUDGE
  ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
#endif
  int T = 1;
  cin >> T; // scanf("%d", &T);
  for (int t = 1; t <= T; ++t) {
    ll res = solve();
    cout << "Case #" << t << ": " << res << '\n';
  }
  return 0;
}