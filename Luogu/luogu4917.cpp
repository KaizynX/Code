#include <bits/stdc++.h>

using namespace std;

const int Maxn = 1e6+7;
const int MOD = 19260817;

int T, n;
int a[Maxn], p[100000], np[Maxn], tot;
long long f[Maxn];

inline long long qpow(long long a, int p)
{
	long long res = 1;
	a %= MOD;
	while(p)
	{
		if(p&1) res = res*a%MOD;
		p >>= 1;
		a = a*a%MOD;
	}
	return res;
}

inline long long mul_reverse(long long a)
{
	return qpow(a, MOD-2);
}

inline void Prime()
{
	/*
	tot = 0;
	memset(p, 0, sizeof p);
	memset(np, 0, sizeof np);
	*/
	for(int i = 2; i <= n; ++i)
	{
		if(np[i]) continue;
		p[++tot] = i;
		for(int j = 1; j <= tot && i*p[j] <= n; ++j)
		{
			np[i*p[j]] = 1;
			if(i%p[j] == 0) break;
		}
	}
}

inline void init()
{
	Prime();
	long long gcd, A = 1;
	f[1] = 1;
	for(int i = 2, cur, tmp; i <= n; ++i)
	{
		cur = i;
		gcd = 1;
		// i分解质因数
		for(int j = 1; j <= tot && cur > 1; ++j)
		{
			if(cur%p[j] == 0)
			{
				tmp = 1;
				while(cur%p[j] == 0)
				{
					cur /= p[j];
					tmp *= p[j];
					gcd = (gcd*qpow(p[j], (i-1)/tmp))%MOD;
				}
			}
		}
		f[i] = qpow(i, i-1)*A%MOD*mul_reverse(gcd*gcd%MOD)%MOD;
		f[i] = f[i]*f[i]%MOD*f[i-1]%MOD;
		// A = (i-1)!
		A = A*i%MOD;
	}
}

int main()
{
	scanf("%d", &T);
	for(int i = 1; i <= T; ++i)
	{
		scanf("%d", a+i);
		n = max(n, a[i]);
	}
	init();
	for(int i = 1; i <= T; ++i)
		printf("%d\n", (int)f[a[i]]);
	return 0;
}
