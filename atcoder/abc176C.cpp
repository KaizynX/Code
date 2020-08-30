/*
 * @Author: Kaizyn
 * @Date: 2020-08-22 21:22:54
 * @LastEditTime: 2020-08-22 21:24:43
 */
#include <bits/stdc++.h>

// #define DEBUG

using namespace std;

const double eps = 1e-7;
const double PI = acos(-1);
typedef pair<int, int> pii;
const int MOD = 998244353;
const int INF = 0x3f3f3f3f;
const int N = 2e5+7;

int n;
int a[N], mv[N];

inline void solve() {
  cin >> n;
  long long res = 0;
  for (int i = 1; i <= n; ++i) {
    cin >> a[i];
    if (a[i] < mv[i-1]) res += mv[i-1]-a[i];
    mv[i] = max(mv[i-1], a[i]);
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