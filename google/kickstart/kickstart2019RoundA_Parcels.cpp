/*
 * @Author: Kaizyn
 * @Date: 2020-09-08 19:20:50
 * @LastEditTime: 2020-09-08 20:23:20
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
queue<pii> q;
string s;

inline void bfs() {
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
  #ifdef DEBUG
  cout << "dis:\n";
  for (int i = 1; i <= n; ++i)
    for (int j = 1; j <= m; ++j)
      cout << dis[i][j] << " \n"[j==m];
  cout << "-----------" << endl;
  #endif
}

inline bool check(int mid) {
  int cnt = 0, mxd = INF, mx[4];
  memset(mx, 0x9f, sizeof mx);
  for (int i = 1; i <= n; ++i) {
    for (int j = 1; j <= m; ++j) {
      if (dis[i][j] <= mid) continue;
      ++cnt;
      for (int k = 0; k < 4; ++k) {
        mx[k] = max(mx[k], tag[k&1]*i+tag[k>>1&1]*j);
      }
    }
  }
  if (!cnt) return true;
  for (int i = 1; i <= n; ++i) {
    for (int j = 1; j <= m; ++j) {
      int tmp = 0;
      for (int k = 0; k < 4; ++k) {
        tmp = max(tmp, tag[k&1]*i+tag[k>>1&1]*j+mx[k^3]);
      }
      mxd = min(mxd, tmp);
    }
  }
  #ifdef DEBUG
  for (int i = 0; i < 4; ++i) cout << mx[i] << " \n"[i==3];
  cout << mid << " " << mxd << endl;
  #endif
  return mxd <= mid;
}

inline int solve() {
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