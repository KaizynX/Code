#include <bits/stdc++.h>

using namespace std;

const int kN = 1e5+7;

int n;
long long a[kN], b[kN];

inline long long qmul(long long x, long long y, long long mo)
{
    // x*y - floor(x*y/mo)*mo
    typedef unsigned long long ull;
    typedef long double ld;
    return ((ull)x*y-(ull)((ld)x/mo*y)*mo+mo)%mo;
}

long long gcd(long long a, long long b)
{
    return b ? gcd(b, a%b) : a;
}

long long exgcd(long long a, long long b, long long &x, long long &y)
{
    if (!b) {
        x = 1;
        y = 0;
        return a;
    }
    long long d = exgcd(b, a%b, y, x);
    y -= a/b*x;
    return d;
}

inline long long EXCRT(long long a[], long long m[])
{
    // M*x + m[i]*y = a[i]-res (mod m[i])
    // res = res+x*M;
    long long M = m[1], res = a[1], x, y, c, d;
    for (int i = 2; i <= n; ++i) {
        d = exgcd(M, m[i], x, y);
        c = (a[i]-res%m[i]+m[i])%m[i];
        if (c%d != 0) return -1;
        x = qmul(c/d, x, m[i]/d);
        res += x*M;
        M *= m[i]/d;
        res = (res%M+M)%M;
    }
    return res;
}

int main()
{
    scanf("%d", &n);
    for (int i = 1; i <= n; ++i) {
        scanf("%lld%lld", a+i, b+i);
    }
    printf("%lld\n", EXCRT(b, a));
    return 0;
}
