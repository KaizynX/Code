/*
 * @Author: Kaizyn
 * @Date: 2020-10-11 17:03:48
 * @LastEditTime: 2020-10-11 17:29:14
 */
#include <bits/stdc++.h>

// #define DEBUG

using namespace std;

const double eps = 1e-7;
const double PI = acos(-1);
typedef pair<int, int> pii;
const int MOD = 998244353;
const int INF = 0x3f3f3f3f;
const int N = 2e5+7;

int n;

inline void solve() {
  cin >> n;
  cout << 2 << endl;
  if (n == 2) {
    cout << "2 1" << endl;
    return;
  }
  cout << n << " " << n-2 << endl;
  cout << n-1 << " " << n-1 << endl;
  for (int i = n-1; i >= 3; --i) {
    cout << i << " " << i-2 << endl;
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