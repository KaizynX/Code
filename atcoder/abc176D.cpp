/*
 * @Author: Kaizyn
 * @Date: 2020-08-22 21:22:54
 * @LastEditTime: 2020-08-22 21:34:18
 */
#include <bits/stdc++.h>

// #define DEBUG

using namespace std;

const double eps = 1e-7;
const double PI = acos(-1);
typedef pair<int, int> pii;
const int MOD = 998244353;
const int INF = 0x3f3f3f3f;
const int N = 1e3+7;
const int dir[] = {0, -1, 0, 1, 0};

int n, m, bx, by, ex, ey;
char a[N][N];
int c[N][N], col;

void bfs(int sx, int sy) {
  queue<pii> q;
  q.push({sx, sy});
  while (q.size()) {
    int x = q.front().first;
    int y = q.front().second;
    q.pop();
    for (int i = 0, nx, ny; i < 4; ++i) {
      nx = x+dir[i];
      ny = y+dir[i+1];
      if (nx < 1 || ny < 1 || nx > n || ny > m) continue;
      if (a[nx][ny] == '#' || c[nx][ny]) continue;
      c[nx][ny] = col;
      q.push({nx, ny});
    }
  }
}

inline void solve() {
  cin >> n >> m >> bx >> by >> ex >> ey;
  for (int i = 1; i <= n; ++i) {
    cin >> (a[i]+1);
  }
  for (int i = 1; i <= n; ++i) {
    for (int j = 1; j <= m;++j) {
      if (a[i][j] == '#' || c[i][j]) continue;
      ++col;
      bfs(i, j);
    }
  }
  for (int i = 1; i <= n; ++i) {
    for (int j = 1; j <= m; ++j) {
      ;
    }
  }
}

signed main() {
  ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
  int T = 1;
  // cin >> T;
  for (int t = 1; t <= T; ++t) {
    solve();
  }
  return 0;
}