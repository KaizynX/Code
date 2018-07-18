#include <iostream>
#include <cstdio>
#include <cmath>

using namespace std;

const int Mo = 1e9 + 7;

// (k)^(k-1) * (n-k)^(n-k) 
long long n;
int k;

long long quickm(long long a, long long p) // a^p % Mo
{
	long long ans = 1;
	a %= Mo;
	while(p)
	{
		if(p&1) ans = ans * a % Mo;
		p >>= 1;
		a = a * a % Mo;
	}
	return ans;
}

int main()
{
	while(scanf("%lld%d", &n, &k) == 2)
		printf("%lld\n", quickm(k, k-1) * quickm(n-k, n-k) % Mo);
	return 0;
}
