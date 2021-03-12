/*
 * @Author: Kaizyn
 * @Date: 2021-03-10 20:02:51
 * @LastEditTime: 2021-03-10 20:16:13
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
const int N = 1e5+7;

int n;
vector<int> a, b;

inline double dis(ll x, ll y) {
  return sqrt(x*x + y*y);
}

inline void solve() {
  a.clear();
  b.clear();
  // cin >> n;
  scanf("%d", &n);
  for (int i = 1, x, y; i <= 2*n; ++i) {
    // cin >> x >> y;
    scanf("%d%d", &x, &y);
    if (x) a.emplace_back(abs(x));
    if (y) b.emplace_back(abs(y));
  }
  sort(a.begin(), a.end());
  sort(b.begin(), b.end());
  // reverse(a.begin(), a.end());
  double res = 0;
  for (int i = 0; i < n; ++i) {
    res += dis(a[i], b[i]);
  }
  // cout << res << '\n';
  printf("%.10f\n", res);
}

signed main() {
#ifdef ONLINE_JUDGE
  // ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
#endif
  int T = 1;
  scanf("%d", &T);
  for (int t = 1; t <= T; ++t) {
    solve();
  }
  return 0;
}