/*
 * @Author: Kaizyn
 * @Date: 2020-07-30 23:21:59
 * @LastEditTime: 2020-07-30 23:23:47
 */ 
#include <bits/stdc++.h>

// #define DEBUG

using namespace std;

const double eps = 1e-7;
const double PI = acos(-1);
typedef pair<int, int> pii;
const int MOD = 998244353;
const int INF = 0x3f3f3f3f;
const int N = 2e5+7;

inline void solve() {
  int n;
  cin >> n;
  int t = 3*n/4;
  cout << string(t, '9')+string(n-t, '8') << endl;
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