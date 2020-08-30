/*
 * @Author: Kaizyn
 * @Date: 2020-08-29 21:37:37
 * @LastEditTime: 2020-08-29 21:38:59
 */
#include <bits/stdc++.h>

// #define DEBUG

using namespace std;

const double eps = 1e-7;
const double PI = acos(-1);
typedef pair<int, int> pii;
const int MOD = 1e9+7;
const int INF = 0x3f3f3f3f;
const int N = 2e5+7;

int n;
int a[N];

inline void solve() {
  cin >> n;
  long long sum = 0, res = 0;
  for (int i=  1; i <= n; ++i) {
    cin >> a[i];
    sum += a[i];
  }
  for (int i = 1; i <= n; ++i) {
    sum -= a[i];
    res += sum%MOD*a[i]%MOD;
  }
  cout << res%MOD << endl;
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