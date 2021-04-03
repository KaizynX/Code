/*
 * @Author: Kaizyn
 * @Date: 2021-04-03 23:08:44
 * @LastEditTime: 2021-04-04 00:01:27
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
const int N = 1e5+7;

int n;
pii a[N];

inline void solve() {
  cin >> n;
  ll res = 0;
  for (int i = 1; i <= n; ++i) {
    cin >> a[i].first >> a[i].second;
    res += a[i].second;
  }
  sort(a+1, a+n+1);
  for (int i = 1, r = a[1].first; i <= n; ++i) {
    if (r < a[i].first) {
      res += a[i].first-r;
    }
    r = max(r, a[i].first+a[i].second);
  }
  cout << res << '\n';
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