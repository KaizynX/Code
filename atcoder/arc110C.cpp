/*
 * @Author: Kaizyn
 * @Date: 2020-12-05 20:17:37
 * @LastEditTime: 2020-12-05 20:57:18
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
int a[N];
vector<int> res;

bool f(int l, int r, int t = 1) {
  if (l >= r) return true;
  if (t) for (int i = l, mx = 0; i < r; ++i) {
    if (a[i] > a[i+1] && max(a[i+1], mx) == i) {
      res.emplace_back(i);
      swap(a[i], a[i+1]);
      return f(l, i, 0) && f(i+1, r, 1);
    }
    mx = max(mx, a[i]);
  }
  else for (int i = r, mn = n+1; i > l; --i) {
    if (a[i-1] > a[i] && min(a[i-1], mn) == i) {
      res.emplace_back(i-1);
      swap(a[i], a[i-1]);
      return f(l, i-1, 0) && f(i, r, 1);
    }
    mn = min(mn, a[i]);
  }
  return false;
}

inline void solve() {
  cin >> n;
  for (int i = 1; i <= n; ++i) cin >> a[i];
  if (f(1, n)) {
    for (int &i : res) cout << i << endl;
  } else {
    cout << -1 << endl;
  }
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