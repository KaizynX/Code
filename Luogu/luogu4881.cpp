#include <cstdio>
#include <iostream>

using namespace std;

const long long Mo = 1e9+7;

int T;
long long n;

inline long long quick_mo(long long x, long long p, long long mo)
{
	long long res = 1;
	x %= mo;
	while(p)
	{
		if(p&1) res = res*x%mo;
		x = x*x%mo;
		p >>= 1;
	}
	return res;
}

inline long long mul_inverse(int x)
{
	return quick_mo(x, Mo-2, Mo);
}

int main()
{
	scanf("%d", &T);
	long long inverse = mul_inverse(625);
	while(T--)
	{
		scanf("%lld", &n);
		n = (n+1)/2;
		// f(n) = (1/625)*((50*n-27)*26^(n+1)+702)%(1e9+7)
		long long res = ((50*n-27)%Mo*quick_mo(26, n+1, Mo)%Mo+702)%Mo*inverse%Mo;
		printf("%lld\n", res);
	}
	return 0;
}
