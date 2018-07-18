#include <iostream>
#include <cstdio>
#include <cmath>

using namespace std;

const int Maxn = 1e3 + 7;

int n;
int prime[Maxn], cnt;
bool is_prime[Maxn];
long long f[Maxn];

int main()
{
	scanf("%d", &n);
	prime[++cnt] = 2;
	for(int i = 3; i <= n ;++i)
	{
		bool is_prime = true;
		for(int j = 2; j <= sqrt(i)+0.5; ++j)
			if(i % j == 0)
			{
				is_prime = false;
				break;
			}
		if(is_prime) prime[++cnt] = i;
	}

	f[0] = 1;
	for(int i = 1; i <= cnt; ++i)
		for(int v = prime[i]; v <= n; ++v)
			f[v] += f[v-prime[i]];
	printf("%lld\n", f[n]);
	return 0;
}
