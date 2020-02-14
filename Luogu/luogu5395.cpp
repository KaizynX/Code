#include <bits/stdc++.h>

using namespace std;

const int N = 8e5+7;
const int G = 3;
const int MOD = 167772161;

int n, len = 1, bit;
int rev[N];
long long inv[N], f[N], g[N];

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

void NTT(long long a[], int flag)
{
    for (int i = 0; i < len; ++i)
        if (i < rev[i]) swap(a[i], a[rev[i]]);

    for (int base = 1; base < len; base <<= 1) {
        long long wn = qpow(G, (MOD-1)/(base*2)), w;
        if (flag == -1) wn = qpow(wn, MOD-2);
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
    cin >> n;
    inv[0] = inv[1] = 1;
    for(int i = 2; i <= n; ++i)
        inv[i] = MOD-MOD/i*inv[MOD%i]%MOD;
    for (int i = 1; i <= n; ++i)
        inv[i] = inv[i-1]*inv[i]%MOD;
    while (len <= (n<<1)) len <<= 1, ++bit;
    for (int i = 0; i < len; ++i)
        rev[i] = (rev[i>>1]>>1)|((i&1)<<(bit-1));
    for (int i = 0, one = 1; i <= n; ++i, one = MOD-one) {
        f[i] = one*inv[i]%MOD;
        g[i] = qpow(i, n)*inv[i]%MOD;
    }
    NTT(f, 1); NTT(g, 1);
    for (int i = 0; i < len; ++i) f[i] = f[i]*g[i]%MOD;
    NTT(f, -1);
    long long invv = qpow(len, MOD-2);
    for (int i = 0; i <= n; ++i)
        printf("%lld%c", f[i]*invv%MOD, " \n"[i==n]);
    return 0;
}
