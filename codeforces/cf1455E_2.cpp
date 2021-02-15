/*
 * @Author: Kaizyn
 * @Date: 2021-02-11 14:37:27
 * @LastEditTime: 2021-02-11 15:21:29
 */
// AC with C++17
#include <bits/stdc++.h>

// #define DEBUG

using namespace std;

typedef long long ll;

struct Node {
  int x, y;
};

int rk[4];
Node a[4], b[4];
/* 0--1
 * |  |
 * 2--3
 */ 

ll f(ll len) { // O(16)
// #define abs(x) (x<0?-(x):x)
// #define min(x,y) (x<y?x:y)
  static function<ll(ll)> fx = [&](ll x) {
    return abs(x-b[0].x)+abs(x-b[1].x)+abs(x+len-b[2].x)+abs(x+len-b[3].x);
  };
  static function<ll(ll)> fy = [&](ll y) {
    return abs(y-b[0].y)+abs(y-b[2].y)+abs(y+len-b[1].y)+abs(y+len-b[3].y);
  };
  return min(min(fx(b[0].x), fx(b[1].x)), min(fx(b[2].x-len), fx(b[3].x-len)))
        +min(min(fy(b[0].y), fy(b[2].y)), min(fy(b[1].y-len), fy(b[3].y-len)));
}

inline void solve() {
  // for (int i = 0; i < 4; ++i) cin >> a[i].x >> a[i].y;
  for (int i = 0; i < 4; ++i) scanf("%d%d", &a[i].x, &a[i].y);
  ll res = 1e18;
  iota(rk, rk+4, 0);
  do {
    for (int i = 0; i < 4; ++i) b[i] = a[rk[i]];
    // 三分边长
    int l = 0, r = 1e9;
    while (l < r) {
      int mid = l+(r-l)/2;
      if (f(mid) < f(mid+1)) r = mid;
      else l = mid+1;
    }
    res = min(res, f(l));
  } while (next_permutation(rk, rk+4));
  // cout << res << '\n';
  printf("%lld\n", res);
}

// O(T*4!*log(1e9))
signed main() {
#ifdef ONLINE_JUDGE
  // ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
#endif
  int T = 1;
  // cin >> T;
  scanf("%d", &T);
  for (int t = 1; t <= T; ++t) {
    solve();
  }
  return 0;
}