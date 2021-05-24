/*
 * @Author: Kaizyn
 * @Date: 2021-05-02 12:24:29
 * @LastEditTime: 2021-05-02 12:34:58
 */
#include <bits/stdc++.h>

#define DEBUG

using namespace std;

const double eps = 1e-7;
const double PI = acos(-1);
typedef pair<int, int> pii;
typedef long long ll;
const int MOD = 998244353; // 1e9+7;
const int INF = 0x3f3f3f3f;
// const ll INF = 1e18;
const int N = 3e3+7;

int n, m, t;
int a[N], d[N];
int dp[N];
vector<int> e[N];

inline void solve() {
  cin >> n >> m >> t;
  for (int i = 2; i <= n; ++i) cin >> a[i];
  for (int i = 1, u, v; i <= m; ++i) {
    cin >> u >> v;
    e[u].emplace_back(v);
    e[v].emplace_back(u);
  }
  queue<int> q;
  memset(d, 0x3f, sizeof d);
  d[1] = 0;
  q.push(1);
  while (q.size()) {
    int u = q.front();
    q.pop();
    for (int &v : e[u]) {
      if (d[u]+1 < d[v]) {
        d[v] = d[u]+1;
        q.push(v);
      }
    }
  }
  #ifdef DEBUG
  for (int i = 1; i <= n; ++i) {
    cout << d[i] << " \n"[i==n];
  }
  #endif
  for (int i = 2; i <= n; ++i) {
    for (int j = d[i]*2; j <= t; ++j) {
      dp[j] = max(dp[j], dp[j-d[i]*2]+a[i]);
    }
  }
  for (int i = 1; i <= t; ++i) {
    cout << dp[i] << " \n"[i==t];
  }
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