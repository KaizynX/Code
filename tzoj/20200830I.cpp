/*
 * @Author: Kaizyn
 * @Date: 2020-08-30 13:46:30
 * @LastEditTime: 2020-08-30 15:05:53
 */
#include <bits/stdc++.h>

// #define DEBUG

using namespace std;

const double eps = 1e-7;
const double PI = acos(-1);
typedef pair<int, int> pii;
const int MOD = 998244353;
const int INF = 0x3f3f3f3f;
const int M = 5e4+7;
const int N = 1e2+7;

int n, m;
int q[M], head, tail;
int dp[N][M], use[N][M];
int cnt[N], a[N], b[N];

inline void solve() {
  for (int i = 0; i <= n; ++i) {
    for (int j = 0; j <= m; ++j) {
      dp[i][j] = INF;
      use[i][j] = 0;
    }
  }
  dp[0][0] = 0;
  for (int i = 1; i <= n; ++i) {
    cin >> a[i] >> b[i];
    for (int d = 0; d < a[i]; ++d) {
      int k = (m-d)/a[i];
      head = tail = 0;
      for (int j = 0; j <= k; ++j) {
#define calc(x) (dp[i-1][x*a[i]+d]-x)
        while (head < tail && q[head+1] < j-b[i]) ++head;
        while (head < tail && calc(q[tail]) >= calc(j)) --tail;
        q[++tail] = j;
        dp[i][j*a[i]+d] = calc(q[head+1])+j;
        use[i][j*a[i]+d] = j-q[head+1];
#undef calc
      }
    }
  }
  cout << dp[n][m] << endl;
  for (int i = n; i; --i) {
    cnt[i] = use[i][m];
    m -= cnt[i]*a[i];
  }
  for (int i = 1; i <= n; ++i) cout << cnt[i] << " \n"[i==n];
}

signed main() {
  ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
  while (cin >> n >> m) solve();
  return 0;
}