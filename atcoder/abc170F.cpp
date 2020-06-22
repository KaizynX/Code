/*
 * @Author: Kaizyn
 * @Date: 2020-06-18 16:58:32
 * @LastEditTime: 2020-06-18 17:24:49
 */ 
#include <bits/stdc++.h>

// #define DEBUG

using namespace std;

const double eps = 1e-7;
const double PI = acos(-1);
typedef pair<int, int> pii;
const int MOD = 998244353;
const long long INF = 1e18;
const int N = 1e6+7;
const int dir[] = {0,-1,0,1,0};

struct Node {
  int x, y, d;
  long long dis;
  friend bool operator <(const Node &lhs, const Node &rhs) {
    return lhs.dis > rhs.dis;
  }
};

int n, m, k, bx, by, ex, ey;
vector<vector<int>> a;
vector<vector<long long>> dis[4];
priority_queue<Node> q;

inline long long solve() {
  cin >> n >> m >> k
      >> bx >> by >> ex >> ey;
  --bx; --by; --ex; --ey;
  a.resize(n, vector<int>(m));
  for (int i = 0; i < 4; ++i) {
    dis[i].resize(n, vector<long long>(m, INF));
  }
  for (int i = 0; i < n; ++i) {
    static string str;
    cin >> str;
    for (int j = 0; j < m; ++j) {
      a[i][j] = str[j] == '.';
    }
  }
  for (int i = 0; i < 4; ++i) {
    dis[i][bx][by] = 0;
    q.push(Node{bx, by, i, 0});
  }
  while (q.size()) {
    Node u = q.top();
    q.pop();
    int ux = u.x;
    int uy = u.y;
    if (u.dis > dis[u.d][ux][uy]) continue;
    for (int i = 0, vx, vy, vdis; i < 4; ++i) {
      vx = ux+dir[i];
      vy = uy+dir[i+1];
      if (vx < 0 || vy < 0 || vx >= n || vy >= m || !a[vx][vy]) continue;
      vdis = i == u.d ? u.dis+1 : (u.dis+k-1)/k*k+1;
      if (vdis >= dis[i][vx][vy]) continue;
      dis[i][vx][vy] = vdis;
      q.push(Node{vx, vy, i, vdis});
    }
  }
  long long res = INF;
  for (int i = 0; i < 4; ++i) {
    res = min(res, dis[i][ex][ey]);
  }
  return res >= INF ? -1 : (res+k-1)/k;
}

signed main() {
  ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
  int T = 1;
  // cin >> T;
  for (int t = 1; t <= T; ++t) {
    cout << solve() << endl;
  }
  return 0;
}