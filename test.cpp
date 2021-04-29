/*
 * @Author: Kaizyn
 * @Date: 2021-03-04 21:47:00
 * @LastEditTime: 2021-04-27 21:17:31
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
const int N = 1e5+7;

// array [0, n)
namespace NTT {
  static const int SIZE = (1<<18)+3;
  const int G = 3;
  int len, bit;
  int rev[SIZE];
  long long f[SIZE], g[SIZE];
  template <class T>
  void ntt(T a[], int flag = 1) {
    for (int i = 0; i < len; ++i)
      if (i < rev[i]) swap(a[i], a[rev[i]]);
    for (int base = 1; base < len; base <<= 1) {
      long long wn = qpow(G, (MOD-1)/(base*2)), w;
      if (flag == -1) wn = qpow(wn, MOD-2);
      for (int i = 0; i < len; i += base*2) {
        w = 1;
        for (int j = 0; j < base; ++j) {
          long long x = a[i+j], y = w*a[i+j+base]%MOD;
          a[i+j] = (x+y)%MOD;
          a[i+j+base] = (x-y+MOD)%MOD;
          w = w*wn%MOD;
        }
      }
    }
  }
  template <class T>
  void work(T a[], const int &n, T b[], const int &m) {
    len = 1; bit = 0;
    while (len < n+m) len <<= 1, ++bit;
    for (int i = 0; i < n; ++i) f[i] = a[i];
    for (int i = n; i < len; ++i) f[i] = 0;
    for (int i = 0; i < m; ++i) g[i] = b[i];
    for (int i = m; i < len; ++i) g[i] = 0;
    for (int i = 0; i < len; ++i)
      rev[i] = (rev[i>>1]>>1)|((i&1)<<(bit-1));
    ntt(f, 1); ntt(g, 1);
    for (int i = 0; i < len; ++i) f[i] = f[i]*g[i]%MOD;
    ntt(f, -1);
    long long inv = qpow(len, MOD-2);
    for (int i = 0; i < n+m-1; ++i) f[i] = f[i]*inv%MOD;
  }
}

void stirling(const int &n) {
  inv[0] = inv[1] = 1;
  for(int i = 2; i <= n; ++i)
    inv[i] = MOD-MOD/i*inv[MOD%i]%MOD;
  for (int i = 1; i <= n; ++i)
    inv[i] = inv[i-1]*inv[i]%MOD;
  while (len <= (n<<1)) len <<= 1, ++bit;
  for (int i = 0; i < len; ++i)
    rev[i] = (rev[i>>1]>>1)|((i&1)<<(bit-1));
  for (int i = 0, one = 1; i <= n; ++i, one = MOD-one) {
    f[i] = one*inv[i]%MOD;
    g[i] = qpow(i, n)*inv[i]%MOD;
  }
  NTT(f, 1); NTT(g, 1);
  for (int i = 0; i < len; ++i) f[i] = f[i]*g[i]%MOD;
  NTT(f, -1);
  long long invv = qpow(len, MOD-2);
  for (int i = 0; i <= n; ++i)
    printf("%lld%c", f[i]*invv%MOD, " \n"[i==n]);
}

int q, n, m;

inline bool solve() {
  cin >> q >> n >> m;
  stirling(n);
  for (int i = 1, x; i <= q; ++i) {
    cin >> x;
    cout << res[x] << '\n';
  }
}

signed main() {
#ifdef ONLINE_JUDGE
  ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
#endif
  int T = 1;
  cin >> T; // scanf("%d", &T);
  for (int t = 1; t <= T; ++t) {
    cout << (solve() ? "Yes" : "No") << '\n';
  }
  return 0;
}