/*
 * @Author: Kaizyn
 * @Date: 2020-12-14 20:29:31
 * @LastEditTime: 2020-12-15 15:49:46
 */
#include <bits/stdc++.h>

// #define DEBUG

using namespace std;

const double eps = 1e-7;
const double PI = acos(-1);
typedef pair<int, int> pii;
const int MOD = 998244353;
const int INF = 0x3f3f3f3f;
const int N = 1e2+7;
const int K = 55;

int n, k;
int w[N], d[N], a[N];
int dp[N][N][K], tmp[K];
vector<int> e[N], fa;

void update(int u, int f, int v) {
  memcpy(tmp, dp[u][f], sizeof(int)*(k+1));
  for (int i = k; i >= 0; --i) {
    dp[u][f][i] = INF;
    for (int j = i; j >= 0; --j) {
      dp[u][f][i] = min(dp[u][f][i],
          tmp[i-j]+min(dp[v][v][j], dp[v][f][j]));
    }
  }
}

void dfs(int u) {
  fa.emplace_back(u);
  for (int &f : fa) {
    fill(dp[u][f], dp[u][f]+k+1, (a[u]-a[f])*w[u]);
  }
  for (int &v : e[u]) {
    a[v] = a[u]+d[v];
    dfs(v);
    for (int &f : fa) update(u, f, v);
  }
  for (int i = k+1; i; --i) {
    dp[u][u][i] = dp[u][u][i-1];
  }
  dp[u][u][0] = INF;
#ifdef DEBUG
  cout << u << "************\n";
  for (int &f : fa) {
    cout << f << ":";
    for (int i = 0; i <= k+1; ++i) {
      cout << dp[u][f][i] << " \n"[i==k+1];
    }
  }
  cout << u << "************\n";
#endif
  fa.pop_back();
}

inline void solve() {
  cin >> n >> k;
  for (int i = 1, v; i <= n; ++i) {
    cin >> w[i] >> v >> d[i];
    e[v].emplace_back(i);
  }
  dfs(0);
  cout << dp[0][0][k+1] << endl;
}

signed main() {
#ifndef DEBUG
  ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
#endif
  int T = 1;
  // cin >> T;
  for (int t = 1; t <= T; ++t) {
    solve();
  }
  return 0;
}