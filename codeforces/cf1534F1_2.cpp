/*
 * @Author: Kaizyn
 * @Date: 2021-07-06 14:02:11
 * @LastEditTime: 2021-07-06 14:48:35
 */
#include <bits/stdc++.h>

// #define DEBUG

using namespace std;

const double eps = 1e-7;
const double PI = acos(-1);
typedef pair<int, int> pii;
typedef long long ll;
const int MOD = 998244353; // 1e9+7;
const int INF = 0x3f3f3f3f;
// const ll INF = 1e18;
const int N = 4e5+7;
const int dir[] = {0,1,0,-1,0};

struct DSU {
  vector<int> fa;
  void init(int n) { fa = vector<int>(n+1); iota(fa.begin(), fa.end(), 0); }
  int get(int s) { return s == fa[s] ? s : fa[s] = get(fa[s]); }
  int& operator [] (int i) { return fa[get(i)]; }
  bool merge(int x, int y) { // merge x to y
    x = get(x); y = get(y);
    return x == y ? false : (fa[x] = y, true);
  }
};

int n, m;
string b[N];
int a[N], deg[N];
DSU dsu;
set<int> e[N];

void add_edge(int u, int v) {
  u = dsu[u]; v = dsu[v];
  if (u == v || e[v].count(u)) return;
  e[u].insert(v);
  ++deg[v];
}

void dfs(int x, int y) {
  for (int d = 0, nx, ny; d < 4; ++d) {
    nx = x+dir[d];
    ny = y+dir[d+1];
    if (nx < 0 || nx >= n || ny < 0 || ny >= m || b[nx][ny] != '#') continue;
    if (dsu.merge(nx*m+ny, x*m+y)) dfs(nx, ny);
  }
}

inline void solve() {
  cin >> n >> m;
  for (int i = 0; i < n; ++i) cin >> b[i];
  for (int i = 0; i < m; ++i) cin >> a[i];

  dsu.init(n*m);
  for (int i = 0; i < n; ++i) {
    for (int j = 0; j < m; ++j) {
      if (b[i][j] != '#' || dsu[i*m+j] != i*m+j) continue;
      dfs(i, j);
    }
  }
  for (int i = 0; i < n; ++i) {
    for (int j = 0; j < m; ++j) {
      // if (b[i][j] != '#' || dsu[i*m+j] != i*m+j) continue;
      if (b[i][j] != '#') continue;
      if (j && b[i][j-1] == '#') add_edge(i*m+j, i*m+j-1);
      if (j+1 < m && b[i][j+1] == '#') add_edge(i*m+j, i*m+j+1);
      for (int k = i+1; k < n; ++k) {
        if (j && b[k][j-1] == '#') add_edge(i*m+j, k*m+j-1);
        if (j+1 < m && b[k][j+1] == '#') add_edge(i*m+j, k*m+j+1);
        if (b[k][j] == '#') {
          add_edge(i*m+j, k*m+j);
          break;
        }
      }
    }
  }
  int res = 0;
  for (int i = 0; i < n; ++i) {
    for (int j = 0; j < m; ++j) {
      if (b[i][j] != '#' || dsu[i*m+j] != i*m+j) continue;
      res += deg[i*m+j] == 0;
    }
  }
  cout << res << '\n';
}

signed main() {
#ifdef ONLINE_JUDGE
  ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
#endif
  int T = 1;
  // cin >> T; // scanf("%d", &T);
  for (int t = 1; t <= T; ++t) {
    solve();
  }
  return 0;
}