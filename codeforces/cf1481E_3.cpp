/*
 * @Author: Kaizyn
 * @Date: 2021-02-06 15:52:35
 * @LastEditTime: 2021-02-06 16:06:32
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
const int N = 5e5+7;

int n;
int a[N], l[N], r[N], dp[N], cf[N], f[N];

inline void solve() {
  cin >> n;
  for (int i = 1; i <= n; ++i) {
    l[i] = n+1;
    r[i] = 0;
  }
  for (int i = 1; i <= n; ++i) {
    cin >> a[i];
    ++f[a[i]];
    l[a[i]] = min(l[a[i]], i);
    r[a[i]] = max(r[a[i]], i);
  }
  for (int i = n; i; --i) {
    dp[i] = dp[i+1];
    ++cf[a[i]];
    if (i == l[a[i]]) dp[i] = max(dp[i], dp[r[a[i]]+1]+f[a[i]]);
    else dp[i] = max(dp[i], cf[a[i]]);
  }
  cout << n-dp[1] << '\n';
}

signed main() {
#ifdef ONLINE_JUDGE
  ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
#endif
  int T = 1;
  // cin >> T;
  for (int t = 1; t <= T; ++t) {
    solve();
  }
  return 0;
}