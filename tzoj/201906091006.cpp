#include <bits/stdc++.h>

using namespace std;

const int MO = 1e9+9;

int T, n, m, k;

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

int main()
{
    cin >> T;
    while(T--)
    {
        cin >> n >> m >> k;
        int pre = n-(n-m)*k;
        if(pre < k) cout << m << endl;
        else cout << (qpow(2, pre/k+1, MO)-2+MO)%MO*k%MO+m-pre/k*k << endl;
    }
    return 0;
}
