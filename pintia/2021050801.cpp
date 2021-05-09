/*
 * @Author: Kaizyn
 * @Date: 2021-05-08 18:54:35
 * @LastEditTime: 2021-05-08 19:16:02
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

template <class T>
struct Fraction {
  T a, b;
  void normalize() {
    if (a == 0) return (void)(b = 1);
    T g = __gcd(a, b);
    a /= g; b /= g;
    if (b < 0) a = -a, b = -b;
  }
  Fraction(const T &_a = 0, const T &_b = 1) : a(_a), b(_b) { normalize(); }
  friend bool operator < (const Fraction &f1, const Fraction &f2) { return (__int128_t)f1.a*f2.b < (__int128_t)f2.a*f1.b; }
  friend Fraction operator + (const Fraction &f1, const Fraction &f2) { return Fraction(f1.a*f2.b+f2.a*f1.b, f1.b*f2.b); }
  friend Fraction operator - (const Fraction &f1, const Fraction &f2) { return Fraction(f1.a*f2.b-f2.a*f1.b, f1.b*f2.b); }
  friend Fraction operator * (const Fraction &f1, const Fraction &f2) { return Fraction(f1.a*f2.a, f1.b*f2.b); }
  friend Fraction operator / (const Fraction &f1, const Fraction &f2) { return Fraction(f1.a*f2.b, f1.b*f2.a); }
  Fraction& operator += (const Fraction &f) { return *this = *this+f; }
  Fraction& operator -= (const Fraction &f) { return *this = *this-f; }
  Fraction& operator *= (const Fraction &f) { return *this = *this*f; }
  Fraction& operator /= (const Fraction &f) { return *this = *this/f; }
  friend istream& operator >> (istream &is, Fraction &f) {
    is >> f.a >> f.b;
    f.normalize();
    return is;
  }
  friend ostream& operator << (ostream &os, const Fraction &f) {
    // if (f.b == 1) return os << f.a;
    return os << f.a << "/" << f.b;
  }
};
using fraction = Fraction<long long>;

int n, m;
int a[N];

inline void solve() {
  // cin >> n >> m;
  for (int i = 1; i <= n; ++i) {
    cin >> a[i];
  }
  fraction res = 0;
  for (int i = 2, mina = a[1]; i <= n; ++i) {
    res = max(res, fraction(m, mina)*a[i]);
    mina = min(mina, a[i]);
  }
  cout << res << '\n';
}

signed main() {
#ifdef ONLINE_JUDGE
  ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
#endif
  // int T = 1;
  while (cin >> n >> m) solve();
  // cin >> T; // scanf("%d", &T);
  return 0;
}