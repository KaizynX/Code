/*
 * @Author: Kaizyn
 * @Date: 2020-05-10 13:59:56
 * @LastEditTime: 2020-05-10 17:23:58
 */
#include <bits/stdc++.h>

#define DEBUG

using namespace std;

const int N = 20;
typedef pair<int, int> pii;
const int dir[] = {0,-1,0,1,0};

int n, m, t;
char a[N][N], b[N][N];
vector<pii> car;

#ifdef DEBUG
void print() {
  puts("***");
  for (int i = 1; i <= n; ++i) puts(a[i]+1);
  puts("***");
}
#endif

inline bool check(const int &x, const int &y) {
  return !(x < 1 || y < 1 || x > n || y > m ||
      a[x][y] == 'X' || a[x][y] == 'R');
}

void dfs(const int &u) {
  if (u == t) {
    for (pii &cur : car) {
      if (b[cur.first][cur.second] == 'D') {
        cout << "YES" << endl;
        exit(0);
      }
    }
    return;
  }
  int ox, oy, nx, ny;
  for (pii &cur : car) {
    ox = cur.first;
    oy = cur.second;
    for (int i = 0; i < 4; ++i) {
      nx = ox; ny = oy;
      while (check(nx+dir[i], ny+dir[i+1])) {
        nx += dir[i];
        ny += dir[i+1];
      }
      a[ox][oy] = b[ox][oy];
      a[nx][ny] = 'R';
      cur = {nx, ny};
      dfs(u+1);
      a[nx][ny] = b[nx][ny];
      a[ox][oy] = 'R';
      cur = {ox, oy};
    }
  }
}

inline void solve() {
  cin >> m >> n >> t;
  for (int i = 1; i <= n; ++i) {
    scanf("%s", a[i]+1);
    strcpy(b[i]+1, a[i]+1);
    for (int j = 1; j <= m; ++j) {
      if (a[i][j] == 'R') {
        car.emplace_back(i, j);
        b[i][j] = '.';
      }
    }
  }
  dfs(0);
  cout << "NO" << endl;
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