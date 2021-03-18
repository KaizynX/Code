/*
 * @Author: Kaizyn
 * @Date: 2021-03-17 22:34:06
 * @LastEditTime: 2021-03-17 22:52:49
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

// 16
inline void solve() {
  int n, k;
  cin >> n >> k;
  if (n&1) {
    cout << 1 << " " << (n-1)/2 << " " << (n-1)/2 << '\n';
  } else {
    if ((n-2)/2%2) {
      cout << n/2 << " " << n/4 << " " << n/4 << '\n';
    } else {
      cout << 2 << " " << (n-2)/2 << " " << (n-2)/2 << '\n';
    }
  }
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