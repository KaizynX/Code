/*
 * @Author: Kaizyn
 * @Date: 2020-03-28 11:26:26
 * @LastEditTime: 2020-03-28 12:01:02
 */
#include <bits/stdc++.h>

// #define DEBUG

using namespace std;

const int N = 12;
const int MOD = 1e9+7;
const double eps = 1e-7;
const int INF = 0x3f3f3f3f;
typedef pair<int, int> pii;

template <class T>
struct Fraction
{
    T a, b;
    void normalize() {
        if (a == 0) return (void)(b = 1);
        T g = __gcd(a, b);
        a /= g; b /= g;
    }
    Fraction(const T &_a = 0, const T &_b = 1) : a(_a), b(_b) { this->normalize(); }
    friend bool operator < (const Fraction &f1, const Fraction &f2) { return f1.a*f2.b < f2.a*f1.b; }
    friend bool operator > (const Fraction &f1, const Fraction &f2) { return f1.a*f2.b > f2.a*f1.b; }
    friend bool operator == (const Fraction &f1, const Fraction &f2) { return f1.a*f2.b == f2.a*f1.b; }
    friend bool operator != (const Fraction &f1, const Fraction &f2) { return f1.a*f2.b != f2.a*f1.b; }
    friend bool operator <= (const Fraction &f1, const Fraction &f2) { return f1 < f2 || f1 == f2; }
    friend bool operator >= (const Fraction &f1, const Fraction &f2) { return f1 > f2 || f1 == f2; }
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
    friend ostream& operator << (ostream &os, Fraction &f) {
        if (f.a == 0) return os << 0;
        if (f.b == 1) return os << f.a;
        return os << f.a << "/" << f.b;
    }
};
using fraction = Fraction<long long>;

int n, m;
int a[N];
int fac[N];
fraction f[2][N];

inline void solve()
{
    for (int k = 0; k <= m; ++k) f[0][k] = 0;
    f[0][0] = 1;
    for (int i = 1; i <= n; ++i) {
        for (int k = 0; k <= m; ++k) f[i&1][k] = 0;
        for (int j = 0; j <= a[i]; ++j) { // choose j's i
            for (int k = 0; k+j <= m; ++k) {
                f[i&1][j+k] += f[~i&1][k]*fraction(1, fac[j]);
            }
        }
    }
    f[n&1][m] *= fac[m];
    cout << f[n&1][m] << endl;
}

signed main()
{
    ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    fac[0] = 1;
    for (int i = 1; i <= 10; ++i) fac[i] = fac[i-1]*i;
    while (cin >> n >> m) {
        for (int i = 1; i <= n; ++i) cin >> a[i];
        solve();
    }
    return 0;
}