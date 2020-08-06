/*
 * @Author: Kaizyn
 * @Date: 2020-07-18 12:00:48
 * @LastEditTime: 2020-07-18 12:02:33
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

inline bool solve() {
  cin >> s;
  for (char &c : s) {
    if (c >= 'A' && c <= 'Z') c += 'a'-'A';
  }
  if (s.size() < 6 || s.substr(0, 6) !="lovely") return false;
  return true;
}

signed main() {
  ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
  int T = 1;
  // cin >> T;
  for (int t = 1; t <= T; ++t) {
    cout << (solve() ? "lovely" : "ugly") << endl;
  }
  return 0;
}