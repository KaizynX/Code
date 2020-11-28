/*
 * @Author: Kaizyn
 * @Date: 2020-11-01 19:02:35
 * @LastEditTime: 2020-11-01 20:14:16
 */
#include <bits/stdc++.h>

// #define DEBUG

using namespace std;

const double eps = 1e-7;
const double PI = acos(-1);
typedef pair<int, int> pii;
const int MOD = 998244353;
const int INF = 0x3f3f3f3f;
const int N = 3e5+7;

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

int n;
int a[N];
Combination comb;

long long shit() {
  long long res = 0, all = comb.C(2*n, n);
  for (int i = 1; i <= n; ++i)   (res -= all*a[i]) %= MOD;
  for (int i = n+1; i <= 2*n; ++i) (res += all*a[i]) %= MOD;
  return (res+MOD)%MOD;
}

inline void solve() {
  cin >> n;
  for (int i = 1; i <= 2*n; ++i) {
    cin >> a[i];
  }
  sort(a+1, a+2*n+1);
  cout << shit() << endl;
  /*
  long long res = 0, all = comb.C(2*n, n);
  for (int i = 1; i <= 2*n; ++i) {
    long long add = 0;
    for (int j = 1; j <= n; ++j) {
      if (i-1 >= n && 2*n-i >= n-j)
        add += comb.C(i-1, j-1);
    }
    (add *= 2) %= MOD;
    (res += a[i]*(add+add-all)) %= MOD;
  }
  cout << (res+MOD)%MOD << endl;
  */
}

signed main() {
  comb.init(3e5);
  ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
  int T = 1;
  // cin >> T;
  for (int t = 1; t <= T; ++t) {
    solve();
  }
  return 0;
}