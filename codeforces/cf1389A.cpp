/*
 * @Author: Kaizyn
 * @Date: 2020-07-29 22:31:14
 * @LastEditTime: 2020-07-29 22:36:41
 */ 
#include <bits/stdc++.h>

// #define DEBUG

using namespace std;

const double eps = 1e-7;
const double PI = acos(-1);
typedef pair<int, int> pii;
const int MOD = 998244353;
const int INF = 0x3f3f3f3f;
const int N = 1e2+7;

inline void solve() {
  int l, r;
  cin >> l >> r;
  if (l*2 <= r) cout << l << " " <<  l*2 << endl;
  else cout << "-1 -1" << endl;
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