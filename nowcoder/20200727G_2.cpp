/*
 * @Author: Kaizyn
 * @Date: 2020-07-27 13:58:53
 * @LastEditTime: 2020-07-27 14:01:04
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

inline void solve() {
  for (int n = 1; n <= 200; ++n) {
    int sum = 2*n*(n+1);
    for (int k = 2; k*k <= 2*n+1; ++k) {
      if ((2*n+1)%k) continue;
      if (sum%k == 0) cout << n << " " << k << endl;
      int kk = (2*n+1)/k;
      if (kk == k) continue;
      if (sum%kk == 0) cout << n << " " << kk << endl;
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