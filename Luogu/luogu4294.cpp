/*
 * @Author: Kaizyn
 * @Date: 2020-07-16 20:29:56
 * @LastEditTime: 2020-07-16 21:51:59
 */ 
#include <bits/stdc++.h>

// #define DEBUG

using namespace std;

const double eps = 1e-7;
const double PI = acos(-1);
typedef pair<int, int> pii;
const int MOD = 998244353;
const int INF = 0x3f3f3f3f;
const int N = 10+2;
const int M = 1e2+7;

int n, m, ed;
int resu, ress;
int a[N][N], b[N][N];
unordered_map<int, int> dp[M], pre[M];

inline void decode(const int &state, int *const s) {
  for (int i = 1; i <= m; ++i) s[i] = (state>>i*3-3)%8;
}

inline void insert(const int &last_state, const int *const s, const int &u, const int &val) {
  static int vis[N];
  int state = 0, cnt = 0;
  memset(vis, 0, sizeof vis);
  for (int i = 1; i <= m; ++i) {
    if (s[i] && !vis[s[i]]) vis[s[i]] = ++cnt;
    state |= (vis[s[i]]<<i*3-3);
  }
  if (!dp[u].count(state) || dp[u][state] > val) {
    dp[u][state] = val;
    pre[u][state] = last_state;
  }
  if (u >= ed && cnt == 1 && (!resu || dp[u][state] < dp[resu][ress])) {
    resu = u;
    ress = state;
  }
}

inline void solve() {
  static int s[N];
  ed = -1;
  cin >> n >> m;
  for (int i = 1; i <= n; ++i) {
    for (int j = 1; j <= m; ++j) {
      cin >> a[i][j];
      if (!a[i][j]) ed = (i-1)*m+j;
    }
  }
  if (ed == -1) return cout << 0 << endl, void();
  dp[0][0] = 0;
  pre[0][0] = 0;
  for (int i = 1; i <= n; ++i) {
    for (int j = 1; j <= m; ++j) {
      int u = (i-1)*m+j;
      for (const auto &p : dp[u-1]) {
        decode(p.first, s);
        int b1 = s[j-1], b2 = s[j];
        // not choose
        if (a[i][j]) {
          s[j] = 0;
          int cnt = 0;
          for (int k = 1; k <= m; ++k) cnt += s[k] == b2;
          if (!b2 || cnt) insert(p.first, s, u, p.second);
          s[j] = b2;
        }
        // choose
        if (!b1 && !b2) {
          s[j] = 7;
        } else {
          if (b1 > b2) swap(b1, b2);
          s[j] = b2;
          if (b1) for (int k = 1; k <= m; ++k) {
            if (s[k] == b1) s[k] = b2;
          }
        }
        insert(p.first, s, u, p.second+a[i][j]);
      }
    }
  }
  cout << dp[resu][ress] << endl;
  for (int u = resu, state = ress, x, y; u; --u) {
    x = (u+m-1)/m;
    y = u%m ? u%m : m;
    b[x][y] = (state>>y*3-3)%8;
    state = pre[u][state];
  }
  for (int i = 1; i <= n; ++i) {
    for (int j = 1; j <= m; ++j) {
      if (!a[i][j]) cout << "x";
      else cout << (b[i][j] ? "o" : "_");
    }
    cout << endl;
  }
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