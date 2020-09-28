/*
 * @Author: Kaizyn
 * @Date: 2020-09-28 15:17:07
 * @LastEditTime: 2020-09-28 15:24:20
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

int n, m, q;
int op[N], x[N];
int col[N], row[N];

signed main() {
  ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
  cin >> n >> q;
  m = n;
  for (int i = 1; i <= q; ++i) {
    cin >> op[i] >> x[i];
    if (op[i] == 1) ++col[x[i]];
    else ++row[x[i]];
  }
  for (int i = 1; i <= n; ++i) {
    col[i] += col[i-1];
    row[i] += row[i-1];
  }
  long long res = (n-2ll)*(n-2ll);
  for (int i = 1; i <= q; ++i) {
    if (op[i] == 1) {
      if (x[i] >= m) continue;
      res -= (n-2ll)*(col[m-1]-col[x[i]-1]);
      m = x[i];
    } else {
      if (x[i] >= n) continue;
      res -= (m-2ll)*(row[n-1]-row[x[i]-1]);
      n = x[i];
    }
  }
  cout << res << endl;
  return 0;
}