/*
 * @Author: Kaizyn
 * @Date: 2020-09-05 14:28:23
 * @LastEditTime: 2020-09-05 14:48:41
 */
#include <bits/stdc++.h>

// #define DEBUG

using namespace std;

const double eps = 1e-7;
const double PI = acos(-1);
typedef pair<int, int> pii;
const int MOD = 998244353;
const int INF = 0x3f3f3f3f;
const int N = 2e3+7;

int n, t;
char s[N];
int num[N], f[N][N<<1], g[N][N<<1];
vector<int> e[N];

void dfs(const int &u, const int &fa) {
  num[u] = 1;
  for (int i = 0; i <= n*2; ++i) f[u][i] = g[u][i] = s[u]-'0';
  for (const int &v : e[u]) if (v != fa) {
    dfs(v, u);
    num[u] += num[v];
    for (int i = 2*num[u]; i >= 0; --i) {
      for (int j = 0; j <= i; ++j) {
        if (i-j >= 2) f[u][i] = max(f[u][i], f[u][j]+f[v][i-j-2]);
        if (i-j >= 2) g[u][i] = max(g[u][i], g[u][j]+f[v][i-j-2]);
        if (i-j >  0) g[u][i] = max(g[u][i], f[u][j]+g[v][i-j]);
      }
      if (u == 1 && s[v] == '1') g[u][i] = max(g[u][i], f[u][i]+1);
    }
  }
}

signed main() {
  // ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
  // cin >> n >> t;
  scanf("%d %d", &n, &t);
  for (int i = 1, u, v; i < n; ++i) {
    // cin >> u >> v;
    scanf("%d %d", &u, &v);
    e[u].emplace_back(v);
    e[v].emplace_back(u);
  }
  // cin >> (s+1);
  scanf("%s", s+1);
  dfs(1, 0);
  int res = 0;
  for (int i = 0; i <= min(t, 2*n); ++i) {
    res = max({res, f[1][i], g[1][i]});
  }
  // cout << res << endl;
  printf("%d\n", res);
  return 0;
}