/*
 * @Author: Kaizyn
 * @Date: 2020-07-17 19:39:33
 * @LastEditTime: 2020-07-17 19:41:42
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

int n;

inline void solve() {
  cin >> n;
  int res = 0;
  for (int i = 1, x; i <= n; ++i) {
    char ch;
    cin >> ch >> x;
    if (ch == 'S') res = max(res, x);
    else res = max(res, (1<<x)-1);
  }
  cout << res << endl;
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