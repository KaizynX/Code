#include <cmath>
#include <iostream>
#include <algorithm>
// #define DEBUG

using namespace std;

const int MAXN = 1e6+5e4+7;
const double PI = acos(-1);
const int MOD = 998244353;
const int G = 3;

int n, m, bit, len = 1;
int rev[MAXN<<1];
long long f[MAXN<<1], g[MAXN<<1];

inline long long qpow(long long a, int p)
{
    long long res = 1;
    while (p) {
        if (p&1) res = res*a%MOD;
        a = a*a%MOD;
        p >>= 1;
    }
    return res;
}

void FFT(long long a[], int flag)
{
    for (int i = 0; i < len; ++i)
        if (i < rev[i]) swap(a[i], a[rev[i]]);

    for (int base = 1; base < len; base <<= 1) {
        long long wn = qpow(G, (MOD-1)/(base*2)), w;
#ifdef DEBUG
        if (flag == -1) wn = 332748118;
#else
        if (flag == -1) wn = qpow(wn, MOD-2);
#endif
        for (int i = 0; i < len; i += base*2) {
            w = 1;
            for (int j = 0; j < base; ++j) {
                long long x = a[i+j], y = w*a[i+j+base]%MOD;
                a[i+j] = (x+y)%MOD;
                a[i+j+base] = (x-y+MOD)%MOD;
                w = w*wn%MOD;
            }
        }
    }
}

int main()
{
    scanf("%d %d", &n, &m);
    for (int i = 0; i <= n; ++i)
        scanf("%lld", f+i);
    for (int i = 0; i <= m; ++i)
        scanf("%lld", g+i);

    while (len <= n+m) len <<= 1, ++bit;
    for (int i = 0; i < len; ++i)
        rev[i] = (rev[i>>1]>>1)|((i&1)<<(bit-1));

    FFT(f, 1);
    FFT(g, 1);
    for (int i = 0; i <= len; ++i) {
        f[i] *= g[i];
    }
    FFT(f, -1);
    long long inv = qpow(len, MOD-2);
    for (int i = 0; i <= n+m; ++i) {
        printf("%lld", f[i]*inv%MOD);
        putchar((i == n+m ? '\n' : ' '));
    }
    return 0;
}

