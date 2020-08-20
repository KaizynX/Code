/*
 * @Author: Kaizyn
 * @Date: 2020-08-09 22:33:58
 * @LastEditTime: 2020-08-09 22:52:44
 */
#include <bits/stdc++.h>

// #define DEBUG

using namespace std;

const double eps = 1e-7;
const double PI = acos(-1);
typedef pair<int, int> pii;
const int MOD = 998244353;
const int INF = 0x3f3f3f3f;
const int N = 1e3+7;

int a[N][N];

inline void print() {
  for (int i = 0; i < 4; ++i) {
    for (int j = 0; j < 4; ++j) {
      cout << a[i][j];
    }
    cout << endl;
  }
}

inline void solve() {
  for (int b = 0; b < 1<<16; ++b) {
    int sum = 0;
    for (int i = 0; i < 4; ++i) {
      for (int j = 0; j < 4; ++j) {
        a[i][j] = b>>(i*4)>>j&1;
        sum += a[i][j];
      }
    }
    int flag = sum&1;
    for (int i = 0; i < 3; ++i) {
      for (int j = 0; j < 3; ++j) {
        int sum = a[i][j]+a[i+1][j]+a[i][j+1]+a[i+1][j+1];
        flag &= sum&1;
      }
    }
    if (flag) print();
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