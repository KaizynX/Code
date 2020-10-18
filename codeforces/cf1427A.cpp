/*
 * @Author: Kaizyn
 * @Date: 2020-10-10 22:48:09
 * @LastEditTime: 2020-10-10 23:02:25
 */
#include <bits/stdc++.h>

// #define DEBUG

using namespace std;

const double eps = 1e-7;
const double PI = acos(-1);
typedef pair<int, int> pii;
const int MOD = 998244353;
const int INF = 0x3f3f3f3f;
const int N = 55;

int n;
int a[N];

inline void solve() {
  cin >> n;
  int sum = 0;
  for (int i = 1; i <= n; ++i) {
    cin >> a[i];
    sum += a[i];
  }
  if (sum == 0) return cout << "NO" << endl, void();
  cout << "YES" << endl;
  sort(a+1, a+n+1);
  if (sum > 0) reverse(a+1, a+n+1);
  /*
  sum = 0;
  for (int i = 1; i <= n; ++i) {
    sum += a[i];
    if (sum == 0) {
      swap(a[1], a[i]);
      swap(a[i], a[n]);
    }
  }
  */
  for (int i = 1; i <= n; ++i) cout << a[i] << " \n"[i==n];
  cout.flush();
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