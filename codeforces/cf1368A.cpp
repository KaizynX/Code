/*
 * @Author: Kaizyn
 * @Date: 2020-06-18 22:29:41
 * @LastEditTime: 2020-06-18 22:47:28
 */ 
#include <bits/stdc++.h>

// #define DEBUG

using namespace std;

const double eps = 1e-7;
const double PI = acos(-1);
typedef pair<int, int> pii;
const int MOD = 998244353;
const int INF = 0x3f3f3f3f;
const int N = 1e2+7;

long long a, b, n;

inline void solve() {
  cin >> a >> b >> n;
  long long t = 0;
  if (a < b) swap(a, b);
  while (a <= n) {
    b += a;
    swap(a, b);
    ++t;
  }
  cout << t << endl;
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