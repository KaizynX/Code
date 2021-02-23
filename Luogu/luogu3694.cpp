/*
 * @Author: Kaizyn
 * @Date: 2021-02-15 16:20:57
 * @LastEditTime: 2021-02-15 16:29:56
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
const int M = 20;
#define log(x) (31-__builtin_clz(x))

int n, m;
int a[N], dp[1<<M], sum[N][M], cnt[M], len[1<<M];

inline void solve() {
  cin >> n >> m;
  for (int i = 1; i <= n; ++i) {
    cin >> a[i];
    --a[i];
    ++cnt[a[i]];
    memcpy(sum[i], sum[i-1], sizeof(sum[0]));
    ++sum[i][a[i]];
  }
  for (int i = 1, j; i < 1<<m; ++i) {
    j = i&-i;
    len[i] = len[i^j]+cnt[log(j)];
    dp[i] = n;
    for (j = 0; j < m; ++j) if ((i>>j)&1) {
      dp[i] = min(dp[i],
          dp[i^(1<<j)]+cnt[j]-(sum[len[i]][j]-sum[len[i]-cnt[j]][j]));
    }
  }
  cout << dp[(1<<m)-1] << '\n';
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