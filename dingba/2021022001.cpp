/*
 * @Author: Kaizyn
 * @Date: 2021-02-20 18:21:23
 * @LastEditTime: 2021-02-20 18:52:31
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

ll fuck(ll x) {
  ll res = 1+x;
  for (ll i = 2; i*i <= x; ++i) {
    if (x%i) continue;
    res = min(res, i+x/i);
  }
  return res;
}

inline void solve() {
  cin >> g >> l;
  // a*b == g*l
  // a = c*g, b = d*g
  // a*b == c*d*g^2
  // l = c*d*g
  // query(a+b == (c+d)*g)
  // min = sqrt(c*d)
  l /= g;
  cout << fuck(l)*g << ' ' << (1+l)*g << '\n';
}

signed main() {
#ifdef ONLINE_JUDGE
  ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
#endif
  int T = 1;
  cin >> T;
  for (int t = 1; t <= T; ++t) {
    solve();
  }
  return 0;
}