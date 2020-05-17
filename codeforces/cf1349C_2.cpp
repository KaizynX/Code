/*
 * @Author: Kaizyn
 * @Date: 2020-05-12 20:33:28
 * @LastEditTime: 2020-05-12 22:36:14
 */
#include <bits/stdc++.h>

#define DEBUG

using namespace std;

const double eps = 1e-7;
const double PI = acos(-1);
typedef pair<int, int> pii;
const int MOD = 998244353;
const int INF = 0x3f3f3f3f;
const int N = 1e3+7;
const int dir[] = {0,-1,0,1,0};

struct Node {
  int x, y, v;
  friend bool operator < (const Node &lhs, const Node &rhs) {
    return lhs.v > rhs.v;
  }
};

int n, m, t;
char a[N][N], b[10][N][N];
int vis[N][N];
queue<pii> q;

inline bool check(const int &x, const int &y) {
  return !(x < 1 || y < 1 || x > n || y > m);
}

inline bool is_rev(const int &k, const int &x, const int &y) {
  for (int i = 0, nx, ny; i < 4; ++i) {
    nx = x+dir[i]; ny = y+dir[i+1];
    if (check(nx, ny) && b[k-1][nx][ny] == b[k-1][x][y]) return true;
  }
  return flase;
}

inline void solve() {
  scanf("%d %d %d", &n, &m, &t);
  for (int i = 1; i <= n; ++i) {
    scanf("%s", a[i]+1);
    for (int j = 1; j <= m; ++j) {
      b[0][i][j] = a[i][j]-'0';
    }
  }
  for (int k = 1; k < 10; ++k) {
    for (int i = 1; i <= n; ++i) {
      for (int j = 1; j <= m; ++j) {
        b[k][i][j] = b[k-1][i][j]^is_rev(k, i, j);
        printf("%d%c", b[k][i][j], " \n"[j==m]);
      }
    }
    puts("***");
  }
  long long p;
  for (int i = 1, x, y; i <= t; ++i) {
    scanf("%d %d %lld", &x, &y, &p);
    printf("%d\n", b[p][x][y]);
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