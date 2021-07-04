/*
 * @Author: Kaizyn
 * @Date: 2021-07-04 13:20:03
 * @LastEditTime: 2021-07-04 13:22:33
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
const int N = 1e2+7;

int n, m;
char a[N][N], c[2];

bool check() {
  for (int i = 0; i < n; ++i) {
    for (int j = 0; j < m; ++j) {
      if (a[i][j] == '.') continue;
      if (a[i][j] != c[(i+j)&1]) return false;
    }
  }
  cout << "YES\n";
  for (int i = 0; i < n; ++i) {
    for (int j = 0; j < m; ++j) {
      cout << c[(i+j)&1];
    }
    cout << '\n';
  }
  return true;
}

inline void solve() {
  cin >> n >> m;
  for (int i = 0; i < n; ++i) {
    cin >> a[i];
  }
  c[0] = 'R', c[1] = 'W';
  if (check()) return;
  swap(c[0], c[1]);
  if (check()) return;
  cout << "NO\n";
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