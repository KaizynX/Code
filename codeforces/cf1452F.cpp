/*
 * @Author: Kaizyn
 * @Date: 2020-11-23 19:06:39
 * @LastEditTime: 2020-11-23 23:29:54
 */
#include <bits/stdc++.h>

// #define DEBUG

using namespace std;

const double eps = 1e-7;
const double PI = acos(-1);
typedef pair<int, int> pii;
const int MOD = 998244353;
const int INF = 0x3f3f3f3f;
const int N = 40;
typedef long long ll;

int n, q;
ll a[N], pw[N];

inline void solve() {
  cin >> n >> q;
  for (int i = 0; i < n; ++i) cin >> a[i];
  ll sum = 0, k;
  for (int i = 0; i < n; ++i) sum += a[i]*pw[i];
  for (int _ = q, op, x; _; --_) {
    cin >> op >> x >> k;
    if (op == 1) {
      sum -= a[x]*pw[x];
      a[x] = k;
      sum += a[x]*pw[x];
      continue;
    }
    if (sum < k) {
      cout << -1 << endl;
      continue;
    }
    ll res = 0, cnt = 0;
    for (int i = 0; i <= x; ++i) {
      k -= a[i];
      cnt += (pw[i]-1)*a[i];
    }
    if (k <= 0) {
      cout << 0 << endl;
      continue;
    }
    /*
    int id;
    for (int i = x+1; i < n && k; ++i) {
      ll t = min(a[i], k/pw[i-x]);
      k -= pw[i-x]*t;
      cnt += (pw[x]-1)*t*pw[i-x];
      res += (pw[i-x]-1)*t;
      if (a[i] == t) continue;
      else break;
    }
    if (k <= 0) {
      cout << res << endl;
      continue;
    }
    ll ans = 1e18;
    while (id > x) {
      if (cnt >= k) ans = min(ans, res+k);
      ++res;
      --id;
      if (k >= pw[id-x]) {
        res += pw[id-x]+1;
        k -= pw[id-x];
        cnt += pw[id-x]*(pw[x]-1);
      }
    }
    /*
    for (int i = x+1; i < n && k; ++i) {
      ll t = min(a[i], k/pw[i-x]);
      k -= pw[i-x]*t;
      cnt += (pw[x]-1)*t*pw[i-x];
      res += (pw[i-x]-1)*t;
      if (a[i] == t) continue;
      if (cnt >= k) res += k, k = 0;
      for (int j = i-1; j > x && k; --j) {
        ++res;
        if (k >= pw[j-x]) {
          k -= pw[j-x];
          res += pw[j-x]-1;
          cnt += pw[j-x]*(pw[x]-1);
        }
        if (cnt >= k) res += k, k = 0;
      }
      break;
    }
    if (k) assert(cnt >= k), res += k;
    // if (k) res += k;
    */
    cout << res << endl;
  }
}

signed main() {
  pw[0] = 1;
  for (int i = 1; i < N; ++i) pw[i] = pw[i-1]<<1;
  ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
  int T = 1;
  // cin >> T;
  for (int t = 1; t <= T; ++t) {
    solve();
  }
  return 0;
}