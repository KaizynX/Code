#include <cstdio>
#include <iostream>

using namespace std;

int n, p;

inline int quick_m(long long x, int k, int mo)
{
	long long res = 1;
	x %= mo;
	while(k)
	{
		if(k&1) res = res*x%mo;
		x = x*x%mo;
		k >>= 1;
	}
	return res;
}

inline int mul_inverse(int x)
{
	return quick_m(x, p-2, p);
}

int main()
{
	scanf("%d%d", &n, &p);
	for(int i = 1; i <= n; ++i)
		printf("%d\n", mul_inverse(i));
	return 0;
}
