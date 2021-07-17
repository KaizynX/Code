/*
 * @Author: Kaizyn
 * @Date: 2021-07-17 22:23:49
 * @LastEditTime: 2021-07-17 22:37:04
 */
#include <bits/stdc++.h>

// #define DEBUG

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
const double eps = 1e-7;
const double PI = acos(-1);
const int MOD = 998244353; // 1e9+7;
const int INF = 0x3f3f3f3f;
// const ll INF = 1e18;
// const int N = ;

inline void solve() {
  int n;
  cin >> n;
  int r = 1;
  while (n) {
    r = max(r, n%10);
    n /= 10;
  }
  cout << r << '\n';
}

signed main() {
#ifdef ONLINE_JUDGE
  ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
#endif
  int T = 1;
  cin >> T; // scanf("%d", &T);
  for (int t = 1; t <= T; ++t) {
    solve();
  }
  return 0;
}