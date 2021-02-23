/*
 * @Author: Kaizyn
 * @Date: 2021-02-15 17:33:05
 * @LastEditTime: 2021-02-15 19:49:01
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
const int N = 1e5+7;
const int K = 16;
#define log(x) (31-__builtin_clz(x))

int k, n;
int a[K], c[N], sc[N], sa[1<<K], dp[1<<K];

inline void solve() {
  cin >> k >> n;
  for (int i = 0; i < k; ++i) cin >> a[i];
  for (int i = 1; i <= n; ++i) {
    cin >> c[i];
    sc[i] = sc[i-1]+c[i];
  }
  for (int i = 1, j; i < 1<<k; ++i) {
    j = i&-i;
    sa[i] = sa[i^j]+a[log(j)];
    for (j = 0; j < k; ++j) if((i>>j)&1) {
      int l = dp[i^(1<<j)];
      int r = upper_bound(sc+1, sc+n+1, a[j]+sc[l])-sc-1;
      // sc[r]-sc[l] <= a[j]
      dp[i] = max(dp[i], r);
    }
  }
  int res = -1;
  for (int i = 1; i < 1<<k; ++i) {
    if (dp[i] == n) {
      res = max(res, sa[(1<<k)-1]-sa[i]);
    }
  }
  cout << res << '\n';
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