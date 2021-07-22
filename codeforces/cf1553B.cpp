/*
 * @Author: Kaizyn
 * @Date: 2021-07-22 22:32:15
 * @LastEditTime: 2021-07-22 22:51:57
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
const int N = 5e2+7;

string s, t;

inline bool solve() {
  cin >> s >> t;
  int n = s.size(), m = t.size();
  /*
  for (int i = 0; i < n; ++i) {
    for (int j = 0; i+j < n && j+1 <= m; ++j) {
      // right to i+j
      if (j-m+j < 0) continue;
      string f = s.substr(i, j+1);
      string g = s.substr(j-m+j, m-j-1);
      reverse(g.begin(), g.end());
      if (f+g == t) return true;
    }
  }
  */
  for (int i = 0; i < n; ++i) {
    for (int j = 0, k; j <= m; ++j) {
      k = m-j;
      if (i-j+1 < 0) continue;
      if (i-k < 0) continue;
      string sr = s.substr(i-j+1, j);
      string sl = s.substr(i-k, k);
      reverse(sl.begin(), sl.end());
      if (sr+sl == t) return true;
    }
  }
  return false;
}

signed main() {
#ifdef ONLINE_JUDGE
  ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
#endif
  int T = 1;
  cin >> T; // scanf("%d", &T);
  for (int t = 1; t <= T; ++t) {
    cout << (solve() ? "YES" : "NO") << '\n';
  }
  return 0;
}