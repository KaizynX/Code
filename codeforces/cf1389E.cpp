/*
 * @Author: Kaizyn
 * @Date: 2020-07-29 23:36:19
 * @LastEditTime: 2020-07-30 00:05:21
 */ 
#include <bits/stdc++.h>

// #define DEBUG

using namespace std;

const double eps = 1e-7;
const double PI = acos(-1);
typedef pair<int, int> pii;
const int MOD = 998244353;
const int INF = 0x3f3f3f3f;
// const int N = ;

long long m, d, w;

inline void solve() {
  cin >> m >> d >> w;
  long long n = min(m, d);
  if (d%w == 1 || w == 1) return cout << n*(n-1)/2 << endl, void();
  // (y-x)*d+x-y === 0 (%w)
  // (y-x)*(d-1) === 0 (%w)
  long long k = d-1;
  long long g = __gcd(k, w);
  long long t = w/g; // t*k == lcm(k, w)
  long long c = (n-1)/t; // c*t < n
  long long res = n*c-(t+c*t)*c/2;
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