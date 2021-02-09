/*
 * @Author: Kaizyn
 * @Date: 2021-01-14 10:11:20
 * @LastEditTime: 2021-01-14 10:13:00
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
const int N = 1e5+7;

int n;
int a[N];
ll dp[N];

inline void solve() {
  for (int i = 1; i <= n; ++i) cin >> a[i];
  ll res = 0;
  dp[0] = 0;
  dp[1] = a[1];
  for (int i = 1; i <= n; ++i) {
    dp[i] = max(dp[i-1], dp[i-2]+a[i]);
    res = max(res, dp[i]);
  }
  cout << res << endl;
}

signed main() {
#ifdef ONLINE_JUDGE
  ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
#endif
  while (cin >> n) solve();
  return 0;
}