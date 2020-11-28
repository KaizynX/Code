/*
 * @Author: Kaizyn
 * @Date: 2020-11-02 22:16:09
 * @LastEditTime: 2020-11-02 22:56:18
 */
#include <bits/stdc++.h>

// #define DEBUG

using namespace std;

const double eps = 1e-7;
const double PI = acos(-1);
typedef pair<int, int> pii;
const int MOD = 998244353;
const int INF = 0x3f3f3f3f;
const int N = 3e4+7;

int n;
int a[N];

inline bool solve() {
  cin >> n;
  for (int i = 1; i <= n; ++i) cin >> a[i];
  int l = a[1], r = 0;
  for (int i = 1; i <= n; ++i) {
    l = min(l, a[i]);
    int tmp = a[i]-l;
    if (tmp < r) {
      l -= r-tmp;
      if (l < 0) return false;
    } else {
      r = tmp;
    }
  }
  return true;
}

signed main() {
  ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
  int T = 1;
  cin >> T;
  for (int t = 1; t <= T; ++t) {
    cout << (solve() ? "YES" : "NO") << endl;
  }
  return 0;
}
/*
4
3 4 3 4
*/