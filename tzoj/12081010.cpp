#include <bits/stdc++.h>

using namespace std;

map<long long, long long> mmp;

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

// map<long long, int> mmp;
inline long long BSGS(long long a, long long x, long long m) // a^n = x
{
    long long t = (long long)ceil(sqrt(m)); // b = a^i
    for(int i = 0; i < t; ++i)
        mmp[x*qpow(a, i, m)] = i;
    a = qpow(a, t, m);
    long long now, ans; // now = (a^t)^i
    for(int i = 0; i <= t; ++i)
    {
        now = qpow(a, i, m);
        if(mmp.count(now))
        {
            ans = t*i-mmp[now];
            if(ans > 0) return ans;
        }
    }
    return -1;
}

int main()
{
	return 0;
}
