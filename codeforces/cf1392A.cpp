/*
 * @Author: Kaizyn
 * @Date: 2020-08-16 22:16:57
 * @LastEditTime: 2020-08-16 22:37:25
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

inline void solve() {
  cin >> n;
  int mv = 0, cnt = 0;
  for (int i = 1; i <= n; ++i) {
    cin >> a[i];
    if (a[i] == a[i-1]) ++cnt;
    else cnt = 1;
  }
  if (cnt == n) cout << n << endl;
  else cout << 1 << endl;
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