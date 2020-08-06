/*
 * @Author: Kaizyn
 * @Date: 2020-07-17 20:28:37
 * @LastEditTime: 2020-07-17 20:48:15
 */ 
#include <bits/stdc++.h>

// #define DEBUG

using namespace std;

const double eps = 1e-7;
const double PI = acos(-1);
typedef pair<int, int> pii;
const int MOD = 998244353;
const int INF = 0x3f3f3f3f;
const int N = 3840+7;
const int M = 2160+7;

int n, m, nn, mm;
int a[N][M], res[N][M];
int sum[N][M];

inline int query(const int &r1, const int &c1, const int &r2, const int &c2) {
  return sum[r2][c2]-sum[r1-1][c2]-sum[r2][c1-1]+sum[r1-1][c1-1];
}

inline void solve() {
  cin >> n >> m >> nn >> mm;
  for (int i = 1; i <= n; ++i) {
    for (int j = 1; j <= m; ++j) {
      cin >> a[i][j];
      sum[i][j] = sum[i-1][j]+sum[i][j-1]-sum[i-1][j-1]+a[i][j];
    }
  }
  int mx = 0;
  for (int i = 1; i <= nn; ++i) {
    for (int j = 1; j <= mm; ++j) {
      int r1, c1, r2, c2;
      r1 = max(1, n+i-nn); // i+n-r1 <= nn
      r2 = min(n, i);
      c1 = max(1, m+j-mm); // j+m-c1 <= mm
      c2 = min(m, j);
      res[i][j] = query(r1, c1, r2, c2);
      #ifdef DEBUG
      printf("(%d, %d) [%d %d %d %d] %d\n", i, j, r1, c1, r2, c2, res[i][j]);
      #endif
      mx = max(mx, res[i][j]);
    }
  }
  #ifdef DEBUG
  for (int i = 1; i <= nn; ++i) {
    for (int j = 1; j <= mm; ++j) {
      cout << res[i][j] << " \n"[j==mm];
    }
  }
  #endif
  for (int i = 1; i <= nn; ++i) {
    for (int j = 1; j <= mm; ++j) {
      cout << 100*res[i][j]/mx << " \n"[j==mm];
    }
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