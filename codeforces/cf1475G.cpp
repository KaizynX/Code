/*
 * @Author: Kaizyn
 * @Date: 2021-02-03 11:07:39
 * @LastEditTime: 2021-02-03 11:18:58
 */
#include <bits/stdc++.h>

#define DEBUG

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
int a[N], dp[N];

inline void solve() {
  cin >> n;
  for (int i = 1; i <= n; ++i) {
    cin >> a[i];
  }
  sort(a+1, a+n+1);
  int res = 0;
  for (int i = 1; i <= n; ++i) {
    for (int j = 1; j*j <= a[i]; ++j) {
      if (a[i]%j) continue;
      dp[a[i]] = max({dp[a[i]], dp[j]+1, dp[a[i]/j]+1});
    }
    res = max(res, dp[a[i]]);
  }
  #ifdef DEBUG
  for (int i = 1; i <= n; ++i) cout << a[i] << " \n"[i==n];
  for (int i = 1; i <= n; ++i) cout << dp[a[i]] << " \n"[i==n];
  #endif
  for (int i = 1; i <= n; ++i) {
    dp[a[i]] = 0;
  }
  cout << n-res << endl;
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