/*
 * @Author: Kaizyn
 * @Date: 2020-06-16 22:33:48
 * @LastEditTime: 2020-06-16 22:47:37
 */ 
#include <bits/stdc++.h>

// #define DEBUG

using namespace std;

const double eps = 1e-7;
const double PI = acos(-1);
typedef pair<int, int> pii;
const int MOD = 998244353;
const int INF = 0x3f3f3f3f;
const int N = 3e3+7;

int n;
int a[N];
int dp[N];

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
  int res = 0;
  for (int i = 1; i <= n; ++i) {
    dp[i] = 1;
    for (int j = 1; j < i; ++j) {
      if (a[j] == a[i]-1) dp[i] = max(dp[i], dp[j]+1);
    }
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