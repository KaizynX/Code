/*
 * @Author: Kaizyn
 * @Date: 2020-10-13 16:12:13
 * @LastEditTime: 2020-10-13 16:20:59
 */
#include <bits/stdc++.h>

// #define DEBUG

using namespace std;

const double eps = 1e-7;
const double PI = acos(-1);
typedef pair<int, int> pii;
const int MOD = 998244353;
const long long INF = 0x3f3f3f3f3f3f3f3f;
const int N = 2e3+7;

int n, k;
int l[N], r[N], a[N];
long long d[N];

inline void solve() {
  cin >> n >> k;
  for (int i = 1; i <= n; ++i) cin >> l[i] >> r[i] >> a[i];
  long long res = INF;
  memset(d, 0x3f, sizeof d);
  d[1] = 0;
  for (int i = 1; i <= n; ++i) {
    long long rem = k, tot = d[i];
    for (int j = i; j <= n; ++j) {
      long long t = (max(0ll, a[j]-rem)+k-1)/k;
      if (t > r[j]-l[j]) break;
      rem = t*k+rem-a[j];
      tot += a[j];
      if (j == n) res = min(res, tot);
      else if (l[j]+t < l[j+1]) d[j+1] = min(d[j+1], tot+rem);
    }
  }
  cout << (res >= INF ? -1 : res) << endl;
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