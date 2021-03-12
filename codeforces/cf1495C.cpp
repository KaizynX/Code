/*
 * @Author: Kaizyn
 * @Date: 2021-03-10 20:03:06
 * @LastEditTime: 2021-03-10 21:32:24
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
const int N = 5e2+7;

int n, m;
char a[N][N];

void print() {
  for (int i = 1; i <= n; ++i) {
    cout << (a[i]+1) << '\n';
  }
}

inline void solve() {
  cin >> n >> m;
  for (int i = 1; i <= n; ++i) {
    cin >> (a[i]+1);
  }
  for (int i = 1; i <= n; i += 3) {
    for (int j = 1; j <= m; ++j) a[i][j] = 'X';
    if (i > 1) {
      int flag = 0;
      for (int j = 1; j <= m; ++j) {
        if (a[i-1][j] == 'X') {
          a[i-2][j] = 'X';
          flag = 1;
        } else if (a[i-2][j] == 'X') {
          a[i-1][j] = 'X';
          flag = 1;
        }
        if (flag) break;
      }
      if (!flag) a[i-1][1] = a[i-2][1] = 'X';
    }
  }
  if (n%3 == 0) {
    int f = 0;
    for (int j = 1; j <= m; ++j) {
      if (a[n][j] == 'X') f = 1;
      if (f) a[n][j] = 'X';
      if (a[n-1][j] == 'X') f = 0;
    }
    if (f) a[n-1][m] = 'X';
  }
  print();
}

signed main() {
#ifdef ONLINE_JUDGE
  ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
#endif
  int T = 1;
  cin >> T; // scanf("%d", &T);
  for (int t = 1; t <= T; ++t) {
    solve();
  }
  return 0;
}