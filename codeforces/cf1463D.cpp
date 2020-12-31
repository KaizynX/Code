/*
 * @Author: Kaizyn
 * @Date: 2020-12-17 22:38:15
 * @LastEditTime: 2020-12-17 22:53:03
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
const int N = 4e5+7;

int n;
int a[N], b[N];

inline void solve() {
  cin >> n;
  for (int i = 1; i <= n; ++i) cin >> a[i];
  for (int j = 1, i = 1, k = 1; j <= n; ++j, ++k) {
    while (i <= n && a[i] == k) ++k, ++i;
    b[j] = k;
  }
  int l, r, m, flag, lef, rig;
  l = 0; r = n;
  while (l < r) {
    flag = 1;
    m = (l+r+1)>>1;
    for (int i = 1; i <= m; ++i) flag &= a[i] < b[n-m+i];
    if (flag) l = m;
    else r = m-1;
  }
  lef = l;
  l = 0; r = n;
  while (l < r) {
    flag = 1;
    m = (l+r+1)>>1;
    for (int i = 1; i <= m; ++i) flag &= a[n-m+i] > b[i];
    if (flag) l = m;
    else r = m-1;
  }
  rig = l;
  // n-rig <= x <= lef
  cout << max(0, lef+rig-n+1) << endl;
}

signed main() {
#ifndef DEBUG
  ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
#endif
  int T = 1;
  cin >> T;
  for (int t = 1; t <= T; ++t) {
    solve();
  }
  return 0;
}