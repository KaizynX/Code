/*
 * @Author: Kaizyn
 * @Date: 2021-07-04 12:56:52
 * @LastEditTime: 2021-07-04 13:19:00
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
char a[N][N];

inline void solve() {
  cin >> n >> m;
  char col[2] = {'\0', '\0'};
  int flag = 1;
  for (int i = 0; i < n; ++i) {
    for (int j = 0; j < m; ++j) {
      cin >> a[i][j];
      if (a[i][j] == '.') continue;
      if (!col[(i+j)&1]) col[(i+j)&1] = a[i][j];
      flag &= col[(i+j)&1] == a[i][j];
    }
  }
  if (col[0] == col[1]) flag = 0;
  if (!flag) return cout << "NO\n", void();
  cout << "YES\n";
  if (!col[0] && !col[1]) col[0] = 'R', col[1] = 'W';
  if (!col[0]) col[0] = col[1] == 'R' ? 'W' : 'R';
  if (!col[1]) col[1] = col[0] == 'R' ? 'W' : 'R';
  for (int i = 0; i < n; ++i) {
    for (int j = 0; j < m; ++j) {
      cout << col[(i+j)&1];
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