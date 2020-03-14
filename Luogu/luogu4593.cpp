/*
 * @Author: Kaizyn
 * @Date: 2020-03-13 20:50:15
 * @LastEditors: Kaizyn
 * @LastEditTime: 2020-03-14 11:12:36
 * @FilePath: \Code\Luogu\luogu4593.cpp
 */
#include <bits/stdc++.h>

#define DEBUG

using namespace std;

const int N = 55;
const int MOD = 1e9+7;

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

template <typename T, typename H, typename P>
long long Largrange(const T &k, const int &n, const H x[], const P y[])
{
    long long res = 0, s1 = 1, s2 = 1;
    for (int i = 1; i <= n; ++i, s1 = s2 = 1) {
        for (int j = 1; j <= n; ++j) if (i != j) {
            s1 = s1*(x[i]-x[j]+MOD)%MOD;
            s2 = s2*(k-x[j]+MOD)%MOD;
        }
        res = (res+y[i]*s2%MOD*mul_inverse(s1)%MOD)%MOD;
    }
    return res;
}

long long n;
int m, k;
int x[N];
long long a[N], y[N];

signed main()
{
    ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    int T;
    cin >> T;
    while (T--) {
        cin >> n >> m;
        for (int i = 1; i <= m; ++i) cin >> a[i];
        sort(a+1, a+m+1);
        k = m+1;
        for (int i = 1; i <= k+2; ++i) {
            x[i] = i;
            y[i] = (y[i-1]+qpow(i, k))%MOD;
        }
        #ifdef DEBUG
        cout << "*****" << endl;
        for (int i = 1; i <= n; ++i)
            cout << i << " " << Largrange(i, k+2, x, y) << endl;
        cout << "*****" << endl;
        #endif
        long long res = 0;
        for (int i = 0; i <= m; ++i) {
            res = (res+Largrange(n-a[i], k+2, x, y))%MOD;
            for (int j = i+1; j <= m; ++j) {
                res = (res-qpow(a[j]-a[i], k)+MOD)%MOD;
            }
        }
        cout << res << endl;
    }
    return 0;
}