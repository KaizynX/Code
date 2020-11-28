/*
 * @Author: Kaizyn
 * @Date: 2020-10-29 10:13:46
 * @LastEditTime: 2020-10-29 10:14:44
 */
#include <bits/stdc++.h>

// #define DEBUG

using namespace std;

const double eps = 1e-7;
const double PI = acos(-1);
typedef pair<int, int> pii;
const int MOD = 998244353;
const int INF = 0x3f3f3f3f;
// const int N = ;

string s;

inline void solve() {
  getline(cin, s);
  reverse(s.begin(), s.end());
  cout << s << endl;
}

signed main() {
  ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
  int T = 1;
  cin >> T;
  getline(cin, s);
  for (int t = 1; t <= T; ++t) {
    solve();
  }
  return 0;
}