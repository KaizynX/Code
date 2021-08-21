/*
 * @Author: Kaizyn
 * @Date: 2021-08-21 14:22:52
 * @LastEditTime: 2021-08-21 14:38:48
 */
#include <bits/stdc++.h>

// #define DEBUG

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
const double eps = 1e-7;
const double PI = acos(-1);
const int MOD = 998244353; // 1e9+7;
const int INF = 0x3f3f3f3f;
// const ll INF = 1e18;
const int N = 1e2+7;
const int M = 1e4+7;

int n, m;
int a[N], t[N];
int dp[M];

void update(int &x, int y) {
  if (y > x) x = y;
}

inline void solve() {
  cin >> n >> m;
  memset(dp, 0, sizeof(int)*(m+1));
  int ans = 0;
  for (int i = 1; i <= n; ++i) {
    cin >> a[i];
    ans += a[i];
  }
  for (int i = 1, j, k, vj, vk; i <= n; ++i) {
    cin >> t[i];
    for (j = 2, k = 1, vk = a[i]; j <= t[i]; ++j) {
      vj = (a[i]+j-1)/j;
      if (vj < vk) {
        for (int l = m, v = j-k, w = vk-vj; l >= v; --l) {
          update(dp[l], dp[l-v]+w);
        }
        k = j;
        vk = vj;
      }
    }
  }
  cout << ans-dp[m] << '\n';
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