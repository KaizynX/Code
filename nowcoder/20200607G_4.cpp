/*
 * @Author: Kaizyn
 * @Date: 2020-06-07 15:50:24
 * @LastEditTime: 2020-06-07 15:56:18
 */ 
#include <bits/stdc++.h>

// #define DEBUG

using namespace std;

const double eps = 1e-7;
const double PI = acos(-1);
typedef pair<int, int> pii;
const int MOD = 998244353;
const int INF = 0x3f3f3f3f;
const int N = 1e5+7;

int n;
int a[N];
int dp[N];

inline void solve() {
  cin >> n;
  for (int i = 1; i <= n; ++i) {
    cin >> a[i];
  }
  for (int i = 1; i <= n; ++i) {
    dp[i] = dp[i-1]+a[i];
    for (int j = i-1, mul = a[i]; j && j >= i-3; --j) {
      mul *= a[j];
      dp[i] = max(dp[i], dp[j-1]+mul);
    }
  }
  cout << dp[n] << endl;
}

signed main() {
  ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
  int T = 1;
  cin >> T;
  for (int t = 1; t <= T; ++t) {
    solve();
  }
  return 0;
}