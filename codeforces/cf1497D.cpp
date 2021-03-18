/*
 * @Author: Kaizyn
 * @Date: 2021-03-17 23:37:51
 * @LastEditTime: 2021-03-17 23:46:51
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
const int N = 5e3+7;

int n;
int t[N], s[N];
ll mx[N];

inline void solve() {
  cin >> n;
  for (int i = 1; i <= n; ++i) cin >> t[i];
  for (int i = 1; i <= n; ++i) cin >> s[i];
  memset(mx+1, 0, sizeof(ll)*n);
  for (int k = 2; k <= n; ++k) {
    for (int i = k-1; i; --i) if (t[k] != t[i]) {
      ll mxk = mx[k], mxi = mx[i];
      ll dpki = mxi+abs(s[i]-s[k]);
      mx[k] = max(mx[k], dpki);
      ll dpik = mxk+abs(s[i]-s[k]);
      mx[i] = max(mx[i], dpik);
    }
  }
  ll res = 0;
  for (int i = 1; i <= n; ++i) res = max(res, mx[i]);
  cout << res << '\n';
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