/*
 * @Author: Kaizyn
 * @Date: 2022-02-26 17:17:48
 * @LastEditTime: 2022-02-26 17:17:49
 */
/*
 * @Author: Kaizyn
 * @Date: 2022-02-26 15:18:51
 * @LastEditTime: 2022-02-26 17:15:12
 */
#include <bits/stdc++.h>

// #define DEBUG

using namespace std;
namespace hjt {
template<typename A,typename B>
std::ostream &operator<<(std::ostream &o,const std::pair<A,B> &x){
  return o<<'('<<x.first<<','<<x.second<<')';
}
#define repeat(i,a,b) for(int i=(a),_=(b);i<_;i++)
#define repeat_back(i,a,b) for(int i=(b)-1,_=(a);i>=_;i--)
#define qwq [&]{cerr<<"qwq"<<endl;}()
#define orz(x) [&]{cerr<<#x": "<<x<<endl;}()
#define orzarr(a,n) [&]{cerr<<#a": "; repeat(__,0,n)cerr<<(a)[__]<<" "; cerr<<endl;}()
#define orzeach(a) [&]{cerr<<#a": "; for(auto __:a)cerr<<__<<" "; cerr<<endl;}()
#define pause [&]{system("pause");}()
} using namespace hjt;

typedef long long ll;
typedef pair<int, int> pii;
const double eps = 1e-7;
const double PI = acos(-1);
const int MOD = 1e9+7;
const int INF = 0x3f3f3f3f;
// const ll INF = 1e18;
const int N = 2e5 + 7;

template <typename T>
T inverse(T a, T m) {
  T u = 0, v = 1;
  while (a != 0) {
    T t = m / a;
    m -= t * a; swap(a, m);
    u -= t * v; swap(u, v);
  }
  assert(m == 1);
  return u;
}
template <typename T>
class Modular {
 public:
  using Type = typename decay<decltype(T::value)>::type;
 
  constexpr Modular() : value() {}
  template <typename U>
  Modular(const U& x) {
    value = normalize(x);
  }
 
  template <typename U>
  static Type normalize(const U& x) {
    Type v;
    if (-mod() <= x && x < mod()) v = static_cast<Type>(x);
    else v = static_cast<Type>(x % mod());
    if (v < 0) v += mod();
    return v;
  }
 
  const Type& operator()() const { return value; }
  template <typename U>
  explicit operator U() const { return static_cast<U>(value); }
  constexpr static Type mod() { return T::value; }
 
  Modular& operator+=(const Modular& other) { if ((value += other.value) >= mod()) value -= mod(); return *this; }
  Modular& operator-=(const Modular& other) { if ((value -= other.value) < 0) value += mod(); return *this; }
  template <typename U> Modular& operator+=(const U& other) { return *this += Modular(other); }
  template <typename U> Modular& operator-=(const U& other) { return *this -= Modular(other); }
  Modular& operator++() { return *this += 1; }
  Modular& operator--() { return *this -= 1; }
  Modular operator++(int) { Modular result(*this); *this += 1; return result; }
  Modular operator--(int) { Modular result(*this); *this -= 1; return result; }
  Modular operator-() const { return Modular(-value); }

  template <typename U = T>
  typename enable_if<is_same<typename Modular<U>::Type, int>::value, Modular>::type& operator*=(const Modular& rhs) {
#ifdef _WIN32
    uint64_t x = static_cast<int64_t>(value) * static_cast<int64_t>(rhs.value);
    uint32_t xh = static_cast<uint32_t>(x >> 32), xl = static_cast<uint32_t>(x), d, m;
    asm(
      "divl %4; \n\t"
      : "=a" (d), "=d" (m)
      : "d" (xh), "a" (xl), "r" (mod())
    );
    value = m;
#else
    value = normalize(static_cast<int64_t>(value) * static_cast<int64_t>(rhs.value));
#endif
    return *this;
  }
  template <typename U = T>
  typename enable_if<is_same<typename Modular<U>::Type, int64_t>::value, Modular>::type& operator*=(const Modular& rhs) {
    int64_t q = static_cast<int64_t>(static_cast<long double>(value) * rhs.value / mod());
    value = normalize(value * rhs.value - q * mod());
    return *this;
  }
  template <typename U = T>
  typename enable_if<!is_integral<typename Modular<U>::Type>::value, Modular>::type& operator*=(const Modular& rhs) {
    value = normalize(value * rhs.value);
    return *this;
  }
 
  Modular& operator/=(const Modular& other) { return *this *= Modular(inverse(other.value, mod())); }
 
  template <typename U>
  friend const Modular<U>& abs(const Modular<U>& v) { return v; }
 
  template <typename U>
  friend bool operator==(const Modular<U>& lhs, const Modular<U>& rhs);
 
  template <typename U>
  friend bool operator<(const Modular<U>& lhs, const Modular<U>& rhs);
 
  template <typename U>
  friend std::istream& operator>>(std::istream& stream, Modular<U>& number);
 
 private:
  Type value;
};
 
template <typename T> bool operator==(const Modular<T>& lhs, const Modular<T>& rhs) { return lhs.value == rhs.value; }
template <typename T, typename U> bool operator==(const Modular<T>& lhs, U rhs) { return lhs == Modular<T>(rhs); }
template <typename T, typename U> bool operator==(U lhs, const Modular<T>& rhs) { return Modular<T>(lhs) == rhs; }
 
template <typename T> bool operator!=(const Modular<T>& lhs, const Modular<T>& rhs) { return !(lhs == rhs); }
template <typename T, typename U> bool operator!=(const Modular<T>& lhs, U rhs) { return !(lhs == rhs); }
template <typename T, typename U> bool operator!=(U lhs, const Modular<T>& rhs) { return !(lhs == rhs); }
 
template <typename T> bool operator<(const Modular<T>& lhs, const Modular<T>& rhs) { return lhs.value < rhs.value; }
 
template <typename T> Modular<T> operator+(const Modular<T>& lhs, const Modular<T>& rhs) { return Modular<T>(lhs) += rhs; }
template <typename T, typename U> Modular<T> operator+(const Modular<T>& lhs, U rhs) { return Modular<T>(lhs) += rhs; }
template <typename T, typename U> Modular<T> operator+(U lhs, const Modular<T>& rhs) { return Modular<T>(lhs) += rhs; }
 
template <typename T> Modular<T> operator-(const Modular<T>& lhs, const Modular<T>& rhs) { return Modular<T>(lhs) -= rhs; }
template <typename T, typename U> Modular<T> operator-(const Modular<T>& lhs, U rhs) { return Modular<T>(lhs) -= rhs; }
template <typename T, typename U> Modular<T> operator-(U lhs, const Modular<T>& rhs) { return Modular<T>(lhs) -= rhs; }
 
template <typename T> Modular<T> operator*(const Modular<T>& lhs, const Modular<T>& rhs) { return Modular<T>(lhs) *= rhs; }
template <typename T, typename U> Modular<T> operator*(const Modular<T>& lhs, U rhs) { return Modular<T>(lhs) *= rhs; }
template <typename T, typename U> Modular<T> operator*(U lhs, const Modular<T>& rhs) { return Modular<T>(lhs) *= rhs; }
 
template <typename T> Modular<T> operator/(const Modular<T>& lhs, const Modular<T>& rhs) { return Modular<T>(lhs) /= rhs; }
template <typename T, typename U> Modular<T> operator/(const Modular<T>& lhs, U rhs) { return Modular<T>(lhs) /= rhs; }
template <typename T, typename U> Modular<T> operator/(U lhs, const Modular<T>& rhs) { return Modular<T>(lhs) /= rhs; }
 
template<typename T, typename U>
Modular<T> power(const Modular<T>& a, const U& b) {
  assert(b >= 0);
  Modular<T> x = a, res = 1;
  U p = b;
  while (p > 0) {
    if (p & 1) res *= x;
    x *= x;
    p >>= 1;
  }
  return res;
}
 
template <typename T>
bool IsZero(const Modular<T>& number) {
  return number() == 0;
}
 
template <typename T>
string to_string(const Modular<T>& number) {
  return to_string(number());
}
 
template <typename T>
std::ostream& operator<<(std::ostream& stream, const Modular<T>& number) {
  return stream << number();
}
 
template <typename T>
std::istream& operator>>(std::istream& stream, Modular<T>& number) {
  typename common_type<typename Modular<T>::Type, int64_t>::type x;
  stream >> x;
  number.value = Modular<T>::normalize(x);
  return stream;
}
 
/*
using ModType = int;
 
struct VarMod { static ModType value; };
ModType VarMod::value;
ModType& md = VarMod::value;
using Mint = Modular<VarMod>;
*/
 
constexpr int md = MOD;
using Mint = Modular<std::integral_constant<decay<decltype(md)>::type, md>>;

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

namespace MTT {
const int SIZE = (1<<19)+1;
const int Mod = MOD;
comp w[SIZE];
int bitrev[SIZE];
long long f[SIZE];
void fft(comp *a, const int &n) {
  for (int i = 0; i < n; ++i) if (i < bitrev[i]) swap(a[i], a[bitrev[i]]);
  for (int i = 2, lyc = n >> 1; i <= n; i <<= 1, lyc >>= 1)
    for (int j = 0; j < n; j += i) {
      comp *l = a + j, *r = a + j + (i >> 1), *p = w;
      for (int k = 0; k < i>>1; ++k) {
        comp tmp = *r * *p;
        *r = *l - tmp, *l = *l + tmp;
        ++l, ++r, p += lyc;
      }
    }
}
template <class T>
inline void work(T *x, const int &n, T *y, const int &m) {
  static int bit, L;
  static comp a[SIZE], b[SIZE];
  static comp dfta[SIZE], dftb[SIZE];

  for (L = 1, bit = 0; L < n+m-1; ++bit, L <<= 1);
  for (int i = 0; i < L; ++i) bitrev[i] = bitrev[i >> 1] >> 1 | ((i & 1) << (bit - 1));
  for (int i = 0; i < L; ++i) w[i] = comp(cos(2 * PI * i / L), sin(2 * PI * i / L));

  for (int i = 0; i < n; ++i) (x[i] += Mod) %= Mod, a[i] = comp(x[i] & 32767, x[i] >> 15);
  for (int i = n; i < L; ++i) a[i] = 0;
  for (int i = 0; i < m; ++i) (y[i] += Mod) %= Mod, b[i] = comp(y[i] & 32767, y[i] >> 15);
  for (int i = m; i < L; ++i) b[i] = 0;
  fft(a, L), fft(b, L);
  for (int i = 0; i < L; ++i) {
    int j = (L - i) & (L - 1);
    static comp da, db, dc, dd;
    da = (a[i] + conjugate(a[j])) * comp(.5, 0);
    db = (a[i] - conjugate(a[j])) * comp(0, -.5);
    dc = (b[i] + conjugate(b[j])) * comp(.5, 0);
    dd = (b[i] - conjugate(b[j])) * comp(0, -.5);
    dfta[j] = da*dc + da*dd*comp(0, 1);
    dftb[j] = db*dc + db*dd*comp(0, 1);
  }
  for (int i = 0; i < L; ++i) a[i] = dfta[i];
  for (int i = 0; i < L; ++i) b[i] = dftb[i];
  fft(a, L), fft(b, L);
  for (int i = 0; i < L; ++i) {
    int da = (long long)(a[i].real / L + 0.5) % Mod;
    int db = (long long)(a[i].imag / L + 0.5) % Mod;
    int dc = (long long)(b[i].real / L + 0.5) % Mod;
    int dd = (long long)(b[i].imag / L + 0.5) % Mod;
    f[i] = (da + ((long long)(db + dc) << 15) + ((long long)dd << 30)) % Mod;
  }
  for (int i = 0; i < n+m-1; ++i) (f[i] += Mod) %= Mod;
}
} // namespace MTT

int n, m, k;
int a[N];
ll s[N * 2];
ll f[N], g[N];
Mint ans;

// 碎片
void solve1() {
  memset(f, 0, sizeof(f[0]) * k);
  memset(g, 0, sizeof(g[0]) * k);
  for (int i = 1; i < n; ++i) {
    // 两头在同一段
    ans += f[s[i]] * m;
    // 少了一部分，这部分在同一段中
    ans += g[(s[i] - s[n] + k) % k] * m;
    ++f[s[i]];
    ++g[s[i]];
  }
}

// 整段
void solve2() {
  for (int i = 1; i < m; ++i) {
    ll val = s[n] * i % k;
    if (val == 0) ans += m;
  }
  if (1ll * s[n] * m % k == 0) ++ans;
}

// 两端为不完整片段
void solve3() {
  if (m == 1) return;
  memset(f, 0, sizeof(f[0]) * k);
  memset(g, 0, sizeof(g[0]) * k);
  for (int i = 1; i < n; ++i) {
    f[(k - s[i]) % k]++;
    g[s[n + i]]++;
  }
  MTT::work(f, k, g, k);
  auto *arr = MTT::f;
  for (int i = 0; i < k; ++i) {
    arr[i] = (arr[i] + arr[i + k]) % MOD;
  }
  #ifdef DEBUG
  orzarr(arr, k);
  #endif
  for (int i = 0; i <= m - 2; ++i) {
    ll val = (k - s[n] * i % k) % k;
    ans += arr[val] * m;
  }
}

// 一端为不完整片段
void solve4() {
  memset(f, 0, sizeof(f[0]) * k);
  memset(g, 0, sizeof(g[0]) * k);
  for (int i = 1; i < n; ++i) {
    ++f[s[i]];
  }
  ll sufsum = 0;
  for (int i = n; i > 1; --i) {
    (sufsum += a[i]) %= k;
    ++g[sufsum];
  }
  for (int i = 0; i < m; ++i) {
    ll val = (k - s[n] * i % k) % k;
    ans += (f[val] + g[val]) * m;
  }
}

inline void solve() {
  cin >> n >> m >> k;
  for (int i = 1; i <= n; ++i) {
    cin >> a[i];
    s[i] = (s[i - 1] + a[i]) % k;
  }
  if (k == 1) {
    cout << Mint(n) * m * (Mint(n) * m + 1) / 2 << '\n';
    return;
  }
  for (int i = 1; i <= n; ++i) {
    s[i + n] = (s[i + n - 1] + a[i]) % k;
  }
  #ifdef DEBUG
  orzarr(s + 1, 2 * n);
  #endif
  solve1();
  #ifdef DEBUG
  orz(ans);
  #endif
  solve2();
  #ifdef DEBUG
  orz(ans);
  #endif
  solve3();
  #ifdef DEBUG
  orz(ans);
  #endif
  solve4();
  cout << ans << '\n';
}

signed main() {
#ifdef ONLINE_JUDGE
  ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
#endif
  int T = 1;
  // cin >> T; // scanf("%d", &T);
  for (int t = 1; t <= T; ++t) {
    solve();
  }
  return 0;
}