/*
 * @Author: Kaizyn
 * @Date: 2021-11-07 14:11:19
 * @LastEditTime: 2021-11-07 14:56:53
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

const int N = 3e3+7;

int n;
int h[N], p[N];
int minh[N][N];
Mint dp[N][N], sum[N][N];

inline void solve() {
  cin >> n;
  for (int i = 1; i <= n; ++i) {
    cin >> h[i];
    p[h[i]] = i;
    minh[i][i] = h[i];
  }
  for (int len = 2; len <= n; ++len) {
    for (int l = 1, r; (r = l+len-1) <= n; ++l) {
      minh[r][l] = minh[l][r] = min(minh[l][r-1], h[r]);
    }
  }
  sum[0][n] = 1;
  for (int i = 1; i <= n; ++i) {
    for (int j = 1; j < h[i]; ++j) {
      if (p[j] > i || minh[i][p[j]] != j) continue;
      dp[i][j] = sum[i-1][j];
    }
    for (int j = i; j; --j) {
      if (h[j] < h[i]) break;
      dp[i][h[i]] += sum[j-1][n];
    }
    for (int j = 1; j <= n; ++j) {
      sum[i][j] = sum[i][j-1]+dp[i][j];
    }
    #ifdef DEBUG
    orzarr(dp[i]+1, n);
    orzarr(sum[i]+1, n);
    #endif
  }
  cout << sum[n][n] << '\n';
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