/*
 * @Author: Kaizyn
 * @Date: 2020-08-25 19:57:53
 * @LastEditTime: 2020-08-25 20:04:07
 */
#include <bits/stdc++.h>

// #define DEBUG

using namespace std;

const double eps = 1e-7;
const double PI = acos(-1);
typedef pair<int, int> pii;
const int MOD = 998244353;
const int INF = 0x3f3f3f3f;

inline void solve() {
  int n, m;
  cin >> n >> m;
  if (n == 0) n = 1;
  if (n <= 2) {
    cout << n%m << endl;
  } else if (n == 3) {
    // 720! % m
    long long res = 1;
    for (int i = 1; i <= 720; ++i) {
      res = res*i%m;
    }
    cout << res << endl;
  } else {
    cout << 0 << endl;
  }
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