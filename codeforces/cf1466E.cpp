/*
 * @Author: Kaizyn
 * @Date: 2020-12-30 23:26:09
 * @LastEditTime: 2020-12-30 23:37:22
 */
#include <bits/stdc++.h>

// #define DEBUG

using namespace std;

const double eps = 1e-7;
const double PI = acos(-1);
typedef pair<int, int> pii;
typedef long long ll;
const int MOD = 1e9+7;
const int INF = 0x3f3f3f3f;
// const ll INF = 1e18;
const int N = 5e5+7;
const int B = 60;

int n;
ll a[N], x[N], t[B];

inline void solve() {
  cin >> n;
  memset(t, 0, sizeof t);
  for (int i = 1; i <= n; ++i) {
    cin >> x[i];
    for (int b = 0; b < B; ++b) {
      t[b] += (x[i]>>b)&1;
    }
  }
  ll res = 0, lhs, rhs;
  for (int i = 1; i <= n; ++i) { // j
    lhs = rhs = 0;
    for (int b = 0; b < B; ++b) {
      if ((x[i]>>b)&1) {
        (rhs += (1ll<<b)%MOD*n) %= MOD;
        (lhs += (1ll<<b)%MOD*t[b]) %= MOD;
      } else {
        (rhs += (1ll<<b)%MOD*t[b]) %= MOD;
      }
    }
    (res += lhs*rhs) %= MOD;
  }
  cout << res << endl;
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