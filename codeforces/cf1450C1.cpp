/*
 * @Author: Kaizyn
 * @Date: 2020-12-06 22:31:58
 * @LastEditTime: 2020-12-07 01:33:43
 */
#include <bits/stdc++.h>

// #define DEBUG

using namespace std;

const double eps = 1e-7;
const double PI = acos(-1);
typedef pair<int, int> pii;
const int MOD = 998244353;
const int INF = 0x3f3f3f3f;
const int N = 3e2+7;

int n;
char a[N][N], b[N][N];

bool check(int x, int y) {
  if (a[x][y] == '.') return false;
  for (int i = max(1, x-2); i <= min(x, n-2); ++i) {
    if (a[i][y] == a[i+1][y] && a[i][y] == a[i+2][y]) return true;
  }
  for (int i = max(1, y-2); i <= min(y, n-2); ++i) {
    if (a[x][i] == a[x][i+1] && a[x][i] == a[x][i+2]) return true;
  }
  return false;
}

void print(char a[N][N]) {
  for (int i = 1; i <= n; ++i) {
    for (int j = 1; j <= n; ++j) {
      cout << a[i][j];
    }
    cout << endl;
  }
}

int fuck(int shit) {
  int t = 0;
  for (int i = shit, x, y; i <= 2*n; i += 3) {
    x = 1; y = i-x;
    if (y > n) x += y-n, y = n;
    for ( ; x <= n && y; ++x, --y) {
      if (check(x, y)) {
        ++t;
        a[x][y] = 'O';
      }
    }
  }
  return t;
}

inline void solve() {
  cin >> n;
  int k = 0;
  for (int i = 1; i <= n; ++i) {
    cin >> (a[i]+1);
    for (int j = 1; j <= n; ++j) {
      k += a[i][j] != '.';
    }
  }
  memcpy(b, a, sizeof a);
  for (int i = 2; i <= 4; ++i) {
    memcpy(a, b, sizeof a);
    int t = fuck(i);
    // cout << t << endl;
    if (t <= k/3) {
      print(a);
      return;
    }
  }
  assert(0);
}

signed main() {
  ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
  int T = 1;
  cin >> T;
  for (int t = 1; t <= T; ++t) {
    solve();
  }
  return 0;
}