/*
 * @Author: Kaizyn
 * @Date: 2020-05-17 16:43:36
 * @LastEditTime: 2020-05-17 17:25:41
 */ 
#include <bits/stdc++.h>

// #define DEBUG

using namespace std;

const double eps = 1e-7;
const double PI = acos(-1);
typedef pair<int, int> pii;
const int MOD = 998244353;
const int INF = 0x3f3f3f3f;

int a, b, c, d;

inline void solve() {
  cin >> a >> b >> c >> d;
  if (b >= a) return void(cout << b << endl);
  if (c <= d) return void(cout << -1 << endl);
  int e = c-d;
  long long res = (a-b+e-1ll)/e*c+b;
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