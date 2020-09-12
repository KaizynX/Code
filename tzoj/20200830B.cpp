/*
 * @Author: Kaizyn
 * @Date: 2020-08-30 12:53:44
 * @LastEditTime: 2020-08-30 13:09:24
 */
#include <bits/stdc++.h>

// #define DEBUG

using namespace std;

const double eps = 1e-7;
const double PI = acos(-1);
typedef pair<int, int> pii;
const int MOD = 998244353;
const int INF = 0x3f3f3f3f;

int n;

inline void solve() {
  cin >> n;
  for (int i = n-1; i >= 0; --i) {
    cout << "|";
    for (int j = 0; j < i; ++j) cout << " ";
    cout << "/\n";
  }
  for (int i = 0; i < n; ++i) {
    cout << "|";
    for (int j = 0; j < i; ++j) cout << " ";
    cout << "\\\n";
  }
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