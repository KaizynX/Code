/*
 * @Author: Kaizyn
 * @Date: 2020-09-09 10:13:11
 * @LastEditTime: 2020-09-09 10:54:18
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
const int tag[] = {-1, 1};
const int dir[] = {0, -1, 0, 1, 0};

int n, m;
int a[N][N], dis[N][N];
pii rk[N*N];
int minx, miny, maxx, maxy, last;

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
  if (dis[rk[last].first][rk[last].second] <= mid) {
    last = 0;
    minx = miny = INF;
    maxx = maxy = -INF;
  }
  while (last+1 <= n*m && dis[rk[last+1].first][rk[last+1].second] > mid) {
    ++last;
    int x = rk[last].first+rk[last].second;
    int y = rk[last].first-rk[last].second;
    minx = min(minx, x);
    miny = min(miny, y);
    maxx = max(maxx, x);
    maxy = max(maxy, y);
  }
  return max((maxx-minx+1)/2, (maxy-miny+1)/2) <= mid;
}

inline int solve() {
  static string s;
  cin >> n >> m;
  for (int i = 1; i <= n; ++i) {
    cin >> s;
    for (int j = 1; j <= m; ++j) {
      a[i][j] = s[j-1]-'0';
      rk[(i-1)*m+j] = {i, j};
    }
  }
  bfs();
  sort(rk+1, rk+n*m+1, [&](pii &p1, pii &p2) {
    return dis[p1.first][p1.second] > dis[p2.first][p2.second];
  });
  last = 0;
  minx = miny = INF;
  maxx = maxy = -INF;
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