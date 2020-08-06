/*
 * @Author: Kaizyn
 * @Date: 2020-07-27 22:48:15
 * @LastEditTime: 2020-07-27 22:50:59
 */ 
#include <bits/stdc++.h>

// #define DEBUG

using namespace std;

const double eps = 1e-7;
const double PI = acos(-1);
typedef pair<int, int> pii;
const int MOD = 998244353;
const int INF = 0x3f3f3f3f;
const int N = 1e6+7;

struct Combination {
  int fac[N], inv[N];
  void init(const int &n) {
    fac[0] = inv[0] = fac[1] = inv[1] = 1;
    for (int i = 2; i <= n; ++i) {
      fac[i] = 1ll*fac[i-1]*i%MOD;
      inv[i] = 1ll*(MOD-MOD/i)*inv[MOD%i]%MOD;
    }
    for (int i = 2; i <= n; ++i) {
      inv[i] = 1ll*inv[i]*inv[i-1]%MOD;
    }
  }
  int A(const int &p, const int &q) {
    return p >= q ? 1ll*fac[p]*inv[p-q]%MOD : 0;
  }
  int C(const int &p, const int &q) {
    return p >= q ? 1ll*fac[p]*inv[q]%MOD*inv[p-q]%MOD : 0;
  }
};

int n, m, k;
Combination comb;

inline void solve() {
  cin >> n >> m >> k;
  if (n > m) swap(n, m);
  long long res = 0;
  for (int i = k; i <= n; ++i) {
    (res += 1ll*comb.C(i-1, k-1)*comb.C(n-i+k-1, k-1)%MOD*comb.C(m-i+k-1, k-1)) %= MOD;
  }
  cout << res << endl;
}

signed main() {
  ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
  comb.init(1e6);
  int T = 1;
  cin >> T;
  for (int t = 1; t <= T; ++t) {
    solve();
  }
  return 0;
}