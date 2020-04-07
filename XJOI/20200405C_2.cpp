/*
 * @Author: Kaizyn
 * @Date: 2020-04-05 14:31:28
 * @LastEditTime: 2020-04-05 16:39:24
 */
#include <bits/stdc++.h>

// #define DEBUG

using namespace std;

const int N = 2e3+7;
const int MOD = 998244353;
const long long INF = 1e18;
const double eps = 1e-7;
const double PI = acos(-1);
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
int v[N], w[N];
fraction dp[N];

inline void solve()
{
    cin >> n >> m;
    for (int i = 1; i <= n; ++i) cin >> a[i];
    for (int i = 1; i <= m; ++i) cin >> v[i] >> w[i];

    for (int i = 1; i <= a[1]; ++i) dp[i] = 0;
    for (int i = 1; i < n; ++i) { // on state i+1
        for (int j = a[i]+1; j <= a[i+1]; ++j) {
            int cnt = 0;
            fraction sum = 0;
            for (int k = 1; k <= m; ++k) if (w[k] <= a[i]) {
                sum += dp[j-w[k]]+v[k];
                ++cnt;
            }
            if (!cnt) return void(cout << -1 << endl);
            dp[j] = sum/cnt;
        }
    }
    fraction res = 0;
    for (int i = 1; i <= a[n]; ++i) {
        res += dp[i];
    }
    cout << res << endl;
}

signed main()
{
    ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    int testcase = 1;
    cin >> testcase;
    for (int i = 1; i <= testcase; ++i) {
        solve();
    }
    return 0;
}