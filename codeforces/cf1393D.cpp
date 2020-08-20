/*
 * @Author: Kaizyn
 * @Date: 2020-08-07 22:40:36
 * @LastEditTime: 2020-08-08 00:18:37
 */
#include <bits/stdc++.h>

// #define DEBUG

using namespace std;

const double eps = 1e-7;
const double PI = acos(-1);
typedef pair<int, int> pii;
const int MOD = 998244353;
const int INF = 0x3f3f3f3f;
const int N = 2e3+7;

int n, m;
char a[N][N];
char buf1[N<<1][N<<1];
char *b[N<<1];
int buf2[2][N<<1], buf3[2][N<<1], buf4[2][N<<1];
int *uv[2] = {buf2[0]+N, buf2[1]+N};
int *dp[2] = {buf3[0]+N, buf3[1]+N};
int *lv[2] = {buf4[0]+N, buf4[1]+N};


inline void solve() {
  scanf("%d %d", &n, &m);
  for (int i = 0; i < n; ++i) {
    scanf("%s", a[i]);
    for (int j = 0; j < m; ++j) {
      b[i+j][i-j] = a[i][j];
    }
  }
#ifdef DEBUG
  for (int i = 0; i <= n+m-2; ++i) {
    for (int j = -m+1; j < n; ++j) {
      putchar(b[i][j]);
    }
    putchar('\n');
  }
#endif
  long long res = 0;
  for (char ch = 'a'; ch <= 'z'; ++ch) {
    memset(buf2, 0, sizeof buf2);
    memset(buf3, 0, sizeof buf3);
    memset(buf4, 0, sizeof buf3);
    for (int i = 0, bj = 0, ej = 0; i <= n+m-2; ++i) {
#ifdef DEBUG
      if (ch == 'a') printf("%d [%d, %d]\n", i, bj, ej);
#endif
      lv[i&1][bj-2] = 0;
      for (int j = bj; j <= ej; j += 2) {
        lv[i&1][j] = b[i][j] == ch ? lv[i&1][j-2]+1 : 0;
      }
      for (int j = ej; j >= bj; j -= 2) {
        if (b[i][j] == ch) {
          ++uv[i&1][j];
          dp[i&1][j] = min({
              lv[i&1][j],
              uv[i&1][j],
              lv[~i&1][j-1]+1,
              uv[~i&1][j-1]+1,
              dp[i&1][j-2]+1});
          res += dp[i&1][j];
        } else {
          uv[i&1][j] = 0;
          dp[i&1][j] = 0;
        }
      }
      bj += i < m-1 ? -1 : 1;
      ej += i < n-1 ? 1 : -1;
    }
  }
  printf("%lld\n", res);
}

signed main() {
  memset(buf1, ' ', sizeof buf1);
  for (int i = 0; i < N<<1; ++i) b[i] = buf1[i]+N;
  int T = 1;
  // cin >> T;
  for (int t = 1; t <= T; ++t) {
    solve();
  }
  return 0;
}