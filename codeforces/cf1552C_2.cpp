/*
 * @Author: Kaizyn
 * @Date: 2021-07-25 23:17:57
 * @LastEditTime: 2021-07-25 23:45:26
 */
#include <bits/stdc++.h>

// #define DEBUG

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
const double eps = 1e-7;
const double PI = acos(-1);
const int MOD = 998244353; // 1e9+7;
const int INF = 0x3f3f3f3f;
// const ll INF = 1e18;
const int N = 2e2+7;

int n, k;
int vis[N], a[N];

int check(int i, int j) {
  // return (i < j) == (vis[i] < vis[j]);
  int j1 = (j-i+2*n)%(2*n);
  int j2 = (vis[j]-i+2*n)%(2*n);
  int i2 = vis[i]-i;
  return (j1 < i2)^(j2 < i2);
}

inline void solve() {
  cin >> n >> k;
  for (int i = 0; i < 2*n; ++i) vis[i] = -1;
  for (int i = 0, x, y; i < k; ++i) {
    cin >> x >> y;
    --x; --y;
    vis[x] = y;
    vis[y] = x;
  }
  int m = 0;
  for (int i = 0; i < 2*n; ++i) {
    if (~vis[i]) continue;
    a[++m] = i;
  }
  for (int i = 1; i <= m/2; ++i) {
    vis[a[i]] = a[i+m/2];
    vis[a[i+m/2]] = a[i];
  }
  #ifdef DEBUG
  for (int i = 0; i < 2*n; ++i) {
    if (vis[i] < i) continue;
    cout << i << ' ' << vis[i] << '\n';
  }
  #endif
  int res = 0;
  for (int i = 0; i < 2*n; ++i) {
    if (vis[i] < i) continue;
    for (int j = 0; j < i; ++j) {
      if (vis[j] < j) continue;
      res += check(i, j);
      #ifdef DEBUG
      printf("(%d,%d)(%d,%d)=%d\n", i, vis[i], j, vis[j], check(i, j));
      #endif
    }
  }
  cout << res << '\n';
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
/*
10
4 2
1 2
3 8
*/