/*
 * @Author: Kaizyn
 * @Date: 2020-11-16 19:25:45
 * @LastEditTime: 2020-11-16 19:30:18
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
int a[N];

int f(int b, int l, int r) {
  if (l > r) return 0;
  if (!b) return r-l+1;
  int m = l;
  while (m <= r && ~(a[m]>>b)&1) ++m;
  int vl = f(b-1, l, m-1);
  int vr = f(b-1, m, r);
  return max(vl+(vr > 0), vr+(vl > 0));
}

inline void solve() {
  cin >> n;
  for (int i = 1; i <= n; ++i) cin >> a[i];
  sort(a+1, a+n+1);
  cout << n-f(29, 1, n) << endl;
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