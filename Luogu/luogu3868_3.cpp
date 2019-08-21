#include <bits/stdc++.h>

using namespace std;

const int kN = 20;

int n;
long long M = 1;
int a[kN], m[kN];

void exgcd(long long a, long long b, long long &x, long long &y)
{
    if (!b) {
        x = 1;
        y = 0;
        return;
    }
    exgcd(b, a%b, y, x);
    y -= a/b*x;
}

inline long long mul_inverse(long long a, long long mo)
{
    long long x, y;
    exgcd(a, mo, x, y);
    return (x%mo+mo)%mo;
}

inline long long mul(long long x, long long y, long long mo)
{
    // x*y - floor(x*y/mo)*mo
    /*
    long long z = (long double)x/mo*y;
    long long res = (unsigned long long)x*y-(unsigned long long)z*mo;
    return (res+mo)%mo;
    */
    // return ((unsigned long long)x*y-(unsigned long long)((long double)x/mo*y)*mo+mo)%mo;
    return (long double)x*y%mo;
}

inline long long CRT(int a[], int m[])
{
    long long res = 0, M = 1;
    for (int i = 1; i <= n; ++i)
        M *= m[i];
    for (int i = 1; i <= n; ++i)
        // res = (res + a[i]*(M/m[i])*mul_inverse(M/m[i], m[i]))%M;
        res = (res+mul(a[i], mul((M/m[i]), mul_inverse(M/m[i], m[i]), M), M))%M;
    return (res+M)%M;
}

int main()
{
    scanf("%d", &n);
    for (int i = 1; i <= n; ++i) {
        scanf("%d", a+i);
    }
    for (int i = 1; i <= n; ++i) {
        scanf("%d", m+i);
        a[i] = (a[i]%m[i]+m[i])%m[i];
    }
    printf("%lld\n", CRT(a, m));
    return 0;
}
