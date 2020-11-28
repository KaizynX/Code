/*
 * @Author: Kaizyn
 * @Date: 2020-10-25 19:02:15
 * @LastEditTime: 2020-10-25 21:12:55
 */
#include <bits/stdc++.h>

// #define DEBUG

using namespace std;

const double eps = 1e-7;
const double PI = acos(-1);
typedef pair<int, int> pii;
const int MOD = 998244353;
const int INF = 0x3f3f3f3f;
const int N = 1e5+7;
typedef long long ll;

ll a, b, c, d;

ll f(int x) {
  if (x == 1) return a;
  ll res = a*x;
  ll t = x*d;
  ll fullc = max(0ll, (t-c)/d+((t-c)%d == 0));
  ll allc = x-1;
  ll restc = allc-fullc;
  res -= fullc*b*c;
  res -= (d+restc*d)*restc/2;
  return res;
}

inline ll solve() {
  cin >> a >> b >> c >> d;
  if (a > b*c) return -1;
  ll l = 1, r = 1e6;
  while (l < r) {
    int mid = (l+r)>>1;
    if (f(mid) > f(mid+1)) r = mid;
    else l = mid+1;
  }
  return f(l);
  /*
  ll res = 0;
  for (int i = max(1ll, l-5); i <= l+5; ++i) res = max(res, f(i));
  return res;
  */
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