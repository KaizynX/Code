/*
 * @Author: Kaizyn
 * @Date: 2020-09-05 15:34:12
 * @LastEditTime: 2020-09-05 15:39:58
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

int n, k;
int x[N], y[N];
int l[N], r[N];

inline void solve() {
  cin >> n >> k;
  for (int i = 1; i <= n; ++i) cin >> x[i];
  for (int i = 1; i <= n; ++i) cin >> y[i];
  sort(x+1, x+n+1);
  l[0] = r[n+1] = 0;
  for (int i = 1, last = 1; i <= n; ++i) {
    while (x[last] < x[i]-k) ++last;
    l[i] = max(l[i-1], i-last+1);
  }
  for (int i = n, last = n; i; --i) {
    while (x[last] > x[i]+k) --last;
    r[i] = max(r[i+1], last-i+1);
  }
  int res = 0;
  for (int i = 0; i <= n; ++i) {
    res = max(res, l[i]+r[i+1]);
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