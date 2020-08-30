/*
 * @Author: Kaizyn
 * @Date: 2020-08-28 10:42:58
 * @LastEditTime: 2020-08-28 14:03:36
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

struct comp {
  typedef double T; // maybe long double ?
  T real, imag;
  comp (const double &_real = 0, const double &_imag = 0) : real(_real), imag(_imag) {}
  friend comp operator + (const comp &c1, const comp &c2) { return comp(c1.real+c2.real, c1.imag+c2.imag); }
  friend comp operator - (const comp &c1, const comp &c2) { return comp(c1.real-c2.real, c1.imag-c2.imag); }
  friend comp operator * (const comp &c1, const comp &c2) { return comp(c1.real*c2.real-c1.imag*c2.imag, c1.real*c2.imag+c1.imag*c2.real); }
  comp& operator += (const comp &c) { return *this = *this+c; }
  comp& operator -= (const comp &c) { return *this = *this-c; }
  comp& operator *= (const comp &c) { return *this = *this*c; }
  friend istream& operator >> (istream &is, comp &c) { return is >> c.real >> c.imag; }
  friend ostream& operator << (ostream &os, comp &c) { return os << c.real << setiosflags(ios::showpos) << c.imag << "i";}
  comp conjugate() { return comp(real, -imag); }
  friend comp conjugate(const comp &c) { return comp(c.real, -c.imag); }
};

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
  template <class T>
  void work(T a[], const int &n) {
    static comp f[SIZE];
    len = 1; bit = 0;
    while (len < n+n) len <<= 1, ++bit;
    // multi-testcase
    for (int i = 0; i < n; ++i) f[i] = a[i];
    for (int i = n; i < len; ++i) f[i] = 0;
    for (int i = 0; i < len; ++i) rev[i] = (rev[i>>1]>>1)|((i&1)<<(bit-1));
    fft(f, 1);
    for (int i = 0; i <= len; ++i) f[i] *= f[i];
    fft(f, -1);
    for (int i = 0; i < n+n; ++i) a[i] = static_cast<T>(f[i].real/len+.5);
  }
}

int n;
int a[N], mp[N], pw2[N];
long long cnt[N<<1];

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
    res -= pw2[a[i]*2%(MOD-1)];
  }
  #ifdef DEBUG
  for (int i = 1; i <= n; ++i) cout << a[i] << " \n"[i==n];
  cout.flush();
  #endif
  FFT::work(cnt, MOD-1);
  for (int i = 0; i < MOD*2-2; ++i) if (cnt[i]) {
    res += pw2[i%(MOD-1)]*cnt[i];
  }
  cout << res/2 << endl;
  return 0;
}