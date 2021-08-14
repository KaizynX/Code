/*
 * @Author: Kaizyn
 * @Date: 2021-08-14 12:01:34
 * @LastEditTime: 2021-08-14 12:10:33
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

ll n;

inline void solve() {
  cin >> n;
  --n;
  ll cur = 1, num = 1;
  while (cur*3 <= n) {
    cur *= 3;
    ++num;
    n -= cur;
  }
  // --n;
  while (num--) {
    cout << "236"[n/cur];
    n %= cur;
    cur /= 3;
  }
}

signed main() {
#ifdef ONLINE_JUDGE
  ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
#endif
  int T = 1;
  // cin >> T; // scanf("%d", &T);
  for (int t = 1; t <= T; ++t) {
    solve();
  }
  return 0;
}