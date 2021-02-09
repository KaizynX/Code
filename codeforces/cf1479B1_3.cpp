/*
 * @Author: Kaizyn
 * @Date: 2021-02-09 16:32:37
 * @LastEditTime: 2021-02-09 16:36:51
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
vector<int> pos[N];

inline void solve() {
  cin >> n;
  for (int i = 1; i <= n; ++i) {
    cin >> a[i];
    pos[a[i]].emplace_back(i);
  }
  for (int i = 0; i <= n; ++i) {
    pos[i].emplace_back(n+1);
    reverse(pos[i].begin(), pos[i].end());
  }
  int res = 0;
  for (int i = 1, x = 0, y = 0; i <= n; ++i) {
    if (a[i] == x) {
      res += y != a[i];
      y = a[i];
    } else if (a[i] == y) {
      res += x != a[i];
      x = a[i];
    } else {
      ++res;
      if (pos[x].back() < pos[y].back()) {
        x = a[i];
      } else {
        y = a[i];
      }
    }
    pos[a[i]].pop_back();
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