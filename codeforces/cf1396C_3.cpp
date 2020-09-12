/*
 * @Author: Kaizyn
 * @Date: 2020-08-30 23:22:52
 * @LastEditTime: 2020-08-31 00:33:14
 */
#include <bits/stdc++.h>

// #define DEBUG

using namespace std;

const double eps = 1e-7;
const double PI = acos(-1);
typedef pair<int, int> pii;
const int MOD = 998244353;
const int INF = 0x3f3f3f3f;
const int N = 1e6+7;

int n;
long long r1, r2, r3, d;
int a[N], q[N], head, tail;
long long b[N][2], dp[N][2], sumb[N];

inline long long calc(int x) {
  return dp[x][0]-sumb[x]-d*x;
}

inline void solve() {
  cin >> n >> r1 >> r2 >> r3 >> d;
  for (int i = 1; i <= n; ++i) cin >> a[i];

  for (int i = 1; i <= n; ++i) {
    b[i][0] = a[i]*r1+r3+d;
    b[i][1] = min(a[i]*r1+2*r1, r2+r1)+2*d;
    sumb[i] = sumb[i-1]+b[i][1];
  }
  memset(dp, 0x3f, sizeof dp);
  dp[0][0] = 0;
  dp[1][0] = b[1][1]-d;
  dp[1][1] = b[1][2]-d;
  for (int i = 2; i <= n; ++i) {
    dp[i][0] = min(dp[i-1][0], dp[i-1][1])+b[i][0];
    while (head < tail && calc(q[tail]) < i-2) --tail;
    q[++tail] = i-2;
    dp[i][1] = calc(q[tail])+sumb[i]+d*(i-2);
    /*
    for (int j = 0; j <= i-2; ++j) {
      dp[i][1] = min(dp[i][1], dp[j][0]+sumb[i]-sumb[j]+d*(i-j-2));
    }
    */
  }
  for (int i = 0; i <= n-2; ++i) {
    dp[n][1] = min(dp[n][1], dp[i][0]+sumb[n]-sumb[i]);
  }
  cout << min(dp[n][0], dp[n][1]) << endl;
}

signed main() {
  ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
  int T = 1;
  // cin >> T;
  for (int t = 1; t <= T; ++t) {
    solve();
  }
  return 0;
}