/*
 * @Author: Kaizyn
 * @Date: 2021-07-05 23:00:41
 * @LastEditTime: 2021-07-05 23:01:15
 */
#include <bits/stdc++.h>

// #define DEBUG

using namespace std;

const double eps = 1e-7;
const double PI = acos(-1);
typedef pair<int, int> pii;
typedef long long ll;
const int MOD = 998244353; // 1e9+7;
const int INF = 0x3f3f3f3f;
// const ll INF = 1e18;
const int N = 5e5+7;

int n, k;
string s;

inline void solve() {
  cin >> n >> k >> s;
  int m = 1;
  for (int p = 1; p < n; ++p) {
    if (s[p] > s[p%m]) break;
    if (s[p] < s[p%m]) m = p+1;
  }
  for (int i = 0; i < k; ++i) cout << s[i%m];
  cout << '\n';
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