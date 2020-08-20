/*
 * @Author: Kaizyn
 * @Date: 2020-08-16 22:17:08
 * @LastEditTime: 2020-08-16 22:54:49
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
int a[N], b[N];

inline void solve() {
  cin >> n;
  for (int i = 1; i <= n; ++i) cin >> a[i];
  b[1] = a[1];
  for (int i = 2; i <= n; ++i) b[i] = max(b[i-1], a[i]);
  long long res = 0, lv = 0;
  for (int i = n; i; --i) {
    b[i] -= a[i];
    if (b[i] > lv) res += b[i]-lv;
    lv = b[i];
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