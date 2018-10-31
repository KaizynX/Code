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

inline long long BSGS(long long a, long long x) // a^n = x
{
    long long t = (long long)ceil(sqrt(m)), b = 1, tmp; // b = a^i
    for(int i = 0; i < t; ++i)
    {
		tmp = mul(x, b);
		if(!mmp.count(tmp)) mmp.insert(make_pair(tmp, i));
        b = mul(b, a);
    }
    // b = a^t
    long long now = 1, ans; // now = (a^t)^i
    for(int i = 0; i <= t; ++i)
    {
        if(mmp.count(now))
        {
            ans = 1ll*i*t-mmp[now];
            if(ans > 0) return ans;
        }
        now = mul(now, b);
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
