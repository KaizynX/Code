#include <bits/stdc++.h>

using namespace std;

const int Maxn = 1e6+7;
const int MOD = 993244853;

int n, ansi;
long long mul[Maxn], sf[Maxn], ansv;

inline void init();
inline long long C(int, int);
inline long long quickm(long long, int);
inline long long mul_inverse(long long);

int main()
{
	scanf("%d", &n);
	init();
	for(int i = 0, c; i <= n; ++i)
	{
		scanf("%d", &c);
		long long cur = sf[i]*C(i, n)%MOD*c%MOD;
		if(cur > ansv)
		{
			ansi = i;
			ansv = cur;
		}
	}
	printf("%lld\n", ansv);
	for(int i = 1; i <= n-ansi; ++i)
		printf("%d ", i);
	for(int i = n-ansi+1, flag = 1; i <= n-3*(ansi&1); ++i, flag = -flag)
		printf("%d ", i+flag);
	if(ansi&1) printf("%d %d %d", n-1, n, n-2);
	putchar('\n');
	return 0;
}

inline long long C(int p, int q)
{
	if(p == 0 || p == q) return 1;
	if(p == 1 || p == q-1) return q;
	long long mv1 = mul_inverse(mul[p]),
			  mv2 = mul_inverse(mul[q-p]);
	return mul[q]*mv2%MOD*mv1%MOD;
}

inline long long quickm(long long a, int p)
{
	long long res = 1;
	while(p)
	{
		if(p&1) res = res*a%MOD;
		p >>= 1;
		a = a*a%MOD;
	}
	return res;
}

inline long long mul_inverse(long long x)
{
	return quickm(x, MOD-2);
}

inline void init()
{
	mul[1] = 1;
	for(int i = 2; i <= n; ++i)
		mul[i] = mul[i-1]*i%MOD;
	sf[0] = 1; sf[1] = 0; sf[2] = 1;
	// sf[n] = (n-1)(sf[n-1]+sf[n-2])
	for(int i = 3; i <= n; ++i)
		sf[i] = (sf[i-1]+sf[i-2])%MOD*(i-1)%MOD;
}
