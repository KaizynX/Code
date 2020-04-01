/*
 * @Author: Kaizyn
 * @Date: 2020-03-31 19:11:25
 * @LastEditTime: 2020-04-01 18:50:27
 */
#include <bits/stdc++.h>

#define DEBUG

using namespace std;

const int N = 2e5+7;
const int MOD = 998244353;
const int INF = 0x3f3f3f3f;
const double eps = 1e-7;
const double PI = acos(-1);
typedef pair<int, int> pii;

struct comp
{
    typedef long double T; // maybe long double ?
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

namespace FFT
{
    static const int SIZE = (1<<18)+3;
    int len, bit;
    int rev[SIZE];
    comp f[SIZE], g[SIZE];
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
    void work(T a[], const int &n, T b[], const int &m) {
        len = 1; bit = 0;
        while (len < n+m) len <<= 1, ++bit;
        // multi-testcase
        for (int i = 0; i < n; ++i) f[i] = a[i];
        for (int i = n; i < len; ++i) f[i] = 0;
        for (int i = 0; i < m; ++i) g[i] = b[i];
        for (int i = m; i < len; ++i) g[i] = 0;
        for (int i = 0; i < len; ++i)
            rev[i] = (rev[i>>1]>>1)|((i&1)<<(bit-1));
        fft(f, 1); fft(g, 1);
        for (int i = 0; i < len; ++i) f[i] *= g[i];
        fft(f, -1);
        for (int i = 0; i < n+m-1; ++i) f[i].real /= len;
    }
}

// give g[1, n) ask f[0, n)
// f[i] = sigma f[i-1]*g[j] (1 <= j <= i)
template <class T>
void cdq_fft(T f[], T g[], const int &l, const int &r) // [l, r)
{
    if (r-l <= 1) return;
    int mid = (l+r)>>1;
    cdq_fft(f, g, l, mid);
    FFT::work(f+l, mid-l, g, r-l);
    #ifdef DEBUG
    for (int i = l; i < mid; ++i) cout << f[i] << " \n"[i==mid-1];
    for (int i = 0; i < r; ++i) cout << (int)(FFT::f[i].real+.5) << " \n"[i==r-1];
    #endif
    for (int i = mid; i < r; ++i)
        (f[i] += (long long)(FFT::f[i-l].real+.5)%MOD) %= MOD;
    cdq_fft(f, g, mid, r);
}

int n;
int f[N], g[N];

signed main()
{
    ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    cin >> n;
    for (int i = 1; i < n; ++i) cin >> g[i];
    f[0] = 1; cdq_fft(f, g, 0, n);
    for (int i = 0; i < n; ++i) cout << f[i] << " \n"[i==n-1];
    return 0;
}