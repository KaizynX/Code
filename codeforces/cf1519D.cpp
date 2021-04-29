/*
 * @Author: Kaizyn
 * @Date: 2021-04-29 22:37:01
 * @LastEditTime: 2021-04-29 22:44:11
 */
#include <bits/stdc++.h>

// #define DEBUG

using namespace std;

const double eps = 1e-7;
const double PI = acos(-1);
typedef pair<int, int> pii;
typedef long long ll;
const int MOD = 998244353; // 1e9+7;
const int INF = 0x3f3f3f3f;
// const ll INF = 1e18;
const int N = 5e3+7;

int n;
ll a[N], b[N], presum[N];

ll calc(int l, int r) {
  return presum[n]-presum[r]+presum[l-1];
}

inline void solve() {
  cin >> n;
  for (int i = 1; i <= n; ++i) {
    cin >> a[i];
  }
  for (int i = 1; i <= n; ++i) {
    cin >> b[i];
  }
  for (int i = 1; i <= n; ++i) {
    presum[i] = presum[i-1]+a[i]*b[i];
  }
  ll res = 0, cur;
  for (int m = 1; m <= n; ++m) {
    cur = a[m]*b[m];
    res = max(res, cur+calc(m, m));
    for (int l = 1; m-l >= 1 && m+l <= n; ++l) {
      cur += a[m-l]*b[m+l]+a[m+l]*b[m-l];
      res = max(res, cur+calc(m-l, m+l));
    }
  }
  for (int m = 1; m < n; ++m) {
    cur = a[m]*b[m+1]+a[m+1]*b[m];
    res = max(res, cur+calc(m, m+1));
    for (int l = 1; m-l >= 1 && m+1+l <= n; ++l) {
      cur += a[m-l]*b[m+1+l]+a[m+1+l]*b[m-l];
      res = max(res, cur+calc(m-l, m+1+l));
    }
  }
  cout << res << '\n';
}

signed main() {
#ifdef ONLINE_JUDGE
  ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
#endif
  int T = 1;
  // cin >> T; // scanf("%d", &T);
  for (int t = 1; t <= T; ++t) {
    solve();
  }
  return 0;
}