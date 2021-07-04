/*
 * @Author: Kaizyn
 * @Date: 2021-07-04 13:14:31
 * @LastEditTime: 2021-07-04 15:49:53
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
const int N = 4e5+7;

int n;
int a[N];

inline void solve() {
  cin >> n;
  ll res = 0;
  for (int i = 1; i <= n; ++i) {
    cin >> a[i];
    res += abs(a[i]-a[i-1]);
  }
  a[n+1] = 0;
  res += a[n];
  for (int i = 1; i <= n; ++i) {
    int x = max(a[i-1], a[i+1]);
    if (a[i] > x) res -= a[i]-x, a[i] = x;
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