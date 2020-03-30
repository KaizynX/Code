/*
 * @Author: Kaizyn
 * @Date: 2020-03-29 17:48:31
 * @LastEditTime: 2020-03-29 18:53:10
 */
#include <bits/stdc++.h>

// #define DEBUG

using namespace std;

const int N = 3e5+7;
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
    int Mod = 1e9 + 7;
    comp w[SIZE];
    int bitrev[SIZE];
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
    inline void work(T *x, const int &n, T *y, const int &m, T *z)
    {
        static int bit, L;
        static comp a[SIZE], b[SIZE];
        static comp dfta[SIZE], dftb[SIZE], dftc[SIZE], dftd[SIZE];

        for (L = 1, bit = 0; L < n+m-1; ++bit, L <<= 1);
        for (int i = 0; i < L; ++i) bitrev[i] = bitrev[i >> 1] >> 1 | ((i & 1) << (bit - 1));
        for (int i = 0; i < L; ++i) w[i] = comp(cos(2 * PI * i / L), sin(2 * PI * i / L));

        for (int i = 0; i < L; ++i) (x[i] += Mod) %= Mod, (y[i] += Mod) %= Mod;
        for (int i = 0; i < L; ++i) a[i] = comp(x[i] & 32767, x[i] >> 15);
        for (int i = 0; i < L; ++i) b[i] = comp(y[i] & 32767, y[i] >> 15);
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
            z[i] = (da + ((long long)(db + dc) << 15) + ((long long)dd << 30)) % Mod;
        }
        for (int i = 0; i < n+m-1; ++i) (z[i] += Mod) %= Mod;
    }
};

MTT mtt;

int main()
{
    /*
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
    */
    int n, m;
    static int a[N], b[N], c[N];
    scanf("%d%d%d", &n, &m, &mtt.Mod), ++n, ++m;
    for (int i = 0; i < n; ++i) scanf("%d", a + i);
    for (int i = 0; i < m; ++i) scanf("%d", b + i);
    mtt.work(a, n, b, m, c);
    for (int i = 0; i < n+m-1; ++i) printf("%d ", c[i]);
    printf("\n");
    return 0;
}