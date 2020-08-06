/*
 * @Author: Kaizyn
 * @Date: 2020-07-26 14:06:57
 * @LastEditTime: 2020-07-26 14:10:32
 */ 
#include <bits/stdc++.h>

// #define DEBUG

using namespace std;

const double eps = 1e-7;
const double PI = acos(-1);
typedef pair<int, int> pii;
const int MOD = 998244353;
const int INF = 0x3f3f3f3f;
const int N = 1e6+7;

int n, m;

long long f(long long x) {
  return x*(x-1)/2;
}

inline void solve() {
  cin >> n >> m;
  m = min(m, n/2);
  cout << f(n)-f(n-2*m) << endl;
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