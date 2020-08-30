/*
 * @Author: Kaizyn
 * @Date: 2020-08-22 21:22:54
 * @LastEditTime: 2020-08-22 21:43:32
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

struct Node {
  int x, y, z;
  bool operator <(const Node &nd) const {
    return z > nd.z;
  }
};

int n, m, bx, by, ex, ey;
char a[N][N];
int d[N][N];
priority_queue<Node> q;

void bfs() {
  memset(d, -1, sizeof d);
  q.push(Node{bx, by, 0});
  d[bx][by] = 0;
  while (q.size()) {
    int x = q.top().x;
    int y = q.top().y;
    int z = q.top().z;
    q.pop();
    if (z > d[x][y]) continue;
    for (int i = 0, nx, ny; i < 4; ++i) {
      nx = x+dir[i];
      ny = y+dir[i+1];
      if (nx < 1 || ny < 1 || nx > n || ny > m) continue;
      if (a[nx][ny] == '#') continue;
      if (d[nx][ny] == -1 || d[nx][ny] > z) {
        d[nx][ny] = z;
        q.push(Node{nx, ny, z});
      }
    }
    for (int i = -2; i <= 2; ++i) {
      for (int j = -2, nx, ny; j <= 2; ++j) {
        nx = x+i;
        ny = y+j;
        if (nx < 1 || ny < 1 || nx > n || ny > m) continue;
        if (a[nx][ny] == '#') continue;
        if (d[nx][ny] == -1 || d[nx][ny] > z+1) {
          d[nx][ny] = z+1;
          q.push(Node{nx, ny, z+1});
        }
      }
    }
  }
}

inline void solve() {
  cin >> n >> m >> bx >> by >> ex >> ey;
  for (int i = 1; i <= n; ++i) {
    cin >> (a[i]+1);
  }
  bfs();
  cout << d[ex][ey] << endl;
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