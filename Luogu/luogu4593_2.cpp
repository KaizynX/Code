/*
 * @Author: Kaizyn
 * @Date: 2020-03-14 10:46:22
 * @LastEditors: Kaizyn
 * @LastEditTime: 2020-03-14 11:11:37
 * @FilePath: \Code\Luogu\luogu4593_2.cpp
 */
#include <bits/stdc++.h>

#define DEBUG

using namespace std;

const int N = 55;
const int MOD = 1e9+7;

long long fac[N];

inline void init()
{
    fac[0] = 1;
    for (int i = 1; i < N; ++i) {
        fac[i] = fac[i-1]*i%MOD;
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

template <typename T>
inline T mul_inverse(const T &a, const int &mo = MOD)
{
    return qpow(a, mo-2);
}

template <typename T, typename P> // x[i] = i -> y[i] = f(i)
long long Largrange(const T &k, const int &n, const P y[])
{
    if (k <= n) return y[k];
    static long long pre[N], suf[N];
    long long res = 0;
    pre[0] = suf[n+1] = 1;
    for (int i = 1; i <= n; ++i) pre[i] = pre[i-1]*(k-i)%MOD;
    for (int i = n; i >= 1; --i) suf[i] = suf[i+1]*(k-i)%MOD;
    for (int i = 1; i <= n; ++i) {
        res = (res+y[i]*(pre[i-1]*suf[i+1]%MOD)%MOD
            *mul_inverse(((n-i)&1 ? -1 : 1)*fac[i-1]*fac[n-i]%MOD)%MOD)%MOD;
    }
    return (res+MOD)%MOD;
}

long long n;
int m, k;
long long a[N], y[N];

signed main()
{
    ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    init();
    int T;
    cin >> T;
    while (T--) {
        cin >> n >> m;
        for (int i = 1; i <= m; ++i) cin >> a[i];
        sort(a+1, a+m+1);
        k = m+1;
        for (int i = 1; i <= k+2; ++i) {
            y[i] = (y[i-1]+qpow(i, k))%MOD;
        }
        #ifdef DEBUG
        cout << "*****" << endl;
        for (int i = 1; i <= n; ++i)
            cout << i << " " << Largrange(i, k+2, y) << endl;
        cout << "*****" << endl;
        #endif
        long long res = 0;
        for (int i = 0; i <= m; ++i) {
            res = (res+Largrange(n-a[i], k+2, y))%MOD;
            for (int j = i+1; j <= m; ++j) {
                res = (res-qpow(a[j]-a[i], k)+MOD)%MOD;
            }
        }
        cout << res << endl;
    }
    return 0;
}