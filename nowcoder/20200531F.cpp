/*
 * @Author: Kaizyn
 * @Date: 2020-05-31 15:37:47
 * @LastEditTime: 2020-05-31 15:47:08
 */ 
#include <bits/stdc++.h>

#define DEBUG

using namespace std;

const double eps = 1e-7;
const double PI = acos(-1);
typedef pair<int, int> pii;
const int MOD = 998244353;
const int INF = 0x3f3f3f3f;

unsigned long long a;
__int128_t b[2];

void print(__int128_t x) {
  if (x > 9) print(x/10);
  putchar('0'+x%10);
}

inline void solve() {
  cin >> a;
  b[0] = b[1] = 1;
  --a;
  for (unsigned long long i = 2; ; ++i) {
    #ifdef DEBUG
    print(b[i&1]);
    putchar('\n');
    #endif
    if (a < b[i&1]) return cout << i-1 << endl, void();
    a -= b[i&1];
    b[~i&1] = b[0]+b[1]+1;
  }
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