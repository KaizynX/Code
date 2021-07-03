/*
 * @Author: Kaizyn
 * @Date: 2021-06-13 17:21:26
 * @LastEditTime: 2021-06-13 17:32:01
 */
#include <bits/stdc++.h>

// #define DEBUG

using namespace std;

const double eps = 1e-7;
const double PI = acos(-1);
typedef pair<int, int> pii;
typedef long long ll;
const int MOD = 998244353; // 1e9+7;
// const int INF = 0x3f3f3f3f;
const ll INF = 1e18;
const int N = 5e2+7;

int n, s, t;
int del[N], vis[N], v[N][N];
ll w[N];

inline ll search() {
  memset(vis, 0, sizeof vis);
  memset(w, 0, sizeof w);
  s = t = 0;
  ll res = INF;
  while (true) {
    int p = 0;
    ll mx = -INF;
    for (int i = 1; i <= n; ++i) if (!del[i] && !vis[i]) {
      if (w[i] > mx) mx = w[i], p = i;
    }
    vis[p] = 1;
    if (!p) return res;
    s = t;
    t = p;
    res = w[p];
    for (int i = 1; i <= n; ++i) if (!del[i] && !vis[i]) {
      w[i] += v[i][p];
    }
  }
}

inline ll SW() {
  ll res = INF;
  for (int i = 1; i < n; ++i) {
    res = min(res, search());
    if (!res) break;
    del[t] = 1;
    for (int j = 1; j <= n; ++j) if (!del[j]) {
      v[s][j] += v[t][j];
      v[j][s] += v[j][t];
    }
  }
  return res;
}

inline void solve() {
  cin >> n;
  ll sum = 0;
  for (int i = 1; i <= n; ++i) {
    for (int j = 1; j <= n; ++j) {
      cin >> v[i][j];
      sum += v[i][j];
      v[i][j] = -v[i][j];
    }
  }
  cout << -SW() << '\n';
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