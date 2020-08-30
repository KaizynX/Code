/*
 * @Author: Kaizyn
 * @Date: 2020-08-24 14:34:54
 * @LastEditTime: 2020-08-24 14:43:28
 */
#include <bits/stdc++.h>

// #define DEBUG

using namespace std;

const double eps = 1e-7;
const double PI = acos(-1);
typedef pair<int, int> pii;
const int MOD = 998244353;
const int INF = 0x3f3f3f3f;
const int N = 30;

int n;
int a[N];

inline void solve() {
  cin >> n;
  int g = 0;
  for (int i = 1; i <= n; ++i) {
    cin >> a[i];
    // g = __gcd(g, abs(a[i]));
    g = __gcd(g, a[i]);
    // g = __gcd(a[i], g);
  }
  cout << abs(g) << endl;
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