/*
 * @Author: Kaizyn
 * @Date: 2021-07-08 13:09:05
 * @LastEditTime: 2021-07-08 17:31:12
 */
#include <bits/stdc++.h>

#define DEBUG

using namespace std;

const double eps = 1e-7;
const double PI = acos(-1);
typedef pair<int, int> pii;
typedef long long ll;
const int MOD = 998244353; // 1e9+7;
const int INF = 0x3f3f3f3f;
// const ll INF = 1e18;
const int N = 1e5+7;

int n, m;
vector<int> e[N];
// f[i][j][x][y] 结点i与父亲边,边权j,所在环边权和%2=x,环非树边权y
int f[N][3][2][3];
int _dfn, cnt, fa[N], dfn[N], from[N], tp[N], bm[N];

void update(int &x, const int &y) {
  if (x == -1 || y < x) x = y;
}

bool dfs(int u) {
  int h[1<<3][3][2][3], g[1<<3][3][2][3];
  dfn[u] = ++_dfn;
  memset(f[u], -1, sizeof(f[u]));
  memset(h, -1, sizeof h);
  // 初始,仅考虑u父亲一条边
  for (int uj : {0, 1, 2}) for (int uy : {0, 1, 2})
    h[1<<uj][uj][uj&1][uy] = 0;
  for (const int &v : e[u]) {
    if (v == fa[u]) continue;
    if (!dfn[v]) {
      fa[v] = u;
      if (!dfs(v)) return false;
      swap(g, h); // memcpy(g, h, sizeof h);
      memset(h, -1, sizeof h); // v必须选
      for (int us = 0; us < 8; ++us) for (int uj : {0, 1, 2}) {
        // if ((us>>((4-uj)%3))%2 == 1 || (us>>uj)%2 == 0) continue; // 条件1
        for (int ux : {0, 1}) for (int uy : {0, 1, 2})
        for (int vj : {0, 1, 2}) if ((us>>((4-vj)%3))%2 == 0)
        for (int vx : {0, 1}) for (int vy : {0, 1, 2}) {
          if (g[us][uj][ux][uy] == -1 || f[v][vj][vx][vy] == -1) continue;
          int x = ux, s = us|(1<<vj);
          if (from[v]) {
            // 如果属于一个环,环权和相加,否则v环权和必须为奇数
            if (from[u] == from[v]) {
              if (uy != vy) continue;
              x = (x+vx+vj)&1;
            } else {
              if ((vx+vj)%2 == 0) continue; // 条件2
              // 若u为环顶部,则需考虑边vy
              assert(u == tp[from[v]]);
              if ((s>>((4-vy)%3))&1) continue; // 条件1
              s |= 1<<vy;
            }
          }
          update(h[s][uj][x][uy], g[us][uj][ux][uy]+f[v][vj][vx][vy]+vj);
        }
      }
    } else if (dfn[v] < dfn[u]) {
      ++cnt;
      tp[cnt] = v; bm[cnt] = u;
      for (int x = u; x != v; x = fa[x]) {
        if (from[x]) return false;
        from[x] = cnt;
      }
    }
  }
  // 若u为环底部,则将y统计进答案
  for (int us = 0; us < 8; ++us) for (int uj : {0, 1, 2}) {
    // if ((us>>((4-uj)%3))&1) continue; // 条件1
    for (int ux : {0, 1}) for (int uy : {0, 1, 2}) {
      if (h[us][uj][ux][uy] == -1) continue;
      if (u == bm[from[u]]) {
        if ((us>>((4-uy)%3))%2 == 1) continue;
        update(f[u][uj][(ux+uy)&1][uy], h[us][uj][ux][uy]+uy);
      } else {
        update(f[u][uj][ux][uy], h[us][uj][ux][uy]);
      }
    }
  }
#ifdef DEBUG
  puts("********************");
  for (int j : {0, 1, 2}) for (int x : {0, 1}) for (int y : {0, 1, 2}) {
    printf("f[%d][%d][%d][%d]=%d\n", u, j, x, y, f[u][j][x][y]);
  }
  // for (int us = 0; us < 8; ++us) for (int uj : {0, 1, 2})
    // for (int ux : {0, 1}) for (int uy : {0, 1, 2})
      // printf("h[%d][%d][%d][%d]=%d\n", us, uj, ux, uy, h[us][uj][ux][uy]);
  puts("********************");
#endif
  return true;
}

inline void solve() {
  cin >> n >> m;
  for (int i = 1, u, v; i <= m; ++i) {
    cin >> u >> v;
    e[u].emplace_back(v);
    e[v].emplace_back(u);
  }
  int ans = 0;
  for (int i = 1; i <= n; ++i) if (!dfn[i]) {
    if (!dfs(i)) return cout << "-1\n", void();
    int res = -1;
    for (int j : {0, 1, 2}) for (int k : {0, 1, 2})
      if (~f[i][j][1][k]) update(res, f[i][j][1][k]);
    ans += res;
  }
  cout << ans << '\n';
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