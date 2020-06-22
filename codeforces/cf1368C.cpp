/*
 * @Author: Kaizyn
 * @Date: 2020-06-18 22:29:49
 * @LastEditTime: 2020-06-18 23:38:20
 */ 
#include <bits/stdc++.h>

// #define DEBUG

using namespace std;

const double eps = 1e-7;
const double PI = acos(-1);
typedef pair<int, int> pii;
const int MOD = 998244353;
const int INF = 0x3f3f3f3f;

int n;

inline void solve() {
  cin >> n;
  cout << n*7+8 << endl;
  cout << 0 << " " << -2 << endl;
  cout << 0 << " " << -1 << endl;
  cout << 0 << " " << 0 << endl;
  for (int i = 1; i < 2*n+2; ++i) {
    cout << i << " " << 0 << endl;
    if (i%2 == 0) {
      cout << i << " " << -2 << endl;
      cout << i << " " << -1 << endl;
      cout << i << " " << 1 << endl;
      cout << i << " " << 2 << endl;
    } else {
      if (i/2%2) {
        cout << i << " " << 2 << endl;
      } else {
        cout << i << " " << -2 << endl;
      }
    }
  }
  int m = 2*n+2;
  if (n%2) {
    cout << m << " " << 0 << endl;
    cout << m << " " << 1 << endl;
    cout << m << " " << 2 << endl;
  } else {
    cout << m << " " << 0 << endl;
    cout << m << " " << -1 << endl;
    cout << m << " " << -2 << endl;
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