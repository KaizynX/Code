/*
 * @Author: Kaizyn
 * @Date: 2020-08-12 16:42:37
 * @LastEditTime: 2020-08-12 16:51:13
 */
#include <bits/stdc++.h>

// #define DEBUG

using namespace std;

const double eps = 1e-7;
const double PI = acos(-1);
typedef pair<int, int> pii;
const int MOD = 1e9+7;
const int INF = 0x3f3f3f3f;
const int N = 1<<20;

int n, m, len;
int a[N], pw[N];

template <class T> void fwt_and(T a[], const int x = 1) {
  for (int l = 2; l <= len; l <<= 1)
  for (int i = 0, k = l>>1; i < len; i += l)
  for (int j = 0; j < k; ++j)
    a[i+j] = (a[i+j]+1ll*a[i+j+k]*x)%MOD;
}

inline void solve() {
  cin >> n;
  for (int i = 0, ai; i < n; ++i) {
    cin >> ai;
    ++a[ai];
    m = max(m, ai);
  }
  ++m;
  pw[0] = 1;
  for (int i = 1; i <= n; ++i) {
    pw[i] = pw[i-1]<<1;
    if (pw[i] > MOD) pw[i] -= MOD;
  }
  len = 1;
  while (len < m) len <<= 1;
  fwt_and(a);
  for (int i = 0 ; i < m; ++i) {
    a[i] = pw[a[i]]-1;
    if (a[i] < 0) a[i] += MOD;
  }
  fwt_and(a, MOD-1);
  cout << a[0] << endl;
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