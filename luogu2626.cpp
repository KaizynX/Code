#include <cmath>
#include <cstdio>
#include <iostream>

using namespace std;

const int Maxn = 50;

int n;
long long f[Maxn];

inline void init_f()
{
	f[1] = f[2] = 1;
	for(int i = 3; i <= n; ++i)
		f[i] = (f[i-1]+f[i-2])%(1<<31);
}

inline bool is_prime(long long x)
{
    for(long long i = 2; i <= sqrt(x)+0.5; ++i)
        if(x%i == 0) return false;
    return true;
}

inline void solve()
{
	int flag = 0;
	printf("%lld=", f[n]);
	/*
	if(is_prime(f[n]))
	{
		printf("%lld\n", f[n]);
		return;
	}
	*/
	for(long long i = 2; i <= f[n] && f[n]; ++i)
	{
		if(f[n]%i)continue;
		while(f[n] && f[n]%i == 0)
		{
			if(flag) putchar('*');
			else flag = 1;
			printf("%lld", i);
			f[n] /= i;
		}
	}
	putchar('\n');
}

int main()
{
	scanf("%d", &n);
	init_f();
	solve();
	return 0;
}
