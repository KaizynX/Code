/*
 * @Author: Kaizyn
 * @Date: 2020-06-13 20:58:04
 * @LastEditTime: 2020-06-22 11:15:32
 */ 
#include <bits/stdc++.h>

// #define DEBUG

using namespace std;

const double eps = 1e-7;
const double PI = acos(-1);
typedef pair<int, int> pii;
const int MOD = 998244353;
const int INF = 0x3f3f3f3f;
const int N = (1<<18)+7;
const int M = 1e5+7;
const int MID = 9;

int n, m, q;
int v[N], w[N];
int a[N], lg2[N], sumv[N], sumw[N];
int dp[10][M];
int res[M];
vector<pii> query[N];

void bfs(const int &u, const int &dep) {
  if (u > n) return;
  if (dep <= MID) {
    // memset(dp[dep], 0, sizeof dp[dep]);
    for (int i = 0; i <= m; ++i) {
      dp[dep][i] = dp[dep-1][i];
      if (i >= w[u]) dp[dep][i] = max(dp[dep][i], dp[dep-1][i-w[u]]+v[u]);
    }
    for (const pii &p : query[u]) {
      res[p.first] = dp[dep][p.second];
    }
  } else {
    a[dep-MID-1] = u;
    for (const pii &p : query[u]) res[p.first] = dp[MID][p.second];
    if (query[u].size()) for (int i = 1, j; i < 1<<(dep-MID); ++i) {
      j = i&-i;
      sumv[i] = sumv[i^j]+v[a[lg2[j]]];
      sumw[i] = sumw[i^j]+w[a[lg2[j]]];
      for (const pii &p : query[u]) {
        if (sumw[i] > p.second) continue;
        res[p.first] = max(res[p.first], dp[MID][p.second-sumw[i]]+sumv[i]);
      }
    }
  }
  bfs(u<<1, dep+1);
  bfs(u<<1|1, dep+1);
}

inline void solve() {
  cin >> n;
  for (int i = 1; i <= n; ++i) {
    cin >> v[i] >> w[i];
  }
  cin >> q;
  for (int i = 1, x, L; i <= q; ++i) {
    cin >> x >> L;
    query[x].emplace_back(i, L);
    m = max(m, L);
  }
  bfs(1, 1);
  for (int i = 1; i <= q; ++i) {
    cout << res[i] << endl;
  }
}

signed main() {
  ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
  for (int i = 0; i <= 18; ++i) lg2[1<<i] = i;
  int T = 1;
  // cin >> T;
  for (int t = 1; t <= T; ++t) {
    solve();
  }
  return 0;
}