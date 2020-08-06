/*
 * @Author: Kaizyn
 * @Date: 2020-07-11 14:15:02
 * @LastEditTime: 2020-07-11 15:44:25
 */ 
#include <bits/stdc++.h>

// #define DEBUG

using namespace std;

const double eps = 5e-4;
const double PI = acos(-1);
typedef pair<int, int> pii;
const int MOD = 998244353;
const int INF = 0x3f3f3f3f;
const int N = 2500+7;

int n, k;
int dfn[N], _dfn, nex[N], id[N];
int s[N], p[N], r[N];
double dp[N][N];
vector<int> e[N];

void dfs(const int &u) {
  dfn[u] = _dfn++;
  id[dfn[u]] = u;
  for (const int &v : e[u]) dfs(v);
  nex[dfn[u]] = _dfn;
}

inline double calc(const int &x, const double &mid) {
  return p[id[x]]-mid*s[id[x]];
}

inline bool check(const double &mid) {
  for (int i = 1; i <= n+1; ++i) {
    for (int j = 0; j <= k+1; ++j) {
      dp[i][j] = -INF;
    }
  }
  for (int i = 0; i <= n; ++i) {
    for (int j = 0; j <= min(k+1, i); ++j) {
      dp[i+1][j+1] = max(dp[i+1][j+1], dp[i][j]+calc(i, mid));
      dp[nex[i]][j] = max(dp[nex[i]][j], dp[i][j]);
    }
  }
  return dp[n+1][k+1] > 0;
}

inline void solve() {
  scanf("%d %d", &k, &n);
  for (int i = 1; i <= n; ++i) {
    scanf("%d %d %d", s+i, p+i, r+i);
    e[r[i]].emplace_back(i);
  }
  dfs(0);
  double l = 0, r = 1e4, mid;
  while (r-l > eps) {
    mid = (l+r)/2;
    if (check(mid)) l = mid;
    else r = mid;
  }
  printf("%.3f\n", l);
}

signed main() {
  // ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
  int T = 1;
  // cin >> T;
  for (int t = 1; t <= T; ++t) {
    solve();
  }
  return 0;
}