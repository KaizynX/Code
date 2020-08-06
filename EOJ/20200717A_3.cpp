/*
 * @Author: Kaizyn
 * @Date: 2020-07-17 19:28:57
 * @LastEditTime: 2020-07-17 21:03:38
 */ 
#include <bits/stdc++.h>

// #define DEBUG

using namespace std;

const double eps = 1e-7;
const double PI = acos(-1);
typedef pair<int, int> pii;
const int MOD = 998244353;
const int INF = 0x3f3f3f3f;
const int N = 1e6+7;

int n;
string s;

inline void solve() {
  cin >> s;
  n = s.size();
  int flag = 1, cur = 0, flag2 = 0;
  for (int i = 0; i < n; ++i) {
    if (s[i] == 'a') {
      ++cur;
    } else {
      --cur;
      flag2 = cur;
    }
    if (cur < 0) flag = 0;
  }
  if (!flag) cout << "Dead Fang" << endl;
  else if (flag2) cout << "Sad Fang" << endl;
  else cout << "Happy Fang" << endl;
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