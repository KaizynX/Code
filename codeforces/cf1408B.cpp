/*
 * @Author: Kaizyn
 * @Date: 2020-09-30 22:32:40
 * @LastEditTime: 2020-10-01 01:08:43
 */
#include <bits/stdc++.h>

// #define DEBUG

using namespace std;

const double eps = 1e-7;
const double PI = acos(-1);
typedef pair<int, int> pii;
const int MOD = 998244353;
const int INF = 0x3f3f3f3f;
const int N = 1e2+7;

int n, k;
int a[N], b[N][N], c[N];

inline int solve() {
  cin >> n >> k;
  for (int i = 1; i <= n; ++i) cin >> a[i];
  n = unique(a+1, a+n+1)-a-1;
  if (n == 1) return 1;
  if (k == 1) return -1;
  /*
  for (int i = 1; i <= n; ++i) b[i][0] = -1;
  for (int m = 1; m <= a[n]; ++m) {
    int flag = 1;
    for (int i = 1; i <= m; ++i) c[i] = 0;
    for (int i = 1; i <= m; ++i) {
      for (int j = 1; j <= n; ++j) {
        b[i][j] = a[j]/m+(a[j]%m <= i);
        if (b[i][j] != b[i][j-1]) ++c[i];
        if (c[i] > k) {
          flag = 0;
          break;
        }
      }
      if (!flag) break;
    }
    if (flag) return m;
  }
  return -1;
  */
  if (n <= k) return 1;
  return (n-2)/(k-1)+1;
}

signed main() {
  ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
  int T = 1;
  cin >> T;
  for (int t = 1; t <= T; ++t) {
    cout << solve() << endl;
  }
  return 0;
}