#include <bits/stdc++.h>

using namespace std;

const int Maxn = 1e6+7;
const int MOD = 19260817;

int T, n;
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

void exgcd(int a, int b, int &x, int &y)
{
	if(!b)
	{
		x = 1;
		y = 0;
		return;
	}
	exgcd(b, a%b, y, x);
	y -= a/b*x;
}

inline int mul_inverse(int a)
{
	int x, y;
	exgcd(a, MOD, x, y);
	return (x%MOD+MOD)%MOD;
}

inline void init()
{
	const int N = 100;
	long long gcd, A = 1;
	f[1] = 1;
	for(int i = 2, cur, tmp; i <= N; ++i)
	{
		cur = i;
		gcd = 1;
		// i分解质因数
		for(int j = 2; cur > 1; j += 2)
		{
			if(cur%j == 0)
			{
				tmp = 1;
				while(cur%j == 0)
				{
					cur /= j;
					tmp *= j;
					gcd = (gcd*qpow(j, (i-1)/tmp))%MOD;
				}
			}
			if(j == 2) j--;
		}
		f[i] = qpow(i, i-1)*A%MOD*mul_inverse((int)(gcd*gcd%MOD))%MOD;
		f[i] = f[i]*f[i]%MOD*f[i-1]%MOD;
		printf("f[%d]=%d gcd=%d\n", i, (int)f[i], (int)gcd);
		// A = (i-1)!
		A = A*i%MOD;
	}
}

int main()
{
	init();
	scanf("%d", &T);
	while(T--)
	{
		scanf("%d", &n);
		printf("%d\n", (int)f[n]);
	}
	return 0;
}
