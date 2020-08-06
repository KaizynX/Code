/*
 * @Author: Kaizyn
 * @Date: 2020-07-14 13:09:11
 * @LastEditTime: 2020-07-14 14:25:54
 */ 
#include <bits/stdc++.h>

// #define DEBUG

using namespace std;

const double eps = 1e-7;
const double PI = acos(-1);
typedef pair<int, int> pii;
const int MOD = 998244353;
const int INF = 0x3f3f3f3f;
const int N = 4e5+7;

struct LCA {
  static const int NN = (int)log2(N)+3;
  int f[N][NN], d[N], lg2[N];
  LCA() { for (int i = 2; i < N; ++i) lg2[i] = lg2[i>>1]+1; }
  template <typename TT>
  void build(const TT e[], const int &u = 1, const int &fa = 0) {
    d[u] = d[fa]+1;
    f[u][0] = fa;
    for (int i = 1; (1<<i) <= d[u]; ++i)
      f[u][i] = f[f[u][i-1]][i-1];
    for (auto v : e[u]) if (v != fa)
      build(e, v, u);
  }
  int get(int x, int y) {
    if (d[x] < d[y]) swap(x, y);
    while (d[x] > d[y])
      x = f[x][lg2[d[x]-d[y]]];
    if (x == y) return x;
    for (int i = lg2[d[x]]; i >= 0; --i)
      if(f[x][i] != f[y][i])
        x = f[x][i], y = f[y][i];
    return f[x][0];
  }
};

int n, m;
int t[N], id[N], cnt[N];
LCA lca;
vector<int> e[N];

inline void solve() {
  cin >> n >> m;
  for (int i = 1; i <= n; ++i) {
    cin >> t[i];
  }
  for (int i = 1; i <= m; ++i) id[i] = i;
  for (int i = 1, a, b; i < m; ++i) {
    cin >> a >> b;
    e[m+i].emplace_back(id[a]);
    e[m+i].emplace_back(id[b]);
    id[a] = m+i;
  }
  lca.build(e, 2*m-1);
  for (int i = 1; i < n; ++i) {
    ++cnt[lca.get(t[i], t[i+1])];
  }
  int res = n-1;
  for (int i = 1; i < m; ++i) {
    res -= cnt[i];
  }
  for (int i = m; i < 2*m; ++i) {
    res -= cnt[i];
    cout << res << endl;
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