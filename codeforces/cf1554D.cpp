/*
 * @Author: Kaizyn
 * @Date: 2021-07-29 22:45:42
 * @LastEditTime: 2021-07-29 22:52:04
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

int n;

inline void solve() {
  cin >> n;
  if (n == 1) return cout << "a\n", void();
  int r = 1+n%2;
  int k = (n-r)/2;
  cout << string(k, 'a')+(r == 1 ? "b" : "bc")+string(k+1, 'a') << '\n';
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