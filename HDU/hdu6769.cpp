/*
 * @Author: Kaizyn
 * @Date: 2020-07-23 23:18:11
 * @LastEditTime: 2020-07-24 10:58:17
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
int a[N], b[N];
long long D;
ll mv[N][K], d1[K], d2[K];
vector<pii> e[N];
vector<ll> dp[N][K];

template <typename T>
inline void update(T &x, const T &y) {
  if (x == -1 || y < x) x = y;
}

void dfs(const int &u, const int fa) {
  memset(d1, -1, sizeof d1);
  memset(d2, -1, sizeof d2);
  for (int i = 0, v, w; i < (int)e[u].size(); ++i) {
    v = e[u][i].first;
    w = e[u][i].second;
    if (v == fa) continue;
    dfs(v, u);
    for (int j = 0; j <= k; ++j) {
      if (~mv[v][j]) {
        update(dp[u][j][i], mv[v][j]+b[w]);
        if (j+1 <= k) update(dp[u][j+1][i], mv[v][j]+a[w]);
      }
      if (dp[u][j][i] > d1[j]) {
        d2[j] = d1[j];
        d1[j] = dp[u][j][i];
      } else if (dp[u][j][i] > d2[j]) {
        d2[j] = dp[u][j][i];
      }
    }
  }
  for (int j = 0; j <= k/2; ++j) mv[u][j] = d1[j];
  if (mv[u][0] == -1) mv[u][0] = 0;
  for (int j = 0; j <= k; ++j) {
    if (j == k-j) {
      if (~d1[j] && ~d2[j]) D = max(D, d1[j]+d2[j]);
    } else {
      if (~d1[j] && ~d1[k-j]) D = max(D, d1[j]+d1[k-j]);
    }
  }
}

inline void solve() {
  cin >> n >> k;
  for (int i = 1, u, v; i < n; ++i) {
    cin >> u >> v >> a[i] >> b[i];
    e[u].emplace_back(v, i);
    e[v].emplace_back(u, i);
  }
  for (int i = 1; i <= n; ++i) {
    for (int j = 0; j <= k; ++j) {
      mv[i][j] = -1;
      vector<ll>(e[i].size(), -1).swap(dp[i][j]);
    }
  }
  D = 0;
  dfs(1, 0);
  cout << D << endl;
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