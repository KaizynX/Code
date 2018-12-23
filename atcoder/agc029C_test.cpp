#include <bits/stdc++.h>

using namespace std;

const int MOD = 1e9+7;

inline long long qpow(long long a, int p, int mo)
{
    long long res = 1;
    a %= mo;
    for( ; p; p >>= 1, a = a*a%mo)
        if(p&1) res = res*a%mo;
    return res;
}

inline long long mul_inv(long long a, int mo)
{
    return qpow(a, mo-2, mo);
}

int main()
{
    long long a, b;
    while(cin >> a >> b)
    {
        cout << a/b%MOD << " ";
        cout << a*mul_inv(b, MOD)%MOD << endl;
    }
    return 0;
}
