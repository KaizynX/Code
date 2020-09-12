/*
 * @Author: Kaizyn
 * @Date: 2020-08-30 23:22:52
 * @LastEditTime: 2020-08-31 10:23:01
 */
#include <bits/stdc++.h>

#define DEBUG

using namespace std;

const double eps = 1e-7;
const double PI = acos(-1);
typedef pair<int, int> pii;
const int MOD = 998244353;
const long long INF = 1e18;
const int N = 1e6+7;

int n;
long long r1, r2, r3, d;
int a[N];
long long b[N][2], dp[N], sumb[N];

inline void solve() {
  cin >> n >> r1 >> r2 >> r3 >> d;
  for (int i = 1; i <= n; ++i) cin >> a[i];

  for (int i = 1; i <= n; ++i) {
    b[i][0] = a[i]*r1+r3+d;
    b[i][1] = min(a[i]*r1+2*r1, r2+r1)+2*d;
    sumb[i] = sumb[i-1]+b[i][1];
  }
  #ifdef DEBUG
  cout << "****" << endl;
  for (int i = 1; i <= n; ++i) {
    cout << b[i][0] << " "<< b[i][1] << endl;
  }
  cout << "****" << endl;
  #endif
  memset(dp, 0x3f, sizeof dp);
  dp[0] = 0;
  for (int i = 1; i <= n; ++i) {
    dp[i] = dp[i-1]+b[i][0];
    if (i >= 2) dp[i] = min(dp[i], dp[i-2]+sumb[i]-sumb[i-2]);
    if (i >= 3) dp[i] = min(dp[i], dp[i-3]+sumb[i]-sumb[i-3]+d);
  }
  for (int i = 0; i < n; ++i) {
    dp[n] = min(dp[n], dp[i]+sumb[n-1]-sumb[i]+b[n][0]);
  }
  cout << dp[n]-d << endl;
}

signed main() {
  ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
  int T = 1;
  // cin >> T;
  for (int t = 1; t <= T; ++t) {
    solve();
  }
  return 0;
}