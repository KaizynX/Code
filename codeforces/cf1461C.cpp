/*
 * @Author: Kaizyn
 * @Date: 2020-12-11 23:42:38
 * @LastEditTime: 2020-12-11 23:50:27
 */
#include <bits/stdc++.h>

// #define DEBUG

using namespace std;

const double eps = 1e-7;
const double PI = acos(-1);
typedef pair<int, int> pii;
const int MOD = 998244353;
const int INF = 0x3f3f3f3f;
const int N = 1e5+7;

int n, m;
int a[N], r[N];
double p[N];

inline void solve() {
  // cin >> n >> m;
  scanf("%d%d", &n, &m);
  for (int i = 1; i <= n; ++i) {
    // cin >> a[i];
    scanf("%d", a+i);
  }
  int k = n;
  double res = 1;
  while (k && a[k] == k) --k;
  for (int i = 1; i <= m; ++i) {
    scanf("%d%lf", r+i, p+i);
    // cin >> r[i] >> p[i];
    if (r[i] >= k) res *= 1-p[i];
  }
  if (!k) res = 0;
  printf("%.7f\n", 1-res);
}

signed main() {
  // ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
  int T = 1;
  // cin >> T;
  scanf("%d", &T);
  for (int t = 1; t <= T; ++t) {
    solve();
  }
  return 0;
}