/*
 * @Author: Kaizyn
 * @Date: 2020-11-02 22:33:24
 * @LastEditTime: 2020-11-03 00:15:59
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
int a[N], b[N], pa[N], pb[N];

inline int solve() {
  cin >> n >> k;
  for (int i = 1; i <= n; ++i) cin >> a[i];
  for (int i = 1; i <= k; ++i) cin >> b[i];
  int res = 1;
  for (int i = 1; i <= n; ++i) pa[a[i]] = i, pb[i] = 0;
  for (int i = 1; i <= k; ++i) pb[b[i]] = i;
  for (int i = 1; i <= k; ++i) {
    int p = pa[b[i]];
    int v = 0;
    if (p > 1 && pb[a[p-1]] < i) ++v;
    if (p < n && pb[a[p+1]] < i) ++v;
    (res *= v) %= MOD;
  }
  return res;
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