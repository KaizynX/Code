/*
 * @Author: Kaizyn
 * @Date: 2020-12-30 23:13:47
 * @LastEditTime: 2020-12-30 23:17:09
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

int n;
int vis[N];
char c[N];

inline int solve() {
  scanf("%s", c+1);
  n = strlen(c+1);
  int res = 0;
  memset(vis+1, 0, sizeof vis);
  for (int i = 1; i <= n; ++i) {
    res += vis[i];
    if (vis[i]) continue;
    if (i+1 <= n && c[i] == c[i+1]) vis[i+1] = 1;
    if (i+2 <= n && c[i] == c[i+2]) vis[i+2] = 1;
  }
  return res;
}

signed main() {
#ifdef ONLINE_JUDGE
  // ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
#endif
  int T = 1;
  // cin >> T;
  scanf("%d", &T);
  for (int t = 1; t <= T; ++t) {
    printf("%d\n", solve());
  }
  return 0;
}