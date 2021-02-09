/*
 * @Author: Kaizyn
 * @Date: 2021-02-09 13:53:04
 * @LastEditTime: 2021-02-09 16:32:44
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
int a[N], last[N];

inline void solve() {
  cin >> n;
  for (int i = 1; i <= n; ++i) {
    cin >> a[i];
    last[i] = -INF;
  }
  int res = 0;
  for (int i = 1, j; i <= n; i = j) {
    j = i+1;
    while (j <= n && a[j] == a[i]) ++j;
    if (j-i == 1) {
      ++res;
    } else {
      if (i-last[a[i]] <= 2) ++res;
      else res += 2, last[a[i]] = j-1;
    }
    // res += min(2, j-i);
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
7
1 1 2 1 1 2 1 1

5
*/