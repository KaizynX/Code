/*
 * @Author: Kaizyn
 * @Date: 2020-07-09 18:10:31
 * @LastEditTime: 2020-07-09 18:32:02
 */ 
#include <bits/stdc++.h>

// #define DEBUG

using namespace std;

const double eps = 1e-7;
const double PI = acos(-1);
typedef pair<int, int> pii;
const int MOD = 998244353;
const int INF = 0x3f3f3f3f;
const int N = 2e2+7;
const int dir[] = {0,-1,0,1,0};

struct Node{
  int x, y, t;
  friend bool operator <(const Node &lhs, const Node &rhs) {
    return lhs.t > rhs.t;
  }
};


int n, m;
char a[N][N];
int dis[N][N];

inline void solve() {
  int bx, by;
  for (int i = 1; i <= n; ++i) {
    scanf("%s", a[i]+1);
    for (int j = 1; j <= m; ++j) {
      dis[i][j] = -1;
      if (a[i][j] == 'a') {
        bx = i; by = j;
      }
    }
  }
  dis[bx][by] = 0;

  priority_queue<Node> q;
  q.push(Node{bx, by, 0});
  while (q.size()) {
    Node u = q.top();
    q.pop();
    int ux = u.x, uy = u.y, ut = u.t;
    if (ut > dis[ux][uy]) continue;
    if (a[ux][uy] == 'r') return printf("%d\n", ut), void();
    for (int i = 0, vx, vy, vt; i < 4; ++i) {
      vx = ux+dir[i];
      vy = uy+dir[i+1];
      if (vx < 1 || vx > n || vy < 1 || vy > m ||
          a[vx][vy] == '#') continue;
      vt = ut+1+(a[vx][vy] == 'x');
      if (dis[vx][vy] == -1 || dis[vx][vy] > vt) {
        q.push(Node{vx, vy, vt});
        dis[vx][vy] = vt;
      }
    }
  }
  puts("Poor Dingba has to stay in the prison all his life.");
}

signed main() {
  // ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
  while (scanf("%d %d", &n, &m) == 2) solve();
  return 0;
}