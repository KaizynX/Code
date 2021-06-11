/*
 * @Author: Kaizyn
 * @Date: 2021-06-09 13:53:41
 * @LastEditTime: 2021-06-09 14:07:10
 */
#include <bits/stdc++.h>

// #define DEBUG

using namespace std;

const double eps = 1e-7;
const double PI = acos(-1);
typedef pair<int, int> pii;
typedef long long ll;
// const int MOD = 998244353; // 1e9+7;
const int INF = 0x3f3f3f3f;
// const ll INF = 1e18;
// const int N = ;
const ll MOD = 1e10+7;

// n²(n+1)²/4

template <typename T> void write(T x) {
  if(x < 0) x = -x, putchar('-');
  if(x > 9) write(x/10);
  putchar(x%10+'0');
}

__int128_t f(__int128_t x) {
  if (x%2) {
    return x*x%MOD*((x+1)/2)%MOD*((x+1)/2)%MOD;
  } else {
    return x/2*x/2%MOD*(x+1)%MOD*(x+1)%MOD;
  }
}

__int128_t g(__int128_t x) {
  return x*x%MOD*x%MOD;
}

inline void solve() {
  ll l, r;
  cin >> l >> r;
  write(g((f(r)-f(l-1)+MOD)%MOD));
  putchar('\n');
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