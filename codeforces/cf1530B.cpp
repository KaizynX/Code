/*
 * @Author: Kaizyn
 * @Date: 2021-07-17 22:24:01
 * @LastEditTime: 2021-07-17 22:43:47
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
const int N = 23;

int n, m;
int a[N][N], b[N][N];

void f(int x, int y) {
  for (int i : {-1, 0, 1})
  for (int j : {-1, 0, 1}) {
    a[x+i][y+j] = 1;
  }
  b[x][y] = 1;
}

inline void solve() {
  cin >> n >> m;
  memset(a, 0, sizeof a);
  memset(b, 0, sizeof b);
  for (int j = 1; j <= m; ++j) if (a[1][j] == 0) f(1, j);
  for (int i = 1; i <= n; ++i) if (a[i][m] == 0) f(i, m);
  for (int j = m; j; --j) if (a[n][j] == 0) f(n, j);
  for (int i = n; i; --i) if (a[i][1] == 0) f(i, 1);
  for (int i = 1; i <= n; ++i) {
    for (int j = 1; j <= m; ++j) {
      cout << b[i][j];
    }
    cout << '\n';
  }
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