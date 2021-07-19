/*
 * @Author: Kaizyn
 * @Date: 2021-07-19 12:31:55
 * @LastEditTime: 2021-07-19 12:50:19
 */
#include <bits/stdc++.h>

// #define DEBUG

using namespace std;

const double eps = 1e-7;
const double PI = acos(-1);
typedef pair<int, int> pii;
typedef long long ll;
const int MOD = 998244353; // 1e9+7;
const int INF = 0x3f3f3f3f;
// const ll INF = 1e18;
const int N = 8e4+7;
const int K = 31;
const int prime[] = {2,3,5,7,11,13,17,19,23,29};

inline __int128_t qpow(__int128_t a, __int128_t p, __int128_t mo) {
  __int128_t res = 1, x = a;
  for (__int128_t i = p; i; i >>= 1, x = x*x%mo)
    if (i&1) res = res*x%mo;
  return res;
}

template <typename T> void write(T x) {
  if(x < 0) x = -x, putchar('-');
  if(x > 9) write(x/10);
  putchar(x%10+'0');
}

int n, m, k, P;
int a[N], t[N];
__int128_t f[N];

__int128_t C(int p, int q) {
  static int kp[10];
  if (q >= p) return 0;
  memset(kp, 0, sizeof kp);
  __int128_t res = 1;
  for (int i = 0, x, y; i < q; ++i) {
    y = p-i;
    x = i+1;
    for (int j = 0; j < 10; ++j) {
      while (y%prime[j] == 0) {
        y /= prime[j];
        ++kp[j];
      }
      while (x%prime[j] == 0) {
        x /= prime[j];
        --kp[j];
      }
    }
    res = res*y%P;
  }
  for (int i = 0; i < 10; ++i) res = res*qpow(prime[i], kp[i], P)%P;
  return res;
}

inline void solve() {
  cin >> n >> k >> P;
  m = 0;
  for (int i = 1; i <= n; ++i) {
    cin >> a[i];
    ++t[a[i]];
    m = max(m, a[i]);
  }
  __int128_t res = 1;
  for (int g = m; g; --g) {
    int cnt = 0;
    for (int i = g; i <= m; i += g) {
      f[g] = (f[g]-f[i])%P;
      cnt += t[i];
    }
    f[g] = (f[g]+C(cnt, k))%P;
    if (f[g]) res = res*qpow(g, f[g], P)%P;
  }
  write((res+P)%P); puts("");
}

signed main() {
#ifdef ONLINE_JUDGE
  ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
#endif
  int T = 1;
  cin >> T; // scanf("%d", &T);
  for (int tt = 1; tt <= T; ++tt) {
    solve();
    for (int i = 1; i <= n; ++i) --t[a[i]];
    for (int i = 1; i <= m; ++i) f[i] = 0;
  }
  return 0;
}