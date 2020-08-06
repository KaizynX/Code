/*
 * @Author: Kaizyn
 * @Date: 2020-08-03 13:25:06
 * @LastEditTime: 2020-08-03 16:04:03
 */ 
#include <bits/stdc++.h>

// #define DEBUG

using namespace std;

const double eps = 1e-7;
const double PI = acos(-1);
typedef pair<int, int> pii;
typedef long long ll;
const int MOD = 998244353;
const int INF = 0x3f3f3f3f;
const int N = 1e3+7;

int n;
ll dp[N][N], f[N], sum[N];

inline void init(const int &n) {
  dp[3][6] = 1;
  f[6] = 1;
  for (int i = 4; i <= n; ++i) {
    for (int j = 6; j <= n; ++j) {
      dp[i][j] = dp[i-1][j-1]+dp[i-1][j-2]+dp[i-1][j-3];
      for (int k = 0; j+i*k <= n; ++k) {
        f[j+i*k] += dp[i][j];
      }
    }
  }
  for(int i = 1; i <= n; ++i) {
    sum[i] = sum[i-1]+f[i];
    printf("f[%d]=%lld\n", i, f[i]);
  }
}

signed main() {
  ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
  init(100);
  int T = 1, l, r;
  cin >> T;
  while (T--) {
    cin >> l >> r;
    cout << sum[r]-sum[l-1] << endl;
  }
  return 0;
}