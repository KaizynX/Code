/*
 * @Author: Kaizyn
 * @Date: 2020-12-22 22:20:42
 * @LastEditTime: 2020-12-22 23:21:12
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
int t[N], x[N], d[N], l[N], r[N];
bitset<N> dp[N];

int lb(int v) {
  return lower_bound(d, d+m+1, v)-d;
}

int ub(int v) {
  return upper_bound(d, d+m+1, v)-d;
}

void discrete() {
  memcpy(d, x, sizeof(int)*(n+1));
  sort(d, d+n+1);
  m = unique(d, d+n+1)-d-1;
  for (int i = 0; i <= n; ++i) {
    x[i] = lb(x[i]);
  }
}

void update(int i, int j, int p = 0) {
  for (int dis, tmp; i <= n; ++i) {
    dis = abs(d[j]-d[x[i]]);
    if (p+t[i] < dis) break;
    dp[i][x[i]] = 1;
    tmp = (p+t[i]-dis)/2;
    if (x[i-1] <= x[i]) {
      l[i] = min(l[i], lb(d[x[i]]-t[i]+1));
      r[i] = max(r[i], ub(d[x[i]]+min(t[i]-1, tmp)));
    } else {
      r[i] = max(r[i], ub(d[x[i]]+t[i]-1));
      l[i] = min(l[i], lb(d[x[i]]-min(t[i]-1, tmp)));
    }
    if (j == x[i]) {
      p += t[i];
    } else {
      p = min(t[i]-1, p-dis+t[i]);
    }
    j = x[i];
  }
}

inline bool solve() {
  cin >> n;
  for (int i = 1; i <= n; ++i) {
    cin >> t[i] >> x[i];
    l[i] = n+1;
    r[i] = -1;
  }
  for (int i = n; i; --i) {
    t[i] -= t[i-1];
  }
  discrete();
  dp[0][x[0]] = 1;
  for (int i = 0; i < n; ++i) {
    if (dp[i][x[i]]) {
      update(i+1, x[i]);
      if (abs(d[x[i]]-d[x[i+1]]) <= t[i+1]) {
        dp[i+1] |= dp[i];
      }
    }
    if (dp[i][x[i+1]]) {
      update(i+1, x[i+1]);
    }
    for (int j = l[i+1]; j < r[i+1]; ++j) {
      dp[i+1][j] = 1;
    }
  }
#ifdef DEBUG
  for (int i = 0; i <= n; ++i) {
    printf("%d (%d,%d) ", i, l[i], r[i]);
    cout << dp[i] << endl;
  }
#endif
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
5
2 1
6 0
7 -1
8 2
9 -2
*/