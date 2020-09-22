/*
 * @Author: Kaizyn
 * @Date: 2020-09-19 22:49:52
 * @LastEditTime: 2020-09-19 22:52:43
 */
#include <bits/stdc++.h>

// #define DEBUG

using namespace std;

const double eps = 1e-7;
const double PI = acos(-1);
typedef pair<int, int> pii;
const int MOD = 998244353;
const int INF = 0x3f3f3f3f;
const int N = 1e5+7;

int n;
int a[N], b[N];

inline void solve() {
  cin >> n;
  for (int i = 1; i <= n; ++i) cin >> a[i];
  sort(a+1, a+n+1);
  for (int i = 2; i <= n; i += 2) b[i] = a[i/2];
  for (int i = n, j = n; i; --i) if (!b[i]) {
    b[i] = a[j--];
  }
  cout << (n-1)/2 << endl;
  for (int i = 1; i <= n; ++i) cout << b[i] << " \n"[i==n];
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