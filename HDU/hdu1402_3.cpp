/*
 * @Author: Kaizyn
 * @Date: 2020-03-28 15:32:03
 * @LastEditTime: 2020-03-28 17:32:03
 */
#include <bits/stdc++.h>

// #define DEBUG

using namespace std;

const int N = 2e5+7;
const int MOD = 998244353;
const double eps = 1e-7;
const int INF = 0x3f3f3f3f;
typedef pair<int, int> pii;

template <typename T, typename H>
inline T qpow(const T &a, const H &p, const int &mo = MOD)
{
    long long res = 1, x = a;
    for (H i = p; i; i >>= 1, x = x*x%mo)
        if (i&1) res = res*x%mo;
    return static_cast<T>(res);
}

// array start from 0
// n, m is the max pow, which means f [0, n]
struct NTT
{
    const int G = 3;
    int len, bit;
    int rev[N];
    template <class T>
    void ntt(T a[], int flag)
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
    template <class T>
    void work(T f[], const int &n, T g[], const int &m) {
        len = 1; bit = 0;
        while (len <= n+m) len <<= 1, ++bit;
        for (int i = 0; i < len; ++i)
            rev[i] = (rev[i>>1]>>1)|((i&1)<<(bit-1));
        ntt(f, 1);
        ntt(g, 1);
        for (int i = 0; i <= len; ++i) f[i] = f[i]*g[i]%MOD;
        ntt(f, -1);
        long long inv = qpow(len, MOD-2);
        for (int i = 0; i <= n+m; ++i) f[i] = f[i]*inv%MOD;
    }
};

NTT fft;
int n, m;
char s1[N], s2[N];
long long a[N], b[N];

inline void solve()
{
    n = strlen(s1);
    m = strlen(s2);
    memset(a, 0, sizeof a);
    memset(b, 0, sizeof b);
    for (int i = 0; i < n; ++i) a[i] = s1[n-i-1]-'0';
    for (int i = 0; i < m; ++i) b[i] = s2[m-i-1]-'0';
    #ifdef DEBUG
    // for (int i = 0; i < n; ++i) cout << a[i] << " \n"[i==n-1];
    // for (int i = 0; i < m; ++i) cout << b[i] << " \n"[i==m-1];
    #endif
    fft.work(a, n-1, b, m-1);
    #ifdef DEBUG
    for (int i = 0; i < fft.len; ++i) cout << a[i] << " \n"[i==fft.len-1];
    #endif
    for (int i = 0; i < n+m; ++i) {
        a[i+1] += a[i]/10;
        a[i] %= 10;
    }
    int t = n+m-1;
    while (t && !a[t]) --t;
    for ( ; t >= 0; --t) putchar(a[t]+'0');
    putchar('\n');
}

signed main()
{
    while (~scanf("%s%s", s1, s2)) solve();
    return 0;
}