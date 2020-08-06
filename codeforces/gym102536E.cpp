/*
 * @Author: Kaizyn
 * @Date: 2020-07-10 13:56:59
 * @LastEditTime: 2020-07-10 14:42:41
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

struct Time {
  int walk, open, close;
  Time() { walk = open = close = INF; }
  Time(int w, int o, int c) : walk(w), open(o), close(c) {};
  int sum() const { return walk+open+close; }
  int check() const { return open-close; }
  friend bool operator <(const Time &lhs, const Time &rhs) {
    return lhs.sum() < rhs.sum();
  }
};

struct Node {
  int x, y;
  Time t;
  // Node(int x, int y, const Time &t) : x(x), y(y), t(t) {};
  friend bool operator <(const Node &lhs, const Node &rhs) {
    return rhs.t < lhs.t;
  }
};

int n, m, k;
vector<string> a;
vector<vector<Time>> dis[2];

inline void solve() {
  int bx, by;
  priority_queue<Node> q;

  cin >> n >> m >> k;
  a.resize(n);
  dis[0].resize(n, vector<Time>(m));
  dis[1].resize(n, vector<Time>(m));
  for (int i = 0; i < n; ++i) {
    cin >> a[i];
    for (int j = 0; j < m; ++j) {
      if (a[i][j] == 'A') bx = i, by = j;
    }
  }

  int res = INF;
  dis[0][bx][by] = Time(0, 0, 0);
  q.push(Node{bx, by, Time(0, 0, 0)});
  while (q.size()) {
    Node u = q.top();
    q.pop();
    int ux = u.x, uy = u.y;
    Time ut = u.t, vt;
    if (dis[ut.check()][ux][uy] < ut) continue;
    if (a[ux][uy] == 'B') res = min(res, ut.sum()-min(ut.close, k));
    for (int i = 0, vx, vy; i < 4; ++i) {
      vx = ux+dir[i];
      vy = uy+dir[i+1];
      if (vx < 0 || vx >= n || vy < 0 || vy >= m || a[vx][vy] == '#') continue;
      vt = ut;
      if (a[vx][vy] == 'D') ++vt.open;
      if (vt.check() > k) continue;
      vt.close += a[ux][uy] == 'D';
      ++vt.walk;
      if (dis[vt.check()][vx][vy] < vt) continue;
      dis[vt.check()][vx][vy] = vt;
      q.push(Node{vx, vy, vt});
    }
  }
  if (res >= INF) cout << "HAHAHUHU" << endl;
  else cout << res << endl;

  vector<string>().swap(a);
  vector<vector<Time>>().swap(dis[0]);
  vector<vector<Time>>().swap(dis[1]);
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