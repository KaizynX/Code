/*
 * @Author: Kaizyn
 * @Date: 2020-05-30 19:56:59
 * @LastEditTime: 2020-05-30 20:09:46
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

inline void solve() {
  cin >> s;
  for (int i = 0; i < (int)s.size(); ++i) {
    if (s[i] != '?') continue;
    /*
    if (i > 0 && s[i-1] == 'P') s[i] = 'D';
    else s[i] = 'P';
    */
    s[i] = 'D';
  }
  cout << s << endl;
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