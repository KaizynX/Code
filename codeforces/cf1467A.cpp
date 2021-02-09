/*
 * @Author: Kaizyn
 * @Date: 2021-01-08 22:33:05
 * @LastEditTime: 2021-01-08 22:41:44
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
const int N = 2e5+7;

inline void solve() {
  int n;
  cin >> n;
  if (n == 1) cout << 9 << endl;
  else if (n == 2) cout << 98 << endl;
  else {
    cout << 98;
    for (int i = 3, j = 9; i <= n; ++i) {
      cout << j;
      if (++j > 9) j = 0;
    }
    cout << endl;
  }
  /*
  for (int i = 1, j = 9; i <= n; ++i) {
    cout << j;
    --j;
    if (j < 0) j = 9;
  }
  cout << endl;
  */
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