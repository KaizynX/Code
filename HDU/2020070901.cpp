/*
 * @Author: Kaizyn
 * @Date: 2020-07-09 17:55:39
 * @LastEditTime: 2020-07-09 18:02:14
 */ 
#include <bits/stdc++.h>

// #define DEBUG

using namespace std;

const double eps = 1e-7;
const double PI = acos(-1);
typedef pair<int, int> pii;
const int MOD = 998244353;
const int INF = 0x3f3f3f3f;

int n, m;

inline void solve() {
  cin >> n >> m;
  if (m&1 || 2*n > m || 4*n < m) return cout << "No Solution!" << endl, void();
  m /= 2;
  int r = m-n, c = n-r;
  cout << c << " " << r << endl;
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