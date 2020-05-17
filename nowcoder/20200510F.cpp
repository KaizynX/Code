/*
 * @Author: Kaizyn
 * @Date: 2020-05-10 13:10:40
 * @LastEditTime: 2020-05-10 13:13:37
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

int n, m;
int a[N], k[N];

inline void solve() {
  cin >> n >> m;
  memset(a+1, 0, sizeof n);
  for (int i = 1, l, r; i <= m; ++i) {
    cin >> l >> r;
    ++a[l]; --a[r+1];
  }
  for(int i = 1; i <= n; ++i) {
    a[i] += a[i-1];
    k[i] = i;
  }
  sort(k+1, k+n+1, [&](const int &x, const int &y) {
      return a[x] < a[y];
  });
  long long res = 0;
  for (int i = 1; i <= n; ++i) {
    res += 1ll*a[k[i]]*i;
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