/*
 * @Author: Kaizyn
 * @Date: 2021-08-07 12:02:50
 * @LastEditTime: 2021-08-07 12:12:21
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

int x, s;

inline ll solve() {
  cin >> x >> s;
  if ((x|s)>s) return 0;
  return (1ll<<__builtin_popcount(x&s))-(x==s);
}

signed main() {
#ifdef ONLINE_JUDGE
  ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
#endif
  int T = 1;
  // cin >> T; // scanf("%d", &T);
  for (int t = 1; t <= T; ++t) {
    cout << solve() << '\n';
  }
  return 0;
}