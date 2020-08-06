/*
 * @Author: Kaizyn
 * @Date: 2020-07-17 13:06:13
 * @LastEditTime: 2020-07-22 14:20:58
 */ 
#include <bits/stdc++.h>

// #define DEBUG

using namespace std;

const double eps = 1e-7;
const double PI = acos(-1);
typedef pair<int, int> pii;
const int MOD = 20110520;
const int P = 1572869;
const int INF = 0x3f3f3f3f;
const int N = 1e2+7;

int n, m;
int a[N][N];
int dp[2][P];
int head[2][P], nex[2][P], tot[2], ver[2][P];

inline void my_rotate() {
  static int b[N][N];
  for (int i = 1; i <= n; ++i) {
    for (int j = 1; j <= m; ++j) {
      b[i][j] = a[i][j];
    }
  }
  swap(n, m);
  for (int i = 1; i <= n; ++i) {
    for (int j = 1; j <= m; ++j) {
      a[i][j] = b[m-j+1][i];
    }
  }
}

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
    if (ver[u][i] == x) {
      (dp[u][i] += v) %= MOD;
      return;
    }
  }
  ++tot[u];
  ver[u][tot[u]] = x;
  nex[u][tot[u]] = head[u][p];
  head[u][p] = tot[u];
  (dp[u][tot[u]] += v) %= MOD;
}

inline int get_val(const int &u, const int &x) {
  int p = x%P;
  for (int i = head[u][p]; i; i = nex[u][i]) {
    if (ver[u][i] == x) return dp[u][i];
  }
  return 0;
}

inline int solve() {
  int ex, ey;
  cin >> n >> m;
  for (int i = 1; i <= n; ++i) {
    static string str;
    cin >> str;
    for (int j = 1; j <= m; ++j) {
      a[i][j] = str[j-1] == '_';
    }
  }
  if (n < m) my_rotate();
  for (int i = 1; i <= n; ++i) {
    for (int j = 1; j <= m; ++j) {
      if (a[i][j]) ex = i, ey = j;
    }
  }
  int base = (1<<m*2+2)-1;
  // 0 none 1 unturned edge 2 turned edge
  int u = 0;
  clear(u);
  insert(u, 0, 1);
  for (int i = 1; i <= n; ++i) {
    // for (int j = 0; j < tot[u]; ++j) ver[u][i] = (ver[u][i]<<2)&base;
    for (int j = 1; j <= m; ++j) {
      clear(u ^= 1);
      for (int k = 1; k <= tot[u^1]; ++k) {
        int state = ver[u^1][k], val = dp[u^1][k];
        if (j == 1) state = (state<<2)&base;
        int b1 = (state>>j*2-2)%4, b2 = (state>>j*2)%4;
        if (!a[i][j]) {
          if (!b1 && !b2) insert(u, state, val);
        } else if (!b1 && !b2) {
          if (i < n) insert(u, state+(1<<j*2-2), val);
          if (j < m) insert(u, state+(1<<j*2), val);
          if (i < n && j < m) insert(u, state+(2<<j*2-2)+(2<<j*2), val);
        } else if (!b1 && b2 == 1) {
          if (i < n) insert(u, state+(1<<j*2-2)-(1<<j*2), val);
          if (j < m) insert(u, state+(2<<j*2)-(1<<j*2), val);
        } else if (!b1 && b2 == 2) {
          insert(u, state-(2<<j*2), val);
          if (i < n) insert(u, state+(2<<j*2-2)-(2<<j*2), val);
        } else if (b1 == 1 && !b2) {
          if (j < m) insert(u, state-(1<<j*2-2)+(1<<j*2), val);
          if (i < n) insert(u, state-(1<<j*2-2)+(2<<j*2-2), val);
        } else if (b1 == 2 && !b2) {
          insert(u, state-(2<<j*2-2), val);
          if (j < m) insert(u, state-(2<<j*2-2)+(2<<j*2), val);
        } else if (b1 == 1 && b2 == 1) {
          insert(u, state-(1<<j*2-2)-(1<<j*2), val);
        }
      }
      if (i == ex && j == ey) return get_val(u, 0);
    }
  }
  return 0;
}

signed main() {
  ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
  int T = 1;
  // cin >> T;
  for (int t = 1; t <= T; ++t) {
    cout << solve() << endl;
  }
  return 0;
}