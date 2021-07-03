/*
 * @Author: Kaizyn
 * @Date: 2021-06-13 12:54:14
 * @LastEditTime: 2021-06-13 13:02:41
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

int n, k;
int a[N];
map<int, int> dp;

inline void solve() {
  cin >> n >> k;
  for (int i = 1; i <= n; ++i) cin >> a[i];
  sort(a+1, a+n+1);
  int res = 1;
  for (int i = 1; i <= n; ++i) {
    res = max(res, dp[a[i]] = max(dp[a[i]], dp[a[i]-k]+1));
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