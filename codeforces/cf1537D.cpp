/*
 * @Author: Kaizyn
 * @Date: 2021-06-18 22:37:17
 * @LastEditTime: 2021-07-03 16:44:05
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

map<int, int> sg;

int f(int x) {
  if (sg.count(x)) return sg[x];
  int val = 0;
  for (int i = 2; i*i <= x; ++i) {
    if (x%i) continue;
    if (f(x-i) == 0 || f(x-x/i) == 0) {
      val = 1;
      break;
    }
  }
  return sg[x] = val;
}

inline void solve() {
  int n;
  cin >> n;
  cout << (f(n) ? "Alice" : "Bob") << '\n';
}

signed main() {
#ifdef ONLINE_JUDGE
  ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
#endif
  sg[1] = 0;
  int T = 1;
  cin >> T; // scanf("%d", &T);
  for (int t = 1; t <= T; ++t) {
    solve();
  }
  return 0;
}