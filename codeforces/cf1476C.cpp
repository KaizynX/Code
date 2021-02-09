/*
 * @Author: Kaizyn
 * @Date: 2021-02-04 15:34:48
 * @LastEditTime: 2021-02-04 15:56:59
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
ll a[N], b[N], c[N];

inline void solve() {
  cin >> n;
  for (int i = 1; i <= n; ++i) cin >> c[i];
  for (int i = 1; i <= n; ++i) cin >> a[i];
  for (int i = 1; i <= n; ++i) cin >> b[i];
  ll res = 0, cur = -INF;
  for (int i = 2; i <= n; ++i) { // end at i'th
    if (a[i] > b[i]) swap(a[i], b[i]);
    if (a[i] == b[i]) {
      cur = 2;
    } else {
      cur = max(cur+a[i]-1+c[i-1]-b[i]+2, b[i]-a[i]+2);
    }
    res = max(res, cur+c[i]-1);
  }
  cout << res << endl;
}

signed main() {
#ifdef ONLINE_JUDGE
  ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
#endif
  int T = 1;
  cin >> T;
  for (int t = 1; t <= T; ++t) {
    solve();
  }
  return 0;
}