/*
 * @Author: Kaizyn
 * @Date: 2020-12-28 19:24:33
 * @LastEditTime: 2020-12-28 20:22:52
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
// const ll INF = 1e18;
const int N = 80+7;
const int M = 3200+7;

int n, m;
int a[N], p[N], res[M];
int dp[N][N][M];
// dp[第几位][有几个1][操作次数]=最值(在当前位填1)
// dp[i][j][k]=dp[ii][j-1][k-abs(p[j]-i)]+(i-ii)^2

template <typename T>
inline void update(T &x, const T &y) {
  if (x < y) x = y;
}

inline int f(int x) {
  return x*(x-1)/2;
}

inline void solve() {
  cin >> n;
  for (int i = 1; i <= n; ++i) {
    cin >> a[i];
    if (a[i]) p[++m] = i;
  }
  // int t = n*(n-1)/2;
  int t = (n+1)/2*(n/2); // (n-m)*m <= n^2/4
  dp[0][0][0] = f(n-m);
  for (int i = 1; i <= n; ++i) {
    for (int j = max(1, m+i-n); j <= min(m, i); ++j) {
      for (int d = abs(i-p[j]), k = d; k <= t; ++k) {
        for (int li = 0; li < i; ++li) {
          update(dp[i][j][k], dp[li][j-1][k-d]-f(i-li-1));
        }
      }
    }
  }
  #ifdef DEBUG
  for (int i = 1; i <= n; ++i) {
    for (int j = 1; j <= m; ++j) {
      printf("dp[%d][%d]=", i, j);
      for (int k = 0; k <= t; ++k) {
        cout << dp[i][j][k] << " \n"[k==t];
      }
    }
    cout << "**************\n";
  }
  #endif
  for (int i = m; i <= n; ++i) {
    for (int k = 0; k <= t; ++k) {
      update(res[k], dp[i][m][k]-f(n-i));
    }
  }
  for (int i = 0; i <= n*(n-1)/2; ++i) {
    if (i) res[i] = max(res[i], res[i-1]);
    cout << res[i] << " ";
  }
}

signed main() {
#ifdef ONLINE_JUDGE
  ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
#endif
  int T = 1;
  // cin >> T;
  for (int t = 1; t <= T; ++t) {
    solve();
  }
  return 0;
}