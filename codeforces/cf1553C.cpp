/*
 * @Author: Kaizyn
 * @Date: 2021-07-22 22:32:23
 * @LastEditTime: 2021-07-22 23:05:02
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

string s;

inline void solve() {
  cin >> s;
  int res = 10, n = 10;
  for (int win : {0, 1}) {
    int cnt[2] = {0, 0}, rest[2] = {5, 5};
    for (int i = 0; i < n; ++i) {
      if (s[i] == '1') {
        ++cnt[i&1];
      } else if (s[i] == '0') {
      } else {
        if (i%2 == win) ++cnt[i&1];
      }
      --rest[i&1];
      if (cnt[win^1]+rest[win^1] < cnt[win]) {
        res = min(res, i+1);
        break;
      }
    }
  }
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