#include <bits/stdc++.h>
#define DEBUG

using namespace std;

const long long Maxn = 1e12+7;

long long n, p;

inline long long qpow(long long a, long long p)
{
    long long res = 1;
    for( ; p; p >>= 1, a *= a)
        if(p&1) res *= a;
    return res;
}

int main()
{
    cin >> n >> p;
    double lgp = log(p);
    long long l = 1, r = p/n;
    while(l < r)
    {
        long long mid = (l+r+1)>>1;
        if(lgp/log(mid) < n || qpow(mid, n) > p) r = mid-1;
        else l = mid;
    }
#ifdef DEBUG
    cout << l << endl;
#endif
    for(long long i = l; i; i--)
    {
        if(p%qpow(i, n) == 0)
        {
            cout << i << endl;
            break;
        }
    }
    return 0;
}
