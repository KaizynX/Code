/*
 * @Author: Kaizyn
 * @Date: 2020-09-05 14:53:25
 * @LastEditTime: 2020-09-05 16:00:24
 */
#include <bits/stdc++.h>

// #define DEBUG

using namespace std;

typedef unsigned long long ull;
const ull INF = 1e19;
const int N = 18+1;
const int S = 162+1;

int a[N];
ull dp[2][N][S];
ull pw10[N];

ull minv(int s) {
  ull res = 0;
  for (int i = 0, t; s; ++i) {
    t = min(s, 9);
    res += pw10[i]*t;
    s -= t;
  }
  return res;
}

inline void solve() {
  ull n;
  int s;
  cin >> n >> s;
  ull res = INF, cur = 0, tmp;
  for (int i = 17; i >= 0; --i) {
    a[i] = n/pw10[i]%10;
    cur += a[i]*pw10[i];
    if (s < a[i]) break;
    tmp = minv(s-a[i]);
    if (tmp < pw10[i] && cur+tmp >= n) res = min(res, cur+tmp-n);
    for (int j = a[i]+1; j <= 9 && j <= s; ++j) {
      tmp = minv(s-j);
      if (tmp < pw10[i]) res = min(res, cur+(j-a[i])*pw10[i]+tmp-n);
    }
    s -= a[i];
  }
  cout << res << endl;
  /*
  memset(dp, -1, sizeof dp);
  dp[1][18][0] = 0;
  for (int i = 17; i >= 0; --i) {
    a[i] = n/pw10[i]%10;
    for (int j = 0; j <= s; ++j) {
      if (j >= a[i]) dp[1][i][j] = dp[1][i+1][j-a[i]]+a[i]*pw10[i];
      for (int k = 0; k <= 9 && k <= j; ++k) {
        if (k > a[i]) dp[0][i][j] = min(dp[0][i][j], dp[1][i+1][j-k]+k*pw10[i]);
        dp[0][i][j] = min(dp[0][i][j], dp[0][i+1][j-k]+k*pw10[i]);
      }
    }
  }
  cout << min(dp[0][0][s], dp[1][0][s])-n << endl;
  */
}

signed main() {
  ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
  pw10[0] = 1;
  for (int i = 1; i <= 18; ++i) pw10[i] = pw10[i-1]*10;
  int T = 1;
  cin >> T;
  for (int t = 1; t <= T; ++t) {
    solve();
  }
  return 0;
}