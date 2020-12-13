/*
 * @Author: Kaizyn
 * @Date: 2020-12-11 23:12:54
 * @LastEditTime: 2020-12-11 23:37:51
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
const int N = 1e6+7;

ll k, l, r, t, x, y;
ll vis[N];

inline bool solve() {
  cin >> k >> l >> r >> t >> x >> y;
  if (k+y <= r) k += y;
  if (k-x < l) return false; // first day
  if (x == y) return k-x >= l;
  if (x > y) return t <= (k-l-y)/(x-y); // ceil( (k-l+1-x)/(x-y) )
  if (r-y < l) return t < (k-l+x)/x; // could never add water
  if (r-y-x+1 >= l) return true;
  for (int flag = 0; t; ) {
    if (flag && k <= r-y) {
      if (vis[r-y-k]) return true;
      vis[r-y-k] = 1;
      k += y;
    } else {
      // make k <= r-y
      ll d = min(t, (k-r+y+x-1)/x);
      t -= d;
      k -= d*x;
      if (k < l) return false;
      flag = 1;
    }
  }
  return true;
}

signed main() {
  ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
  int T = 1;
  // cin >> T;
  for (int t = 1; t <= T; ++t) {
    cout << (solve() ? "Yes" : "No") << endl;
  }
  return 0;
}