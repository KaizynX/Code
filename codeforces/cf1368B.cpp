/*
 * @Author: Kaizyn
 * @Date: 2020-06-18 22:29:49
 * @LastEditTime: 2020-06-18 23:57:58
 */ 
#include <bits/stdc++.h>

// #define DEBUG

using namespace std;

const double eps = 1e-7;
const double PI = acos(-1);
typedef pair<int, int> pii;
const int MOD = 998244353;
const int INF = 0x3f3f3f3f;


long long k;
string sss = "codeforces";

inline void solve() {
  cin >> k;
  if (k == 1) return cout << sss << endl, void();
  for (int i = 2; i <= 16; ++i) {
    long long cur = 1;
    for (int j = 0; j < 10; ++j) cur *= i;
    if (cur >= k) {
      int cnt = 10;
      while (cnt && cur/i*(i-1) >= k) {
        cur = cur/i*(i-1);
        --cnt;
      }
      // cout << cnt << endl;
      for (int j = 0; j < 10; ++j) {
        for (int k = 1; k <= i-(cnt <= 0); ++k) {
          cout << sss[j];
        }
        --cnt;
      }
      cout << endl;
      return;
    }
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