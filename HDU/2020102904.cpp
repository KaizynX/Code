/*
 * @Author: Kaizyn
 * @Date: 2020-10-29 10:15:23
 * @LastEditTime: 2020-10-29 10:16:01
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

int a, b, c, d;

inline void solve() {
  cin >> a >> b >> c >> d;
  a *= c;
  b *= d;
  int g = __gcd(a, b);
  a /= g;
  b /= g;
  cout << a << " " << b << endl;
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