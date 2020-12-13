/*
 * @Author: Kaizyn
 * @Date: 2020-12-05 19:55:55
 * @LastEditTime: 2020-12-05 20:17:02
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
string s = "110", t;

inline void solve() {
  cin >> n >> t;
  long long res = 0, ten = 3e10;
  for (int b = 0; b < 3; ++b) {
    int ok = 1;
    for (int i = 0; i < n; ++i) {
      if (t[i] != s[(i+b)%3]) {
        ok = 0;
        break;
      }
    }
    if (!ok) continue;
    res += (ten-n+3-b)/3;
  }
  cout << res << endl;
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