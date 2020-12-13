/*
 * @Author: Kaizyn
 * @Date: 2020-11-29 15:01:32
 * @LastEditTime: 2020-11-29 15:12:16
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

int n, p, k, x, y;
int a[N];
string s;

inline void solve() {
  cin >> n >> p >> k >> s >> x >> y;
  for (int i = n; i; --i) {
    a[i] = s[i-1] == '0';
    if (i+k <= n) a[i] += a[i+k];
  }
  int res = n*x;
  for (int i = 0; i <= n-p; ++i) {
    res = min(res, a[p+i]*x+i*y);
  }
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