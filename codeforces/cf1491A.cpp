/*
 * @Author: Kaizyn
 * @Date: 2021-02-28 20:55:55
 * @LastEditTime: 2021-02-28 21:37:57
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

int n, m;
int a[N], cnt[2];

inline void solve() {
  cin >> n >> m;
  for (int i = 1; i <= n; ++i) {
    cin >> a[i];
    ++cnt[a[i]];
  }
  for (int i = 1, op, x; i <= m; ++i) {
    cin >> op >> x;
    if (op == 1) {
      --cnt[a[x]];
      ++cnt[a[x] ^= 1];
    } else {
      cout << int(cnt[1] >= x) << '\n';
    }
  }
}

signed main() {
#ifdef ONLINE_JUDGE
  ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
#endif
  int T = 1;
  // cin >> T;
  for (int t = 1; t <= T; ++t) {
    solve();
  }
  return 0;
}