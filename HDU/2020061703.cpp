/*
 * @Author: Kaizyn
 * @Date: 2020-06-17 18:39:57
 * @LastEditTime: 2020-06-17 18:41:14
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
  unsigned long long a = 0;
  for (const char &c : s) {
    if (isdigit(c)) {
      a = a*10+c-'0';
    }
  }
  cout << a*513 << endl;
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