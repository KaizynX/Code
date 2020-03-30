/*
 * @Author: Kaizyn
 * @Date: 2020-03-28 22:55:32
 * @LastEditTime: 2020-03-29 18:31:26
 */
#include <bits/stdc++.h>

// #define DEBUG

using namespace std;

const int N = 2e5+7;
const int MOD = 998244353;
const int INF = 0x3f3f3f3f;
const double eps = 1e-7;
const double PI = acos(-1);
typedef pair<int, int> pii;

struct comp
{
    typedef double T; // maybe long double ?
    T real, imag;
    comp(){}
    template <class U, class H>
    comp (const U &_real = 0, const H &_imag = 0) : real(_real), imag(_imag) {}
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

struct MTT
{
    static const int SIZE = 262144+5;
    int len, bit, mod;
    int rev[SIZE];
    comp w[SIZE];
    void fft(comp a[]) {
        for (int i = 0; i < len; ++i) if (i < rev[i]) swap(a[i], a[rev[i]]);
        for (int i = 2, lyc = len >> 1; i <= len; i <<= 1, lyc >>= 1)
            for (int j = 0; j < len; j += i) {
                comp *l = a+j, *r = a+j+(i>>1), *p = w;
                for (int k = 0; k < i>>1; ++k) {
                    comp tmp = *r * *p;
                    *r = *l-tmp; *l = *l+tmp;
                    ++l; ++r; p += lyc;
                }
            }
    }
    template <typename T>
    void work(T *x, const int &n, T *y, const int &m, T *z) {
        static comp a[SIZE], b[SIZE], dfta[SIZE], dftb[SIZE], dftc[SIZE], dftd[SIZE];
        len = 1; bit = 0;
        while (len < n+m-1) len <<= 1, ++bit;
        for (int i = 0; i < len; ++i) rev[i] = (rev[i>>1]>>1)|((i&1)<<(bit-1));
        for (int i = 0; i < len; ++i) w[i] = comp(cos(2*PI*i/len), sin(2*PI*i/len));
        for (int i = 0; i < len; ++i) (x[i] += mod) %= mod, (y[i] += mod) %= mod;
        for (int i = 0; i < len; ++i) a[i] = comp(x[i]&32767, x[i]>>15), b[i] = comp(y[i]&32767, y[i]>>15);
        fft(a); fft(b);
        for (int i = 0, j; i < len; ++i) {
            j = (len-i)&(len-1);
            static comp da, db, dc, dd;
            da = (a[i]+conjugate(a[j]))*comp(.5, 0);
            db = (a[i]-conjugate(a[j]))*comp(0, -.5);
            dc = (b[i]+conjugate(b[j]))*comp(.5, 0);
            dd = (b[i]-conjugate(b[j]))*comp(0, -.5);
            dfta[j] = da*dc;
            dftb[j] = da*dd;
            dftc[j] = db*dc;
            dftd[j] = db*dd;
        }
        for (int i = 0; i < len; ++i) a[i] = dfta[i]+dftb[i]*comp(0, 1), b[i] = dftc[i]+dftd[i]*comp(0, 1);
        fft(a); fft(b);
        for (int i = 0; i < len; ++i) {
            int da = (long long)(a[i].real/len+.5)%mod,
                db = (long long)(a[i].imag/len+.5)%mod,
                dc = (long long)(b[i].real/len+.5)%mod,
                dd = (long long)(b[i].imag/len+.5)%mod;
            z[i] = (da+((long long)(db+dc)<<15)+((long long)dd<<30))%mod;
        }
        for (int i = 0; i < n+m-1; ++i) (z[i] += mod) %= mod;
    }
};

MTT mtt;

signed main()
{
    ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    int n, m, p;
    static int a[N], b[N], c[N];
    cin >> n >> m >> p;
    ++n; ++m;
    for (int i = 0; i < n; ++i) cin >> a[i];
    for (int i = 0; i < m; ++i) cin >> b[i];
    mtt.mod = p;
    mtt.work(a, n, b, m, c);
    for (int i = 0; i < n+m-1; ++i) cout << c[i] << " \n"[i==n+m-2];
    return 0;
}