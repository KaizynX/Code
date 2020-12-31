/*
 * @Author: Kaizyn
 * @Date: 2020-12-30 22:32:59
 * @LastEditTime: 2020-12-30 22:38:28
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
const int N = 1e2+7;

int n;
int a[N];
set<int> vis;

inline void solve() {
  vis.clear();
  cin >> n;
  for (int i = 1; i <= n; ++i) {
    cin >> a[i];
  }
  int res = 0;
  for (int i = 1; i <= n; ++i) {
    for (int j = i+1; j <= n; ++j) {
      int b = a[j]-a[i];
      if (vis.count(b)) continue;
      ++res;
      vis.insert(b);
    }
  }
  cout << res << endl;
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