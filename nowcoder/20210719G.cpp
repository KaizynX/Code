/*
 * @Author: Kaizyn
 * @Date: 2021-07-19 15:05:05
 * @LastEditTime: 2021-07-19 16:39:41
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
const int N = 5e3+7;

struct Node {
  int l, r;
  bool operator <(const Node &b) const {
    return l < b.l;
    // return l != b.l ? l < b.l : r > b.r;
  }
};

int n, m, k, rnm;
Node a[N], b[N];
int q[N], head, tail, c[N], s[N];
int dp[N][N];

inline int calc(int i, int j) {
  return dp[i][j]+b[j+1].r;
}

inline void solve() {
  cin >> n >> k;
  for (int i = 1; i <= n; ++i) {
    cin >> a[i].l >> a[i].r;
  }
  for (int i = 1; i <= n; ++i) {
    int flag = 1;
    for (int j = 1; j <= n; ++j) {
      if (a[j].l == a[i].l && a[j].r == a[i].r) {
        if (j < i) flag = 0;
      } else if (a[j].l >= a[i].l && a[j].r <= a[i].r) {
        flag = 0;
      }
    }
    if (flag) b[++m] = a[i];
    else c[++rnm] = a[i].r-a[i].l;
  }
  sort(b+1, b+m+1);
  sort(c+1, c+rnm+1);
  reverse(c+1, c+rnm+1);
  for (int i = 1; i <= rnm; ++i) s[i] = s[i-1]+c[i];
  memset(dp, -1, sizeof dp);
  dp[0][0] = 0;
  int res = 0;
  for (int i = 1; i <= k; ++i) {
    head = tail = 0;
    for (int j = 1; j <= m; ++j) {
      if (~dp[i-1][j-1]) {
        while (head < tail && calc(i-1, q[tail-1]) <= calc(i-1, j-1)) --tail;
        q[tail++] = j-1;
      }
      while (head < tail && b[q[head]+1].r <= b[j].l) ++head;
      if (head < tail) dp[i][j] = dp[i-1][q[head]]+b[q[head]+1].r-b[j].l;
#ifdef DEBUG
      cout << dp[i][j] << " \n"[j==m];
#endif
    }
    if (~dp[i][m]) res = max(res, dp[i][m]+s[k-i]);
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