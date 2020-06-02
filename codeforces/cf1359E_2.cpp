/*
 * @Author: Kaizyn
 * @Date: 2020-05-28 23:04:59
 * @LastEditTime: 2020-05-29 00:05:51
 */ 
#include <bits/stdc++.h>

#define DEBUG

using namespace std;

const double eps = 1e-7;
const double PI = acos(-1);
typedef pair<int, int> pii;
const int MOD = 998244353;
const int INF = 0x3f3f3f3f;
const int N = 5e5+7;

int n, k;
long long fac[N], inv[N];

inline long long C(const int &n, const int &k) {
  // return C(n-1, k-1)
  return fac[n]*inv[k]%MOD*inv[n-k]%MOD;
}

#ifdef DEBUG
inline long long qpow(long long a, int p) {
  long long res = 1;
  while (p) {
    if (p&1) res = res*a%MOD;
    a = a*a%MOD;
    p >>= 1;
  }
  return res;
}
#endif

inline void solve() {
  int n, k;
  cin >> n >> k;
  // if (n < k) return cout << 0 << endl, void();
  long long res = 0;
  for (int i = 1; n/i >= k; ++i) {
    (res += C(n/i-1, k-1)) %= MOD;
    cout << n/i << " " << C(n/i-1, k-1) << endl;
  }
  cout << res << endl;
}

signed main() {
  fac[0] = inv[0] = fac[1] = inv[1] = 1;
  for (int i = 2; i < N; ++i) {
    fac[i] = fac[i-1]*i%MOD;
    inv[i] = (MOD-MOD/i)*inv[MOD%i]%MOD;
  }
  #ifdef DEBUG
  cout << inv[2] << " " << inv[4] << endl;
  cout << qpow(2, MOD-2) << " " << qpow(4, MOD-2) << endl;
  #endif
  ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
  int T = 1;
  // cin >> T;
  for (int t = 1; t <= T; ++t) {
    solve();
  }
  return 0;
}