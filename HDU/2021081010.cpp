/*
 * @Author: Kaizyn
 * @Date: 2021-08-10 12:12:17
 * @LastEditTime: 2021-08-10 12:13:35
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

double p, q;

inline void solve() {
  cin >> p >> q;
  int pp = p*10000+0.5;
  int qq = q*10000+0.5;
  cout << (qq < pp ? "ENJ0Y YOURS3LF!" : "N0 M0R3 BL4CK 1CE TEA!") << '\n';
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