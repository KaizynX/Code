/*
 * @Author: Kaizyn
 * @Date: 2020-06-07 22:23:23
 * @LastEditTime: 2020-06-07 23:18:48
 */ 
#include <bits/stdc++.h>

// #define DEBUG

using namespace std;

const double eps = 1e-7;
const double PI = acos(-1);
typedef pair<int, int> pii;
const int MOD = 998244353;
const int INF = 0x3f3f3f3f;
const int N = 55;
const int dir[] = {0,-1,0,1,0};

int n, m;
char a[N][N];
int vis[N][N];
queue<pii> q;

inline bool in_range(const int &x, const int &y) {
  return x >= 1 && x <= n && y >= 1 && y <= m && a[x][y] != '#';
}

inline bool check(const int &x, const int &y) {
  for (int i = 0, nx, ny; i < 4; ++i) {
    nx = x+dir[i];
    ny = y+dir[i+1];
    if (!in_range(nx, ny)) continue;
    if (a[nx][ny] == 'B') return false;
  }
  return true;
}

inline bool solve() {
  scanf("%d %d", &n, &m);
  for (int i = 1; i <= n; ++i) {
    scanf("%s", a[i]+1);
    for (int j = 1; j <= m; ++j) vis[i][j] = 0;
  }
  if (a[n][m] == 'B') return false;
  // vis[n][m] = 1;
  q.push({n+1, m});
  while (q.size()) {
    int ux = q.front().first;
    int uy = q.front().second;
    q.pop();
    for (int i = 0, vx, vy; i < 4; ++i) {
      vx = ux+dir[i];
      vy = uy+dir[i+1];
      if (!in_range(vx, vy) || !check(vx, vy) || vis[vx][vy]) continue;
      q.push({vx, vy});
      vis[vx][vy] = 1;
    }
  }
  for (int i = 1; i <= n; ++i) {
    for (int j = 1; j <= m; ++j) {
      if (a[i][j] == 'G' && !vis[i][j]) return false;
    }
  }
  return true;
}

signed main() {
  int T = 1;
  scanf("%d", &T);
  for (int t = 1; t <= T; ++t) {
    puts(solve() ? "Yes" : "No");
  }
  return 0;
}