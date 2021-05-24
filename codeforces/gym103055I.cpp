/*
 * @Author: Kaizyn
 * @Date: 2021-05-02 12:51:37
 * @LastEditTime: 2021-05-02 13:17:56
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
const int N = 10;

int a[N];

inline void solve() {
  for (int i = 1; i <= 6; ++i) {
    static string str;
    cin >> str;
    a[i] = str == "true";
  }
  int res = 0;
  for (int i = 0; i < 1<<3; ++i) {
    int b1 = i&1, b2 = (i>>1)&1, b3 = (i>>2)&1;
    res += (!(a[1]^a[4])||(b1|b2))
        &  (!(a[2]^a[5])||(b1|b3))
        &  (!(a[3]^a[6])||(b2|b3));
  }
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
/*
8
false false false false false false
true true true true true true
false true false false true false

4
false true true true false false
*/