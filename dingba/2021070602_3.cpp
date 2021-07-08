/*
 * @Author: Kaizyn
 * @Date: 2021-07-08 13:30:13
 * @LastEditTime: 2021-07-08 13:31:55
 */
#include <bits/stdc++.h>

// #define DEBUG

using namespace std;

const double eps = 1e-7;
const double PI = acos(-1);
typedef long long ll;
typedef pair<int, int> pii;
typedef pair<int, ll> pil;
const int MOD = 998244353; // 1e9+7;
const int INF = 0x3f3f3f3f;
// const ll INF = 1e18;
const int N = 5e4+7;

const int NN = (int)log2(N)+3;
int n, m, _dfn, cnt;
// from[i] 节点i与父亲的边所在环的编号
// tp[i]环i深度最小的节点编号, bm[i]环i深度最大的节点编号
int fa[N], dfn[N], from[N], tp[N], bm[N];
vector<int> e[N];
// dp[i][j][k] 在结点i的子树,i的选择情况为j,i和父亲的边所在环底部选择情况k
int dp[N][2][2];

bool dfs(int u) {
  dfn[u] = ++_dfn;
  for (int ui : {0, 1}) for (int uj : {0, 1}) dp[u][ui][uj] = ui;
  for (const int &v : e[u]) {
    if (v == fa[u]) continue;
    if (!dfn[v]) {
      fa[v] = u;
      if (!dfs(v)) return false;
      for (int ui : {0, 1}) for (int uj : {0, 1}) {
        int tmp = 0;
        for (int vi : {0, 1}) for (int vj : {0, 1}) {
          if (ui+vi > 1) continue;
          if (from[v] && bm[from[v]] == v && vi != vj) continue;
          if (from[v] && tp[from[v]] == u && (vi|vj)+ui > 1) continue;
          if (from[u] && from[v] && from[u] == from[v] && uj != vj) continue;
          tmp = max(tmp, dp[v][vi][vj]);
        }
        dp[u][ui][uj] += tmp;
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
  return true;
}

inline void solve() {
  cin >> n >> m;
  for (int i = 1, u, v; i <= m; ++i) {
    cin >> u >> v;
    e[u].emplace_back(v);
    e[v].emplace_back(u);
  }
  dfs(1);
  cout << max({dp[1][0][0], dp[1][0][1], dp[1][1][0], dp[1][1][1]}) << '\n';
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