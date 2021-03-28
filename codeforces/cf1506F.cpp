/*
 * @Author: Kaizyn
 * @Date: 2021-03-25 23:12:15
 * @LastEditTime: 2021-03-25 23:25:22
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
const int N = 2e5+7;

int n;
pii a[N];

inline void solve() {
  cin >> n;
  a[0] = {1, 1};
  for (int i = 1; i <= n; ++i) cin >> a[i].first;
  for (int i = 1; i <= n; ++i) cin >> a[i].second;
  sort(a+1, a+n+1);
  ll res = 0;
  for (int i = 1, x, y, r, c; i <= n; ++i) {
    x = a[i-1].first;
    y = a[i-1].second;
    r = a[i].first;
    c = a[i].second;
    if (r == x && c == y) continue;
    int d = (r-x)-(c-y);
    if (!d) {
      if ((x+y)%2 == 0) res += c-y;
      continue;
    }
    d -= (x+y)%2 == 0;
    res += (d+1)/2;
  }
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