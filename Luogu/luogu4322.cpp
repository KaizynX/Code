/*
 * @Author: Kaizyn
 * @Date: 2020-07-11 14:15:02
 * @LastEditTime: 2020-07-11 14:51:07
 */ 
#include <bits/stdc++.h>

// #define DEBUG

using namespace std;

const double eps = 1e-4;
const double PI = acos(-1);
typedef pair<int, int> pii;
const int MOD = 998244353;
const int INF = 0x3f3f3f3f;
const int N = 2500+7;

int n, k;
int s[N], p[N], r[N], son[N];
double dp[N][N];
vector<int> e[N];

void dfs(const int &u, const double &mid) {
  son[u] = 1;
  dp[u][0] = 0;
  dp[u][1] = p[u]-mid*s[u];
  for (const int &v : e[u]) {
    dfs(v, mid);
    for (int i = 1; i <= son[v]; ++i) dp[u][son[u]+i] = -INF;
    for (int i = min(son[u]+son[v], k+1); i; --i) {
      for (int j = max(0, i-son[u]); j <= min(son[v], i-1); ++j) {
        dp[u][i] = max(dp[u][i], dp[u][i-j]+dp[v][j]);
      }
    }
    son[u] += son[v];
  }
}

inline bool check(const double &mid) {
  dfs(0, mid);
  return dp[0][k+1] > 0;
}

inline void solve() {
  scanf("%d %d", &k, &n);
  for (int i = 1; i <= n; ++i) {
    scanf("%d %d %d", s+i, p+i, r+i);
    e[r[i]].emplace_back(i);
  }
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