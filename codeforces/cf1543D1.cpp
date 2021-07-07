/*
 * @Author: Kaizyn
 * @Date: 2021-07-07 22:34:35
 * @LastEditTime: 2021-07-07 23:09:19
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
const int N = 2e5+7;

int n, k;

inline void solve() {
  cin >> n >> k;
  for (int i = 0, y; i < n; ++i) {
    cout << (i^max(0, i-1)) << endl;
    cin >> y;
    if (y) return;
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