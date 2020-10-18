/*
 * @Author: Kaizyn
 * @Date: 2020-10-04 20:52:41
 * @LastEditTime: 2020-10-04 21:08:28
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

int n, m, res;
int vis[N][N];
char a[N][N];
queue<pii> q;
set<pii> st[2];

void bfs(int sx, int sy) {
  st[0].clear();
  st[1].clear();
  q.push({sx, sy});
  vis[sx][sy] = 1;
  while (q.size()) {
    int ux = q.front().first;
    int uy = q.front().second;
    st[a[ux][uy] == '.'].insert({-ux-uy, ux});
    q.pop();
    for (int i = 0, vx, vy; i < 4; ++i) {
      vx = ux+dir[i];
      vy = uy+dir[i+1];
      if (vx < 1 || vy < 1 || vx > n || vy > m) continue;
      if (a[vx][vy] == '#' || vis[vx][vy]) continue;
      vis[vx][vy] = 1;
      q.push({vx, vy});
    }
  }
  for (auto p0 = st[0].begin(); p0 != st[0].end(); ++p0) {
    int vx = p0->second, vy = -p0->first-vx;
    for (auto p1 = st[1].begin(); p1 != st[1].end(); ++p1) {
      int ux = p1->second, uy = -p1->first-ux;
      if (ux <= vx && uy <= vy) {
        res += vx-ux+vy-uy;
        st[1].erase(p1);
        break;
      }
    }
  }
}

signed main() {
  ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
  cin >> n >> m;
  for (int i = 1; i <= n; ++i) {
    cin >> (a[i]+1);
  }
  for (int i = 1; i <= n; ++i) {
    for (int j = 1; j <= m; ++j) {
      if (vis[i][j] || a[i][j] == '#') continue;
      bfs(i, j);
    }
  }
  cout << res << endl;
  return 0;
}