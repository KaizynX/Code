/*
 * @Author: Kaizyn
 * @Date: 2021-07-03 15:59:11
 * @LastEditTime: 2021-07-03 16:14:13
 */
#include <bits/stdc++.h>

// #define DEBUG

using namespace std;

const double eps = 1e-7;
const double PI = acos(-1);
typedef pair<int, int> pii;
typedef long long ll;
const int MOD = 998244353; // 1e9+7;
const int INF = 0x3f3f3f3f;
// const ll INF = 1e18;
const int N = 6e2+7;

template <typename T>
T sw(int n, T dis[N][N]) {
  int s, t;
  T res = INF;
  vector<int> dap(n+1, 0), ord(n+1, 0), vis;
  vector<T> w;
  function<T(int)> proc = [&](int x) {
    vis = vector<int>(n+1, 0);
    w = vector<T>(n+1, 0);
    w[0] = -1;
    for (int i = 1; i <= n-x+1; ++i) {
      int mx = 0;
      for (int j = 1; j <= n; ++j) {
        if (!dap[j] && !vis[j] && w[j] > w[mx]) mx = j;
      }
      vis[mx] = 1;
      ord[i] = mx;
      for (int j = 1; j <= n; ++j) {
        if (!dap[j] && ! vis[j]) w[j] += dis[mx][j];
      }
    }
    s = ord[n-x];
    t = ord[n-x+1];
    return w[t];
  };
  for (int i = 1; i < n; ++i) {
    res = min(res, proc(i));
    dap[t] = 1;
    for (int j = 1; j <= n; ++j) {
      dis[s][j] += dis[t][j];
      dis[j][s] += dis[j][t];
    }
  }
  return res;
}

int n, m;
int dis[N][N];

inline void solve() {
  cin >> n >> m;
  for (int i = 1, a, b, w; i <= m; ++i) {
    cin >> a >> b >> w;
    dis[a][b] += w;
    dis[b][a] += w;
  }
  cout << sw(n, dis) << '\n';
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