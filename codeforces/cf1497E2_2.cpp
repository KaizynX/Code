/*
 * @Author: Kaizyn
 * @Date: 2021-03-18 18:03:48
 * @LastEditTime: 2021-03-18 18:27:16
 */
#include <bits/stdc++.h>

#define DEBUG

using namespace std;

const double eps = 1e-7;
const double PI = acos(-1);
typedef pair<int, int> pii;
typedef long long ll;
const int MOD = 998244353; // 1e9+7;
const int INF = 0x3f3f3f3f;
// const ll INF = 1e18;
const int N = 2e5+7;
const int K = 21;

int n, k;
int a[N], lef[N][K], dp[N][K];
map<int, int> last;

int magic(int x) {
  int y = 1;
  for (int i = 2, k; i*i <= x; ++i) {
    if (x%i) continue;
    for (k = 0; x%i == 0; x /= i, ++k) {}
    if (k&1) y *= i;
  }
  return x*y;
}

template <typename T>
void update(T &x, const T &y) {
  if (x == -1 || y < x) x = y;
}

inline void solve() {
  last.clear();
  cin >> n >> k;
  for (int i = 1; i <= n; ++i) {
    cin >> a[i];
    a[i] = magic(a[i]);
  }
  for (int i = 1; i <= n; ++i) {
    int j = max(last[a[i]], lef[i-1][0]);
    lef[i][0] = j;
    j = max(j-1, 0);
    for (int l = 1; l <= k; ++l) {
      lef[i][l] = lef[j][l-1];
    }
    last[a[i]] = i;
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
  dp[0][0] = 0;
  for (int i = 1; i <= n; ++i) {
    memset(dp[i], -1, sizeof dp[i]);
    for (int j = 0; j <= k; ++j) {
      for (int l = 0; l <= j; ++l) if (~dp[lef[i][l]][j-l]) {
        update(dp[i][j], dp[lef[i][l]][j-l]+1);
      }
    }
  }
  int res = -1;
  for (int i = 0; i <= k; ++i) if (~dp[n][i]) {
    update(res, dp[n][i]);
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