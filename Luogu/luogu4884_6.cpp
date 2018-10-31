#include <bits/stdc++.h>

using namespace std;

long long k, m;
map<long long, int> mmp;

inline long long mul(long long a, long long b)
{
	long long lf = a*((b>>25))%m *(1ll<<25)%m;
	long long rg = a*(b&((1ll<<25)-1))%m;
    return (lf+rg)%m;
}

inline long long qpow(long long a, long long p)
{
	long long res = 1;
	while(p)
	{
		if(p&1) res = mul(res, a);
		a = mul(a, a);
		p >>= 1;
	}
	return res;
}

inline long long BSGS(long long a, long long x) // a^n = x
{
    long long t = (long long)ceil(sqrt(m)); // b = a^i
    for(int i = 0; i < t; ++i)
		mmp[mul(x, qpow(a, i))] = i;
	a = qpow(a, t);
    long long now, ans; // now = (a^t)^i
    for(int i = 0; i <= t; ++i)
    {
		now = qpow(a, i);
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
    cin >> k >> m;
    // 10^n (%m) = 9k+1 (%m)
    k = (k*9+1)%m;
	cout << BSGS(10, k) << endl;
    return 0;
}
