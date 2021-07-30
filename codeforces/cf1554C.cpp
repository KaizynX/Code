/*
 * @Author: Kaizyn
 * @Date: 2021-07-29 22:59:31
 * @LastEditTime: 2021-07-29 23:15:23
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

int n, m;

inline void solve() {
  cin >> n >> m;
  if (n > m) return cout << "0\n", void();
  int res = 0, flag = 0;
  #ifdef DEBUG
  cout << "n=" << bitset<30>(n) << '\n';
  cout << "m=" << bitset<30>(m) << '\n';
  #endif
  for (int b = 29; b >= 0; --b) {
    int nb = (n>>b)&1, mb = (m>>b)&1;
    if (nb == mb) continue;
    if (nb < mb) res |= 1<<b;
    if (nb > mb) { flag = 1; break; }
  }
  if (!flag) for (int b = 0; b <= 29; ++b) {
    int nb = (n>>b)&1, mb = (m>>b)&1;
    if (nb == 0 && mb == 0) {
      res &= ~((1<<b)-1);
      res |= 1<<b;
      // if ((1<<b) > res) res = 1<<b;
      // else res |= 1<<b;
      break;
    }
  }
  #ifdef DEBUG
  cout << "r=" << bitset<30>(res) << '\n';
  #endif
  cout << res << '\n';
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