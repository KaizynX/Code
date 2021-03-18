/*
 * @Author: Kaizyn
 * @Date: 2021-03-18 20:05:54
 * @LastEditTime: 2021-03-18 20:10:46
 */
#include <bits/stdc++.h>

// #define DEBUG

using namespace std;

const double eps = 1e-7;
const double PI = acos(-1);
typedef pair<int, int> pii;
typedef long long ll;
const int MOD = 998244353; // 1e9+7;
const int INF = 0x3f3f3f3f;
// const ll INF = 1e18;
const int N = 2e5+7;
const int A = 1e7+7;
const int K = 21;

int n, k;
int a[N], lef[N][K], dp[N][K];
int cnt[A];

int magic(int x) {
  int y = 1;
  for (int i = 2, k; i*i <= x; ++i) {
    if (x%i) continue;
    for (k = 0; x%i == 0; x /= i, ++k) {}
    if (k&1) y *= i;
  }
  return x*y;
}

inline void solve() {
  cin >> n >> k;
  for (int i = 1; i <= n; ++i) {
    cin >> a[i];
    a[i] = magic(a[i]);
  }
  for (int j = 0; j <= k; ++j) {
    for (int i = 1, sum = 0; i <= n; ++i) {
      lef[i][j] = lef[i-1][j];
      if (++cnt[a[i]] > 1) ++sum;
      while (sum > j) {
        if (--cnt[a[++lef[i][j]]] > 0) --sum;
      }
    }
    for (int i = lef[n][j]+1; i <= n; ++i) --cnt[a[i]];
  }
#ifdef DEBUG
  cout << "a:";
  for (int i = 1; i <= n; ++i) cout << a[i] << " \n"[i==n];
  for (int i = 1; i <= n; ++i) {
    cout << i << ":";
    for (int j = 0; j <= k; ++j) {
      cout << lef[i][j] << " \n"[j==k];
    }
  }
#endif
  memset(dp[0], 0x3f, sizeof dp[0]);
  dp[0][0] = 0;
  for (int i = 1; i <= n; ++i) {
    memset(dp[i], 0x3f, sizeof(int)*(k+1));
    for (int j = 0; j <= k; ++j) {
      for (int l = 0; l <= j; ++l) {
        dp[i][j] = min(dp[i][j], dp[lef[i][l]][j-l]+1);
      }
    }
  }
  int res = INF;
  for (int i = 0; i <= k; ++i) {
    res = min(res, dp[n][i]);
  }
  cout << res << '\n';
}

signed main() {
#ifdef ONLINE_JUDGE
  ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
#endif
  int T = 1;
  cin >> T; // scanf("%d", &T);
  for (int t = 1; t <= T; ++t) {
    solve();
  }
  return 0;
}