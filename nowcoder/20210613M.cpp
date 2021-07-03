/*
 * @Author: Kaizyn
 * @Date: 2021-06-13 13:20:38
 * @LastEditTime: 2021-06-13 13:30:25
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
const int N = 30+7;

int n, m, h;
char a[N][N][N];
int deg[N], e[N][N], vis[N];
// vector<int> e[N];

inline void solve() {
  memset(e, 0, sizeof e);
  memset(vis, 0, sizeof vis);
  memset(deg, 0, sizeof deg);
  cin >> n >> m >> h;
  for (int i = 1; i <= h; ++i) {
    for (int j = 1; j <= n; ++j) {
      for (int k = 1; k <= m; ++k) {
        cin >> a[i][j][k];
        vis[a[i][j][k]-'A'] = 1;
        if (i > 1) e[a[i][j][k]-'A'][a[i-1][j][k]-'A'] = 1;
      }
    }
  }
  for (int i = 0; i < 26; ++i) {
    e[i][i] = 0;
    for (int j = 0; j < 26; ++j) {
      if (e[i][j]) ++deg[j];
    }
  }
  int all = 0;
  string res;
  priority_queue<int> q;
  for (int i = 0; i < 26; ++i) if (vis[i]) {
    ++all;
    if (deg[i] == 0) q.push(i);
  }
  while (q.size()) {
    int u = q.top();
    q.pop();
    res += 'A'+u;
    for (int v = 0; v < 26; ++v) if (e[u][v]) {
      if (--deg[v] == 0) q.push(v);
    }
  }
  if ((int)res.size() < all) cout << "-1\n";
  else cout << res << '\n';
}

signed main() {
#ifdef ONLINE_JUDGE
  ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
#endif
  int T = 1;
  cin >> T; // scanf("%d", &T);
  for (int t = 1; t <= T; ++t) {
    solve();
  }
  return 0;
}