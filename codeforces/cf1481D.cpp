/*
 * @Author: Kaizyn
 * @Date: 2021-02-06 19:15:37
 * @LastEditTime: 2021-02-06 20:26:22
 */
#include <bits/stdc++.h>

// #define DEBUG

using namespace std;

const double eps = 1e-7;
const double PI = acos(-1);
typedef pair<int, int> pii;
typedef long long ll;
const int MOD = 998244353;
const int INF = 0x3f3f3f3f;
// const ll INF = 1e18;
const int N = 1e3+7;

int n, m;
char a[N][N];

inline void solve() {
  cin >> n >> m;
  for (int i = 1; i <= n; ++i) cin >> (a[i]+1);

  for (int i = 1; i <= n; ++i) {
    for (int j = 1; j < i; ++j) {
      if (a[i][j] == a[j][i]) {
        cout << "YES\n";
        for (int k = 0; k <= m; ++k) {
          cout << (k&1 ? i : j) << " \n"[k==m];
        }
        return;
      }
    }
  }
  if (m&1) {
    cout << "YES\n";
    for (int k = 0; k <= m; ++k) {
      cout << k%2+1 << " \n"[k==m];
    }
    return;
  }
  for (int x, z, y = 1; y <= n; ++y) {
    x = z = 0;
    for (int i = 1; i <= n; ++i) {
      if (a[i][y] == 'a') x = i;
      if (a[y][i] == 'a') z = i;
    }
    if (!x || !z) continue;
    cout << "YES\n";
    if ((m/2)&1) {
      int res[4] = {x, y, z, y};
      for (int k = 0; k <= m; ++k) {
        cout << res[k%4] << " \n"[k==m];
      }
    } else {
      cout << y << ' ';
      for (int i = 1; i <= m/2 ; ++i) cout << (i&1 ? z : y) << ' ';
      for (int i = 1; i <= m/2 ; ++i) cout << (i&1 ? x : y) << " \n"[i==m/2];
    }
    return;
  }
  cout << "NO\n";
}

signed main() {
#ifdef ONLINE_JUDGE
  ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
#endif
  int T = 1;
  cin >> T;
  for (int t = 1; t <= T; ++t) {
    solve();
  }
  return 0;
}
/*
4 4
*aab
b*aa
bb*a
abb*
*/