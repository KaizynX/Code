/*
 * @Author: Kaizyn
 * @Date: 2020-08-27 13:09:59
 * @LastEditTime: 2020-08-27 13:15:01
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

int n;
long long res;

inline void solve() {
  cin >> n;
  for (int i = 1; i <= n; ++i) res += i*(n-i+1ll);
  for (int i = 1, u, v; i < n; ++i) {
    cin >> u >> v;
    if (u > v) swap(u, v);
    res -= u*(n-v+1ll);
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