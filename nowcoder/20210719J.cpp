/*
 * @Author: Kaizyn
 * @Date: 2021-07-19 12:20:37
 * @LastEditTime: 2021-07-19 12:31:35
 */
#include <bits/stdc++.h>

#define DEBUG

using namespace std;

const double eps = 1e-7;
const double PI = acos(-1);
typedef pair<int, int> pii;
typedef long long ll;
const int MOD = 998244353; // 1e9+7;
const int INF = 0x3f3f3f3f;
// const ll INF = 1e18;
const int N = 8e4+7;

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

template <typename T, typename H>
inline T qpow(const T &a, const H &p, const int &mo = MOD) {
  long long res = 1, x = a;
  for (H i = p; i; i >>= 1, x = x*x%mo)
    if (i&1) res = res*x%mo;
  return static_cast<T>(res);
}

int n, m, k, P;
int a[N], t[N];
ll f[N];
Combination comb;

inline void solve() {
  cin >> n >> k >> P;
  m = 0;
  for (int i = 1; i <= n; ++i) {
    cin >> a[i];
    ++t[a[i]];
    m = max(m, a[i]);
  }
  ll res = 1;
  for (int g = m; g; --g) {
    int cnt = 0;
    for (int i = g; i <= m; i += g) {
      f[g] = (f[g]-f[i])%P;
      cnt += t[i];
    }
    f[g] = (f[g]+comb.C(cnt, k))%P;
    #ifdef DEBUG
    // printf("g=%d cnt=%d f=%lld res=%lld\n", g, cnt, f[g], res);
    #endif
    if (f[g]) res = res*qpow(g, f[g])%P;
  }
  cout << (res+P)%P << '\n';
}

signed main() {
#ifdef ONLINE_JUDGE
  ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
#endif
  comb.init(4e4);
  int T = 1;
  cin >> T; // scanf("%d", &T);
  for (int tt = 1; tt <= T; ++tt) {
    solve();
    for (int i = 1; i <= n; ++i) --t[a[i]];
    for (int i = 1; i <= m; ++i) f[i] = 0;
  }
  return 0;
}