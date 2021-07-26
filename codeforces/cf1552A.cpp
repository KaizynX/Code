/*
 * @Author: Kaizyn
 * @Date: 2021-07-25 22:29:58
 * @LastEditTime: 2021-07-25 22:36:55
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

int n;
string s, t;

inline void solve() {
  cin >> n >> s;
  t = s;
  sort(t.begin(), t.end());
  int k = n;
  for (int i = 0; i < n; ++i) {
    k -= s[i] == t[i];
  }
  cout << k << '\n';
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