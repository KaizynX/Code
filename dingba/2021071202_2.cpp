/*
 * @Author: Kaizyn
 * @Date: 2021-07-12 16:01:24
 * @LastEditTime: 2021-07-12 16:03:13
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
const int N = 1e6+7;

int n, k;
int a[N], cnt[N][2], b[N];

inline void solve() {
  int res = 0, sum = 0;
  for (int i = 0; i < n; ++i) {
    ++cnt[i%k][a[i]];
  }
  for (int i = 0; i < k; ++i) {
    if (cnt[i][0] <= cnt[i][1]) {
      res += cnt[i][0];
    } else {
      res += cnt[i][1];
      sum ^= 1;
    }
  }
  if (sum) {
    int tmp = n;
    for (int i = 0; i < k; ++i) {
      tmp = min(tmp, abs(cnt[i][0]-cnt[i][1]));
    }
    res += tmp;
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
    cin >> n >> k;
    for (int i = 0; i < n; ++i) {
      cin >> a[i];
      a[i] &= 1;
    }
    solve();
  }
  return 0;
}