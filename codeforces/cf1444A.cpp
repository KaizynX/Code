/*
 * @Author: Kaizyn
 * @Date: 2020-11-01 19:02:26
 * @LastEditTime: 2020-11-01 19:22:19
 */
#include <bits/stdc++.h>

// #define DEBUG

using namespace std;

const double eps = 1e-7;
const double PI = acos(-1);
typedef pair<int, int> pii;
const int MOD = 998244353;
const int INF = 0x3f3f3f3f;
typedef long long ll;
// const int N = ;

inline ll qpow(const ll &a, const ll &p) {
  long long res = 1;
  for (int i = 1; i <= p; ++i) res *= a;
  return res;
}

inline ll solve() {
  ll p, q;
  cin >> p >> q;
  if (p%q == 0) {
    ll pp = p, res = 1;
    for (int i = 2, pk, qk; i*i <= q; ++i) {
      if (q%i) continue;
      pk = qk = 0;
      while (q%i == 0) q /= i, ++qk;
      while (p%i == 0) p /= i, ++pk;
      res = max(res, pp/qpow(i, pk-qk+1));
    }
    if (q > 1) {
      int qk = 1;
      int pk = 0;
      ll i = q;
      while (p%i == 0) p /= i, ++pk;
      res = max(res, pp/qpow(i, pk-qk+1));
    }
    return res;
  } else {
    return p;
  }
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