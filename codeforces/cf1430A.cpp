/*
 * @Author: Kaizyn
 * @Date: 2020-10-11 17:03:20
 * @LastEditTime: 2020-10-11 17:13:16
 */
#include <bits/stdc++.h>

// #define DEBUG

using namespace std;

const double eps = 1e-7;
const double PI = acos(-1);
typedef pair<int, int> pii;
const int MOD = 998244353;
const int INF = 0x3f3f3f3f;
const int N = 1e3+7;

int n;

inline void solve() {
  cin >> n;
  // if (n < 3 || n%2 == 0) return cout << -1 << endl, void();
  for (int c7 = 0, c3, c5; c7*7 <= n; ++c7) {
    int r = n-7*c7;
    c3 = r/3; c5 = 0;
    if (r == 2 || r%3 == 1) continue;
    if (r%3 == 2) --c3, ++c5;
    cout << c3 << " " << c5 << " " << c7 << endl;
    return;
  }
  cout << -1 << endl;
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