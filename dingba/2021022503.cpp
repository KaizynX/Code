/*
 * @Author: Kaizyn
 * @Date: 2021-02-25 21:30:16
 * @LastEditTime: 2021-02-26 17:09:02
 */
#include <bits/stdc++.h>

// #define DEBUG

using namespace std;

const double eps = 1e-7;
const double PI = acos(-1);
typedef pair<int, int> pii;
typedef long long ll;
const int MOD = 998244353;
const int INF = 0x3f3f3f3f;
// const ll INF = 1e18;
const int N = 1e5+7;

int n, p;
int d[N];
vector<pii> e[N];

void dfs(int u, int fa = 0) {
  for (auto &p : e[u]) {
    int v = p.first;
    if (v == fa) continue;
    d[v] = d[u]+1;
    dfs(v, u);
  }
}

inline void solve() {
  cin >> n >> p;
  for (int i = 1, u, v, w; i < n; ++i) {
    cin >> u >> v >> w;
    e[u].emplace_back(v, w);
    e[v].emplace_back(u, w);
  }
  int res = 1;
  if (p == 1) {
    res = 1;
  } else if (p == 2) {
    memset(d+1, 0, sizeof(int)*n);
    d[1] = 1;
    dfs(1);
    int p = 0;
    for (int i = 1; i <= n; ++i) if (d[p] < d[i]) p = i;
    // for (int i = 1; i <= n; ++i) cout << d[i] << " \n"[i==n];
    memset(d+1, 0, sizeof(int)*n);
    d[p] = 1;
    dfs(p);
    for (int i = 1; i <= n; ++i) res = max(res, d[i]);
  } else {
    res = n;
  }
  cout << res << '\n';
}

signed main() {
#ifdef ONLINE_JUDGE
  ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
#endif
  int T = 1;
  cin >> T;
  for (int t = 1; t <= T; ++t) {
    solve();
    for (int i = 1; i <= n; ++i) e[i].clear();
  }
  return 0;
}