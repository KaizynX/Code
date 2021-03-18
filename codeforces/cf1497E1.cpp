/*
 * @Author: Kaizyn
 * @Date: 2021-03-17 23:09:09
 * @LastEditTime: 2021-03-18 00:12:52
 */
#include <bits/stdc++.h>

#define DEBUG

using namespace std;

const double eps = 1e-7;
const double PI = acos(-1);
typedef pair<int, int> pii;
typedef long long ll;
const int MOD = 998244353; // 1e9+7;
const int INF = 0x3f3f3f3f;
// const ll INF = 1e18;
const int N = 2e5+7;

int n, k;
int a[N];
set<int> vis;

int magic(int x) {
  int y = 1;
  for (int i = 2, k; i*i <= x; ++i) {
    if (x%i) continue;
    for (k = 0; x%i == 0; x /= i, ++k) {}
    if (k&1) y *= i;
  }
  return x*y;
}

inline void solve() {
  cin >> n >> k;
  for (int i = 1; i <= n; ++i) {
    cin >> a[i];
    a[i] = magic(a[i]);
  }
  #ifdef DEBUG
  for (int i = 1; i <= n; ++i) {
    cout << a[i] << " \n"[i==n];
  }
  #endif
  int res = 0;
  vis.clear();
  for (int i = 1; i <= n; ++i) {
    if (vis.count(a[i])) {
      vis.clear();
      ++res;
    }
    vis.insert(a[i]);
  }
  cout << res+1 << '\n';
}

signed main() {
#ifdef ONLINE_JUDGE
  ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
#endif
  int T = 1;
  cin >> T; // scanf("%d", &T);
  for (int t = 1; t <= T; ++t) {
    solve();
  }
  return 0;
}