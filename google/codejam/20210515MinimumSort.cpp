/*
 * @Author: Kaizyn
 * @Date: 2021-05-15 22:54:58
 * @LastEditTime: 2021-05-15 23:24:29
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
const int N = 1e2+7;

int n;

inline int my_query(int l, int r) {
  if (l > r) swap(l, r);
  cout << "M " << l << ' ' << r << endl;
  cin >> l;
  return l;
}

inline void my_swap(int l, int r) {
  if (l > r) swap(l, r);
  cout << "S " << l << ' ' << r << endl;
  cin >> l;
  assert(l == 1);
}

inline bool check() {
  cout << "D" << endl;
  int x;
  cin >> x;
  return x == 1;
}

/*
[51,33,100,11]
[30,20,10,40]
*/
inline void solve() {
  /*
  int res = 0;
  for (int i = 1; i <= 100; ++i) {
    res += (100'000'000+i-1)/i;
  }
  cout << res << ' ' << (res <= 6e8) << '\n';
  */
  // cin >> n;
  for (int i = 1, x; i < n; ++i) {
    x = my_query(i, n);
    if (x != i) my_swap(i, x);
  }
  if (!check()) return;
}

signed main() {
#ifdef ONLINE_JUDGE
  ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
#endif
  int T = 1;
  cin >> T >> n; // scanf("%d", &T);
  for (int t = 1; t <= T; ++t) {
    solve();
  }
  return 0;
}