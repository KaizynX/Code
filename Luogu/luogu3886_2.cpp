/*
 * @Author: Kaizyn
 * @Date: 2020-07-16 15:46:57
 * @LastEditTime: 2020-07-16 16:31:34
 */ 
#include <bits/stdc++.h>

// #define DEBUG

using namespace std;

const double eps = 1e-7;
const double PI = acos(-1);
typedef pair<int, int> pii;
const int MOD = 998244353;
const int INF = 0x3f3f3f3f;
const int N = 9+2;

int n, u, res = -INF;
int a[N][N];
unordered_map<int, int> dp[2];

inline void decode(const int &state, int *const s) {
  for (int i = 1; i <= n; ++i) s[i] = (state>>i*3-3)%8;
}

inline void insert(const int *const s, const int &val) {
  static int vis[N];
  int state = 0, cnt = 0;
  memset(vis, 0, sizeof vis);
  for (int i = 1; i <= n; ++i) {
    if (s[i] && !vis[s[i]]) vis[s[i]] = ++cnt;
    state |= (vis[s[i]]<<i*3-3);
  }
  if (dp[u].count(state)) dp[u][state] = max(dp[u][state], val);
  else dp[u].insert({state, val});
  if (cnt == 1) res = max(res, val);
}

inline void solve() {
  static int s[N];
  cin >> n;
  for (int i = 1; i <= n; ++i) {
    for (int j = 1; j <= n; ++j) {
      cin >> a[i][j];
    }
  }
  dp[u = 0].clear();
  dp[u][0] = 0;
  for (int i = 1; i <= n; ++i) {
    for (int j = 1; j <= n; ++j) {
      dp[u ^= 1].clear();
      for (const auto &p : dp[u^1]) {
        decode(p.first, s);
        int b1 = s[j-1], b2 = s[j];
        // not choose
        s[j] = 0;
        int cnt = 0;
        for (int k = 1; k <= n; ++k) cnt += s[k] == b2;
        if (!b2 || cnt) insert(s, p.second);
        s[j] = b2;
        // choose
        if (!b1 && !b2) {
          s[j] = 7;
        } else {
          if (b1 > b2) swap(b1, b2); // in case b2 == 0
          s[j] = b2;
          if (b1) for (int k = 1; k <= n; ++k) if (s[k] == b1) s[k] = b2;
        }
        insert(s, p.second+a[i][j]);
      }
    }
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