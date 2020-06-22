/*
 * @Author: Kaizyn
 * @Date: 2020-06-17 18:42:09
 * @LastEditTime: 2020-06-17 19:00:31
 */ 
#include <bits/stdc++.h>

// #define DEBUG

using namespace std;

const double eps = 1e-7;
const double PI = acos(-1);
typedef pair<int, int> pii;
const int MOD = 998244353;
const int INF = 0x3f3f3f3f;
const int N = 20;
const int dir[] = {0, -1, 0, 1, 0};

int n, m, bx, by, ex, ey;
char a[N][N];
int dis[N][N];
queue<pii> q;

inline bool check(const int &x, const int &y) {
  return !(x < 1 || x > n || y < 1 || y > m);
}

inline void solve() {
  for (int i = 1; i <= n; ++i) {
    scanf("%s", a[i]+1);
    for (int j = 1; j <= m; ++j) {
      dis[i][j] = -1;
    }
  }
  scanf("%d %d %d %d", &bx, &by, &ex, &ey);
  q.push({bx, by});
  dis[bx][by] = 0;
  while (q.size()) {
    int ux = q.front().first;
    int uy = q.front().second;
    q.pop();
    for (int i = 0, vx, vy; i < 4; ++i) {
      vx = ux+dir[i];
      vy = uy+dir[i+1];
      if (!check(vx, vy)) continue;
      if (a[vx][vy] == '*') {
        vx += dir[i];
        vy += dir[i+1];
        if (!check(vx, vy)) continue;
        if (a[vx][vy] == '*') continue;
      }
      if (dis[vx][vy] != -1 && dis[vx][vy] <= dis[ux][uy]+1) continue;
      dis[vx][vy] = dis[ux][uy]+1;
      q.push({vx, vy});
    }
  }
  printf("%d\n", dis[ex][ey]);
}

signed main() {
  // ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
  while (scanf("%d %d", &n, &m) == 2) {
    solve();
  }
  return 0;
}