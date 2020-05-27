/*
 * @Author: Kaizyn
 * @Date: 2020-05-23 20:18:02
 * @LastEditTime: 2020-05-23 20:33:20
 */ 
#include <bits/stdc++.h>

// #define DEBUG

using namespace std;

const double eps = 1e-7;
const double PI = acos(-1);
typedef pair<int, int> pii;
const int MOD = 998244353;
const int INF = 0x3f3f3f3f;
const int N = 5e2+7;

int n;
int p[N*N], dp[N*N], a[N*N];
queue<int> q;

inline int mp(const int &x, const int &y) {
  return (x-1)*n+y;
}

inline void push(const int &x, const int &v) {
  if (v < dp[x]) {
    dp[x] = v;
    q.push(x);
  }
}

inline void bfs() {
  while (q.size()) {
    int u = q.front();
    q.pop();
    if (u%n != 1) push(u-1, dp[u]+a[u]);
    if (u%n != 0) push(u+1, dp[u]+a[u]);
    if (u-n > 0) push(u-n, dp[u]+a[u]);
    if (u+n <= n*n) push(u+n, dp[u]+a[u]);
  }
}

inline void solve() {
  cin >> n;
  memset(dp, 0x3f, sizeof dp);
  for (int i = 1; i <= n*n; ++i) a[i] = 1;
  for (int i = 1; i <= n; ++i) {
    push(mp(1, i), 0);
    push(mp(n, i), 0);
    push(mp(i, 1), 0);
    push(mp(i, n), 0);
  }
  bfs();
  int res = 0;
  for (int i = 1; i <= n*n; ++i) {
    cin >> p[i];
    res += dp[p[i]];
    a[p[i]] = 0;
    q.push(p[i]);
    // push(p[i], --dp[p[i]]);
    bfs();
  }
  cout << res << endl;
}

signed main() {
  ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
  int T = 1;
  // cin >> T;
  for (int t = 1; t <= T; ++t) {
    solve();
  }
  return 0;
}