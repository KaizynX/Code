/*
 * @Author: Kaizyn
 * @Date: 2020-06-13 13:10:45
 * @LastEditTime: 2020-06-13 14:21:22
 */ 
#include <bits/stdc++.h>

// #define DEBUG

using namespace std;

const double eps = 1e-7;
const double PI = acos(-1);
typedef pair<int, int> pii;
const int MOD = 998244353;
const int INF = 0x3f3f3f3f;
const int N = 1e6+7;

int q;
long long dp[N], sum[N];

inline void solve() {
  cin >> q;
  for (int i = 1, l, r; i <= q; ++i) {
    cin >> l >> r;
    cout << sum[r]-sum[l-1] << endl;
  }
}

signed main() {
  ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
  /*
  for (int i = 1; i <= 10000; ++i) {
    for (int j = 1; j*j <= i; ++j) {
      if (i%j) continue;
      dp[i] += j;
      if (i/j != j) dp[i] += i/j;
    }
    sum[i] = sum[i-1]+dp[i];
  }
  */
  for (int i = 1; i < N; ++i) {
    for (int j = i; j < N; j += i) {
      dp[j] += i;
    }
  }
  for (int i = 1; i < N; ++i) {
    sum[i] = sum[i-1]+dp[i];
  }
  int T = 1;
  // cin >> T;
  for (int t = 1; t <= T; ++t) {
    solve();
  }
  return 0;
}