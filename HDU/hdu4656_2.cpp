/*
 * @Author: Kaizyn
 * @Date: 2020-03-31 17:01:49
 * @LastEditTime: 2020-04-07 20:45:48
 */
#include <bits/stdc++.h>

#define DEBUG

using namespace std;

const int N = 1e5+7;
const int MOD = 1e6+3;
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
    static const int SIZE = (1<<19)+7;
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
        static comp dfta[SIZE], dftb[SIZE];

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
            dfta[j] = da*dc + da*dd*comp(0, 1);
            dftb[j] = db*dc + db*dd*comp(0, 1);
        }
        for (int i = 0; i < L; ++i) a[i] = dfta[i];
        for (int i = 0; i < L; ++i) b[i] = dftb[i];
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

template <typename T, typename H>
inline T qpow(const T &a, const H &p, const int &mo = MOD)
{
    long long res = 1, x = a;
    for (H i = p; i; i >>= 1, x = x*x%mo)
        if (i&1) res = res*x%mo;
    return static_cast<T>(res);
}

int n, b, c, d;
int a[N];
long long f[N], g[N<<1], p[N], fac[N], inv[N], c2[N];

void init()
{
    fac[0] = fac[1] = inv[0] = inv[1] = 1;
    for (int i = 2; i < N; ++i) {
        fac[i] = fac[i-1]*i%MOD;
        inv[i] = (MOD-MOD/i)*inv[MOD%i]%MOD;
    }
    for (int i = 2; i < N; ++i) (inv[i] *= inv[i-1]) %= MOD;
}

inline void solve()
{
    long long pw = 1;
    for (int i = 0; i < n; ++i, (pw *= d) %= MOD) {
        f[i] = a[n-1-i]*fac[n-1-i]%MOD;
        g[i] = pw*inv[i]%MOD;
    }
    MTT::work(f, n, g, n);
    for (int i = 0; i < n; ++i) p[i] = MTT::f[n-1-i];

    pw = 1;
    for (int i = 0; i < n; ++i, (pw *= b) %= MOD) {
        c2[i] = qpow(c, 1ll*i*i%(MOD-1));
        f[i] = pw*c2[i]%MOD*p[i]%MOD*inv[i]%MOD;
        g[i+(n-1)] = g[-i+(n-1)] = qpow(c2[i], MOD-2);
    }
    // for (int i = -n+1; i < n; ++i) g[i+(n-1)] = qpow(qpow(c, 1ll*i*i), MOD-2);
    MTT::work(f, n, g, n*2-1);
    for (int i = 0; i < n; ++i)
        cout << MTT::f[n-1+i]*c2[i]%MOD << endl;
}

signed main()
{
    ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    init();
    while (cin >> n >> b >> c >> d) {
        for (int i = 0; i < n; ++i) cin >> a[i];
        solve();
    }
    return 0;
}