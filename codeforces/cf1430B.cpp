/*
 * @Author: Kaizyn
 * @Date: 2020-10-11 17:03:34
 * @LastEditTime: 2020-10-11 17:15:38
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
int a[N];

inline void solve() {
  cin >> n >> k;
  for (int i = 1; i <= n; ++i) {
    cin >> a[i];
  }
  sort(a+1, a+n+1);
  reverse(a+1, a+n+1);
  long long res = 0;
  for (int i = 1; i <= n && i <= k+1; ++i) res += a[i];
  cout << res << endl;
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