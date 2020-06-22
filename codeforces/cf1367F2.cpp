/*
 * @Author: Kaizyn
 * @Date: 2020-06-16 22:33:48
 * @LastEditTime: 2020-06-17 20:23:20
 */ 
#include <bits/stdc++.h>

#define DEBUG

using namespace std;

const double eps = 1e-7;
const double PI = acos(-1);
typedef pair<int, int> pii;
const int MOD = 998244353;
const int INF = 0x3f3f3f3f;
const int N = 2e5+7;

int n;
int a[N];
int last[N], dp[N];

void discrete() {
  static int m;
  static int d[N];
  memcpy(d+1, a+1, sizeof(int)*n);
  sort(d+1, d+n+1);
  m = unique(d+1, d+n+1)-d;
  memset(last, 0, sizeof(int)*m);
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
#ifdef DEBUG
  for (int i = 1; i <= n; ++i) {
    cout << a[i] << " \n"[i==n];
  }
#endif
  int res = 0;
  for (int i = 1; i <= n; ++i) {
    dp[i] = max(last[a[i]], last[a[i]-1])+1;
    // dp[i] = last[a[i]]+1;
    last[a[i]] = max(last[a[i]], dp[i]);
    res = max(res, dp[i]);
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