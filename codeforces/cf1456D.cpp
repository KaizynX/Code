/*
 * @Author: Kaizyn
 * @Date: 2020-12-22 21:26:22
 * @LastEditTime: 2020-12-22 22:20:37
 */
#include <bits/stdc++.h>

#define DEBUG

using namespace std;

const double eps = 1e-7;
const double PI = acos(-1);
typedef pair<int, int> pii;
typedef long long ll;
const int MOD = 998244353;
const int INF = 0x3f3f3f3f;
// const ll INF = 1e18;
#ifdef DEBUG
const int N = 4;
#else
const int N = 5e3+7;
#endif

int n, m;
int t[N], x[N], d[N], mxt[N];
bitset<N> dp[N];

void discrete() {
  memcpy(d, x, sizeof(int)*(n+1));
  sort(d, d+n+1);
  m = unique(d, d+n+1)-d-1;
  for (int i = 0; i <= n; ++i) {
    x[i] = lower_bound(d, d+m+1, x[i])-d;
  }
}

void update(int i, int j, int r = 0) {
  for (int k = i+1; k <= n; ++k) {
    if (r+t[k]-t[k-1] < abs(d[j]-d[x[k]])) break;
    dp[k][x[k]] = 1;
    if (j == x[k]) {
      r += t[k]-t[k-1];
    } else {
      r = min(t[k]-t[k-1]-1, r-abs(d[j]-d[x[k]])+t[k]-t[k-1]);
    }
    j = x[k];
    mxt[k] = max(mxt[k], r);
  }
}

inline bool solve() {
  cin >> n;
  for (int i = 1; i <= n; ++i) {
    cin >> t[i] >> x[i];
    mxt[i] = -1;
  }
  discrete();
  for (int i = 0; i <= n; ++i) {
    int l = lower_bound(d, d+m+1, d[x[i]]-mxt[i])-d;
    int r = upper_bound(d, d+m+1, d[x[i]]+mxt[i])-d;
    for (int j = l; j < r; ++j) dp[i][j] = 1;
    #ifdef DEBUG
    cout << i << " " << dp[i] << endl;
    cout << l << " " << r << endl;
    #endif
    if (i == n) break;

    if (dp[i][x[i]]) {
      update(i, x[i]);
      if (abs(d[x[i]]-d[x[i+1]]) <= t[i+1]-t[i]) {
        dp[i+1] |= dp[i];
      }
    }
    if (dp[i][x[i+1]]) {
      update(i, x[i+1]);
    }
  }
  return dp[n].any();
}

signed main() {
#ifdef ONLINE_JUDGE
  ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
#endif
  int T = 1;
  // cin >> T;
  for (int t = 1; t <= T; ++t) {
    cout << (solve() ? "YES" : "NO") << endl;
  }
  return 0;
}
/*
3
1 0
5 5
6 2
*/