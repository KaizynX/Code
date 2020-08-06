/*
 * @Author: Kaizyn
 * @Date: 2020-07-29 22:31:28
 * @LastEditTime: 2020-07-29 23:34:27
 */ 
#include <bits/stdc++.h>

// #define DEBUG

using namespace std;

const double eps = 1e-7;
const double PI = acos(-1);
typedef pair<int, int> pii;
const int MOD = 998244353;
const int INF = 0x3f3f3f3f;
const int N = 2e5+7;

int n;
long long k, l1, l2, r1, r2;

inline void solve() {
  cin >> n >> k >> l1 >> r1 >> l2 >> r2;
  if (l1 > l2) swap(l1, l2), swap(r1, r2);
  if (r1 > l2) k -= n*(min(r1, r2)-l2);
  if (k <= 0) return cout << 0 << endl, void();
  long long p1 = max(0ll, l2-r1), p2 = abs(r1-r2)+min(r1-l1, l2-l1);
  long long res = 1e18;
  for (int i = 1; i <= n; ++i) { // how many operated
    long long cur = p1*i;
    if (i*p2 >= k) {
      res = min(res, cur+k);
      continue;
    }
    cur += i*p2;
    long long rk = k-i*p2;
    res = min(res, cur+rk*2);
  }
  cout << res << endl;
}

signed main() {
  ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
  int T = 1;
  cin >> T;
  for (int t = 1; t <= T; ++t) {
    solve();
  }
  return 0;
}