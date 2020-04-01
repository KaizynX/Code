/*
 * @Author: Kaizyn
 * @Date: 2020-04-01 21:19:37
 * @LastEditTime: 2020-04-01 21:40:08
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

template <typename T, typename H>
inline T qpow(const T &a, const H &p, const int &mo = MOD)
{
    long long res = 1, x = a;
    for (H i = p; i; i >>= 1, x = x*x%mo)
        if (i&1) res = res*x%mo;
    return static_cast<T>(res);
}

namespace NTT
{
    static const int SIZE = (1<<18)+3;
    const int G = 3;
    int len, bit;
    int rev[SIZE];
    long long f[SIZE], g[SIZE];
    template <class T>
    void ntt(T a[], int flag = 1) {
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
    void work(T a[], const int &n, T b[], const int &m) {
        len = 1; bit = 0;
        while (len < n+m) len <<= 1, ++bit;
        for (int i = 0; i < n; ++i) f[i] = a[i];
        for (int i = n; i < len; ++i) f[i] = 0;
        for (int i = 0; i < m; ++i) g[i] = b[i];
        for (int i = m; i < len; ++i) g[i] = 0;
        for (int i = 0; i < len; ++i)
            rev[i] = (rev[i>>1]>>1)|((i&1)<<(bit-1));
        ntt(f, 1); ntt(g, 1);
        for (int i = 0; i < len; ++i) f[i] = f[i]*g[i]%MOD;
        ntt(f, -1);
        long long inv = qpow(len, MOD-2);
        for (int i = 0; i < n+m-1; ++i) f[i] = f[i]*inv%MOD;
    }
}

int n, m, a;
int c[N];
long long f[N], g[N], powa[N];
long long fac[N], inv[N];

inline void solve()
{
    for (int i = 0 ; i <= n; ++i) cin >> c[i];
    cin >> m;
    a = 0;
    for (int i = 1, x; i <= m; ++i) {
        cin >> x;
        a = (a-x+MOD)%MOD;
    }
    powa[0] = 1;
    for (int i = 1; i <= n; ++i) powa[i] = (powa[i-1]*a%MOD+MOD)%MOD;
    for (int i = 0; i <= n; ++i) {
        f[i] = c[n-i]*fac[n-i]%MOD;
        g[i] = powa[i]*inv[i];
    }
    NTT::work(f, n+1, g, n+1);
    for (int i = 0; i <= n; ++i)
        cout << NTT::f[n-i]*inv[i]%MOD << " ";
    cout << endl;
}

signed main()
{
    ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    fac[0] = inv[0] = 1;
    for (int i = 1; i < N; ++i) {
        fac[i] = fac[i-1]*i%MOD;
        inv[i] = qpow(fac[i], MOD-2);
    }
    while (cin >> n) solve();
    return 0;
}