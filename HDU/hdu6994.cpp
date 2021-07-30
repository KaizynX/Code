/*
 * @Author: Kaizyn
 * @Date: 2021-07-30 12:23:13
 * @LastEditTime: 2021-07-30 13:24:46
 */
#include <bits/stdc++.h>

// #define DEBUG

using namespace std;

const double eps = 1e-7;
const double PI = acos(-1);
typedef pair<int, int> pii;
typedef long long ll;
const int MOD = 1e9+7;
const int INF = 0x3f3f3f3f;
// const ll INF = 1e18;
const int N = 4e2+7;

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
    value = normalize(static_cast<int64_t>(value) * static_cast<int64_t>(rhs.value));
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

template <typename T>
struct Martix {
  int n, m;
  T a[N][N];
  Martix(){}
  Martix(const int &_n) : n(_n), m(_n) { init(); }
  Martix(const int &_n, const int &_m) : n(_n), m(_m) { init(); }
  T* operator [] (const int &i) { return a[i]; }
  void init(const int &tag = 0) {
    for (int i = 1; i <= n; ++i) memset(a[i], 0, sizeof(T)*(m+1));
    for (int i = 1; i <= n; ++i) a[i][i] = tag;
  }
  friend Martix operator * (const Martix &m1, const Martix &m2) {
    Martix res(m1.n, m2.m);
    for (int i = 1; i <= res.n; ++i)
      for (int j = 1; j <= res.m; ++j)
        for (int k = 1; k <= m1.m; ++k)
          res.a[i][j] += m1.a[i][k]*m2.a[k][j];
    return res;
  }
  Martix& operator *= (const Martix &mx) { return *this = *this*mx; }
  Martix& operator + (const Martix &mx) const { Martix res(n, m); return res += mx; }
  Martix& operator += (const Martix &mx) {
    assert(n == mx.n && m == mx.m);
    for (int i = 1; i <= n; ++i)
      for (int j = 1; j <= m; ++j)
        a[i][j] += mx.a[i][j];
    return *this;
  }
  Martix& operator - (const Martix &mx) const { Martix res(n, m); return res -= mx; }
  Martix& operator -= (const Martix &mx) {
    assert(n == mx.n && m == mx.m);
    for (int i = 1; i <= n; ++i)
      for (int j = 1; j <= m; ++j)
        a[i][j] -= mx.a[i][j];
    return *this;
  }
  template <typename TT>
  Martix pow(const TT &p) const {
    Martix res(n, m), a = *this;
    res.init(1);
    for (TT i = p; i; i >>= 1, a *= a) if (i&1) res *= a;
    return res;
  }
  Martix inv() const {
    Martix res = *this;
    vector<int> is(n+1), js(n+1);
    for (int k = 1; k <= n; ++k) {
      for (int i = k; i <= n; ++i)
        for (int j = k; j <= n; ++j) if (res.a[i][j]) {
          is[k] = i; js[k] = j; break;
        }
      for (int i = 1; i <= n; ++i) swap(res.a[k][i], res.a[is[k]][i]);
      for (int i = 1; i <= n; ++i) swap(res.a[i][k], res.a[i][js[k]]);
      if (!res.a[k][k]) return Martix(0);
      res.a[k][k] = 1/res.a[k][k]; // get inv of number
      for (int j = 1; j <= n; ++j) if (j != k)
        res.a[k][j] *= res.a[k][k];
      for (int i = 1; i <= n; ++i) if (i != k)
        for (int j = 1; j <= n; ++j) if (j != k)
          res.a[i][j] -= res.a[i][k]*res.a[k][j];
      for (int i = 1; i <= n; ++i) if (i != k)
        res.a[i][k] = -res.a[i][k]*res.a[k][k];
    }
    for (int k = n; k; --k) {
      for (int i = 1; i <= n; ++i) swap(res.a[js[k]][i], res.a[k][i]);
      for (int i = 1; i <= n; ++i) swap(res.a[i][is[k]], res.a[i][k]);
    }
    return res;
  }
  T sum() const {
    T res = 0;
    for (int i =1 ; i <= n; ++i) {
      for (int j = 1; j <= m; ++j) {
        res += a[i][j];
      }
    }
    return res;
  }
  friend ostream& operator << (ostream &os, Martix<T> &mx) {
    for (int i = 1; i <= mx.n; ++i)
      for (int j = 1; j <= mx.m; ++j)
        os << mx[i][j] << " \n"[j==mx.m];
    return os;
  }
};

const pii dir[] = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};
int n, m, q;
Martix<Mint> A, A_inv, B, U, V, C;

signed main() {
#ifdef ONLINE_JUDGE
  ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
#endif
  cin >> n >> m >> q;
  A.n = A.m = n*m; A.init();
  B.n = n*m; B.m = 1; B.init();
  U.n = n*m; U.m = 1; U.init();
  V.n = 1; V.m = n*m; V.init();
  C.n = C.m = 1;
  for (int i = 1, p, x, y, nx, ny; i <= n*m; ++i) {
    x = (i-1)/m+1;
    y = (i-1)%m+1;
    A[i][i] = -1;
    B[i][1] = -1;
    for (int d = 0, j; d < 4; ++d) {
      cin >> p;
      nx = x+dir[d].first;
      ny = y+dir[d].second;
      if (nx < 1 || ny < 1 || nx > n || ny > m) continue;
      j = (nx-1)*m+ny;
      A[i][j] = p;
    }
  }
  A_inv = A.inv();
  for (int _ = q, op, x, y, p, nx, ny; _; --_) {
    cin >> op;
    if (op == 1) {
      cin >> x >> y;
      for (int d = 0, i = (x-1)*m+y, j; d < 4; ++d) {
        cin >> p;
        nx = x+dir[d].first;
        ny = y+dir[d].second;
        if (nx < 1 || ny < 1 || nx > n || ny > m) continue;
        j = (nx-1)*m+ny;
        C[1][1] = p-A[i][j];
        A[i][j] = p;
        U[i][1] = 1;
        V[1][j] = 1;
        // A_inv = A_inv-A_inv*U*(C.inv()+V*A_inv*U).inv()*V*A_inv;
        C[1][1] = 1/(1/C[1][1]+(V*A_inv*U)[1][1]);
        A_inv -= (A_inv*U)*C*(V*A_inv);
        U[i][1] = 0;
        V[1][j] = 0;
      }
    } else {
      cout << (A_inv*B).sum() << '\n';
    }
  }
  return 0;
}