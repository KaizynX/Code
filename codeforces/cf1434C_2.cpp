/*
 * @Author: Kaizyn
 * @Date: 2020-11-02 15:23:49
 * @LastEditTime: 2020-11-02 15:29:15
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

inline long long solve() {
  long long a, b, c, d;
  cin >> a >> b >> c >> d;
  if (a > b*c) return -1;
  long long k = a/b/d;
  return a*(k+1)-k*(k+1)/2*b*d;
}

signed main() {
  ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
  int T = 1;
  cin >> T;
  for (int t = 1; t <= T; ++t) {
    cout << solve() << endl;
  }
  return 0;
}