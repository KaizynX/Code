/*
 * @Author: Kaizyn
 * @Date: 2020-03-28 17:37:26
 * @LastEditTime: 2020-03-28 18:39:36
 */
/*
 * @Author: Kaizyn
 * @Date: 2020-03-28 15:32:03
 * @LastEditTime: 2020-03-28 17:35:33
 */
#include <bits/stdc++.h>

// #define DEBUG

using namespace std;

const int N = 2e5+7;
const int MOD = 998244353;
const double eps = 1e-7;
const int INF = 0x3f3f3f3f;
const double PI = acos(-1);
typedef pair<int, int> pii;

struct cf
{
    typedef double T; // maybe long double ?
    T real, imag;
    cf(){}
    template <class T>
    cf (const T &_real = 0, const T &_imag = 0) : real(_real), imag(_imag) {}
    friend cf operator + (const cf &c1, const cf &c2) { return cf(c1.real+c2.real, c1.imag+c2.imag); }
    friend cf operator - (const cf &c1, const cf &c2) { return cf(c1.real-c2.real, c1.imag-c2.imag); }
    friend cf operator * (const cf &c1, const cf &c2) { return cf(c1.real*c2.real-c1.imag*c2.imag, c1.real*c2.imag+c1.imag*c2.real); }
    cf& operator += (const cf &c) { return *this = *this+c; }
    cf& operator -= (const cf &c) { return *this = *this-c; }
    cf& operator *= (const cf &c) { return *this = *this*c; }
    friend istream& operator >> (istream &is, cf &c) { return is >> c.real >> c.imag; }
    friend ostream& operator << (ostream &os, cf &c) { return os << c.real << setiosflags(ios::showpos) << c.imag << "i";}
};

// array [0, n)
struct FFT
{
    int len, bit;
    int rev[N];
    // #define cf complex<long double>
    void fft(cf a[], int flag) {
        for (int i = 0; i < len; ++i)
            if (i < rev[i]) swap(a[i], a[rev[i]]);
        for (int base = 1; base < len; base <<= 1) {
            cf w, wn = {cos(PI/base), flag*sin(PI/base)};
            for (int i = 0; i < len; i += base*2) {
                w = { 1.0, 0.0 };
                for (int j = 0; j < base; ++j) {
                    cf x = a[i+j], y = w*a[i+j+base];
                    a[i+j] = x+y;
                    a[i+j+base] = x-y;
                    w *= wn;
                }
            }
        }
    }
    void work(cf f[], const int &n, cf g[], const int &m) {
        len = 1; bit = 0;
        while (len < n+m) len <<= 1, ++bit;
        // multi-testcase
        for (int i = n; i < len; ++i) f[i] = 0;
        for (int i = m; i < len; ++i) g[i] = 0;
        for (int i = 0; i < len; ++i)
            rev[i] = (rev[i>>1]>>1)|((i&1)<<(bit-1));
        fft(f, 1); fft(g, 1);
        for (int i = 0; i <= len; ++i) f[i] *= g[i];
        fft(f, -1);
        for (int i = 0; i < n+m; ++i) f[i].real /= len;
    }
};

FFT fft;
int n, m;
char s1[N], s2[N];
int res[N];
cf a[N], b[N];

inline void solve()
{
    n = strlen(s1);
    m = strlen(s2);
    for (int i = 0; i < n; ++i) a[i] = s1[n-i-1]-'0';
    for (int i = 0; i < m; ++i) b[i] = s2[m-i-1]-'0';
    fft.work(a, n, b, m);
    #ifdef DEBUG
    for (int i = 0; i < n+m; ++i)
        printf("%d%c", static_cast<int>(a[i].real/len+0.5), " \n"[i==n+m-1]);
    #endif
    for (int i = 0; i < n+m; ++i) res[i] = static_cast<int>(a[i].real+.5);
    for (int i = 0; i < n+m; ++i) {
        res[i+1] += res[i]/10;
        res[i] %= 10;
    }
    int t = n+m-1;
    while (t && !res[t]) --t;
    for ( ; t >= 0; --t) putchar(res[t]+'0');
    putchar('\n');
}

signed main()
{
    while (~scanf("%s%s", s1, s2)) solve();
    return 0;
}