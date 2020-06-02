/*
 * @Author: Kaizyn
 * @Date: 2020-05-30 11:57:24
 * @LastEditTime: 2020-05-30 13:31:38
 */ 
#include <bits/stdc++.h>

// #define DEBUG

using namespace std;

const double eps = 1e-7;
const double PI = acos(-1);
typedef pair<int, int> pii;
const int MOD = 998244353;
const int INF = 0x3f3f3f3f;

long long n, m, x, y;

inline long long solve() {
  cin >> n >> m >> x >> y;
  if (x <= y) return m;
  return min(m, (n+(m-1)*y)/x);
  long long d = x-y;
  long long t = n%d >= y ? n/d : n/d-1;
  if (t >= m) return m;
  n -= t*d;
  m -= t;
  n += (m-1)*y;
  t += n/x;
  return t;
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