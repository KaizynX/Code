/*
 * @Author: Kaizyn
 * @Date: 2021-08-01 15:21:01
 * @LastEditTime: 2021-08-01 15:46:30
 */
#include <bits/stdc++.h>

// #define DEBUG

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
const double eps = 1e-7;
const double PI = acos(-1);
const int MOD = 998244353; // 1e9+7;
const int INF = 0x3f3f3f3f;
// const ll INF = 1e18;
const int N = 1e5+7;

int n;
ll m;
ll a[N];

ll f(ll x) {
  for (int i = 1; i <= n; ++i) {
    x += a[i];
    if (x < 0) x = 0;
    if (x >= m) break;
  }
  return x;
}

inline int solve() {
  cin >> n >> m;
  for (int i = 1; i <= n; ++i) cin >> a[i];
  ll x = f(0);
  if (x >= m) return 1;
  ll y = f(x);
  if (y >= m) return 2;
  if (y <= x) return -1;
  y -= x;
  ll mx = 0, cur = x;
  for (int i = 1; i <= n; ++i) {
    cur += a[i];
    assert(cur > 0);
    mx = max(mx, cur-x);
  }
  #ifdef DEBUG
  cout << mx << ' ' << x << ' ' << y << '\n';
  #endif
  return 2+(m-mx-x+y-1)/y;
}

signed main() {
#ifdef ONLINE_JUDGE
  ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
#endif
  int T = 1;
  cin >> T; // scanf("%d", &T);
  for (int t = 1; t <= T; ++t) {
    cout << solve() << '\n';
  }
  return 0;
}