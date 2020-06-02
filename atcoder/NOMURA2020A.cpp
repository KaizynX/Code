/*
 * @Author: Kaizyn
 * @Date: 2020-05-30 19:56:47
 * @LastEditTime: 2020-05-30 20:07:35
 */ 
#include <bits/stdc++.h>

// #define DEBUG

using namespace std;

const double eps = 1e-7;
const double PI = acos(-1);
typedef pair<int, int> pii;
const int MOD = 998244353;
const int INF = 0x3f3f3f3f;

int h1, m1, h2, m2, k;

inline void solve() {
  cin >> h1 >> m1 >> h2 >> m2 >> k;
  int t = m2-m1+(h2-h1)*60-k;
  cout << max(0, t) << endl;
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