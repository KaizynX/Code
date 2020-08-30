/*
 * @Author: Kaizyn
 * @Date: 2020-08-28 10:42:58
 * @LastEditTime: 2020-08-28 13:20:15
 */
#include <bits/stdc++.h>

#define DEBUG

using namespace std;

const double eps = 1e-7;
const double PI = acos(-1);
typedef pair<int, int> pii;
const int MOD = 2e5+3;
const int INF = 0x3f3f3f3f;
const int G = 2;
const int N = 2e5+7;

template <typename T, typename H>
inline T qpow(const T &a, const H &p, const int &mo = MOD) {
  long long res = 1, x = a;
  for (H i = p; i; i >>= 1, x = x*x%mo)
    if (i&1) res = res*x%mo;
  return static_cast<T>(res);
}

namespace FFT {
  static const int SIZE = 1<<19;
  int len, bit;
  int rev[SIZE];
  // #define comp complex<long double>
  void fft(comp a[], int flag = 1) {
    for (int i = 0; i < len; ++i)
      if (i < rev[i]) swap(a[i], a[rev[i]]);
    for (int base = 1; base < len; base <<= 1) {
      comp w, wn = {cos(PI/base), flag*sin(PI/base)};
      for (int i = 0; i < len; i += base*2) {
        w = { 1.0, 0.0 };
        for (int j = 0; j < base; ++j) {
          comp x = a[i+j], y = w*a[i+j+base];
          a[i+j] = x+y;
          a[i+j+base] = x-y;
          w *= wn;
        }
      }
    }
  }
  void work(comp f[], const int &n, comp g[], const int &m) {
    len = 1; bit = 0;
    while (len < n+m) len <<= 1, ++bit;
    // multi-testcase
    for (int i = n; i < len; ++i) f[i] = 0;
    for (int i = m; i < len; ++i) g[i] = 0;
    for (int i = 0; i < len; ++i)
      rev[i] = (rev[i>>1]>>1)|((i&1)<<(bit-1));
    fft(f, 1); fft(g, 1);
    for (int i = 0; i < len; ++i) f[i] *= g[i];
    fft(f, -1);
    for (int i = 0; i < n+m; ++i) f[i].real /= len;
  }
}

int n;
int a[N], mp[N], pw2[N], cnt[N];

signed main() {
  ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
  pw2[0] = 1; mp[1] = 0;
  for (int i = 1; i < MOD-1; ++i) {
    pw2[i] = pw2[i-1]*G%MOD;
    mp[pw2[i]] = i;
  }

  long long res = 0;
  cin >> n;
  for (int i = 1; i <= n; ++i) {
    cin >> a[i];
    if (!a[i]) continue;
    a[i] = mp[a[i]];
    ++cnt[a[i]];
    res -= pw2[a[i]*2];
  }
  NTT::work(cnt, MOD-1, cnt, MOD-1);
  for (int i = 0; i < MOD*2-2; ++i) if (NTT::f[i]) {
    res += pw2[i%(MOD-1)]*NTT::f[i];
  }
  cout << res/2 << endl;
  return 0;
}