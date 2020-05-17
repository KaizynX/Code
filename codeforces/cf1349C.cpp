/*
 * @Author: Kaizyn
 * @Date: 2020-05-12 20:33:28
 * @LastEditTime: 2020-05-12 22:36:47
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
const int dir[] = {0,-1,0,1,0};

struct Node {
  int x, y, v;
  friend bool operator < (const Node &lhs, const Node &rhs) {
    return lhs.v > rhs.v;
  }
};

int n, m, t;
char a[N][N];
int vis[N][N];
queue<pii> q;

inline bool check(const int &x, const int &y) {
  return !(x < 1 || y < 1 || x > n || y > m);
}

inline bool is_rev(const int &x, const int &y) {
  for (int i = 0, nx, ny; i < 4; ++i) {
    nx = x+dir[i]; ny = y+dir[i+1];
    if (check(nx, ny) && a[nx][ny] == a[x][y]) return true;
  }
  return false;
}

void bfs() {
  while (q.size()) {
    int ux = q.front().first,
        uy = q.front().second;
    q.pop();
    #ifdef DEBUG
    printf("(%d %d)\n", ux, uy);
    #endif
    for (int i = 0, nx, ny, nv; i < 4; ++i) {
      nx = ux+dir[i]; ny = uy+dir[i+1];
      if (!check(nx, ny)) continue;
      nv = vis[ux][uy]+(a[ux][uy] != a[nx][ny]);
      if (!vis[nx][ny] || vis[nx][ny] > nv) {
        vis[nx][ny] = nv;
        q.push({nx, ny});
      }
    }
  }
}

inline void solve() {
  scanf("%d %d %d", &n, &m, &t);
  for (int i = 1; i <= n; ++i) {
    scanf("%s", a[i]+1);
  }
  for (int i = 1; i <= n; ++i) {
    for (int j = 1; j <= m; ++j) {
      if (is_rev(i, j)) {
        vis[i][j] = 1;
        q.push({i, j});
      }
    }
  }
  bfs();
  #ifdef DEBUG
  for (int i = 1; i <= n; ++i) {
    for (int j = 1; j <= m; ++j) {
      printf("%d%c", vis[i][j], " \n"[j==m]);
    }
  }
  #endif
  long long p;
  for (int i = 1, x, y; i <= t; ++i) {
    scanf("%d %d %lld", &x, &y, &p);
    if (p < vis[x][y] || !vis[x][y]) {
      putchar(a[x][y]);
      putchar('\n');
    } else {
      printf("%d\n", int((a[x][y]-'0')^((p-vis[x][y]-1)&1)));
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