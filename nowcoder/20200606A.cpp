/*
 * @Author: Kaizyn
 * @Date: 2020-06-06 13:28:00
 * @LastEditTime: 2020-06-06 13:32:43
 */ 
#include <bits/stdc++.h>

// #define DEBUG

using namespace std;

const double eps = 1e-7;
const double PI = acos(-1);
typedef pair<int, int> pii;
const int MOD = 998244353;
const int INF = 0x3f3f3f3f;

string s;

int f(const char &c) {
  return c >= 'A' && c <= 'Z';
}

inline void solve() {
  cin >> s;
  s = 'A'+s;
  int res = 0;
  for (int i = 1; i < (int)s.size(); ++i) {
    if (f(s[i]) != f(s[i-1])) ++res;
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