/*
 * @Author: Kaizyn
 * @Date: 2020-08-29 16:03:13
 * @LastEditTime: 2020-08-29 16:21:11
 */
#include <bits/stdc++.h>

// #define DEBUG

using namespace std;

const double eps = 1e-7;
const double PI = acos(-1);
typedef pair<int, int> pii;
const int MOD = 998244353;
const int INF = 0x3f3f3f3f;
const int N = 1e3+7;

int n, m;
int a[N];
vector<int> e[N];

inline void solve() {
  cin >> n;
  for (int i = 1; i <= n; ++i) cin >> a[i];
  for (int i = 1; i <= n; ++i) {
    for (int j = i+1; j <= n; ++j) {
      if (a[i] > a[j]) {
        ++m;
        e[i].emplace_back(j);
      }
    }
  }
  for (int i = 1; i <= n; ++i) {
    sort(e[i].begin(), e[i].end(), [](int x, int y) {
      return a[x] > a[y];
    });
    for (int &j : e[i]) swap(a[i], a[j]);
  }
  if (!is_sorted(a+1, a+n+1)) return cout << -1 << endl, void();
  cout << m << endl;
  for (int i = 1; i <= n; ++i) {
    for (int &j : e[i]) cout << i << " " << j << endl;
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