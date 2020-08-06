/*
 * @Author: Kaizyn
 * @Date: 2020-07-10 13:56:59
 * @LastEditTime: 2020-07-10 15:29:56
 */ 
#include <bits/stdc++.h>

// #define DEBUG

using namespace std;

const double eps = 1e-7;
const double PI = acos(-1);
typedef pair<int, int> pii;
const int MOD = 998244353;
const int INF = 1e8;
const int N = 5e3+7;
const int K = 55;
const int dir[] = {0,-1,0,1,0};

struct Node {
  int x, y, d, t;
  friend bool operator <(const Node &lhs, const Node &rhs) {
    return rhs.t < lhs.t;
  }
};

int n, m, k;
vector<string> a;
vector<vector<int>> dis[K];

inline void solve() {
  int bx, by;
  priority_queue<Node> q;

  cin >> n >> m >> k;
  a.resize(n);
  for (int i = 0; i <= k; ++i) {
    dis[i].resize(n, vector<int>(m, INF));
  }
  for (int i = 0; i < n; ++i) {
    cin >> a[i];
    for (int j = 0; j < m; ++j) {
      if (a[i][j] == 'A') bx = i, by = j;
    }
  }

  int res = INF;
  dis[0][bx][by] = 0;
  q.push(Node{bx, by, 0, 0});
  while (q.size()) {
    Node u = q.top();
    q.pop();
    int ux = u.x, uy = u.y, ud = u.d, ut = u.t;
    #ifdef DEBUG
    cout << ux << " " << uy << " " << ud << " " << ut << endl;
    #endif
    if (dis[ud][ux][uy] < ut) continue;
    if (a[ux][uy] == 'B') res = min(res, ut);
    for (int i = 0, vx, vy, vd, vt; i < 4; ++i) {
      vx = ux+dir[i];
      vy = uy+dir[i+1];
      if (vx < 0 || vx >= n || vy < 0 || vy >= m || a[vx][vy] == '#') continue;
      vd = ud; vt = ut+1;
      // if (a[vx][vy] == 'D' && vd == k) continue;
      if (a[vx][vy] == 'D') ++vd, ++vt;
      if (vd > k) continue;
      if (dis[vd][vx][vy] > vt) {
        dis[vd][vx][vy] = vt;
        q.push(Node{vx, vy, vd, vt});
      }
      if (a[ux][uy] == 'D') --vd, ++vt;
      if (dis[vd][vx][vy] > vt) {
        dis[vd][vx][vy] = vt;
        q.push(Node{vx, vy, vd, vt});
      }
    }
  }
  if (res >= INF) cout << "HAHAHUHU" << endl;
  else cout << res << endl;

  vector<string>().swap(a);
  for (int i = 0; i <= k; ++i) {
    vector<vector<int>>().swap(dis[i]);
  }
}

signed main() {
  ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
  int T = 1;
  cin >> T;
  for (int t = 1; t <= T; ++t) {
    solve();
  }
  return 0;
}
/*
10
1 6 1
A.DD.B
1 6 2
A.DD.B
1 6 2
ADDDDB
*/