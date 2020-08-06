/*
 * @Author: Kaizyn
 * @Date: 2020-07-16 16:47:37
 * @LastEditTime: 2020-07-16 17:55:12
 */ 
#include <bits/stdc++.h>

// #define DEBUG

using namespace std;

const double eps = 1e-7;
const double PI = acos(-1);
typedef pair<int, int> pii;
const int MOD = 998244353;
const int INF = 0x3f3f3f3f;
const int N = 1e2+7;
const int M = 6+2;

int n, m, u, res = -INF;
int a[N][M];
unordered_map<int, int> dp[2];

inline void insert(const int &state, const int &val) {
  if (dp[u].count(state)) dp[u][state] = max(dp[u][state], val);
  else dp[u].insert({state, val});
}

inline void solve() {
  cin >> n >> m;
  for (int i = 1; i <= n; ++i) {
    for (int j = 1; j <= m; ++j) {
      cin >> a[i][j];
    }
  }
  int base = (1<<2*m+2)-1;
  dp[u = 0].clear();
  dp[u][0] = 0;
  for (int i = 1; i <= n; ++i) {
    // add a null b1
    dp[u ^= 1].clear();
    for (const auto &p : dp[u^1]) dp[u].insert({(p.first<<2)&base, p.second});
    for (int j = 1; j <= m; ++j) {
      dp[u ^= 1].clear();
      for (const auto &p : dp[u^1]) {
        int state = p.first, val = p.second+a[i][j];
        // b1 right b2 down
        int b1 = (state>>j*2-2)%4, b2 = (state>>j*2)%4;
        if (!b1 && !b2) {
          insert(state, p.second); // not choose
          if (j < m) insert(state+(1<<j*2-2)+(1<<j*2+1), val);
        } else if (!b1 && b2) {
          if (j < m) insert(state, val);
          insert(state+(b2<<j*2-2)-(b2<<j*2), val);
        } else if (b1 && !b2) {
          insert(state, val);
          if (j < m) insert(state-(b1<<j*2-2)+(b1<<j*2), val);
        } else if (b1 == 1 && b2 == 1) { // find 2 turn to 1
          for (int k = j+1, t = 1; k <= m; ++k) {
            if ((state>>k*2)%4 == 1) ++t;
            if ((state>>k*2)%4 == 2) --t;
            if (!t) { insert(state-(1<<j*2-2)-(1<<j*2)-(1<<k*2), val); break; }
          }
        } else if (b1 == 2 && b2 == 2) { // find 1 turn to 2
          for (int k = j-2, t = 1; k >= 0; --k) {
            if ((state>>k*2)%4 == 1) --t;
            if ((state>>k*2)%4 == 2) ++t;
            if (!t) { insert(state-(1<<j*2-1)-(1<<j*2+1)+(1<<k*2), val); break; }
          }
        } else if (b1 == 2 && b2 == 1) {
          insert(state-(1<<j*2-1)-(1<<j*2), val);
        } else if (b1 == 1 && b2 == 2) {
          if (state == (b1<<j*2-2)+(b2<<j*2)) res = max(res, val);
        }
      }
    }
  }
  cout << res << endl;
}

signed main() {
  ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
  solve();
  return 0;
}