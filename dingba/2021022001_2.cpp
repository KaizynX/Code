/*
 * @Author: Kaizyn
 * @Date: 2021-02-20 18:21:23
 * @LastEditTime: 2021-02-20 19:07:03
 */
#include <bits/stdc++.h>

// #define DEBUG

using namespace std;

const double eps = 1e-7;
const double PI = acos(-1);
typedef pair<int, int> pii;
typedef long long ll;
const int MOD = 998244353;
const int INF = 0x3f3f3f3f;
// const ll INF = 1e18;
// const int N = ;

ll g, l;

template <typename T> void write(T x) {
  if(x < 0) x = -x, putchar('-');
  if(x > 9) write(x/10);
  putchar(x%10+'0');
}

__int128_t sqrt(__int128_t x) {
  __int128_t l = 1, r = 1e18, m;
  while (l < r) {
    m = (l+r)/2;
    if (m*m >= x) r = m; 
    else l = m+1;
  }
  return l;
}

inline void solve() {
  cin >> g >> l;
  __int128_t x = g;
  x *= l;
  x = sqrt(x);
  write(x+x);
  cout << ' ' << g+l << '\n';
}

signed main() {
#ifdef ONLINE_JUDGE
  // ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
#endif
  int T = 1;
  cin >> T;
  for (int t = 1; t <= T; ++t) {
    solve();
  }
  return 0;
}