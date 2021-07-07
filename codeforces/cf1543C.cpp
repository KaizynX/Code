/*
 * @Author: Kaizyn
 * @Date: 2021-07-07 23:58:12
 * @LastEditTime: 2021-07-08 00:06:31
 */
#include <bits/stdc++.h>

// #define DEBUG

using namespace std;

const double eps = 1e-7;
const double PI = acos(-1);
typedef pair<int, int> pii;
typedef long long ll;
const int MOD = 998244353; // 1e9+7;
const int INF = 0x3f3f3f3f;
// const ll INF = 1e18;
const int N = 3;

double res, v;

void f(double c, double m, double p, double now = 1, int len = 1) {
#ifdef DEBUG
  cout << c << ' ' << m << ' ' << p << ' ' << now << ' ' << len << '\n';
#endif
  res += len*now*p;
  if (c > eps && m > eps) f(max(0.0, c-v), m+min(c, v)/2, p+min(c, v)/2, now*c, len+1);
  if (c > eps && m > eps) f(c+min(m, v)/2, max(0.0, m-v), p+min(m, v)/2, now*m, len+1);
  if (c > eps && m < eps) f(max(0.0, c-v), 0.0, p+min(c, v), now*c, len+1);
  if (c < eps && m > eps) f(0.0, max(0.0, m-v), p+min(m, v), now*m, len+1);
}

inline void solve() {
  double c, m, p;
  cin >> c >> m >> p >> v;
  res = 0;
  f(c, m, p);
  printf("%.7f\n", res);
}

signed main() {
#ifdef ONLINE_JUDGE
  ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
#endif
  int T = 1;
  cin >> T; // scanf("%d", &T);
  for (int t = 1; t <= T; ++t) {
    solve();
  }
  return 0;
}