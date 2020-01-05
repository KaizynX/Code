#include <cmath>
#include <vector>
#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>

using namespace std;

long long L;

inline long long qmul(long long x, long long y, long long mo)
{
    // x*y - floor(x*y/mo)*mo
    typedef unsigned long long ull;
    typedef long double ld;
    return ((ull)x*y-(ull)((ld)x/mo*y)*mo+mo)%mo;
}

inline long long phi(long long x) {
    long long res = x;
    for (long long i = 2; i*i <= x; ++i) {
        if (x%i) continue;
        res = res/i*(i-1);
        while (x%i == 0) x /= i;
    }
    if (x > 1) res = res/x*(x-1);
    return res;
}

inline long long qpow(long long a, long long p, long long mo) {
    long long res = 1;
    while (p) {
        if (p&1) res = qmul(res, a, mo);
        a = qmul(a, a, mo);
        p >>= 1;
    }
    return res;
}

int main()
{
    // L | 8*(10^x-1)/9
    // 10^x = 1 % 9*L\d
    ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    int T = 0;
    long long L, d, p, res;
    while (cin >> L && L) {
        d = __gcd(8ll, L);
        L = L/d*9;
        p = phi(L);
        res = 0;
        for (long long i = 1; i*i <= p; ++i) {
            if (p%i) continue;
            if (qpow(10, i, L) == 1)
                res = (res ? min(res, i) : i);
            if (qpow(10, p/i, L) == 1)
                res = (res ? min(res, p/i) : p/i);
        }
        cout << "Case " << ++T << ": " << res << endl;
    }
    return 0;
}

