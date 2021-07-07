/*
 * @Author: Kaizyn
 * @Date: 2021-07-06 15:24:26
 * @LastEditTime: 2021-07-06 15:28:19
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

int n, m;
string b[N];
int a[N], deg[N];
vector<int> e[N];
int dfn[N], low[N], __dfn, vis[N], sta[N], top, w_col[N], col[N];

inline void add_edge(int u, int v) {
  e[u].emplace_back(v);
}

void tarjan(int u) {
  dfn[u] = low[u] = ++_dfn;
  vis[u] = 1;
  sta[++top] = u;
  for (int v : e[u]) {
    if (!dfn[v]) {
      tarjan(v);
      low[u] = min(low[u], low[v]);
    } else if (vis[v]) {
      low[u] = min(low[u], low[v]);
    }
  }
  if (dfn[u] == low[u]) {
    w_col[++_col] = 0;
    do {
      col[sta[top]] = _col;
      vis[sta[top]] = 0;
      w_col[_col] += w[sta[top]];
    } while (sta[top--] != u);
  }
}

inline void suodian() {
  for (int i = 1; i <= n; ++i) {
    if (!dfn[i]) tarjan(i);
  }
  for (int i = 1; i <= n; ++i) {
    for (int j : e[i]) {
      if (col[i] == col[j]) continue;
      e_col[col[i]].push_back(col[j]);
    }
  }
}
inline void solve() {
  cin >> n >> m;
  for (int i = 0; i < n; ++i) cin >> b[i];
  for (int i = 0; i < m; ++i) cin >> a[i];

  for (int i = 0; i < n; ++i) {
    for (int j = 0; j < m; ++j) {
      if (b[i][j] != '#') continue;
      if (j && b[i][j-1] == '#') add_edge(i*m+j, i*m+j-1);
      if (j+1 < m && b[i][j+1] == '#') add_edge(i*m+j, i*m+j+1);
      for (int k = i+1; k < n; ++k) {
        if (b[k][j] == '#') {
          add_edge(i*m+j, k*m+j);
          break;
        }
        if (j && b[k][j-1] == '#') add_edge(i*m+j, k*m+j-1);
        if (j+1 < m && b[k][j+1] == '#') add_edge(i*m+j, k*m+j+1);
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