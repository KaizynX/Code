/*
 * @Author: Kaizyn
 * @Date: 2020-03-31 17:01:49
 * @LastEditTime: 2020-03-31 18:43:09
 */
#include <bits/stdc++.h>

// #define DEBUG

using namespace std;

const int N = 2e5+7;
const int MOD = 313;
const int INF = 0x3f3f3f3f;
const double eps = 1e-7;
const double PI = acos(-1);
typedef pair<int, int> pii;

template <typename T, typename H>
inline T qpow(const T &a, const H &p, const int &mo = MOD)
{
    long long res = 1, x = a;
    for (H i = p; i; i >>= 1, x = x*x%mo)
        if (i&1) res = res*x%mo;
    return static_cast<T>(res);
}

template <typename T>
inline T mul_inverse(const T &a, const int &mo = MOD)
{
    return qpow(a, mo-2);
}

struct comp
{
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

// array [0, n)
namespace FFT
{
    static const int SIZE = (1<<18)+3;
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
int a[N];

inline void solve()
{
    FFT::work(a, n+1);
}

signed main()
{
    ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    while (cin >> n && n) {
        for (int i = 1; i <= n; ++i) cin >> a[i];
        solve();
    }
    return 0;
}