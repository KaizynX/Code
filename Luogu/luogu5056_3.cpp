/*
 * @Author: Kaizyn
 * @Date: 2020-08-19 23:42:13
 * @LastEditTime: 2020-08-20 10:40:30
 */
#include <bits/stdc++.h>

// #define DEBUG

using namespace std;

// const int P = 1572869;
const int P = 299987;
const int M = 1<<21;
const int N = 15;

int n, m;
int a[N][N];
long long dp[2][M];
int head[2][P], nex[2][M], tot[2], ver[2][M];
// long long dp[2][P];
// int head[2][P], nex[2][P], tot[2], ver[2][P];

inline void clear(const int &u) {
  for (int i = 1; i <= tot[u]; ++i) {
    dp[u][i] = 0; //
    nex[u][i] = 0; //
    head[u][ver[u][i]%P] = 0;
  }
  tot[u] = 0;
}

template <typename T, typename U>
inline void insert(const int &u, const T &x, const U &v) {
  int p = x%P;
  for (int i = head[u][p]; i; i = nex[u][i]) {
    if (ver[u][i] == x) return dp[u][i] += v, void();
  }
  ++tot[u]; assert(tot[u] < M);
  ver[u][tot[u]] = x;
  nex[u][tot[u]] = head[u][p];
  head[u][p] = tot[u];
  dp[u][tot[u]] = v;
}

template <typename T>
inline int get_val(const int &u, const T &x) {
  int p = x%P;
  for (int i = head[u][p]; i; i = nex[u][i]) {
    if (ver[u][i] == x) return dp[u][i];
  }
  return 0;
}

inline long long solve() {
  int ex, ey;
  cin >> n >> m;
  for (int i = 1; i <= n; ++i) {
    static string str;
    cin >> str;
    for (int j = 1; j <= m; ++j) {
      a[i][j] = str[j-1] == '.';
      if (a[i][j]) ex = i, ey = j;
    }
  }
  int u = 0, base = (1<<m*2+2)-1;
  long long res = 0;
  clear(u);
  insert(u, 0, 1);
  for (int i = 1; i <= n; ++i) {
    for (int j = 1; j <= m; ++j) {
      clear(u ^= 1);
      for (int k = 1; k <= tot[u^1]; ++k) {
        int state = ver[u^1][k];
        long long val = dp[u^1][k];
        if (j == 1) state = (state<<2)&base;
        // b1 right b2 down
        // 0 no 1 left 2 right
        int b1 = (state>>j*2-2)%4, b2 = (state>>j*2)%4;
        if (!a[i][j]) {
          if (!b1 && !b2) insert(u, state, val);
        } else if (!b1 && !b2) {
          if (a[i+1][j] && a[i][j+1]) insert(u, state+(1<<j*2-2)+(2<<j*2), val);
        } else if (!b1 && b2) {
          if (a[i][j+1]) insert(u, state, val);
          if (a[i+1][j]) insert(u, state+(b2<<j*2-2)-(b2<<j*2), val);
        } else if (b1 && !b2) {
          if (a[i+1][j]) insert(u, state, val);
          if (a[i][j+1]) insert(u, state-(b1<<j*2-2)+(b1<<j*2), val);
        } else if (b1 == 1 && b2 == 1) { // find 2 turn to 1
          for (int k = j+1, t = 1; k <= m; ++k) {
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
        } else if (i == ex && j == ey) { // b1 == 1, b2 == 2
          res += val;
        }
      }
    }
  }
  return res;
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