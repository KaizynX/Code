/*
 * @Author: Kaizyn
 * @Date: 2021-08-21 13:24:43
 * @LastEditTime: 2021-08-21 13:28:36
 */
#include <bits/stdc++.h>

// #define DEBUG

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
const double eps = 1e-7;
const double PI = acos(-1);
const int MOD = 998244353; // 1e9+7;
// const int INF = 0x3f3f3f3f;
const ll INF = 1e18;
const int N = 1e5+7;
mt19937 rnd(chrono::high_resolution_clock::now().time_since_epoch().count());

int n;
int a[2][N], b[N];

bool fuck(int *x, int *y, int k) {
  ll mn = INF, mx = -INF;
  for (int i = 1; i <= n; ++i) {
    ll tmp = 1ll*k*x[i]-y[i];
    mn = min(mn, tmp);
    mx = max(mx, tmp);
  }
  return mx-mn <= 20;
}

bool check(int *x ,int *y) {
  double sk = 0;
  for (int t = 1; t <= n; ++t) {
    int i = rnd()%n+1, j = i;
    while (x[i] == x[j]) j = rnd()%n+1;
    sk += 1.0*(y[i]-y[j])/(x[i]-x[j]);
  }
  sk /= n;
  // cout << sk << '\n';
  for (int k = sk-3; k <= sk+3; ++k)
    if (fuck(x, y, k)) return true;
  return false;
}

inline void solve() {
  cin >> n;
  for (int i : {0, 1}) for (int j = 1; j <= n; ++j) cin >> a[i][j];
  for (int j = 1; j <= n; ++j) cin >> b[j];
  for (int i = 0; ; ++i) {
    if (check(a[i&1], b)) {
      cout << i+1 << '\n';
      break;
    }
  }
  // cout << (check(a[0], b) ? 1 : 2) << '\n';
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