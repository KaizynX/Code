/*
 * @Author: Kaizyn
 * @Date: 2021-02-13 14:51:19
 * @LastEditTime: 2021-02-13 17:06:44
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
const int N = 5e2+7;

int n, m;
int a[N][N];
int b[N][N];

inline void solve() {
  cin >> n >> m;
  for (int i = 1; i <= n; ++i) {
    for (int j = 1; j <= m; ++j) {
      cin >> a[i][j];
    }
  }
  int x = 1;
  for (int i = 1; i <= 16; ++i) x *= i/__gcd(x, i);
  for (int i = 1; i <= n; ++i) {
    for (int j = 1; j <= m; ++j) {
      cout << x+(i+j)%2*a[i][j]*a[i][j]*a[i][j]*a[i][j] << " \n"[j==m];
    }
  }
}

signed main() {
#ifdef ONLINE_JUDGE
  ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
#endif
  int T = 1;
  // cin >> T;
  for (int t = 1; t <= T; ++t) {
    solve();
  }
  return 0;
}