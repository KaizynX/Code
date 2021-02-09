/*
 * @Author: Kaizyn
 * @Date: 2021-02-09 15:16:14
 * @LastEditTime: 2021-02-09 15:18:46
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
const int N = 1e5+7;

int n;
int a[N];

inline void solve() {
  cin >> n;
  for (int i = 1; i <= n; ++i) {
    cin >> a[i];
  }
  int res = 0;
  for (int i = 1, s1 = 0, s2 = 0; i <= n; ++i) {
    if (a[i] != s1) {
      s1 = a[i];
      ++res;
    } else if (a[i] != s2) {
      s2 = a[i];
      ++res;
    }
  }
  cout << res << '\n';
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
/*
8
1 1 2 1 1 2 1 1

6
*/