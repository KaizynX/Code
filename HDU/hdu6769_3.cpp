/*
 * @Author: Kaizyn
 * @Date: 2020-07-23 23:18:11
 * @LastEditTime: 2020-07-24 15:38:45
 */ 
#include <bits/stdc++.h>

// #define DEBUG

using namespace std;

const double eps = 1e-7;
const double PI = acos(-1);
typedef pair<int, int> pii;
typedef long long ll;
const int MOD = 998244353;
// const int INF = 0x3f3f3f3f;
const ll INF = 1e18;
const int N = 2e5+7;
const int K = 22;

int n, k;
int a[N], b[N], sz[N];
long long D;
long long dp[N][K];
vector<pii> e[N];

void dfs(const int &u, const int fa) {
  static long long mv[K];
  dp[u][0] = sz[u] = 0;
  for (int i = 0, v, w; i < (int)e[u].size(); ++i) {
    v = e[u][i].first;
    w = e[u][i].second;
    if (v == fa) continue;
    dfs(v, u);
    for (int j = 0; j <= k; ++j) mv[j] = D+1;
    for (int j = 0; j <= sz[u]; ++j) {
      for (int l = 0; l <= sz[v] && j+l <= k; ++l) {
        if (dp[u][j]+dp[v][l]+a[w] <= D) {
          mv[j+l+1] = min(mv[j+l+1], max(dp[u][j], dp[v][l]+a[w]));
        }
        if (dp[u][j]+dp[v][l]+b[w] <= D) {
          mv[j+l] = min(mv[j+l], max(dp[u][j], dp[v][l]+b[w]));
        }
      }
    }
    sz[u] = min(sz[u]+sz[v]+1, k);
    for (int j = 0; j <= k; ++j) dp[u][j] = mv[j];
  }
}

inline void solve() {
  cin >> n >> k;
  for (int i = 1, u, v; i < n; ++i) {
    cin >> u >> v >> a[i] >> b[i];
    e[u].emplace_back(v, i);
    e[v].emplace_back(u, i);
  }
  long long l = 0, r = 2e13, mid;
  while (l < r) {
    mid = (l+r)>>1;
    D = mid;
    dfs(1, 0);
    if (dp[1][k] <= mid) r = mid;
    else l = mid+1;
  }
  cout << l << endl;
  for (int i = 1; i <= n; ++i) {
    vector<pii>().swap(e[i]);
  }
}

signed main() {
  ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
  int T = 1;
  cin >> T;
  for (int t = 1; t <= T; ++t) {
    solve();
  }
  return 0;
}