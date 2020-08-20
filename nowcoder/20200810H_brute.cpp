/*
 * @Author: Kaizyn
 * @Date: 2020-08-10 11:57:52
 * @LastEditTime: 2020-08-10 13:51:34
 */
#include <bits/stdc++.h>

// #define DEBUG

using namespace std;

const double eps = 1e-7;
const double PI = acos(-1);
typedef pair<int, int> pii;
const int MOD = 998244353;
const int INF = 0x3f3f3f3f;
const int N = 1e1+7;
const int dir[] = {0,-1,0,1,0};

int n;
int a[N][N], vis[N][N];

void dfs(int x, int y) {
  if (x < 0 || x >= n || y < 0 || y >= n) return;
  if (a[x][y] || vis[x][y]) return;
  vis[x][y] = 1;
  for (int d = 0; d < 4; ++d) {
    dfs(x+dir[d], y+dir[d+1]);
  }
}

inline void solve() {
  n = 4;
  int res = 0;
  for (long long b = 1; b < 1ll<<(n*n); ++b) {
    for (int i = 0; i < n; ++i) {
      for (int j = 0; j < n; ++j) {
        a[i][j] = b>>(i*n)>>j&1;
      }
    }
    int flag = 1;
    for (int i = 0; i < n; ++i) {
      for (int j = 0; j < n; ++j) if (a[i][j]) {
        for (int d = 0, x, y; d < 4; ++d) {
          x = i+dir[d];
          y = j+dir[d+1];
          if (x < 0 || x >= n || y < 0 || y >= n) continue;
          if (a[x][y]) {
            flag = 0;
            break;
          }
        }
      }
    }
    if (!flag) continue;
    int cnt = 0;
    memset(vis, 0, sizeof vis);
    for (int i = 0; i < n; ++i) {
      for (int j = 0; j < n; ++j) {
        if (!a[i][j] && !vis[i][j]) ++cnt, dfs(i, j);
      }
    }
    if (cnt > 1) continue;
    // if (__builtin_popcount(b) > res) {
      // res = __builtin_popcount(b);
    if (__builtin_popcount(b) == 5) {
      cout << res << endl;
      for (int i = 0; i < n; ++i){
        for (int j = 0; j < n; ++j) {
          cout << a[i][j];
        }
        cout << endl;
      }
    }
  }
}

signed main() {
  ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
  int T = 1;
  // cin >> T;
  for (int t = 1; t <= T; ++t) {
    solve();
  }
  return 0;
}