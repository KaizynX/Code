/*
 * @Author: Kaizyn
 * @Date: 2020-10-17 21:01:39
 * @LastEditTime: 2020-10-17 21:20:55
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

string s;

inline void solve() {
  cin >> s;
  int n = s.size(), b = 0, res = n;
  for (int i = n-1; i >= 0; --i) {
    int c = s[i]-'A';
    if (c) ++b;
    else {
      if (b) {
        --b;
        res -= 2;
      }
    }
  }
  res -= b/2*2;
  cout << res << endl;
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