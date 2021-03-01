/*
 * @Author: Kaizyn
 * @Date: 2021-02-28 20:56:02
 * @LastEditTime: 2021-02-28 21:54:48
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
const int N = 1e2+7;

int n, u, v, res;
int a[N];

void update(int x, int y) {
  if (abs(x-y) > 1) return res = 0, void();
  if (x == y) {
    res = min(res, 2*v);
  } else {
    res = min({res, u, v});
  }
}

inline void solve() {
  cin >> n >> u >> v;
  for (int i = 1; i <= n; ++i) {
    cin >> a[i];
  }
  res = u+v;
  for (int i = 1; i <= n; ++i) {
    if (i-1 > 0) update(a[i], a[i-1]);
    if (i+1 <= n) update(a[i], a[i+1]);
  }
  cout << res << '\n';
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