/*
 * @Author: Kaizyn
 * @Date: 2021-01-14 10:26:18
 * @LastEditTime: 2021-01-14 10:29:13
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
// const ll INF = 1e18;
// const int N = ;
/*
假设要行走的距离为L米，每次找车和开锁的时间一共是T1秒，每次停车和锁车的时间一共是T2秒，骑车的速度为V1米/秒，行走的速度为V2米/秒。
*/

inline void solve() {
  int l, t1, t2, v1, v2;
  cin >> l >> t1 >> t2 >> v1 >> v2;
  // l/v2 cmp l/v1+t1+t2
  ll r1 = l*v1, r2 = l*v2+(t1+t2)*v1*v2;
  if (r1 == r2) cout << "Both are OK!" << endl;
  if (r1 < r2) cout << "Walk is OK!" << endl;
  if (r1 > r2) cout << "Bike is OK!" << endl;
}

signed main() {
#ifdef ONLINE_JUDGE
  ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
#endif
  int T = 1;
  cin >> T;
  for (int t = 1; t <= T; ++t) {
    solve();
  }
  return 0;
}