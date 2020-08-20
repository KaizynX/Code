/*
 * @Author: Kaizyn
 * @Date: 2020-08-18 11:53:15
 * @LastEditTime: 2020-08-18 16:59:20
 */
#include <bits/stdc++.h>

// #define DEBUG

using namespace std;

typedef pair<int, int> pii;
typedef long long ll;
const int P = 1572869; // 3145739
const int INF = 0x3f3f3f3f;
const int N = 1e1+7;

int n;
int a[N][N];
int dp[2][P];
int head[2][P], nex[2][P], tot[2], ver[2][P];

inline void clear(const int &u) {
  for (int i = 0; i <= tot[u]; ++i) {
    dp[u][i] = 0;
    nex[u][i] = 0;
    head[u][ver[u][i]%P] = 0;
  }
  tot[u] = 0;
}

inline void insert(const int &u, const int &x, const int &v) {
  int p = x%P;
  for (int i = head[u][p]; i; i = nex[u][i]) {
    if (ver[u][i] == x) return dp[u][i] = max(dp[u][i], v), void();
  }
  ++tot[u];
  ver[u][tot[u]] = x;
  nex[u][tot[u]] = head[u][p];
  head[u][p] = tot[u];
  dp[u][tot[u]] += v;
}

inline int get_val(const int &u, const int &x) {
  int p = x%P;
  for (int i = head[u][p]; i; i = nex[u][i]) {
    if (ver[u][i] == x) return dp[u][i];
  }
  return 0;
}

inline int solve() {
  cin >> n;
  for (int i = 1; i <= n; ++i) {
    for (int j = 1; j <= n; ++j) {
      cin >> a[i][j];
    }
  }
  int u = 0, res = 0, base = (1<<n*2+2)-1;
  clear(u);
  insert(u, 0, 0);
  for (int i = 1; i <= n; ++i) {
    // for (int k = 0; k < tot[u]; ++k) ver[u][k] = (ver[u][k]<<2)&base;
    for (int j = 1; j <= n; ++j) {
      clear(u ^= 1);
      for (int k = 1; k <= tot[u^1]; ++k) {
        int state = ver[u^1][k], val = dp[u^1][k];
        if (j == 1) state = (state<<2)&base;
        // b1 right b2 down
        // 0 no 1 left 2 right 3 black
        int b1 = (state>>j*2-2)%4, b2 = (state>>j*2)%4;
        if (!b1 && !b2) insert(u, state+(3<<j*2-2)+(3<<j*2), val+a[i][j]);
        if (b1 == 3) state -= 3<<j*2-2, b1 = 0;
        if (b2 == 3) state -= 3<<j*2, b2 = 0;
        if (!b1 && !b2) {
          if (i < n && j < n) insert(u, state+(1<<j*2-2)+(2<<j*2), val);
        } else if (!b1 && b2) {
          if (j < n) insert(u, state, val);
          if (i < n) insert(u, state+(b2<<j*2-2)-(b2<<j*2), val);
        } else if (b1 && !b2) {
          if (i < n) insert(u, state, val);
          if (j < n) insert(u, state-(b1<<j*2-2)+(b1<<j*2), val);
        } else if (b1 == 1 && b2 == 1) { // find 2 turn to 1
          for (int k = j+1, t = 1; k <= n; ++k) {
            if ((state>>k*2)%4 == 1) ++t;
            if ((state>>k*2)%4 == 2) --t;
            if (!t) { insert(u, state-(1<<j*2-2)-(1<<j*2)-(1<<k*2), val); break; }
          }
        } else if (b1 == 2 && b2 == 2) { // find 1 turn to 2
          for (int k = j-2, t = 1; k >= 0; --k) {
            if ((state>>k*2)%4 == 1) --t;
            if ((state>>k*2)%4 == 2) ++t;
            if (!t) { insert(u, state-(2<<j*2-2)-(2<<j*2)+(1<<k*2), val); break; }
          }
        } else if (b1 == 2 && b2 == 1) {
          insert(u, state-(2<<j*2-2)-(1<<j*2), val);
        } else if (b1 == 1 && b2 == 2) {
          if (i < n) continue;
          if (j == n-1) {
            if ((state>>n*2)%4 != 3) res = max(res, val+a[n][n]);
          } else if (j == n) {
            res = max(res, val);
          }
        }
      }
    }
  }
  return res;
}

signed main() {
  ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
  int T = 1;
  cin >> T;
  for (int t = 1; t <= T; ++t) {
    cout << solve() << endl;
  }
  return 0;
}