#include <bits/stdc++.h>

using namespace std;

const int kN = 20;

int n;
long long M = 1;
int a[kN], m[kN];

inline long long qpow(long long a, long long p, long long mo)
{
    if(p == 0) return 1 % mo;
    long long ans = 1;
    a %= mo;
    while(p)
    {
        if(p&1) ans = ans*a%mo;
        a = a*a%mo;
        p >>= 1;
    }
    return ans;
}

inline long long mul_inverse(long long a, long long mo)
{
    // a^(mo-2)%mo
    return qpow(a, mo-2, mo);
}

inline long long CRT(int a[], int m[])
{
    long long res = 0, M = 1;
    for (int i = 1; i <= n; ++i)
        M *= m[i];
    for (int i = 1; i <= n; ++i)
        res = (res+a[i]*(M/m[i])*mul_inverse(M/m[i], M))%M;
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
