/*
 * @Author: Kaizyn
 * @Date: 2020-07-19 14:50:50
 * @LastEditTime: 2020-07-19 15:15:01
 */ 
#include <bits/stdc++.h>

// #define DEBUG

using namespace std;

const double eps = 1e-7;
const double PI = acos(-1);
typedef pair<int, int> pii;
const int MOD = 998244353;
const int INF = 0x3f3f3f3f;
const int N = 5e2+7;

int n, bx, by;
int a[N][N];

inline int dis(const int &r1, const int &c1, const int &r2, const int &c2) {
  return abs(r1-r2)+abs(c1-c2);
}

inline void solve() {
  cin >> n >> bx >> by;
  for (int i = 1; i <= n; ++i) {
    for (int j = 1; j <= n; ++j) {
      cin >> a[i][j];
    }
  }
  int res = INF;
#ifdef DEBUG
  int resx, resy;
#endif
  vector<int> vec;
  for (int i = 1; i <= n; ++i) {
    for (int j = 1; j <= n; ++j) {
      int t = (dis(i, j, bx, by)+1)/2;
      vec.clear();
      for (int x = max(1, i-3); x <= min(n, i+3); ++x) {
        for (int y = max(1, j-3); y <= min(n, j+3); ++y) {
          if (i == x && j == y) continue; // city itself
          if (dis(i, j, x, y) > 3) continue;
          vec.emplace_back(a[x][y]);
        }
      }
      sort(vec.begin(), vec.end());
      reverse(vec.begin(), vec.end());
      for (int r = 1, v = a[i][j], f = 0; r <= 8; ++r) {
        int tmp = f >= 8*r*r ? 0 : (8*r*r-f+v-1)/v;
        f += v*tmp;
        t += tmp;
        if (r-1 < (int)vec.size()) v += vec[r-1];
      }
#ifdef DEBUG
      if (t < res) {
        res = t;
        resx = i;
        resy = j;
      }
#endif
      res = min(res, t);
    }
  }
  cout << res << endl;
#ifdef DEBUG
  cout << resx << " " << resy << endl;
#endif
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