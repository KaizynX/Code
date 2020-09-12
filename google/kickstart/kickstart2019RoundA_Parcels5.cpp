/*
 * @Author: Kaizyn
 * @Date: 2020-09-09 10:13:11
 * @LastEditTime: 2020-09-09 15:17:50
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
const int dir[] = {0, -1, 0, 1, 0};

int n, m;
int a[N][N], dis[N][N];

inline void bfs() {
  static queue<pii> q;
  for (int i = 1; i <= n; ++i) {
    for (int j = 1; j <= m; ++j) {
      if (a[i][j]) {
        q.push({i, j});
        dis[i][j] = 0;
      } else {
        dis[i][j] = INF;
      }
    }
  }
  while (q.size()) {
    int ux = q.front().first;
    int uy = q.front().second;
    q.pop();
    for (int i = 0, vx, vy; i < 4; ++i) {
      vx = ux+dir[i];
      vy = uy+dir[i+1];
      if (vx < 1 || vy < 1 || vx > n || vy > m) continue;
      if (dis[vx][vy] > dis[ux][uy]+1) {
        dis[vx][vy] = dis[ux][uy]+1;
        q.push({vx, vy});
      }
    }
  }
}

inline bool check(int mid) {
  int minx, miny, maxx, maxy, cnt = 0;
  minx = miny = INF;
  maxx = maxy = -INF;
  for (int i = 1; i <= n; ++i) {
    for (int j = 1; j <= m; ++j) if (dis[i][j] > mid) {
      ++cnt;
      int x = i+j, y = i-j;
      minx = min(minx, x);
      miny = min(miny, y);
      maxx = max(maxx, x);
      maxy = max(maxy, y);
    }
  }
  if (!cnt) return true;
  /*********************************
  最优情况下应该取 qx = (minx+maxx)/2, qy = (miny+maxy)/2
  原坐标下是否存在 (mx, my) -> (qx = mx+my, qy = mx-my)
  解得 mx = (qx+qy)/2, my = (qx-qy)/2
  那么要求 qx, qy 奇偶性相同,可是如果不相同呢...
  **********************************/
  // return max((maxx-minx+1)/2, (maxy-miny+1)/2) <= mid;
  int maxd = INF;
  int x = (minx+maxx)/2, y = (miny+maxy)/2;
  for (int i = x-2; i <= x+2; ++i) {
    for (int j = y-2; j <= y+2; ++j) {
      if ((i+j)%2) continue;
      maxd = min(maxd, max({abs(i-minx), abs(i-maxx), abs(j-miny), abs(j-maxy)}));
    }
  }
  return maxd <= mid;
}

inline int solve() {
  static string s;
  cin >> n >> m;
  for (int i = 1; i <= n; ++i) {
    cin >> s;
    for (int j = 1; j <= m; ++j) {
      a[i][j] = s[j-1]-'0';
    }
  }
  bfs();
  int l = 0, r = n+m;
  while (l < r) {
    int mid = (l+r)>>1;
    if (check(mid)) r = mid;
    else l = mid+1;
  }
  return l;
}

signed main() {
  ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
  int T = 1;
  cin >> T;
  for (int t = 1; t <= T; ++t) {
    cout << "Case #" << t << ": " << solve() << endl;
  }
  return 0;
}