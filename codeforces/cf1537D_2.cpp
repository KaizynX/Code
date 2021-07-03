/*
 * @Author: Kaizyn
 * @Date: 2021-07-03 16:43:40
 * @LastEditTime: 2021-07-03 16:47:40
 */
#include <bits/stdc++.h>

// #define DEBUG

using namespace std;

const double eps = 1e-7;
const double PI = acos(-1);
typedef pair<int, int> pii;
typedef long long ll;
const int MOD = 998244353; // 1e9+7;
const int INF = 0x3f3f3f3f;
// const ll INF = 1e18;
// const int N = ;

inline bool f(int x) {
  if (x%2) return false;
  int k = 0;
  while (x%2 == 0) x /= 2, ++k;
  if (x == 1) return k%2 == 0;
  return true;
}

inline void solve() {
  int n;
  cin >> n;
  cout << (f(n) ? "Alice" : "Bob") << '\n';
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