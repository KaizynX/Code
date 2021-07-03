/*
 * @Author: Kaizyn
 * @Date: 2021-06-13 13:11:47
 * @LastEditTime: 2021-06-13 13:14:55
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
// const int N = ;

int n;
map<string, int> cnt;

inline void solve() {
  cin >> n;
  string s;
  for (int i = 1; i <= n; ++i) {
    cin >> s;
    ++cnt[s];
  }
  int res = cnt["cat"];
  int t = min(cnt["c"], cnt["at"]);
  cnt["c"] -= t; cnt["at"] -= t; res += t;
  t = min(cnt["ca"], cnt["t"]);
  cnt["ca"] -= t; cnt["t"] -= t; res += t;
  res += min({cnt["c"], cnt["a"], cnt["t"]});
  cout << res << '\n';
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