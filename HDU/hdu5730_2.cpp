/*
 * @Author: Kaizyn
 * @Date: 2020-04-06 14:09:11
 * @LastEditTime: 2020-04-06 14:41:41
 */
#include <bits/stdc++.h>

// #define DEBUG

using namespace std;

const int N = 1e5+7;
const int MOD = 313;
const int INF = 0x3f3f3f3f;
const double eps = 1e-7;
const double PI = acos(-1);
typedef pair<int, int> pii;

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

namespace MTT
{
    static const int SIZE = (1<<18)+7;
    int Mod = MOD;
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
    inline void work(T *x, const int &n, T *y, const int &m)
    {
        static int bit, L;
        static comp a[SIZE], b[SIZE];
        static comp dfta[SIZE], dftb[SIZE], dftc[SIZE], dftd[SIZE];

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
            dfta[j] = da * dc;
            dftb[j] = da * dd;
            dftc[j] = db * dc;
            dftd[j] = db * dd;
        }
        for (int i = 0; i < L; ++i) a[i] = dfta[i] + dftb[i] * comp(0, 1);
        for (int i = 0; i < L; ++i) b[i] = dftc[i] + dftd[i] * comp(0, 1);
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
}

// give g[1, n) ask f[0, n)
// f[i] = sigma f[i-j]*g[j] (1 <= j <= i)
template <class T>
void cdq_fft(T f[], T g[], const int &l, const int &r) // [l, r)
{
    if (r-l <= 1) return;
    int mid = (l+r)>>1;
    cdq_fft(f, g, l, mid);
    MTT::work(f+l, mid-l, g, r-l);
    for (int i = mid; i < r; ++i)
        (f[i] += MTT::f[i-l]) %= MOD;
    cdq_fft(f, g, mid, r);
}
// f[0] = 1; cdq_fft(f, g, 0, n);

int n;
long long a[N], f[N];

signed main()
{
    ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    while (cin >> n && n) {
        for (int i = 1; i <= n; ++i) cin >> a[i], a[i] %= MOD;
        for (int i = 1; i <= n; ++i) f[i] = 0;
        f[0] = 1; cdq_fft(f, a, 0, n+1);
        cout << f[n] << endl;
    }
    return 0;
}