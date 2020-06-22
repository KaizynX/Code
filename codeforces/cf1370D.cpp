/*
 * @Author: Kaizyn
 * @Date: 2020-06-20 22:24:06
 * @LastEditTime: 2020-06-20 23:36:00
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

int n, k;
int a[N], dp[N];

int check(const int &l, const int &r, const int &mid) {
  dp[l] = a[l] <= mid;
  if (l-1 >= 0) dp[l-1] = 0;
  for (int i = l+1; i <= r; ++i) {
    if (a[i] > mid) dp[i] = dp[i-1];
    else dp[i] = dp[i-2]+1;
  }
  return dp[r];
}

inline void solve() {
  cin >> n >> k;
  for (int i = 1; i <= n; ++i) {
    cin >> a[i];
  }
  int l = 1, r = 1e9, mid;
  while (l < r) {
    mid = (l+r)>>1;
    if (k&1) {
      if (check(2, n-1, mid) >= k/2 ||
          check(1, n, mid) >= (k+1)/2) r = mid;
      else l = mid+1;
    } else {
      if (check(1, n-1, mid) >= k/2 ||
          check(2, n, mid) >= k/2) r = mid;
      else l = mid+1;
    }
  }
  cout << l << endl;
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