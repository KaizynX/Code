/*
 * @Author: Kaizyn
 * @Date: 2020-08-01 12:23:54
 * @LastEditTime: 2020-08-01 12:45:38
 */ 
#include <bits/stdc++.h>

// #define DEBUG

using namespace std;

const double eps = 1e-7;
const double PI = acos(-1);
typedef pair<int, int> pii;
typedef long long ll;
const int MOD = 998244353;
const int INF = 0x3f3f3f3f;
// const int N = ;

inline void solve() {
  ll n, k;
  cin >> n >> k;
  // for (n = 1; n <= 10; ++n) for (k = 1; k <= 10; ++k) {
  ll res = 0;
  for (int i = 1; i <= k; ++i) {
    ++res; // n == 1
    for (int j = 2; j <= n; ++j) {
      if (j%i == 0 || (j-1)%i == 0) ++res;
    }
  }
  cout << res << endl;
  // }
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