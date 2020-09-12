/*
 * @Author: Kaizyn
 * @Date: 2020-09-05 14:53:25
 * @LastEditTime: 2020-09-05 16:09:01
 */
#include <bits/stdc++.h>

// #define DEBUG

using namespace std;

typedef unsigned long long ull;
const ull INF = 1e19;
const int N = 18+1;
const int S = 162+1;

int a[N];
ull pw10[N];

inline void solve() {
  ull n, res = 0;
  int s, sum = 0;
  cin >> n >> s;
  for (int i = 0; i < 18; ++i) {
    a[i] = n%10;
    n /= 10;
    // a[i] = n/pw10[i]%10;
    sum += a[i];
  }
  for (int i = 0; sum > s; ++i) {
    if (a[i] > 9) {
      sum -= 9;
      ++a[i+1];
      continue;
    } else if (a[i]) {
      ++a[i+1];
      res += (10-a[i])*pw10[i];
      sum -= a[i]-1;
    }
  }
  cout << res << endl;
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