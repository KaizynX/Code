/*
 * @Author: Kaizyn
 * @Date: 2021-02-11 14:11:24
 * @LastEditTime: 2021-02-11 14:40:44
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

struct Node {
  int x, y;
};

int rk[4];
Node a[4], b[4];
/* 0--1
 * |  |
 * 2--3
 */ 

ll fx(ll x, ll len) {
  return abs(x-b[0].x)+abs(x-b[1].x)+abs(x+len-b[2].x)+abs(x+len-b[3].x);
}

ll fy(ll y, ll len) {
  return abs(y-b[0].y)+abs(y-b[2].y)+abs(y+len-b[1].y)+abs(y+len-b[3].y);
}

ll f(ll len) {
  ll l, r, mid, res = 0;
  l = -1e9; r = 1e9;
  while (l < r) {
    mid = l+(r-l)/2;
    if (fx(mid, len) < fx(mid+1, len)) r = mid;
    else l = mid+1;
  }
  res += fx(l, len);
  l = -1e9; r = 1e9;
  while (l < r) {
    mid = l+(r-l)/2;
    if (fy(mid, len) < fy(mid+1, len)) r = mid;
    else l = mid+1;
  }
  res += fy(l, len);
  return res;
}

inline void solve() {
  for (int i = 0; i < 4; ++i) cin >> a[i].x >> a[i].y;
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
  cout << res << '\n';
}

// O(T*4!*log^2(1e9))
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