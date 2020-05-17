/*
 * @Author: Kaizyn
 * @Date: 2020-05-10 13:59:56
 * @LastEditTime: 2020-05-11 21:11:40
 */
#include <bits/stdc++.h>

// #define DEBUG

using namespace std;

const int N = 20;
typedef pair<int, int> pii;
const int dir[] = {0,-1,0,1,0};

int n, m, k;
char a[N][N];
vector<pii> car, dst;

inline bool check(const int &x, const int &y) {
  return !(x < 1 || y < 1 || x > n || y > m ||
      a[x][y] == 'X' || a[x][y] == 'R');
}

void dfs(const int &t) {
  if (t >= k) {
    for (const pii &p : dst) {
      if (a[p.first][p.second] == 'R') {
        cout << "YES" << endl;
        exit(0);
      }
    }
    return;
  }
  int ox, oy, nx, ny;
  for (int i = 0; i < (int)car.size(); ++i) {
    ox = car[i].first;
    oy = car[i].second;
    for (int j = 0; j < 4; ++j) {
      nx = ox; ny = oy;
      while (check(nx+dir[j], ny+dir[j+1])) {
        nx += dir[j];
        ny += dir[j+1];
      }
      /*
      if (a[nx][ny] == 'D') {
        cout << "YES" << endl;
        exit(0);
      }
      */
      a[ox][oy] = '.';
      a[nx][ny] = 'R';
      car[i] = {nx, ny};
      dfs(t+1);
      a[nx][ny] = '.';
      a[ox][oy] = 'R';
      car[i] = {ox, oy};
    }
  }
}

signed main() {
  // ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
  cin >> m >> n >> k;
  for (int i = 1; i <= n; ++i) {
    scanf("%s", a[i]+1);
    for (int j = 1; j <= m; ++j) {
      if (a[i][j] == 'R') {
        car.emplace_back(i, j);
      } else if (a[i][j] == 'D') {
        dst.emplace_back(i, j);
      }
    }
  }
  dfs(0);
  cout << "NO" << endl;
  return 0;
}