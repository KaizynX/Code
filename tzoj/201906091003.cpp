#include <bits/stdc++.h>

using namespace std;

int T, n, q, p;

inline long long mul(long long x,long long y,long long mod)
{
    return (x*y-(long long)((long double)x/mod*y)*mod+mod)%mod;     
}

inline long long qpow(long long a, long long p, long long mo)
{
    if(p == 0) return 1 % mo;
    long long ans = 1;
    a %= mo;
    while(p)
    {
        if(p&1) ans = mul(ans,a, mo)%mo;
        a = mul(a, a, mo)%mo;
        p >>= 1;
    }
    return ans;
}

inline long long mul_inverse(long long a, long long mo)
{
    // a^(mo-2)%mo
    return qpow(a, mo-2, mo);
}

int main()
{
    cin >> T;
    while(T--)
    {
        cin >> n >> q >> p;
        // cout << (qpow(q, n, p)-1+p)%p*q%p*mul_inverse(q-1, p) << endl;
        long long mod = (long long)p*(q-1);
        cout << mul((qpow(q, n, mod)-1+mod)%mod,q, mod)%mod/(q-1) << endl;
    }
    return 0;
}
