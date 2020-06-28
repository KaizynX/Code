/*
 * @Author: Kaizyn
 * @Date: 2020-06-23 15:09:05
 * @LastEditTime: 2020-06-23 15:12:04
 */ 
#include <bits/stdc++.h>

// #define DEBUG

using namespace std;

const double eps = 1e-7;
const double PI = acos(-1);
typedef pair<int, int> pii;
const int MOD = 998244353;
const int INF = 0x3f3f3f3f;

int L, R, m;

int f(int x) {
  int sum = 0, res = 0;
  while (x) {
    (res += x%10*sum) %= m;
    (sum += x%10) %= m;
    x /= 10;
  }
  return res;
}

inline void solve() {
  cin >> L >> R >> m;
  int res = 0;
  for (int i = L; i <= R; ++i) {
    res += f(i) == i%m;
  }
  cout << res << endl;
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