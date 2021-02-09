/*
 * @Author: Kaizyn
 * @Date: 2021-01-08 22:33:27
 * @LastEditTime: 2021-01-08 23:29:41
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
const int N = 3e5+7;

int n[3];
int a[3][N], mx[3];
ll s[3];

inline void solve() {
  for (int i = 0; i < 3; ++i) cin >> n[i];
  for (int i = 0; i < 3; ++i) {
    mx[i] = INF;
    for (int j = 0; j < n[i]; ++j) {
      cin >> a[i][j];
      s[i] += a[i][j];
      mx[i] = min(mx[i], a[i][j]);
    }
  }
  ll res = s[0]+s[1]+s[2]-2*min({s[0], s[1], s[2]});
  for (int b = 0; b < 1<<3; ++b) {
    if (__builtin_popcount(b) == 2) {
      ll tmp = s[0]+s[1]+s[2];
      for (int i = 0; i < 3; ++i) {
        if ((b>>i)&1) tmp -= 2*mx[i];
      }
      res = max(res, tmp);
    }
  }
  cout << res << endl;
}

signed main() {
#ifdef ONLINE_JUDGE
  ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
#endif
  int T = 1;
  // cin >> T;
  for (int t = 1; t <= T; ++t) {
    solve();
  }
  return 0;
}