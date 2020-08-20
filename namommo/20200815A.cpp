/*
 * @Author: Kaizyn
 * @Date: 2020-08-15 19:00:45
 * @LastEditTime: 2020-08-15 19:03:16
 */
#include <bits/stdc++.h>

// #define DEBUG

using namespace std;

const double eps = 1e-7;
const double PI = acos(-1);
typedef pair<int, int> pii;
const int MOD = 998244353;
const int INF = 0x3f3f3f3f;

inline int solve() {
  long long n;
  cin >> n;
  if (!n) return 1;
  int res = 0;
  while (n) {
    res = max(res, int(n%10));
    n /= 10;
  }
  return res;
}

signed main() {
  ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
  int T = 1;
  // cin >> T;
  for (int t = 1; t <= T; ++t) {
    cout << solve() << endl;
  }
  return 0;
}