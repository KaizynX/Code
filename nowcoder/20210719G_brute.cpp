/*
 * @Author: Kaizyn
 * @Date: 2021-07-19 15:26:42
 * @LastEditTime: 2021-07-19 15:50:53
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
const int N = 5e3+7;

struct Node {
  int l, r;
  bool operator <(const Node &b) const {
    return l != b.l ? l < b.l : r > b.r;
  }
};

int n, m, k;
Node a[N], b[N];
int q[N], head, tail;
ll dp[N][N];

inline void solve() {
  cin >> n >> k;
  int mx = 0;
  for (int i = 1; i <= n; ++i) {
    cin >> a[i].l >> a[i].r;
    mx = max(mx, a[i].r-a[i].l);
  }
  sort(a+1, a+n+1);
  head = tail = 0;
  for (int i = 1; i <= n; ++i) {
    while (head < tail && a[q[tail-1]].r >= a[i].r) --tail;
    q[tail++] = i;
  }
  m = tail;
  for (int i = 1; i <= m; ++i) b[i] = a[q[i-1]];
  ll res = 0;
  memset(dp, -1, sizeof dp);
  dp[0][0] = 0;
  for (int i = 1; i <= k; ++i) {
    for (int j = 1; j <= m; ++j) {
      for (int p = 0; p < j; ++p) {
        if (dp[i-1][p] == -1) continue;
        if (b[p+1].r <= b[j].l) continue;
        dp[i][j] = max(dp[i][j], dp[i-1][p]+b[p+1].r-b[j].l);
      }
      #ifdef DEBUG
      cout << dp[i][j] << " \n"[j==m];
      #endif
    }
    if (~dp[i][m]) res = max(res, dp[i][m]+(k-i)*mx);
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