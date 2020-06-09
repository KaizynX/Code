/*
 * @Author: Kaizyn
 * @Date: 2020-06-06 14:23:08
 * @LastEditTime: 2020-06-06 14:24:31
 */ 
#include <bits/stdc++.h>

// #define DEBUG

using namespace std;

const double eps = 1e-7;
const double PI = acos(-1);
typedef pair<int, int> pii;
const int MOD = 998244353;
const int INF = 0x3f3f3f3f;
const int N = 1e4+7;

int k;

inline void solve() {
  cin >> k;
  int a = 4*k;
  int b = (2*k-1)*(2*k-1)-5;
  int g = __gcd(a, b);
  a /= g; b /= g;
  if (b == 1) cout << a << endl;
  else cout << a << "/" << b << endl;
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