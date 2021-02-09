/*
 * @Author: Kaizyn
 * @Date: 2021-02-07 14:09:29
 * @LastEditTime: 2021-02-07 15:09:18
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
const int N = 2e5+7;

int n;
ll k;
ll x[N];

inline void solve() {
  cin >> n >> k;
  for (int i = 1; i <= n; ++i) cin >> x[i];
  sort(x+1, x+n+1);
  ll g = x[2]-x[1];
  for (int i = 1; i < n; ++i) {
    g = __gcd(g, x[i+1]-x[i]);
  }
  cout << (abs(k-x[1])%g ? "NO" : "YES") << '\n';
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