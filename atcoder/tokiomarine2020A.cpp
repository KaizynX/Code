/*
 * @Author: Kaizyn
 * @Date: 2020-06-13 19:44:24
 * @LastEditTime: 2020-06-13 20:02:06
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
  cin >> s;
  cout << s.substr(0, 3) << endl;
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