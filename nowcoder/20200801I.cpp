/*
 * @Author: Kaizyn
 * @Date: 2020-08-01 16:23:31
 * @LastEditTime: 2020-08-01 16:42:51
 */ 
#include <bits/stdc++.h>

// #define DEBUG

using namespace std;

const double eps = 1e-7;
const double PI = acos(-1);
typedef pair<int, int> pii;
const int INF = 0x3f3f3f3f;
// const int N = 5e3+7;
const int N = 2e2+7;

int M;
long long res[N];

inline void init(const int &n) {
  static long long val[2][N][N], cnt[2][N][N];
  cnt[1][1][0] = 1;
  val[1][1][0] = 1;
  for (int i = 2; i <= n; ++i) {
    memset(cnt[i&1], 0, sizeof cnt[i&1]);
    memset(val[i&1], 0, sizeof val[i&1]);
    for (int j = 1; j < i; ++j) {
      for (int k = 0; k <= i-2; ++k) {
        (cnt[i&1][i][0] += cnt[~i&1][j][k]) %= M;
        (cnt[i&1][j][k] += cnt[~i&1][j][k]) %= M;
        (val[i&1][i][0] += val[~i&1][j][k]) %= M;
        (val[i&1][j][k] += val[~i&1][j][k]) %= M;
        (cnt[i&1][i][k+1] += cnt[~i&1][j][k]) %= M;
        (cnt[i&1][j][k+1] += cnt[~i&1][j][k]) %= M;
        (val[i&1][i][k+1] += val[~i&1][j][k]+cnt[~i&1][j][k]*(2*(k+1)*(k+1)-k*k)) %= M;
        (val[i&1][j][k+1] += val[~i&1][j][k]+cnt[~i&1][j][k]*(2*(k+1)*(k+1)-k*k)) %= M;
      }
    }
    for (int j = 0; j < i; ++j) {
      (res[i] += val[i&1][i][j]) %= M;
    }
  }
}

signed main() {
  ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
  int T, n;
  cin >> T >> M;
  init(107);
  for (int t = 1; t <= T; ++t) {
    cin >> n;
    cout << res[n] << endl;
  }
  return 0;
}