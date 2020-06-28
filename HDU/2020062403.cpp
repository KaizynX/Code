/*
 * @Author: Kaizyn
 * @Date: 2020-06-24 18:27:14
 * @LastEditTime: 2020-06-24 18:41:21
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
long long dp[N], mv[N];

inline void solve() {
  for (int i = 1; i <= n; ++i) cin >> a[i];
  mv[1] = dp[1] = a[1];
  long long res = dp[1];
  for (int i = 2; i <= n; ++i) {
    dp[i] = mv[i-2]+a[i];
    mv[i] = max(mv[i-1], dp[i]);
    res = max(dp[i], res);
  }
  cout << res << endl;
}

signed main() {
  ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
  while (cin >> n) solve();
  return 0;
}