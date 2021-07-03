/*
 * @Author: Kaizyn
 * @Date: 2021-06-09 14:18:20
 * @LastEditTime: 2021-06-09 16:48:35
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
const int N = 6e3+7;

int n;
int a[N], b[N*N];

int magic(int x) {
  int y = 1;
  for (int i = 2, k; i*i <= x; ++i) {
    if (x%i) continue;
    k = 0;
    while (x%i == 0) x /= i, ++k;
    if (k&1) y *= i;
  }
  return y*x;
}

inline int magic(const int &x, const int &y) {
  int g = __gcd(x, y);
  return x/g*y/g;
}

inline void solve() {
  cin >> n;
  for (int i = 1; i <= n; ++i) {
    cin >> a[i];
    a[i] = magic(a[i]);
  }
  ll cnt = 0;
  for (int i = 1; i <= n; ++i) {
    for (int j = i+1; j <= n; ++j) {
      auto v = magic(a[i], a[j]);
      if (v == 1) cnt -= n-2;
      auto &t = b[v];
      cnt += t;
      ++t;
    }
  }
  cout << cnt/3 << '\n';
}

signed main() {
#ifdef ONLINE_JUDGE
  ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
#endif
  int T = 1;
  // cin >> T; // scanf("%d", &T);
  for (int t = 1; t <= T; ++t) {
    solve();
  }
  return 0;
}