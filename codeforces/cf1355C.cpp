/*
 * @Author: Kaizyn
 * @Date: 2020-05-16 19:25:45
 * @LastEditTime: 2020-05-16 20:16:46
 */ 
#include <bits/stdc++.h>

#define DEBUG

using namespace std;

const double eps = 1e-7;
const double PI = acos(-1);
typedef pair<int, int> pii;
const int MOD = 998244353;
const int INF = 0x3f3f3f3f;

int a, b, c, d;

inline void solve() {
  cin >> a >> b >> c >> d;
  long long res = 0;
  for (int i = a, j, st; i <= b; ++i) {
    // a <= i <= b <= j <= c <= k <= d
    // i+j > k
    j = max(c-i+1, b);
    st = i+j-c;
    res += 1ll*(st+st+c-j)*(c-j+1)/2;
    #ifdef DEBUG
    cout << j << " " << st << endl;
    #endif
    if (i+c-1 > d) {
      // i+j-1 == d+1
      j = max(d+2-i, b);
      st = i+j-d-1;
      res -= 1ll*(st+st+c-j)*(c-j+1)/2;
      #ifdef DEBUG
      cout << "del:" << j << " " << st << endl;
      #endif
    }
  }
  cout << res << endl;
}

signed main() {
  ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
  int T = 1;
  // cin >> T;
  for (int t = 1; t <= T; ++t) {
    solve();
  }
  return 0;
}