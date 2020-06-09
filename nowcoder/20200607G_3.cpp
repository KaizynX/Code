/*
 * @Author: Kaizyn
 * @Date: 2020-06-07 14:03:05
 * @LastEditTime: 2020-06-07 15:14:02
 */ 
#include <bits/stdc++.h>

// #define DEBUG

using namespace std;

const double eps = 1e-7;
const double PI = acos(-1);
typedef pair<int, int> pii;
const int MOD = 998244353;
const int INF = 0x3f3f3f3f;
const int N = 1e5+7;

int n, m;
int a[N], b[N];

inline void solve() {
  cin >> n;
  m = 0;
  for (int i = 1; i <= n; ++i) {
    cin >> a[i];
  }
  int val = a[1], cnt = 1;
  for (int i = 2; i <= n; ++i) {
    if (val != a[i]) {
      b[++m] = val*cnt;
      val = a[i];
      cnt = 1;
    } else {
      ++cnt;
    }
  }
  b[++m] = val*cnt;

  int res = 0;
  for (int i = 1; i <= m; ++i) {
    if (b[i] >= 0) res += b[i];
    else {
      if (b[i]%2 == 0) res += (-b[i])/2;
      else {
        if (i+2 <= m && b[i+1] == 1 && b[i+2]%2 == -1) {
          b[i+2] += 1;
          ++i;
          res += 1;
        } else if ((i-1 >= 1 && b[i-1] == 0) || (i+1 <= m && b[i+1] == 0)) {
          res += (-b[i])/2;
        } else {
          res += (-b[i])/2-1;
        }
      }
    }
  }
  cout << res << endl;
}

signed main() {
  ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
  int T = 1;
  cin >> T;
  for (int t = 1; t <= T; ++t) {
    solve();
  }
  return 0;
}
/*
3
-1 1 -1
7
-1 1 -1  1  -1 1 -1
4
-1 1 -1 -1
*/
/*
1
3
1
*/