/*
 * @Author: Kaizyn
 * @Date: 2020-06-19 10:55:14
 * @LastEditTime: 2020-06-19 11:17:27
 */ 
#include <bits/stdc++.h>

// #define DEBUG

using namespace std;

const double eps = 1e-7;
const double PI = acos(-1);
typedef pair<int, int> pii;
const int MOD = 998244353;
const int INF = 0x3f3f3f3f;
const int N = 2e5+7;

int n;
int a[N], b[N];
int fir[N], pre[N], dp[N], suf[N];

void discrete() {
  static int m;
  static int d[N];
  memcpy(d+1, a+1, sizeof(int)*n);
  sort(d+1, d+n+1);
  m = unique(d+1, d+n+1)-d;
  for (int i = 1; i <= n; ++i) {
    a[i] = lower_bound(d+1, d+m, a[i])-d;
  }
}

inline void solve() {
  cin >> n;
  for (int i = 1; i <= n; ++i) {
    cin >> a[i];
  }
  discrete();
  memcpy(b+1, a+1, sizeof(int)*n);
  sort(b+1, b+n+1);
  memset(fir+1, 0, sizeof(int)*n);
  for (int i = 1; i <= n; ++i) {
    if (!fir[b[i]]) {
      fir[b[i]] = i;
    }
  }
  memset(pre+1, 0, sizeof(int)*n);
  memset(suf+1, 0, sizeof(int)*n);
  memset(dp+1, 0, sizeof(int)*n);
  int res = 0;
  for (int i = 1, p; i <= n; ++i) {
    p = fir[a[i]]+pre[a[i]];
    dp[p] = dp[p-1]+1;
    if (pre[a[i]] == 0) dp[p] = max(dp[p], pre[a[i]-1]+1);
    suf[a[i]] = max({suf[a[i]]+1, dp[fir[a[i]]-1]+1, pre[a[i]-1]+1});
    ++pre[a[i]];
    res = max({res, dp[p], suf[a[i]]});
  }
  cout << n-res << endl;
}

signed main() {
  ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
  int T = 1;
  cin >> T;
  for (int t = 1; t <= T; ++t) {
    solve();
  }
  return 0;
}