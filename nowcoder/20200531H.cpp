/*
 * @Author: Kaizyn
 * @Date: 2020-05-31 14:16:36
 * @LastEditTime: 2020-05-31 14:19:26
 */ 
#include <bits/stdc++.h>

// #define DEBUG

using namespace std;

const double eps = 1e-7;
const double PI = acos(-1);
typedef pair<int, int> pii;
const int MOD = 998244353;
const int INF = 0x3f3f3f3f;

long long n;

void print(__int128_t x) {
  if (x > 9) print(x/10);
  putchar('0'+x%10);
}

inline void solve() {
  cin >> n;
  __int128_t res = n;
  res = (res-1)*res/2;
  print(res);
  putchar('\n');
}

signed main() {
  // ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
  int T = 1;
  cin >> T;
  for (int t = 1; t <= T; ++t) {
    solve();
  }
  return 0;
}