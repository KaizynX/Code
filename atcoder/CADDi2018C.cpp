#include <bits/stdc++.h>
#define DEBUG

using namespace std;

const long long Maxn = 1e12+7;

long long n, p;

inline int count_len(long long x)
{
    int res = 0;
    for( ; x > 9; x /= 10, res++);
    return res;
}

inline long long qpow(long long a, long long p)
{
    long long res = 1;
    for( ; p; p >>= 1, a *= a)
        if(p&1) res *= a;
    return res;
}

inline long long calc_len(long long x) // len of x^n
{
    int res = 0;
    for( ; x > 9; x /= 10, res++);
    return res*n+count_len(qpow(x, n));
}


int main()
{
    cin >> n >> p;
    int p_len = count_len(p)+1;
    long long l = 1, r = p/n;
    while(l < r)
    {
        long long mid = (l+r+1)>>1;
#ifdef DEBUG
        cout << mid << " " << calc_len(mid) << endl;
#endif
        if(calc_len(mid) > p_len || qpow(mid, n) > p) r = mid-1;
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
