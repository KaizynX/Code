/*
 * @Author: Kaizyn
 * @Date: 2021-06-13 15:49:01
 * @LastEditTime: 2021-06-13 17:14:07
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
const int N = 5e2+7;

int n;
ll sum;
int vis[N], v[N][N];
ll add[N], del[N];

ll f(int s) {
  ll val = sum;
  for (int i = 1; i <= n; ++i) val -= 2*v[s][i];
  memset(vis, 0, sizeof vis);
  memset(add, 0, sizeof add);
  memset(del, 0, sizeof del);
  vis[s] = 1;
  for (int i = 1; i <= n; ++i) if (!vis[i]) {
    for (int j = 1; j <= n; ++j) {
      if (vis[j]) add[i] += v[i][j];
      else del[i] += v[i][j];
    }
  }
  for (int _ = 2; _ < n; ++_) {
    int choose = 0;
    for (int i = 1; i <= n; ++i) if (!vis[i]) {
      if (add[i]-del[i] > add[choose]-del[choose]) choose = i;
    }
    if (add[choose]-del[choose] < 0) break;
    val += (add[choose]-del[choose])*2;
    vis[choose] = 1;
    for (int i = 1; i <= n; ++i) if (!vis[i]) {
      add[i] += v[i][choose];
      del[i] -= v[i][choose];
    }
  }
  return val;
}

inline void solve() {
  cin >> n;
  for (int i = 1; i <= n; ++i) {
    for (int j = 1; j <= n; ++j) {
      cin >> v[i][j];
      sum += v[i][j];
    }
  }
  ll res = 0;
  for (int i = 1; i <= n; ++i) {
    res = max(res, f(i));
  }
  cout << res << '\n';
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